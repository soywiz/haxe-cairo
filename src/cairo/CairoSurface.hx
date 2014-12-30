package cairo;

import haxe.io.Input;
import haxe.io.BytesOutput;
import haxe.io.Output;
import haxe.io.Bytes;
import haxe.io.BytesData;

class CairoSurface {
	private var handle:Dynamic;
	public var format(get, never):CairoSurfaceFormat;
	public var width(get, never):Int;
	public var height(get, never):Int;
	public var stride(get, never):Int;

	public function new(handle:Dynamic) {
		if (handle == null) throw "Couldn't create surface";
		this.handle = handle;
	}

	private function get_format() return cast(CairoRaw.cairo_image_surface_get_format(handle), CairoSurfaceFormat);
	private function get_width() return CairoRaw.cairo_image_surface_get_width(handle);
	private function get_height() return CairoRaw.cairo_image_surface_get_height(handle);
	private function get_stride() return CairoRaw.cairo_image_surface_get_stride(handle);

	static public function create(format:CairoSurfaceFormat, width:Int, height:Int):CairoSurface {
		return new CairoSurface(CairoRaw.cairo_image_surface_create(format, width, height));
	}

	static public function createFromPng(filename:String):CairoSurface {
		return new CairoSurface(CairoRaw.cairo_image_surface_create_from_png(filename));
	}

	static public function createFromPngStream(input:Input, autoclose:Bool = true):CairoSurface {
		var result = new CairoSurface(CairoRaw.cairo_image_surface_create_from_png_stream(null, function(len:Int):BytesData {
			return input.read(len).getData();
		}));
		if (autoclose) input.close();
		return result;
	}

	static public function createForSvg(filename:String, width_in_points:Float, height_in_points:Float):CairoSurface {
		return new CairoSurface(CairoRaw.cairo_svg_surface_create(filename, width_in_points, height_in_points));
	}

	// should work on GC before get this working, and close after destroying
	/*
	static public function createForSvgStream(output:Output, width_in_points:Float, height_in_points:Float):CairoSurface {
		var result = new CairoSurface(CairoRaw.cairo_svg_surface_create_for_stream(null, function(data:BytesData) {
			try {
				output.write(Bytes.ofData(data));
				output.flush();
				return CairoStatus.SUCCESS;
			} catch (e:Dynamic) {
				return CairoStatus.WRITE_ERROR;
			}
		}, width_in_points, height_in_points));
		//output.flush();
		//if (autoclose) output.close();
		return result;
	}
	*/

	static public function createForPdf(filename:String, width:Float, height:Float):CairoSurface {
		return new CairoSurface(CairoRaw.cairo_pdf_surface_create(filename, width, height));
	}

	public function createSimilar(content:CairoContent, width:Int, height:Int):CairoSurface {
		return new CairoSurface(CairoRaw.cairo_surface_create_similar(handle, content, width, height));
	}

	public function createSimilarImage(format:CairoSurfaceFormat, width:Int, height:Int):CairoSurface {
		return new CairoSurface(CairoRaw.cairo_surface_create_similar_image(handle, format, width, height));
	}

	public function createForRectangle(x:Float, y:Float, width:Float, height:Float):CairoSurface {
		return new CairoSurface(CairoRaw.cairo_surface_create_for_rectangle(handle, x, y, width, height));
	}

	public function restrictToVersion(version:CairoSvgVersion):Void {
		CairoRaw.cairo_svg_surface_restrict_to_version(handle, version);
	}

	static public function svgVersionToString(version:CairoSvgVersion):String {
		return CairoRaw.cairo_svg_version_to_string(version);
	}

	public function getStatus():CairoStatus return cast(CairoRaw.cairo_surface_status(handle), CairoStatus);
/*
	public function destroy():CairoSurface {
		CairoRaw.cairo_surface_destroy(this.handle);
		this.handle = null;
		return this;
	}
	*/

	public function flush():CairoSurface {
		CairoRaw.cairo_surface_flush(this.handle);
		return this;
	}

	public function finish():CairoSurface {
		CairoRaw.cairo_surface_finish(this.handle);
		return this;
	}

	public function getContext():CairoContext {
		return new CairoContext(CairoRaw.cairo_create(this.handle));
	}

	public function writeToPng(path:String) {
		CairoRaw.cairo_surface_write_to_png(this.handle, path);
	}

	public function getPngBytes():Bytes {
		return writeToPngStream(new BytesOutput()).getBytes();
	}

	public function writeToPngStream<T: Output>(output:T, autoclose:Bool = true):T {
		var result = CairoRaw.cairo_surface_write_to_png_stream(handle, null, function(data:BytesData) {
			try {
				output.write(Bytes.ofData(data));
				return CairoStatus.SUCCESS;
			} catch (e:Dynamic) {
				return CairoStatus.WRITE_ERROR;
			}
		});
		output.flush();
		if (autoclose) output.close();
		if (result != CairoStatus.SUCCESS) throw "Error writeToPngStream";
		return output;
	}

	public function toString() {
		return 'CairoSurface(format=$format, ${width}x${height}, stride=$stride)';
	}
}
