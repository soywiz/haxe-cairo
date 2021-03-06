#ifndef STATIC_LINK
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif

#include <hx/CFFI.h>

#include <string.h>
#include <stdio.h>

#include "cairo/src/cairo.h"
#include "cairo/src/cairo-svg.h"
#include "cairo/src/cairo-pdf.h"

#include "ExtraFunctions.cpp"

extern "C" {
	#define val_get_float(v) val_get_double(v)

	void dummy_free(void*ptr) { }

	cairo_matrix_t* cairo_matrix_create() {
		return new cairo_matrix_t;
	}

	void cairo_matrix_destroy(cairo_matrix_t* matrix) {
		delete matrix;
	}

    		DECLARE_KIND(kind_cairo_surface_t)
		DEFINE_KIND(kind_cairo_surface_t)
		void kind_cairo_surface_t_check(value z) {
			val_check_kind(z, kind_cairo_surface_t);
		}
		cairo_surface_t* kind_cairo_surface_t_get(value z) {
			return ((cairo_surface_t*)val_get_handle(z, kind_cairo_surface_t));
		}
		void kind_cairo_surface_t_destroy(value z) {
			cairo_surface_destroy(kind_cairo_surface_t_get(z));
		}
		value kind_cairo_surface_t_alloc(cairo_surface_t* z) {
	        value abstract_object = alloc_abstract(kind_cairo_surface_t, z);
	        val_gc(abstract_object, ((hxFinalizer) kind_cairo_surface_t_destroy));
	        return abstract_object; 
		}

    		DECLARE_KIND(kind_cairo_t)
		DEFINE_KIND(kind_cairo_t)
		void kind_cairo_t_check(value z) {
			val_check_kind(z, kind_cairo_t);
		}
		cairo_t* kind_cairo_t_get(value z) {
			return ((cairo_t*)val_get_handle(z, kind_cairo_t));
		}
		void kind_cairo_t_destroy(value z) {
			cairo_destroy(kind_cairo_t_get(z));
		}
		value kind_cairo_t_alloc(cairo_t* z) {
	        value abstract_object = alloc_abstract(kind_cairo_t, z);
	        val_gc(abstract_object, ((hxFinalizer) kind_cairo_t_destroy));
	        return abstract_object; 
		}

    		DECLARE_KIND(kind_cairo_pattern_t)
		DEFINE_KIND(kind_cairo_pattern_t)
		void kind_cairo_pattern_t_check(value z) {
			val_check_kind(z, kind_cairo_pattern_t);
		}
		cairo_pattern_t* kind_cairo_pattern_t_get(value z) {
			return ((cairo_pattern_t*)val_get_handle(z, kind_cairo_pattern_t));
		}
		void kind_cairo_pattern_t_destroy(value z) {
			cairo_pattern_destroy(kind_cairo_pattern_t_get(z));
		}
		value kind_cairo_pattern_t_alloc(cairo_pattern_t* z) {
	        value abstract_object = alloc_abstract(kind_cairo_pattern_t, z);
	        val_gc(abstract_object, ((hxFinalizer) kind_cairo_pattern_t_destroy));
	        return abstract_object; 
		}

    		DECLARE_KIND(kind_cairo_matrix_t)
		DEFINE_KIND(kind_cairo_matrix_t)
		void kind_cairo_matrix_t_check(value z) {
			val_check_kind(z, kind_cairo_matrix_t);
		}
		cairo_matrix_t* kind_cairo_matrix_t_get(value z) {
			return ((cairo_matrix_t*)val_get_handle(z, kind_cairo_matrix_t));
		}
		void kind_cairo_matrix_t_destroy(value z) {
			cairo_matrix_destroy(kind_cairo_matrix_t_get(z));
		}
		value kind_cairo_matrix_t_alloc(cairo_matrix_t* z) {
	        value abstract_object = alloc_abstract(kind_cairo_matrix_t, z);
	        val_gc(abstract_object, ((hxFinalizer) kind_cairo_matrix_t_destroy));
	        return abstract_object; 
		}

    		DECLARE_KIND(kind_cairo_path_t)
		DEFINE_KIND(kind_cairo_path_t)
		void kind_cairo_path_t_check(value z) {
			val_check_kind(z, kind_cairo_path_t);
		}
		cairo_path_t* kind_cairo_path_t_get(value z) {
			return ((cairo_path_t*)val_get_handle(z, kind_cairo_path_t));
		}
		void kind_cairo_path_t_destroy(value z) {
			cairo_path_destroy(kind_cairo_path_t_get(z));
		}
		value kind_cairo_path_t_alloc(cairo_path_t* z) {
	        value abstract_object = alloc_abstract(kind_cairo_path_t, z);
	        val_gc(abstract_object, ((hxFinalizer) kind_cairo_path_t_destroy));
	        return abstract_object; 
		}

    		DECLARE_KIND(kind_cairo_region_t)
		DEFINE_KIND(kind_cairo_region_t)
		void kind_cairo_region_t_check(value z) {
			val_check_kind(z, kind_cairo_region_t);
		}
		cairo_region_t* kind_cairo_region_t_get(value z) {
			return ((cairo_region_t*)val_get_handle(z, kind_cairo_region_t));
		}
		void kind_cairo_region_t_destroy(value z) {
			cairo_region_destroy(kind_cairo_region_t_get(z));
		}
		value kind_cairo_region_t_alloc(cairo_region_t* z) {
	        value abstract_object = alloc_abstract(kind_cairo_region_t, z);
	        val_gc(abstract_object, ((hxFinalizer) kind_cairo_region_t_destroy));
	        return abstract_object; 
		}

    		DECLARE_KIND(kind_cairo_font_options_t)
		DEFINE_KIND(kind_cairo_font_options_t)
		void kind_cairo_font_options_t_check(value z) {
			val_check_kind(z, kind_cairo_font_options_t);
		}
		cairo_font_options_t* kind_cairo_font_options_t_get(value z) {
			return ((cairo_font_options_t*)val_get_handle(z, kind_cairo_font_options_t));
		}
		void kind_cairo_font_options_t_destroy(value z) {
			cairo_font_options_destroy(kind_cairo_font_options_t_get(z));
		}
		value kind_cairo_font_options_t_alloc(cairo_font_options_t* z) {
	        value abstract_object = alloc_abstract(kind_cairo_font_options_t, z);
	        val_gc(abstract_object, ((hxFinalizer) kind_cairo_font_options_t_destroy));
	        return abstract_object; 
		}

    
    					value hx_cairo_version() {
		        	
        					int _result = cairo_version();
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_version, 0);
		    					value hx_cairo_version_string() {
		        	
        					const char* _result = cairo_version_string();
	        					return alloc_string(_result);
        	        }
				DEFINE_PRIM(hx_cairo_version_string, 0);
		    					value hx_cairo_status_to_string(value status) {
		        	        		val_check(status, int);
        	
        					const char* _result = cairo_status_to_string(((cairo_status_t)val_get_int(status)));
	        		        		;
	        					return alloc_string(_result);
        	        }
				DEFINE_PRIM(hx_cairo_status_to_string, 1);
		    					value hx_cairo_debug_reset_static_data() {
		        	
        					cairo_debug_reset_static_data();
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_debug_reset_static_data, 0);
		    					value hx_cairo_create(value target) {
		        	        		kind_cairo_surface_t_check(target);
        	
        					cairo_t* _result = cairo_create(kind_cairo_surface_t_get(target));
	        		        		;
	        					return kind_cairo_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_create, 1);
		    					value hx_cairo_save(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_save(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_save, 1);
		    					value hx_cairo_restore(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_restore(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_restore, 1);
		    					value hx_cairo_set_source(value cr, value source) {
		        	        		kind_cairo_t_check(cr);
        	        		kind_cairo_pattern_t_check(source);
        	
        					cairo_set_source(kind_cairo_t_get(cr), kind_cairo_pattern_t_get(source));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_source, 2);
		    					value hx_cairo_set_source_rgb(value cr, value red, value green, value blue) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(red, number);;
        	        		val_check(green, number);;
        	        		val_check(blue, number);;
        	
        					cairo_set_source_rgb(kind_cairo_t_get(cr), val_get_double(red), val_get_double(green), val_get_double(blue));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_source_rgb, 4);
		    					value hx_cairo_set_source_rgba(value cr, value red, value green, value blue, value alpha) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(red, number);;
        	        		val_check(green, number);;
        	        		val_check(blue, number);;
        	        		val_check(alpha, number);;
        	
        					cairo_set_source_rgba(kind_cairo_t_get(cr), val_get_double(red), val_get_double(green), val_get_double(blue), val_get_double(alpha));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_source_rgba, 5);
		    					value hx_cairo_set_source_surface(value cr, value surface, value x, value y) {
		        	        		kind_cairo_t_check(cr);
        	        		kind_cairo_surface_t_check(surface);
        	        		val_check(x, number);;
        	        		val_check(y, number);;
        	
        					cairo_set_source_surface(kind_cairo_t_get(cr), kind_cairo_surface_t_get(surface), val_get_double(x), val_get_double(y));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_source_surface, 4);
		    					value hx_cairo_get_source(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_pattern_t* _result = cairo_get_source(kind_cairo_t_get(cr));
	        		        		;
	        					return kind_cairo_pattern_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_get_source, 1);
		    					value hx_cairo_fill(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_fill(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_fill, 1);
		    					value hx_cairo_stroke(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_stroke(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_stroke, 1);
		    					value hx_cairo_status(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_status_t _result = cairo_status(kind_cairo_t_get(cr));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_status, 1);
		    					value hx_cairo_get_target(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_surface_t* _result = cairo_get_target(kind_cairo_t_get(cr));
	        		        		;
	        					return kind_cairo_surface_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_get_target, 1);
		    					value hx_cairo_set_antialias(value cr, value value) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(value, int);
        	
        					cairo_set_antialias(kind_cairo_t_get(cr), ((cairo_antialias_t)val_get_int(value)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_antialias, 2);
		    					value hx_cairo_get_antialias(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_antialias_t _result = cairo_get_antialias(kind_cairo_t_get(cr));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_get_antialias, 1);
		    					value hx_cairo_set_fill_rule(value cr, value value) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(value, int);
        	
        					cairo_set_fill_rule(kind_cairo_t_get(cr), ((cairo_fill_rule_t)val_get_int(value)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_fill_rule, 2);
		    					value hx_cairo_get_fill_rule(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_fill_rule_t _result = cairo_get_fill_rule(kind_cairo_t_get(cr));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_get_fill_rule, 1);
		    					value hx_cairo_set_line_cap(value cr, value value) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(value, int);
        	
        					cairo_set_line_cap(kind_cairo_t_get(cr), ((cairo_line_cap_t)val_get_int(value)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_line_cap, 2);
		    					value hx_cairo_get_line_cap(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_line_cap_t _result = cairo_get_line_cap(kind_cairo_t_get(cr));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_get_line_cap, 1);
		    					value hx_cairo_set_line_join(value cr, value value) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(value, int);
        	
        					cairo_set_line_join(kind_cairo_t_get(cr), ((cairo_line_join_t)val_get_int(value)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_line_join, 2);
		    					value hx_cairo_get_line_join(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_line_join_t _result = cairo_get_line_join(kind_cairo_t_get(cr));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_get_line_join, 1);
		    					value hx_cairo_set_line_width(value cr, value value) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(value, number);;
        	
        					cairo_set_line_width(kind_cairo_t_get(cr), val_get_double(value));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_line_width, 2);
		    					value hx_cairo_set_miter_limit(value cr, value value) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(value, number);;
        	
        					cairo_set_miter_limit(kind_cairo_t_get(cr), val_get_double(value));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_miter_limit, 2);
		    					value hx_cairo_set_tolerance(value cr, value value) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(value, number);;
        	
        					cairo_set_tolerance(kind_cairo_t_get(cr), val_get_double(value));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_tolerance, 2);
		    					value hx_cairo_get_line_width(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					double _result = cairo_get_line_width(kind_cairo_t_get(cr));
	        		        		;
	        					return alloc_float(_result);
        	        }
				DEFINE_PRIM(hx_cairo_get_line_width, 1);
		    					value hx_cairo_get_miter_limit(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					double _result = cairo_get_miter_limit(kind_cairo_t_get(cr));
	        		        		;
	        					return alloc_float(_result);
        	        }
				DEFINE_PRIM(hx_cairo_get_miter_limit, 1);
		    					value hx_cairo_get_tolerance(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					double _result = cairo_get_tolerance(kind_cairo_t_get(cr));
	        		        		;
	        					return alloc_float(_result);
        	        }
				DEFINE_PRIM(hx_cairo_get_tolerance, 1);
		    					value hx_cairo_set_operator(value cr, value op) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(op, int);
        	
        					cairo_set_operator(kind_cairo_t_get(cr), ((cairo_operator_t)val_get_int(op)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_operator, 2);
		    					value hx_cairo_get_operator(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_operator_t _result = cairo_get_operator(kind_cairo_t_get(cr));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_get_operator, 1);
		    					value hx_cairo_copy_page(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_copy_page(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_copy_page, 1);
		    					value hx_cairo_show_page(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_show_page(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_show_page, 1);
		    					value hx_cairo_push_group(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_push_group(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_push_group, 1);
		    					value hx_cairo_push_group_with_content(value cr, value content) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(content, int);
        	
        					cairo_push_group_with_content(kind_cairo_t_get(cr), ((cairo_content_t)val_get_int(content)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_push_group_with_content, 2);
		    					value hx_cairo_pop_group(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_pattern_t* _result = cairo_pop_group(kind_cairo_t_get(cr));
	        		        		;
	        					return kind_cairo_pattern_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pop_group, 1);
		    					value hx_cairo_pop_group_to_source(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_pop_group_to_source(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_pop_group_to_source, 1);
		    					value hx_cairo_get_group_target(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_surface_t* _result = cairo_get_group_target(kind_cairo_t_get(cr));
	        		        		;
	        					return kind_cairo_surface_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_get_group_target, 1);
		    					value hx_cairo_clip_extents(value cr, value p1, value p2) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(p1, array); double p1_x = val_number(val_array_i(p1, 0)), p1_y = val_number(val_array_i(p1, 1));
        	        		val_check(p2, array); double p2_x = val_number(val_array_i(p2, 0)), p2_y = val_number(val_array_i(p2, 1));
        	
        					cairo_clip_extents(kind_cairo_t_get(cr), &p1_x, &p1_y, &p2_x, &p2_y);
	        		        		;
	        		        		val_array_set_i(p1, 0, alloc_float(p1_x)); val_array_set_i(p1, 1, alloc_float(p1_y));;
	        		        		val_array_set_i(p2, 0, alloc_float(p2_x)); val_array_set_i(p2, 1, alloc_float(p2_y));;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_clip_extents, 3);
		    					value hx_cairo_clip(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_clip(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_clip, 1);
		    					value hx_cairo_clip_preserve(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_clip_preserve(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_clip_preserve, 1);
		    					value hx_cairo_in_clip(value cr, value x, value y) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(x, number);;
        	        		val_check(y, number);;
        	
        					bool _result = cairo_in_clip(kind_cairo_t_get(cr), val_get_double(x), val_get_double(y));
	        		        		;
	        		        		;
	        		        		;
	        					return alloc_bool(_result);
        	        }
				DEFINE_PRIM(hx_cairo_in_clip, 3);
		    					value hx_cairo_reset_clip(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_reset_clip(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_reset_clip, 1);
		    					value hx_cairo_fill_preserve(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_fill_preserve(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_fill_preserve, 1);
		    					value hx_cairo_fill_extents(value cr, value p1, value p2) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(p1, array); double p1_x = val_number(val_array_i(p1, 0)), p1_y = val_number(val_array_i(p1, 1));
        	        		val_check(p2, array); double p2_x = val_number(val_array_i(p2, 0)), p2_y = val_number(val_array_i(p2, 1));
        	
        					cairo_fill_extents(kind_cairo_t_get(cr), &p1_x, &p1_y, &p2_x, &p2_y);
	        		        		;
	        		        		val_array_set_i(p1, 0, alloc_float(p1_x)); val_array_set_i(p1, 1, alloc_float(p1_y));;
	        		        		val_array_set_i(p2, 0, alloc_float(p2_x)); val_array_set_i(p2, 1, alloc_float(p2_y));;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_fill_extents, 3);
		    					value hx_cairo_in_fill(value cr, value x, value y) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(x, number);;
        	        		val_check(y, number);;
        	
        					bool _result = cairo_in_fill(kind_cairo_t_get(cr), val_get_double(x), val_get_double(y));
	        		        		;
	        		        		;
	        		        		;
	        					return alloc_bool(_result);
        	        }
				DEFINE_PRIM(hx_cairo_in_fill, 3);
		    					value hx_cairo_stroke_preserve(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_stroke_preserve(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_stroke_preserve, 1);
		    					value hx_cairo_stroke_extents(value cr, value p1, value p2) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(p1, array); double p1_x = val_number(val_array_i(p1, 0)), p1_y = val_number(val_array_i(p1, 1));
        	        		val_check(p2, array); double p2_x = val_number(val_array_i(p2, 0)), p2_y = val_number(val_array_i(p2, 1));
        	
        					cairo_stroke_extents(kind_cairo_t_get(cr), &p1_x, &p1_y, &p2_x, &p2_y);
	        		        		;
	        		        		val_array_set_i(p1, 0, alloc_float(p1_x)); val_array_set_i(p1, 1, alloc_float(p1_y));;
	        		        		val_array_set_i(p2, 0, alloc_float(p2_x)); val_array_set_i(p2, 1, alloc_float(p2_y));;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_stroke_extents, 3);
		    					value hx_cairo_in_stroke(value cr, value x, value y) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(x, number);;
        	        		val_check(y, number);;
        	
        					bool _result = cairo_in_stroke(kind_cairo_t_get(cr), val_get_double(x), val_get_double(y));
	        		        		;
	        		        		;
	        		        		;
	        					return alloc_bool(_result);
        	        }
				DEFINE_PRIM(hx_cairo_in_stroke, 3);
		    					value hx_cairo_mask(value cr, value value) {
		        	        		kind_cairo_t_check(cr);
        	        		kind_cairo_pattern_t_check(value);
        	
        					cairo_mask(kind_cairo_t_get(cr), kind_cairo_pattern_t_get(value));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_mask, 2);
		    					value hx_cairo_mask_surface(value cr, value surface, value x, value y) {
		        	        		kind_cairo_t_check(cr);
        	        		kind_cairo_surface_t_check(surface);
        	        		val_check(x, number);;
        	        		val_check(y, number);;
        	
        					cairo_mask_surface(kind_cairo_t_get(cr), kind_cairo_surface_t_get(surface), val_get_double(x), val_get_double(y));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_mask_surface, 4);
		    					value hx_cairo_paint(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_paint(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_paint, 1);
		    					value hx_cairo_paint_with_alpha(value cr, value alpha) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(alpha, number);;
        	
        					cairo_paint_with_alpha(kind_cairo_t_get(cr), val_get_double(alpha));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_paint_with_alpha, 2);
		    					value hx_cairo_get_dash_count(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					int _result = cairo_get_dash_count(kind_cairo_t_get(cr));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_get_dash_count, 1);
		    					value hx_cairo_set_dash(value cr, value dashes, value num_dashes, value offset) {
		        	        		kind_cairo_t_check(cr);
        	        		
				val_check(dashes, array);
				int dashes_size = val_array_size(dashes);
				double* dashes_values = (double*)malloc(sizeof(double) * dashes_size);
				{
					for (int n = 0; n < dashes_size; n++) dashes_values[n] = val_number(val_array_i(dashes, n));
				}
			;
        	        		val_check(num_dashes, int);
        	        		val_check(offset, number);;
        	
        					cairo_set_dash(kind_cairo_t_get(cr), dashes_values, val_get_int(num_dashes), val_get_double(offset));
	        		        		;
	        		        		
				{
					for (int n = 0; n < dashes_size; n++) val_array_set_i(dashes, n, alloc_float(dashes_values[n]));
				}
				free(dashes_values);
			;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_dash, 4);
		    					value hx_cairo_get_dash(value cr, value dashes, value offset) {
		        	        		kind_cairo_t_check(cr);
        	        		
				val_check(dashes, array);
				int dashes_size = val_array_size(dashes);
				double* dashes_values = (double*)malloc(sizeof(double) * dashes_size);
				{
					for (int n = 0; n < dashes_size; n++) dashes_values[n] = val_number(val_array_i(dashes, n));
				}
			;
        	        		
				val_check(offset, array);
				int offset_size = val_array_size(offset);
				double* offset_values = (double*)malloc(sizeof(double) * offset_size);
				{
					for (int n = 0; n < offset_size; n++) offset_values[n] = val_number(val_array_i(offset, n));
				}
			;
        	
        					cairo_get_dash(kind_cairo_t_get(cr), dashes_values, offset_values);
	        		        		;
	        		        		
				{
					for (int n = 0; n < dashes_size; n++) val_array_set_i(dashes, n, alloc_float(dashes_values[n]));
				}
				free(dashes_values);
			;
	        		        		
				{
					for (int n = 0; n < offset_size; n++) val_array_set_i(offset, n, alloc_float(offset_values[n]));
				}
				free(offset_values);
			;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_get_dash, 3);
		    					value hx_cairo_matrix_create() {
		        	
        					cairo_matrix_t* _result = cairo_matrix_create();
	        					return kind_cairo_matrix_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_matrix_create, 0);
		    					value hx_cairo_matrix_init(value *_args, int _nargs) {
							value matrix = _args[0];
							value xx = _args[1];
							value yx = _args[2];
							value xy = _args[3];
							value yy = _args[4];
							value x0 = _args[5];
							value y0 = _args[6];
					        	        		kind_cairo_matrix_t_check(matrix);
        	        		val_check(xx, number);;
        	        		val_check(yx, number);;
        	        		val_check(xy, number);;
        	        		val_check(yy, number);;
        	        		val_check(x0, number);;
        	        		val_check(y0, number);;
        	
        					cairo_matrix_init(kind_cairo_matrix_t_get(matrix), val_get_double(xx), val_get_double(yx), val_get_double(xy), val_get_double(yy), val_get_double(x0), val_get_double(y0));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM_MULT(hx_cairo_matrix_init);
		    					value hx_cairo_matrix_init_identity(value matrix) {
		        	        		kind_cairo_matrix_t_check(matrix);
        	
        					cairo_matrix_init_identity(kind_cairo_matrix_t_get(matrix));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_matrix_init_identity, 1);
		    					value hx_cairo_matrix_init_translate(value matrix, value tx, value ty) {
		        	        		kind_cairo_matrix_t_check(matrix);
        	        		val_check(tx, number);;
        	        		val_check(ty, number);;
        	
        					cairo_matrix_init_translate(kind_cairo_matrix_t_get(matrix), val_get_double(tx), val_get_double(ty));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_matrix_init_translate, 3);
		    					value hx_cairo_matrix_init_scale(value matrix, value sx, value sy) {
		        	        		kind_cairo_matrix_t_check(matrix);
        	        		val_check(sx, number);;
        	        		val_check(sy, number);;
        	
        					cairo_matrix_init_scale(kind_cairo_matrix_t_get(matrix), val_get_double(sx), val_get_double(sy));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_matrix_init_scale, 3);
		    					value hx_cairo_matrix_init_rotate(value matrix, value radians) {
		        	        		kind_cairo_matrix_t_check(matrix);
        	        		val_check(radians, number);;
        	
        					cairo_matrix_init_rotate(kind_cairo_matrix_t_get(matrix), val_get_double(radians));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_matrix_init_rotate, 2);
		    					value hx_cairo_matrix_translate(value matrix, value tx, value ty) {
		        	        		kind_cairo_matrix_t_check(matrix);
        	        		val_check(tx, number);;
        	        		val_check(ty, number);;
        	
        					cairo_matrix_translate(kind_cairo_matrix_t_get(matrix), val_get_double(tx), val_get_double(ty));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_matrix_translate, 3);
		    					value hx_cairo_matrix_scale(value matrix, value sx, value sy) {
		        	        		kind_cairo_matrix_t_check(matrix);
        	        		val_check(sx, number);;
        	        		val_check(sy, number);;
        	
        					cairo_matrix_scale(kind_cairo_matrix_t_get(matrix), val_get_double(sx), val_get_double(sy));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_matrix_scale, 3);
		    					value hx_cairo_matrix_rotate(value matrix, value radians) {
		        	        		kind_cairo_matrix_t_check(matrix);
        	        		val_check(radians, number);;
        	
        					cairo_matrix_rotate(kind_cairo_matrix_t_get(matrix), val_get_double(radians));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_matrix_rotate, 2);
		    					value hx_cairo_matrix_invert(value matrix) {
		        	        		kind_cairo_matrix_t_check(matrix);
        	
        					cairo_status_t _result = cairo_matrix_invert(kind_cairo_matrix_t_get(matrix));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_matrix_invert, 1);
		    					value hx_cairo_matrix_multiply(value result, value a, value b) {
		        	        		kind_cairo_matrix_t_check(result);
        	        		kind_cairo_matrix_t_check(a);
        	        		kind_cairo_matrix_t_check(b);
        	
        					cairo_matrix_multiply(kind_cairo_matrix_t_get(result), kind_cairo_matrix_t_get(a), kind_cairo_matrix_t_get(b));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_matrix_multiply, 3);
		    					value hx_cairo_matrix_transform_distance(value matrix, value point) {
		        	        		kind_cairo_matrix_t_check(matrix);
        	        		val_check(point, array); double point_x = val_number(val_array_i(point, 0)), point_y = val_number(val_array_i(point, 1));
        	
        					cairo_matrix_transform_distance(kind_cairo_matrix_t_get(matrix), &point_x, &point_y);
	        		        		;
	        		        		val_array_set_i(point, 0, alloc_float(point_x)); val_array_set_i(point, 1, alloc_float(point_y));;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_matrix_transform_distance, 2);
		    					value hx_cairo_matrix_transform_point(value matrix, value point) {
		        	        		kind_cairo_matrix_t_check(matrix);
        	        		val_check(point, array); double point_x = val_number(val_array_i(point, 0)), point_y = val_number(val_array_i(point, 1));
        	
        					cairo_matrix_transform_point(kind_cairo_matrix_t_get(matrix), &point_x, &point_y);
	        		        		;
	        		        		val_array_set_i(point, 0, alloc_float(point_x)); val_array_set_i(point, 1, alloc_float(point_y));;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_matrix_transform_point, 2);
		    					value hx_cairo_image_surface_create(value format, value width, value height) {
		        	        		val_check(format, int);
        	        		val_check(width, int);
        	        		val_check(height, int);
        	
        					cairo_surface_t* _result = cairo_image_surface_create(((cairo_format_t)val_get_int(format)), val_get_int(width), val_get_int(height));
	        		        		;
	        		        		;
	        		        		;
	        					return kind_cairo_surface_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_image_surface_create, 3);
		    					value hx_cairo_image_surface_create_for_data(value data, value format, value width, value height, value stride) {
		        	        		{ buffer temp = val_to_buffer(data); if (!temp) hx_failure("invalid source buffer");};
        	        		val_check(format, int);
        	        		val_check(width, int);
        	        		val_check(height, int);
        	        		val_check(stride, int);
        	
        					cairo_surface_t* _result = cairo_image_surface_create_for_data((unsigned char*)buffer_data(val_to_buffer(data)), ((cairo_format_t)val_get_int(format)), val_get_int(width), val_get_int(height), val_get_int(stride));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return kind_cairo_surface_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_image_surface_create_for_data, 5);
		    					value hx_cairo_image_surface_get_format(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					cairo_format_t _result = cairo_image_surface_get_format(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_image_surface_get_format, 1);
		    					value hx_cairo_image_surface_get_width(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					int _result = cairo_image_surface_get_width(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_image_surface_get_width, 1);
		    					value hx_cairo_image_surface_get_height(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					int _result = cairo_image_surface_get_height(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_image_surface_get_height, 1);
		    					value hx_cairo_image_surface_get_stride(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					int _result = cairo_image_surface_get_stride(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_image_surface_get_stride, 1);
		    					value hx_cairo_surface_finish(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					cairo_surface_finish(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_surface_finish, 1);
		    					value hx_cairo_surface_flush(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					cairo_surface_flush(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_surface_flush, 1);
		    					value hx_cairo_surface_create_similar(value other, value content, value width, value height) {
		        	        		kind_cairo_surface_t_check(other);
        	        		val_check(content, int);
        	        		val_check(width, int);
        	        		val_check(height, int);
        	
        					cairo_surface_t* _result = cairo_surface_create_similar(kind_cairo_surface_t_get(other), ((cairo_content_t)val_get_int(content)), val_get_int(width), val_get_int(height));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return kind_cairo_surface_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_surface_create_similar, 4);
		    					value hx_cairo_surface_create_similar_image(value other, value format, value width, value height) {
		        	        		kind_cairo_surface_t_check(other);
        	        		val_check(format, int);
        	        		val_check(width, int);
        	        		val_check(height, int);
        	
        					cairo_surface_t* _result = cairo_surface_create_similar_image(kind_cairo_surface_t_get(other), ((cairo_format_t)val_get_int(format)), val_get_int(width), val_get_int(height));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return kind_cairo_surface_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_surface_create_similar_image, 4);
		    					value hx_cairo_surface_create_for_rectangle(value target, value x, value y, value width, value height) {
		        	        		kind_cairo_surface_t_check(target);
        	        		val_check(x, number);;
        	        		val_check(y, number);;
        	        		val_check(width, number);;
        	        		val_check(height, number);;
        	
        					cairo_surface_t* _result = cairo_surface_create_for_rectangle(kind_cairo_surface_t_get(target), val_get_double(x), val_get_double(y), val_get_double(width), val_get_double(height));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return kind_cairo_surface_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_surface_create_for_rectangle, 5);
		    					value hx_cairo_surface_status(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					cairo_status_t _result = cairo_surface_status(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_surface_status, 1);
		    					value hx_cairo_surface_copy_page(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					cairo_surface_copy_page(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_surface_copy_page, 1);
		    					value hx_cairo_surface_show_page(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					cairo_surface_show_page(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_surface_show_page, 1);
		    					value hx_cairo_image_surface_get_data2(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					value _result = cairo_image_surface_get_data2(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return _result;
        	        }
				DEFINE_PRIM(hx_cairo_image_surface_get_data2, 1);
		    					value hx_cairo_image_surface_set_data2(value surface, value vv) {
		        	        		kind_cairo_surface_t_check(surface);
        	        		value* root_vv = alloc_root(); *root_vv = vv;;
        	
        					cairo_image_surface_set_data2(kind_cairo_surface_t_get(surface), (void*)vv);
	        		        		;
	        		        		free_root(root_vv);;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_image_surface_set_data2, 2);
		    					value hx_cairo_surface_get_content(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					cairo_content_t _result = cairo_surface_get_content(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_surface_get_content, 1);
		    					value hx_cairo_surface_mark_dirty(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					cairo_surface_mark_dirty(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_surface_mark_dirty, 1);
		    					value hx_cairo_surface_mark_dirty_rectangle(value surface, value x, value y, value width, value height) {
		        	        		kind_cairo_surface_t_check(surface);
        	        		val_check(x, int);
        	        		val_check(y, int);
        	        		val_check(width, int);
        	        		val_check(height, int);
        	
        					cairo_surface_mark_dirty_rectangle(kind_cairo_surface_t_get(surface), val_get_int(x), val_get_int(y), val_get_int(width), val_get_int(height));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_surface_mark_dirty_rectangle, 5);
		    					value hx_cairo_translate(value cr, value tx, value ty) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(tx, number);;
        	        		val_check(ty, number);;
        	
        					cairo_translate(kind_cairo_t_get(cr), val_get_double(tx), val_get_double(ty));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_translate, 3);
		    					value hx_cairo_scale(value cr, value sx, value sy) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(sx, number);;
        	        		val_check(sy, number);;
        	
        					cairo_scale(kind_cairo_t_get(cr), val_get_double(sx), val_get_double(sy));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_scale, 3);
		    					value hx_cairo_rotate(value cr, value angle) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(angle, number);;
        	
        					cairo_rotate(kind_cairo_t_get(cr), val_get_double(angle));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_rotate, 2);
		    					value hx_cairo_transform(value cr, value matrix) {
		        	        		kind_cairo_t_check(cr);
        	        		kind_cairo_matrix_t_check(matrix);
        	
        					cairo_transform(kind_cairo_t_get(cr), kind_cairo_matrix_t_get(matrix));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_transform, 2);
		    					value hx_cairo_set_matrix(value cr, value matrix) {
		        	        		kind_cairo_t_check(cr);
        	        		kind_cairo_matrix_t_check(matrix);
        	
        					cairo_set_matrix(kind_cairo_t_get(cr), kind_cairo_matrix_t_get(matrix));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_matrix, 2);
		    					value hx_cairo_get_matrix(value cr, value matrix) {
		        	        		kind_cairo_t_check(cr);
        	        		kind_cairo_matrix_t_check(matrix);
        	
        					cairo_get_matrix(kind_cairo_t_get(cr), kind_cairo_matrix_t_get(matrix));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_get_matrix, 2);
		    					value hx_cairo_identity_matrix(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_identity_matrix(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_identity_matrix, 1);
		    					value hx_cairo_user_to_device(value cr, value point) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(point, array); double point_x = val_number(val_array_i(point, 0)), point_y = val_number(val_array_i(point, 1));
        	
        					cairo_user_to_device(kind_cairo_t_get(cr), &point_x, &point_y);
	        		        		;
	        		        		val_array_set_i(point, 0, alloc_float(point_x)); val_array_set_i(point, 1, alloc_float(point_y));;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_user_to_device, 2);
		    					value hx_cairo_user_to_device_distance(value cr, value point) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(point, array); double point_x = val_number(val_array_i(point, 0)), point_y = val_number(val_array_i(point, 1));
        	
        					cairo_user_to_device_distance(kind_cairo_t_get(cr), &point_x, &point_y);
	        		        		;
	        		        		val_array_set_i(point, 0, alloc_float(point_x)); val_array_set_i(point, 1, alloc_float(point_y));;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_user_to_device_distance, 2);
		    					value hx_cairo_device_to_user(value cr, value point) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(point, array); double point_x = val_number(val_array_i(point, 0)), point_y = val_number(val_array_i(point, 1));
        	
        					cairo_device_to_user(kind_cairo_t_get(cr), &point_x, &point_y);
	        		        		;
	        		        		val_array_set_i(point, 0, alloc_float(point_x)); val_array_set_i(point, 1, alloc_float(point_y));;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_device_to_user, 2);
		    					value hx_cairo_device_to_user_distance(value cr, value point) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(point, array); double point_x = val_number(val_array_i(point, 0)), point_y = val_number(val_array_i(point, 1));
        	
        					cairo_device_to_user_distance(kind_cairo_t_get(cr), &point_x, &point_y);
	        		        		;
	        		        		val_array_set_i(point, 0, alloc_float(point_x)); val_array_set_i(point, 1, alloc_float(point_y));;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_device_to_user_distance, 2);
		    					value hx_cairo_copy_path(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_path_t* _result = cairo_copy_path(kind_cairo_t_get(cr));
	        		        		;
	        					return kind_cairo_path_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_copy_path, 1);
		    					value hx_cairo_copy_path_flat(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_path_t* _result = cairo_copy_path_flat(kind_cairo_t_get(cr));
	        		        		;
	        					return kind_cairo_path_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_copy_path_flat, 1);
		    					value hx_cairo_append_path(value cr, value path) {
		        	        		kind_cairo_t_check(cr);
        	        		kind_cairo_path_t_check(path);
        	
        					cairo_append_path(kind_cairo_t_get(cr), kind_cairo_path_t_get(path));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_append_path, 2);
		    					value hx_cairo_line_to(value cr, value x, value y) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(x, number);;
        	        		val_check(y, number);;
        	
        					cairo_line_to(kind_cairo_t_get(cr), val_get_double(x), val_get_double(y));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_line_to, 3);
		    					value hx_cairo_move_to(value cr, value x, value y) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(x, number);;
        	        		val_check(y, number);;
        	
        					cairo_move_to(kind_cairo_t_get(cr), val_get_double(x), val_get_double(y));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_move_to, 3);
		    					value hx_cairo_new_path(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_new_path(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_new_path, 1);
		    					value hx_cairo_new_sub_path(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_new_sub_path(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_new_sub_path, 1);
		    					value hx_cairo_close_path(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					cairo_close_path(kind_cairo_t_get(cr));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_close_path, 1);
		    					value hx_cairo_arc(value *_args, int _nargs) {
							value cr = _args[0];
							value xc = _args[1];
							value yc = _args[2];
							value radius = _args[3];
							value angle1 = _args[4];
							value angle2 = _args[5];
					        	        		kind_cairo_t_check(cr);
        	        		val_check(xc, number);;
        	        		val_check(yc, number);;
        	        		val_check(radius, number);;
        	        		val_check(angle1, number);;
        	        		val_check(angle2, number);;
        	
        					cairo_arc(kind_cairo_t_get(cr), val_get_double(xc), val_get_double(yc), val_get_double(radius), val_get_double(angle1), val_get_double(angle2));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM_MULT(hx_cairo_arc);
		    					value hx_cairo_arc_negative(value *_args, int _nargs) {
							value cr = _args[0];
							value xc = _args[1];
							value yc = _args[2];
							value radius = _args[3];
							value angle1 = _args[4];
							value angle2 = _args[5];
					        	        		kind_cairo_t_check(cr);
        	        		val_check(xc, number);;
        	        		val_check(yc, number);;
        	        		val_check(radius, number);;
        	        		val_check(angle1, number);;
        	        		val_check(angle2, number);;
        	
        					cairo_arc_negative(kind_cairo_t_get(cr), val_get_double(xc), val_get_double(yc), val_get_double(radius), val_get_double(angle1), val_get_double(angle2));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM_MULT(hx_cairo_arc_negative);
		    					value hx_cairo_curve_to(value *_args, int _nargs) {
							value cr = _args[0];
							value x1 = _args[1];
							value y1 = _args[2];
							value x2 = _args[3];
							value y2 = _args[4];
							value x3 = _args[5];
							value y3 = _args[6];
					        	        		kind_cairo_t_check(cr);
        	        		val_check(x1, number);;
        	        		val_check(y1, number);;
        	        		val_check(x2, number);;
        	        		val_check(y2, number);;
        	        		val_check(x3, number);;
        	        		val_check(y3, number);;
        	
        					cairo_curve_to(kind_cairo_t_get(cr), val_get_double(x1), val_get_double(y1), val_get_double(x2), val_get_double(y2), val_get_double(x3), val_get_double(y3));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM_MULT(hx_cairo_curve_to);
		    					value hx_cairo_rel_curve_to(value *_args, int _nargs) {
							value cr = _args[0];
							value dx1 = _args[1];
							value dy1 = _args[2];
							value dx2 = _args[3];
							value dy2 = _args[4];
							value dx3 = _args[5];
							value dy3 = _args[6];
					        	        		kind_cairo_t_check(cr);
        	        		val_check(dx1, number);;
        	        		val_check(dy1, number);;
        	        		val_check(dx2, number);;
        	        		val_check(dy2, number);;
        	        		val_check(dx3, number);;
        	        		val_check(dy3, number);;
        	
        					cairo_rel_curve_to(kind_cairo_t_get(cr), val_get_double(dx1), val_get_double(dy1), val_get_double(dx2), val_get_double(dy2), val_get_double(dx3), val_get_double(dy3));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM_MULT(hx_cairo_rel_curve_to);
		    					value hx_cairo_rel_line_to(value cr, value dx, value dy) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(dx, number);;
        	        		val_check(dy, number);;
        	
        					cairo_rel_line_to(kind_cairo_t_get(cr), val_get_double(dx), val_get_double(dy));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_rel_line_to, 3);
		    					value hx_cairo_rel_move_to(value cr, value dx, value dy) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(dx, number);;
        	        		val_check(dy, number);;
        	
        					cairo_rel_move_to(kind_cairo_t_get(cr), val_get_double(dx), val_get_double(dy));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_rel_move_to, 3);
		    					value hx_cairo_rectangle(value cr, value x, value y, value width, value height) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(x, number);;
        	        		val_check(y, number);;
        	        		val_check(width, number);;
        	        		val_check(height, number);;
        	
        					cairo_rectangle(kind_cairo_t_get(cr), val_get_double(x), val_get_double(y), val_get_double(width), val_get_double(height));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_rectangle, 5);
		    					value hx_cairo_has_current_point(value cr) {
		        	        		kind_cairo_t_check(cr);
        	
        					bool _result = cairo_has_current_point(kind_cairo_t_get(cr));
	        		        		;
	        					return alloc_bool(_result);
        	        }
				DEFINE_PRIM(hx_cairo_has_current_point, 1);
		    					value hx_cairo_get_current_point(value cr, value point) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(point, array); double point_x = val_number(val_array_i(point, 0)), point_y = val_number(val_array_i(point, 1));
        	
        					cairo_get_current_point(kind_cairo_t_get(cr), &point_x, &point_y);
	        		        		;
	        		        		val_array_set_i(point, 0, alloc_float(point_x)); val_array_set_i(point, 1, alloc_float(point_y));;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_get_current_point, 2);
		    					value hx_cairo_path_extents(value cr, value p1, value p2) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(p1, array); double p1_x = val_number(val_array_i(p1, 0)), p1_y = val_number(val_array_i(p1, 1));
        	        		val_check(p2, array); double p2_x = val_number(val_array_i(p2, 0)), p2_y = val_number(val_array_i(p2, 1));
        	
        					cairo_path_extents(kind_cairo_t_get(cr), &p1_x, &p1_y, &p2_x, &p2_y);
	        		        		;
	        		        		val_array_set_i(p1, 0, alloc_float(p1_x)); val_array_set_i(p1, 1, alloc_float(p1_y));;
	        		        		val_array_set_i(p2, 0, alloc_float(p2_x)); val_array_set_i(p2, 1, alloc_float(p2_y));;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_path_extents, 3);
		    					value hx_cairo_text_path(value cr, value utf8) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(utf8, string);
        	
        					cairo_text_path(kind_cairo_t_get(cr), val_get_string(utf8));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_text_path, 2);
		    					value hx_cairo_region_create() {
		        	
        					cairo_region_t* _result = cairo_region_create();
	        					return kind_cairo_region_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_create, 0);
		    					value hx_cairo_region_copy(value region) {
		        	        		kind_cairo_region_t_check(region);
        	
        					cairo_region_t* _result = cairo_region_copy(kind_cairo_region_t_get(region));
	        		        		;
	        					return kind_cairo_region_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_copy, 1);
		    					value hx_cairo_region_status(value region) {
		        	        		kind_cairo_region_t_check(region);
        	
        					cairo_status_t _result = cairo_region_status(kind_cairo_region_t_get(region));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_status, 1);
		    					value hx_cairo_region_is_empty(value region) {
		        	        		kind_cairo_region_t_check(region);
        	
        					bool _result = cairo_region_is_empty(kind_cairo_region_t_get(region));
	        		        		;
	        					return alloc_bool(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_is_empty, 1);
		    					value hx_cairo_region_contains_point(value region, value x, value y) {
		        	        		kind_cairo_region_t_check(region);
        	        		val_check(x, int);
        	        		val_check(y, int);
        	
        					bool _result = cairo_region_contains_point(kind_cairo_region_t_get(region), val_get_int(x), val_get_int(y));
	        		        		;
	        		        		;
	        		        		;
	        					return alloc_bool(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_contains_point, 3);
		    					value hx_cairo_region_equal(value a, value b) {
		        	        		kind_cairo_region_t_check(a);
        	        		kind_cairo_region_t_check(b);
        	
        					bool _result = cairo_region_equal(kind_cairo_region_t_get(a), kind_cairo_region_t_get(b));
	        		        		;
	        		        		;
	        					return alloc_bool(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_equal, 2);
		    					value hx_cairo_region_translate(value region, value dx, value dy) {
		        	        		kind_cairo_region_t_check(region);
        	        		val_check(dx, int);
        	        		val_check(dy, int);
        	
        					cairo_region_translate(kind_cairo_region_t_get(region), val_get_int(dx), val_get_int(dy));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_region_translate, 3);
		    					value hx_cairo_region_num_rectangles(value region) {
		        	        		kind_cairo_region_t_check(region);
        	
        					int _result = cairo_region_num_rectangles(kind_cairo_region_t_get(region));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_num_rectangles, 1);
		    					value hx_cairo_region_intersect(value dst, value other) {
		        	        		kind_cairo_region_t_check(dst);
        	        		kind_cairo_region_t_check(other);
        	
        					cairo_status_t _result = cairo_region_intersect(kind_cairo_region_t_get(dst), kind_cairo_region_t_get(other));
	        		        		;
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_intersect, 2);
		    					value hx_cairo_region_subtract(value dst, value other) {
		        	        		kind_cairo_region_t_check(dst);
        	        		kind_cairo_region_t_check(other);
        	
        					cairo_status_t _result = cairo_region_subtract(kind_cairo_region_t_get(dst), kind_cairo_region_t_get(other));
	        		        		;
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_subtract, 2);
		    					value hx_cairo_region_union(value dst, value other) {
		        	        		kind_cairo_region_t_check(dst);
        	        		kind_cairo_region_t_check(other);
        	
        					cairo_status_t _result = cairo_region_union(kind_cairo_region_t_get(dst), kind_cairo_region_t_get(other));
	        		        		;
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_union, 2);
		    					value hx_cairo_region_xor(value dst, value other) {
		        	        		kind_cairo_region_t_check(dst);
        	        		kind_cairo_region_t_check(other);
        	
        					cairo_status_t _result = cairo_region_xor(kind_cairo_region_t_get(dst), kind_cairo_region_t_get(other));
	        		        		;
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_xor, 2);
		    					value hx_cairo_region_union_rectangle(value dst, value rectangle) {
		        	        		kind_cairo_region_t_check(dst);
        	        		
				val_check(rectangle, object);
				int field_x = val_id("x");
				int field_y = val_id("y");
				int field_width = val_id("width");
				int field_height = val_id("height");
				cairo_rectangle_int_t rect_rectangle = { 0 };
				rect_rectangle.x = val_number(val_field(rectangle, field_x));
				rect_rectangle.y = val_number(val_field(rectangle, field_y));
				rect_rectangle.width = val_number(val_field(rectangle, field_width));
				rect_rectangle.height = val_number(val_field(rectangle, field_height));
				;
        	
        					cairo_status_t _result = cairo_region_union_rectangle(kind_cairo_region_t_get(dst), &rect_rectangle);
	        		        		;
	        		        		
				alloc_field(rectangle, field_x, alloc_int(rect_rectangle.x));
				alloc_field(rectangle, field_y, alloc_int(rect_rectangle.y));
				alloc_field(rectangle, field_width, alloc_int(rect_rectangle.width));
				alloc_field(rectangle, field_height, alloc_int(rect_rectangle.height));
			;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_union_rectangle, 2);
		    					value hx_cairo_region_intersect_rectangle(value dst, value rectangle) {
		        	        		kind_cairo_region_t_check(dst);
        	        		
				val_check(rectangle, object);
				int field_x = val_id("x");
				int field_y = val_id("y");
				int field_width = val_id("width");
				int field_height = val_id("height");
				cairo_rectangle_int_t rect_rectangle = { 0 };
				rect_rectangle.x = val_number(val_field(rectangle, field_x));
				rect_rectangle.y = val_number(val_field(rectangle, field_y));
				rect_rectangle.width = val_number(val_field(rectangle, field_width));
				rect_rectangle.height = val_number(val_field(rectangle, field_height));
				;
        	
        					cairo_status_t _result = cairo_region_intersect_rectangle(kind_cairo_region_t_get(dst), &rect_rectangle);
	        		        		;
	        		        		
				alloc_field(rectangle, field_x, alloc_int(rect_rectangle.x));
				alloc_field(rectangle, field_y, alloc_int(rect_rectangle.y));
				alloc_field(rectangle, field_width, alloc_int(rect_rectangle.width));
				alloc_field(rectangle, field_height, alloc_int(rect_rectangle.height));
			;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_intersect_rectangle, 2);
		    					value hx_cairo_region_subtract_rectangle(value dst, value rectangle) {
		        	        		kind_cairo_region_t_check(dst);
        	        		
				val_check(rectangle, object);
				int field_x = val_id("x");
				int field_y = val_id("y");
				int field_width = val_id("width");
				int field_height = val_id("height");
				cairo_rectangle_int_t rect_rectangle = { 0 };
				rect_rectangle.x = val_number(val_field(rectangle, field_x));
				rect_rectangle.y = val_number(val_field(rectangle, field_y));
				rect_rectangle.width = val_number(val_field(rectangle, field_width));
				rect_rectangle.height = val_number(val_field(rectangle, field_height));
				;
        	
        					cairo_status_t _result = cairo_region_subtract_rectangle(kind_cairo_region_t_get(dst), &rect_rectangle);
	        		        		;
	        		        		
				alloc_field(rectangle, field_x, alloc_int(rect_rectangle.x));
				alloc_field(rectangle, field_y, alloc_int(rect_rectangle.y));
				alloc_field(rectangle, field_width, alloc_int(rect_rectangle.width));
				alloc_field(rectangle, field_height, alloc_int(rect_rectangle.height));
			;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_subtract_rectangle, 2);
		    					value hx_cairo_region_xor_rectangle(value dst, value rectangle) {
		        	        		kind_cairo_region_t_check(dst);
        	        		
				val_check(rectangle, object);
				int field_x = val_id("x");
				int field_y = val_id("y");
				int field_width = val_id("width");
				int field_height = val_id("height");
				cairo_rectangle_int_t rect_rectangle = { 0 };
				rect_rectangle.x = val_number(val_field(rectangle, field_x));
				rect_rectangle.y = val_number(val_field(rectangle, field_y));
				rect_rectangle.width = val_number(val_field(rectangle, field_width));
				rect_rectangle.height = val_number(val_field(rectangle, field_height));
				;
        	
        					cairo_status_t _result = cairo_region_xor_rectangle(kind_cairo_region_t_get(dst), &rect_rectangle);
	        		        		;
	        		        		
				alloc_field(rectangle, field_x, alloc_int(rect_rectangle.x));
				alloc_field(rectangle, field_y, alloc_int(rect_rectangle.y));
				alloc_field(rectangle, field_width, alloc_int(rect_rectangle.width));
				alloc_field(rectangle, field_height, alloc_int(rect_rectangle.height));
			;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_xor_rectangle, 2);
		    					value hx_cairo_region_contains_rectangle(value region, value rectangle) {
		        	        		kind_cairo_region_t_check(region);
        	        		
				val_check(rectangle, object);
				int field_x = val_id("x");
				int field_y = val_id("y");
				int field_width = val_id("width");
				int field_height = val_id("height");
				cairo_rectangle_int_t rect_rectangle = { 0 };
				rect_rectangle.x = val_number(val_field(rectangle, field_x));
				rect_rectangle.y = val_number(val_field(rectangle, field_y));
				rect_rectangle.width = val_number(val_field(rectangle, field_width));
				rect_rectangle.height = val_number(val_field(rectangle, field_height));
				;
        	
        					cairo_region_overlap_t _result = cairo_region_contains_rectangle(kind_cairo_region_t_get(region), &rect_rectangle);
	        		        		;
	        		        		
				alloc_field(rectangle, field_x, alloc_int(rect_rectangle.x));
				alloc_field(rectangle, field_y, alloc_int(rect_rectangle.y));
				alloc_field(rectangle, field_width, alloc_int(rect_rectangle.width));
				alloc_field(rectangle, field_height, alloc_int(rect_rectangle.height));
			;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_region_contains_rectangle, 2);
		    					value hx_cairo_region_get_extents(value region, value extents) {
		        	        		kind_cairo_region_t_check(region);
        	        		
				val_check(extents, object);
				int field_x = val_id("x");
				int field_y = val_id("y");
				int field_width = val_id("width");
				int field_height = val_id("height");
				cairo_rectangle_int_t rect_extents = { 0 };
				rect_extents.x = val_number(val_field(extents, field_x));
				rect_extents.y = val_number(val_field(extents, field_y));
				rect_extents.width = val_number(val_field(extents, field_width));
				rect_extents.height = val_number(val_field(extents, field_height));
				;
        	
        					cairo_region_get_extents(kind_cairo_region_t_get(region), &rect_extents);
	        		        		;
	        		        		
				alloc_field(extents, field_x, alloc_int(rect_extents.x));
				alloc_field(extents, field_y, alloc_int(rect_extents.y));
				alloc_field(extents, field_width, alloc_int(rect_extents.width));
				alloc_field(extents, field_height, alloc_int(rect_extents.height));
			;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_region_get_extents, 2);
		    					value hx_cairo_region_get_rectangle(value region, value nth, value rectangle) {
		        	        		kind_cairo_region_t_check(region);
        	        		val_check(nth, int);
        	        		
				val_check(rectangle, object);
				int field_x = val_id("x");
				int field_y = val_id("y");
				int field_width = val_id("width");
				int field_height = val_id("height");
				cairo_rectangle_int_t rect_rectangle = { 0 };
				rect_rectangle.x = val_number(val_field(rectangle, field_x));
				rect_rectangle.y = val_number(val_field(rectangle, field_y));
				rect_rectangle.width = val_number(val_field(rectangle, field_width));
				rect_rectangle.height = val_number(val_field(rectangle, field_height));
				;
        	
        					cairo_region_get_rectangle(kind_cairo_region_t_get(region), val_get_int(nth), &rect_rectangle);
	        		        		;
	        		        		;
	        		        		
				alloc_field(rectangle, field_x, alloc_int(rect_rectangle.x));
				alloc_field(rectangle, field_y, alloc_int(rect_rectangle.y));
				alloc_field(rectangle, field_width, alloc_int(rect_rectangle.width));
				alloc_field(rectangle, field_height, alloc_int(rect_rectangle.height));
			;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_region_get_rectangle, 3);
		    					value hx_cairo_select_font_face(value cr, value family, value slant, value weight) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(family, string);
        	        		val_check(slant, int);
        	        		val_check(weight, int);
        	
        					cairo_select_font_face(kind_cairo_t_get(cr), val_get_string(family), ((cairo_font_slant_t)val_get_int(slant)), ((cairo_font_weight_t)val_get_int(weight)));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_select_font_face, 4);
		    					value hx_cairo_set_font_size(value cr, value size) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(size, number);;
        	
        					cairo_set_font_size(kind_cairo_t_get(cr), val_get_double(size));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_font_size, 2);
		    					value hx_cairo_show_text(value cr, value text) {
		        	        		kind_cairo_t_check(cr);
        	        		val_check(text, string);
        	
        					cairo_show_text(kind_cairo_t_get(cr), val_get_string(text));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_show_text, 2);
		    					value hx_cairo_set_font_matrix(value cr, value matrix) {
		        	        		kind_cairo_t_check(cr);
        	        		kind_cairo_matrix_t_check(matrix);
        	
        					cairo_set_font_matrix(kind_cairo_t_get(cr), kind_cairo_matrix_t_get(matrix));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_font_matrix, 2);
		    					value hx_cairo_get_font_matrix(value cr, value matrix) {
		        	        		kind_cairo_t_check(cr);
        	        		kind_cairo_matrix_t_check(matrix);
        	
        					cairo_get_font_matrix(kind_cairo_t_get(cr), kind_cairo_matrix_t_get(matrix));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_get_font_matrix, 2);
		    					value hx_cairo_set_font_options(value cr, value options) {
		        	        		kind_cairo_t_check(cr);
        	        		kind_cairo_font_options_t_check(options);
        	
        					cairo_set_font_options(kind_cairo_t_get(cr), kind_cairo_font_options_t_get(options));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_set_font_options, 2);
		    					value hx_cairo_get_font_options(value cr, value options) {
		        	        		kind_cairo_t_check(cr);
        	        		kind_cairo_font_options_t_check(options);
        	
        					cairo_get_font_options(kind_cairo_t_get(cr), kind_cairo_font_options_t_get(options));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_get_font_options, 2);
		    					value hx_cairo_font_options_create() {
		        	
        					cairo_font_options_t* _result = cairo_font_options_create();
	        					return kind_cairo_font_options_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_font_options_create, 0);
		    					value hx_cairo_font_options_copy(value original) {
		        	        		kind_cairo_font_options_t_check(original);
        	
        					cairo_font_options_t* _result = cairo_font_options_copy(kind_cairo_font_options_t_get(original));
	        		        		;
	        					return kind_cairo_font_options_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_font_options_copy, 1);
		    					value hx_cairo_font_options_status(value options) {
		        	        		kind_cairo_font_options_t_check(options);
        	
        					cairo_status_t _result = cairo_font_options_status(kind_cairo_font_options_t_get(options));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_font_options_status, 1);
		    					value hx_cairo_font_options_merge(value options, value other) {
		        	        		kind_cairo_font_options_t_check(options);
        	        		kind_cairo_font_options_t_check(other);
        	
        					cairo_font_options_merge(kind_cairo_font_options_t_get(options), kind_cairo_font_options_t_get(other));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_font_options_merge, 2);
		    					value hx_cairo_font_options_hash(value options) {
		        	        		kind_cairo_font_options_t_check(options);
        	
        					int _result = cairo_font_options_hash(kind_cairo_font_options_t_get(options));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_font_options_hash, 1);
		    					value hx_cairo_font_options_equal(value a, value b) {
		        	        		kind_cairo_font_options_t_check(a);
        	        		kind_cairo_font_options_t_check(b);
        	
        					bool _result = cairo_font_options_equal(kind_cairo_font_options_t_get(a), kind_cairo_font_options_t_get(b));
	        		        		;
	        		        		;
	        					return alloc_bool(_result);
        	        }
				DEFINE_PRIM(hx_cairo_font_options_equal, 2);
		    					value hx_cairo_font_options_set_antialias(value options, value antialias) {
		        	        		kind_cairo_font_options_t_check(options);
        	        		val_check(antialias, int);
        	
        					cairo_font_options_set_antialias(kind_cairo_font_options_t_get(options), ((cairo_antialias_t)val_get_int(antialias)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_font_options_set_antialias, 2);
		    					value hx_cairo_font_options_set_subpixel_order(value options, value subpixel_order) {
		        	        		kind_cairo_font_options_t_check(options);
        	        		val_check(subpixel_order, int);
        	
        					cairo_font_options_set_subpixel_order(kind_cairo_font_options_t_get(options), ((cairo_subpixel_order_t)val_get_int(subpixel_order)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_font_options_set_subpixel_order, 2);
		    					value hx_cairo_font_options_set_hint_style(value options, value hintstyle) {
		        	        		kind_cairo_font_options_t_check(options);
        	        		val_check(hintstyle, int);
        	
        					cairo_font_options_set_hint_style(kind_cairo_font_options_t_get(options), ((cairo_hint_style_t)val_get_int(hintstyle)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_font_options_set_hint_style, 2);
		    					value hx_cairo_font_options_set_hint_metrics(value options, value hintmetrics) {
		        	        		kind_cairo_font_options_t_check(options);
        	        		val_check(hintmetrics, int);
        	
        					cairo_font_options_set_hint_metrics(kind_cairo_font_options_t_get(options), ((cairo_hint_metrics_t)val_get_int(hintmetrics)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_font_options_set_hint_metrics, 2);
		    					value hx_cairo_font_options_get_antialias(value options) {
		        	        		kind_cairo_font_options_t_check(options);
        	
        					cairo_antialias_t _result = cairo_font_options_get_antialias(kind_cairo_font_options_t_get(options));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_font_options_get_antialias, 1);
		    					value hx_cairo_font_options_get_subpixel_order(value options) {
		        	        		kind_cairo_font_options_t_check(options);
        	
        					cairo_subpixel_order_t _result = cairo_font_options_get_subpixel_order(kind_cairo_font_options_t_get(options));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_font_options_get_subpixel_order, 1);
		    					value hx_cairo_font_options_get_hint_style(value options) {
		        	        		kind_cairo_font_options_t_check(options);
        	
        					cairo_hint_style_t _result = cairo_font_options_get_hint_style(kind_cairo_font_options_t_get(options));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_font_options_get_hint_style, 1);
		    					value hx_cairo_font_options_get_hint_metrics(value options) {
		        	        		kind_cairo_font_options_t_check(options);
        	
        					cairo_hint_metrics_t _result = cairo_font_options_get_hint_metrics(kind_cairo_font_options_t_get(options));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_font_options_get_hint_metrics, 1);
		    					value hx_cairo_pattern_create_rgba(value red, value green, value blue, value alpha) {
		        	        		val_check(red, number);;
        	        		val_check(green, number);;
        	        		val_check(blue, number);;
        	        		val_check(alpha, number);;
        	
        					cairo_pattern_t* _result = cairo_pattern_create_rgba(val_get_double(red), val_get_double(green), val_get_double(blue), val_get_double(alpha));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return kind_cairo_pattern_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pattern_create_rgba, 4);
		    					value hx_cairo_pattern_create_rgb(value red, value green, value blue) {
		        	        		val_check(red, number);;
        	        		val_check(green, number);;
        	        		val_check(blue, number);;
        	
        					cairo_pattern_t* _result = cairo_pattern_create_rgb(val_get_double(red), val_get_double(green), val_get_double(blue));
	        		        		;
	        		        		;
	        		        		;
	        					return kind_cairo_pattern_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pattern_create_rgb, 3);
		    					value hx_cairo_pattern_create_for_surface(value surface) {
		        	        		kind_cairo_surface_t_check(surface);
        	
        					cairo_pattern_t* _result = cairo_pattern_create_for_surface(kind_cairo_surface_t_get(surface));
	        		        		;
	        					return kind_cairo_pattern_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pattern_create_for_surface, 1);
		    					value hx_cairo_pattern_create_mesh() {
		        	
        					cairo_pattern_t* _result = cairo_pattern_create_mesh();
	        					return kind_cairo_pattern_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pattern_create_mesh, 0);
		    					value hx_cairo_pattern_create_linear(value x0, value y0, value x1, value y2) {
		        	        		val_check(x0, number);;
        	        		val_check(y0, number);;
        	        		val_check(x1, number);;
        	        		val_check(y2, number);;
        	
        					cairo_pattern_t* _result = cairo_pattern_create_linear(val_get_double(x0), val_get_double(y0), val_get_double(x1), val_get_double(y2));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return kind_cairo_pattern_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pattern_create_linear, 4);
		    					value hx_cairo_pattern_create_radial(value *_args, int _nargs) {
							value cx0 = _args[0];
							value cy0 = _args[1];
							value radius0 = _args[2];
							value cx1 = _args[3];
							value cy2 = _args[4];
							value radius1 = _args[5];
					        	        		val_check(cx0, number);;
        	        		val_check(cy0, number);;
        	        		val_check(radius0, number);;
        	        		val_check(cx1, number);;
        	        		val_check(cy2, number);;
        	        		val_check(radius1, number);;
        	
        					cairo_pattern_t* _result = cairo_pattern_create_radial(val_get_double(cx0), val_get_double(cy0), val_get_double(radius0), val_get_double(cx1), val_get_double(cy2), val_get_double(radius1));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return kind_cairo_pattern_t_alloc(_result);
        	        }
				DEFINE_PRIM_MULT(hx_cairo_pattern_create_radial);
		    					value hx_cairo_pattern_set_filter(value pattern, value filter) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	        		val_check(filter, int);
        	
        					cairo_pattern_set_filter(kind_cairo_pattern_t_get(pattern), ((cairo_filter_t)val_get_int(filter)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_pattern_set_filter, 2);
		    					value hx_cairo_pattern_get_filter(value pattern) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	
        					cairo_filter_t _result = cairo_pattern_get_filter(kind_cairo_pattern_t_get(pattern));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pattern_get_filter, 1);
		    					value hx_cairo_pattern_add_color_stop_rgb(value pattern, value offset, value r, value g, value b) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	        		val_check(offset, number);;
        	        		val_check(r, number);;
        	        		val_check(g, number);;
        	        		val_check(b, number);;
        	
        					cairo_pattern_add_color_stop_rgb(kind_cairo_pattern_t_get(pattern), val_get_double(offset), val_get_double(r), val_get_double(g), val_get_double(b));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_pattern_add_color_stop_rgb, 5);
		    					value hx_cairo_pattern_add_color_stop_rgba(value *_args, int _nargs) {
							value pattern = _args[0];
							value offset = _args[1];
							value r = _args[2];
							value g = _args[3];
							value b = _args[4];
							value a = _args[5];
					        	        		kind_cairo_pattern_t_check(pattern);
        	        		val_check(offset, number);;
        	        		val_check(r, number);;
        	        		val_check(g, number);;
        	        		val_check(b, number);;
        	        		val_check(a, number);;
        	
        					cairo_pattern_add_color_stop_rgba(kind_cairo_pattern_t_get(pattern), val_get_double(offset), val_get_double(r), val_get_double(g), val_get_double(b), val_get_double(a));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM_MULT(hx_cairo_pattern_add_color_stop_rgba);
		    					value hx_cairo_pattern_set_extend(value pattern, value v) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	        		val_check(v, int);
        	
        					cairo_pattern_set_extend(kind_cairo_pattern_t_get(pattern), ((cairo_extend_t)val_get_int(v)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_pattern_set_extend, 2);
		    					value hx_cairo_pattern_get_extend(value pattern) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	
        					cairo_extend_t _result = cairo_pattern_get_extend(kind_cairo_pattern_t_get(pattern));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pattern_get_extend, 1);
		    					value hx_cairo_pattern_get_type(value pattern) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	
        					cairo_pattern_type_t _result = cairo_pattern_get_type(kind_cairo_pattern_t_get(pattern));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pattern_get_type, 1);
		    					value hx_cairo_pattern_status(value pattern) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	
        					cairo_status_t _result = cairo_pattern_status(kind_cairo_pattern_t_get(pattern));
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pattern_status, 1);
		    					value hx_cairo_mesh_pattern_begin_patch(value pattern) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	
        					cairo_mesh_pattern_begin_patch(kind_cairo_pattern_t_get(pattern));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_mesh_pattern_begin_patch, 1);
		    					value hx_cairo_mesh_pattern_end_patch(value pattern) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	
        					cairo_mesh_pattern_end_patch(kind_cairo_pattern_t_get(pattern));
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_mesh_pattern_end_patch, 1);
		    					value hx_cairo_mesh_pattern_move_to(value pattern, value x, value y) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	        		val_check(x, number);;
        	        		val_check(y, number);;
        	
        					cairo_mesh_pattern_move_to(kind_cairo_pattern_t_get(pattern), val_get_double(x), val_get_double(y));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_mesh_pattern_move_to, 3);
		    					value hx_cairo_mesh_pattern_line_to(value pattern, value x, value y) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	        		val_check(x, number);;
        	        		val_check(y, number);;
        	
        					cairo_mesh_pattern_line_to(kind_cairo_pattern_t_get(pattern), val_get_double(x), val_get_double(y));
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_mesh_pattern_line_to, 3);
		    					value hx_cairo_mesh_pattern_curve_to(value *_args, int _nargs) {
							value pattern = _args[0];
							value x1 = _args[1];
							value y1 = _args[2];
							value x2 = _args[3];
							value y2 = _args[4];
							value x3 = _args[5];
							value y3 = _args[6];
					        	        		kind_cairo_pattern_t_check(pattern);
        	        		val_check(x1, number);;
        	        		val_check(y1, number);;
        	        		val_check(x2, number);;
        	        		val_check(y2, number);;
        	        		val_check(x3, number);;
        	        		val_check(y3, number);;
        	
        					cairo_mesh_pattern_curve_to(kind_cairo_pattern_t_get(pattern), val_get_double(x1), val_get_double(y1), val_get_double(x2), val_get_double(y2), val_get_double(x3), val_get_double(y3));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM_MULT(hx_cairo_mesh_pattern_curve_to);
		    					value hx_cairo_mesh_pattern_set_control_point(value pattern, value point_num, value x, value y) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	        		val_check(point_num, int);
        	        		val_check(x, number);;
        	        		val_check(y, number);;
        	
        					cairo_mesh_pattern_set_control_point(kind_cairo_pattern_t_get(pattern), val_get_int(point_num), val_get_double(x), val_get_double(y));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_mesh_pattern_set_control_point, 4);
		    					value hx_cairo_mesh_pattern_set_corner_color_rgb(value pattern, value corner_num, value r, value g, value b) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	        		val_check(corner_num, int);
        	        		val_check(r, number);;
        	        		val_check(g, number);;
        	        		val_check(b, number);;
        	
        					cairo_mesh_pattern_set_corner_color_rgb(kind_cairo_pattern_t_get(pattern), val_get_int(corner_num), val_get_double(r), val_get_double(g), val_get_double(b));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_mesh_pattern_set_corner_color_rgb, 5);
		    					value hx_cairo_mesh_pattern_set_corner_color_rgba(value *_args, int _nargs) {
							value pattern = _args[0];
							value corner_num = _args[1];
							value r = _args[2];
							value g = _args[3];
							value b = _args[4];
							value a = _args[5];
					        	        		kind_cairo_pattern_t_check(pattern);
        	        		val_check(corner_num, int);
        	        		val_check(r, number);;
        	        		val_check(g, number);;
        	        		val_check(b, number);;
        	        		val_check(a, number);;
        	
        					cairo_mesh_pattern_set_corner_color_rgba(kind_cairo_pattern_t_get(pattern), val_get_int(corner_num), val_get_double(r), val_get_double(g), val_get_double(b), val_get_double(a));
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM_MULT(hx_cairo_mesh_pattern_set_corner_color_rgba);
		    					value hx_cairo_pattern_set_matrix(value pattern, value matrix) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	        		kind_cairo_matrix_t_check(matrix);
        	
        					cairo_pattern_set_matrix(kind_cairo_pattern_t_get(pattern), kind_cairo_matrix_t_get(matrix));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_pattern_set_matrix, 2);
		    					value hx_cairo_pattern_get_matrix(value pattern, value matrix) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	        		kind_cairo_matrix_t_check(matrix);
        	
        					cairo_pattern_get_matrix(kind_cairo_pattern_t_get(pattern), kind_cairo_matrix_t_get(matrix));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_pattern_get_matrix, 2);
		    					value hx_cairo_pattern_get_color_stop_count(value pattern, value countPtr) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	        		
				val_check(countPtr, array);
				int countPtr_size = val_array_size(countPtr);
				int* countPtr_values = (int*)malloc(sizeof(int) * countPtr_size);
				{
					for (int n = 0; n < countPtr_size; n++) countPtr_values[n] = val_int(val_array_i(countPtr, n));
				}
			;
        	
        					cairo_status_t _result = cairo_pattern_get_color_stop_count(kind_cairo_pattern_t_get(pattern), countPtr_values);
	        		        		;
	        		        		
				{
					for (int n = 0; n < countPtr_size; n++) val_array_set_i(countPtr, n, alloc_int(countPtr_values[n]));
				}
				free(countPtr_values);
			;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pattern_get_color_stop_count, 2);
		    					value hx_cairo_pattern_get_color_stop_rgba(value *_args, int _nargs) {
							value pattern = _args[0];
							value index = _args[1];
							value offset = _args[2];
							value red = _args[3];
							value green = _args[4];
							value blue = _args[5];
							value alpha = _args[6];
					        	        		kind_cairo_pattern_t_check(pattern);
        	        		val_check(index, int);
        	        		
				val_check(offset, array);
				int offset_size = val_array_size(offset);
				double* offset_values = (double*)malloc(sizeof(double) * offset_size);
				{
					for (int n = 0; n < offset_size; n++) offset_values[n] = val_number(val_array_i(offset, n));
				}
			;
        	        		
				val_check(red, array);
				int red_size = val_array_size(red);
				double* red_values = (double*)malloc(sizeof(double) * red_size);
				{
					for (int n = 0; n < red_size; n++) red_values[n] = val_number(val_array_i(red, n));
				}
			;
        	        		
				val_check(green, array);
				int green_size = val_array_size(green);
				double* green_values = (double*)malloc(sizeof(double) * green_size);
				{
					for (int n = 0; n < green_size; n++) green_values[n] = val_number(val_array_i(green, n));
				}
			;
        	        		
				val_check(blue, array);
				int blue_size = val_array_size(blue);
				double* blue_values = (double*)malloc(sizeof(double) * blue_size);
				{
					for (int n = 0; n < blue_size; n++) blue_values[n] = val_number(val_array_i(blue, n));
				}
			;
        	        		
				val_check(alpha, array);
				int alpha_size = val_array_size(alpha);
				double* alpha_values = (double*)malloc(sizeof(double) * alpha_size);
				{
					for (int n = 0; n < alpha_size; n++) alpha_values[n] = val_number(val_array_i(alpha, n));
				}
			;
        	
        					cairo_status_t _result = cairo_pattern_get_color_stop_rgba(kind_cairo_pattern_t_get(pattern), val_get_int(index), offset_values, red_values, green_values, blue_values, alpha_values);
	        		        		;
	        		        		;
	        		        		
				{
					for (int n = 0; n < offset_size; n++) val_array_set_i(offset, n, alloc_float(offset_values[n]));
				}
				free(offset_values);
			;
	        		        		
				{
					for (int n = 0; n < red_size; n++) val_array_set_i(red, n, alloc_float(red_values[n]));
				}
				free(red_values);
			;
	        		        		
				{
					for (int n = 0; n < green_size; n++) val_array_set_i(green, n, alloc_float(green_values[n]));
				}
				free(green_values);
			;
	        		        		
				{
					for (int n = 0; n < blue_size; n++) val_array_set_i(blue, n, alloc_float(blue_values[n]));
				}
				free(blue_values);
			;
	        		        		
				{
					for (int n = 0; n < alpha_size; n++) val_array_set_i(alpha, n, alloc_float(alpha_values[n]));
				}
				free(alpha_values);
			;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM_MULT(hx_cairo_pattern_get_color_stop_rgba);
		    					value hx_cairo_pattern_get_rgba(value pattern, value red, value green, value blue, value alpha) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	        		
				val_check(red, array);
				int red_size = val_array_size(red);
				double* red_values = (double*)malloc(sizeof(double) * red_size);
				{
					for (int n = 0; n < red_size; n++) red_values[n] = val_number(val_array_i(red, n));
				}
			;
        	        		
				val_check(green, array);
				int green_size = val_array_size(green);
				double* green_values = (double*)malloc(sizeof(double) * green_size);
				{
					for (int n = 0; n < green_size; n++) green_values[n] = val_number(val_array_i(green, n));
				}
			;
        	        		
				val_check(blue, array);
				int blue_size = val_array_size(blue);
				double* blue_values = (double*)malloc(sizeof(double) * blue_size);
				{
					for (int n = 0; n < blue_size; n++) blue_values[n] = val_number(val_array_i(blue, n));
				}
			;
        	        		
				val_check(alpha, array);
				int alpha_size = val_array_size(alpha);
				double* alpha_values = (double*)malloc(sizeof(double) * alpha_size);
				{
					for (int n = 0; n < alpha_size; n++) alpha_values[n] = val_number(val_array_i(alpha, n));
				}
			;
        	
        					cairo_status_t _result = cairo_pattern_get_rgba(kind_cairo_pattern_t_get(pattern), red_values, green_values, blue_values, alpha_values);
	        		        		;
	        		        		
				{
					for (int n = 0; n < red_size; n++) val_array_set_i(red, n, alloc_float(red_values[n]));
				}
				free(red_values);
			;
	        		        		
				{
					for (int n = 0; n < green_size; n++) val_array_set_i(green, n, alloc_float(green_values[n]));
				}
				free(green_values);
			;
	        		        		
				{
					for (int n = 0; n < blue_size; n++) val_array_set_i(blue, n, alloc_float(blue_values[n]));
				}
				free(blue_values);
			;
	        		        		
				{
					for (int n = 0; n < alpha_size; n++) val_array_set_i(alpha, n, alloc_float(alpha_values[n]));
				}
				free(alpha_values);
			;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pattern_get_rgba, 5);
		    					value hx_cairo_pattern_get_linear_points(value pattern, value x0, value y0, value x1, value y1) {
		        	        		kind_cairo_pattern_t_check(pattern);
        	        		
				val_check(x0, array);
				int x0_size = val_array_size(x0);
				double* x0_values = (double*)malloc(sizeof(double) * x0_size);
				{
					for (int n = 0; n < x0_size; n++) x0_values[n] = val_number(val_array_i(x0, n));
				}
			;
        	        		
				val_check(y0, array);
				int y0_size = val_array_size(y0);
				double* y0_values = (double*)malloc(sizeof(double) * y0_size);
				{
					for (int n = 0; n < y0_size; n++) y0_values[n] = val_number(val_array_i(y0, n));
				}
			;
        	        		
				val_check(x1, array);
				int x1_size = val_array_size(x1);
				double* x1_values = (double*)malloc(sizeof(double) * x1_size);
				{
					for (int n = 0; n < x1_size; n++) x1_values[n] = val_number(val_array_i(x1, n));
				}
			;
        	        		
				val_check(y1, array);
				int y1_size = val_array_size(y1);
				double* y1_values = (double*)malloc(sizeof(double) * y1_size);
				{
					for (int n = 0; n < y1_size; n++) y1_values[n] = val_number(val_array_i(y1, n));
				}
			;
        	
        					cairo_status_t _result = cairo_pattern_get_linear_points(kind_cairo_pattern_t_get(pattern), x0_values, y0_values, x1_values, y1_values);
	        		        		;
	        		        		
				{
					for (int n = 0; n < x0_size; n++) val_array_set_i(x0, n, alloc_float(x0_values[n]));
				}
				free(x0_values);
			;
	        		        		
				{
					for (int n = 0; n < y0_size; n++) val_array_set_i(y0, n, alloc_float(y0_values[n]));
				}
				free(y0_values);
			;
	        		        		
				{
					for (int n = 0; n < x1_size; n++) val_array_set_i(x1, n, alloc_float(x1_values[n]));
				}
				free(x1_values);
			;
	        		        		
				{
					for (int n = 0; n < y1_size; n++) val_array_set_i(y1, n, alloc_float(y1_values[n]));
				}
				free(y1_values);
			;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pattern_get_linear_points, 5);
		    					value hx_cairo_pattern_get_radial_circles(value *_args, int _nargs) {
							value pattern = _args[0];
							value x0 = _args[1];
							value y0 = _args[2];
							value r0 = _args[3];
							value x1 = _args[4];
							value y1 = _args[5];
							value r1 = _args[6];
					        	        		kind_cairo_pattern_t_check(pattern);
        	        		
				val_check(x0, array);
				int x0_size = val_array_size(x0);
				double* x0_values = (double*)malloc(sizeof(double) * x0_size);
				{
					for (int n = 0; n < x0_size; n++) x0_values[n] = val_number(val_array_i(x0, n));
				}
			;
        	        		
				val_check(y0, array);
				int y0_size = val_array_size(y0);
				double* y0_values = (double*)malloc(sizeof(double) * y0_size);
				{
					for (int n = 0; n < y0_size; n++) y0_values[n] = val_number(val_array_i(y0, n));
				}
			;
        	        		
				val_check(r0, array);
				int r0_size = val_array_size(r0);
				double* r0_values = (double*)malloc(sizeof(double) * r0_size);
				{
					for (int n = 0; n < r0_size; n++) r0_values[n] = val_number(val_array_i(r0, n));
				}
			;
        	        		
				val_check(x1, array);
				int x1_size = val_array_size(x1);
				double* x1_values = (double*)malloc(sizeof(double) * x1_size);
				{
					for (int n = 0; n < x1_size; n++) x1_values[n] = val_number(val_array_i(x1, n));
				}
			;
        	        		
				val_check(y1, array);
				int y1_size = val_array_size(y1);
				double* y1_values = (double*)malloc(sizeof(double) * y1_size);
				{
					for (int n = 0; n < y1_size; n++) y1_values[n] = val_number(val_array_i(y1, n));
				}
			;
        	        		
				val_check(r1, array);
				int r1_size = val_array_size(r1);
				double* r1_values = (double*)malloc(sizeof(double) * r1_size);
				{
					for (int n = 0; n < r1_size; n++) r1_values[n] = val_number(val_array_i(r1, n));
				}
			;
        	
        					cairo_status_t _result = cairo_pattern_get_radial_circles(kind_cairo_pattern_t_get(pattern), x0_values, y0_values, r0_values, x1_values, y1_values, r1_values);
	        		        		;
	        		        		
				{
					for (int n = 0; n < x0_size; n++) val_array_set_i(x0, n, alloc_float(x0_values[n]));
				}
				free(x0_values);
			;
	        		        		
				{
					for (int n = 0; n < y0_size; n++) val_array_set_i(y0, n, alloc_float(y0_values[n]));
				}
				free(y0_values);
			;
	        		        		
				{
					for (int n = 0; n < r0_size; n++) val_array_set_i(r0, n, alloc_float(r0_values[n]));
				}
				free(r0_values);
			;
	        		        		
				{
					for (int n = 0; n < x1_size; n++) val_array_set_i(x1, n, alloc_float(x1_values[n]));
				}
				free(x1_values);
			;
	        		        		
				{
					for (int n = 0; n < y1_size; n++) val_array_set_i(y1, n, alloc_float(y1_values[n]));
				}
				free(y1_values);
			;
	        		        		
				{
					for (int n = 0; n < r1_size; n++) val_array_set_i(r1, n, alloc_float(r1_values[n]));
				}
				free(r1_values);
			;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM_MULT(hx_cairo_pattern_get_radial_circles);
		    					value hx_cairo_image_surface_create_from_png(value filename) {
		        	        		val_check(filename, string);
        	
        					cairo_surface_t* _result = cairo_image_surface_create_from_png(val_get_string(filename));
	        		        		;
	        					return kind_cairo_surface_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_image_surface_create_from_png, 1);
		    					value hx_cairo_image_surface_create_from_png_stream(value __, value reader) {
		        	        		;
        	        		value* root_reader = alloc_root(); *root_reader = reader;;
        	
        					cairo_surface_t* _result = cairo_image_surface_create_from_png_stream(cairo_read_stream, (void*)reader);
	        		        		;
	        		        		free_root(root_reader);;
	        					return kind_cairo_surface_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_image_surface_create_from_png_stream, 2);
		    					value hx_cairo_surface_write_to_png(value surface, value filename) {
		        	        		kind_cairo_surface_t_check(surface);
        	        		val_check(filename, string);
        	
        					cairo_status_t _result = cairo_surface_write_to_png(kind_cairo_surface_t_get(surface), val_get_string(filename));
	        		        		;
	        		        		;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_surface_write_to_png, 2);
		    					value hx_cairo_surface_write_to_png_stream(value surface, value __, value writer) {
		        	        		kind_cairo_surface_t_check(surface);
        	        		;
        	        		value* root_writer = alloc_root(); *root_writer = writer;;
        	
        					cairo_status_t _result = cairo_surface_write_to_png_stream(kind_cairo_surface_t_get(surface), cairo_write_stream, (void*)writer);
	        		        		;
	        		        		;
	        		        		free_root(root_writer);;
	        					return alloc_int(_result);
        	        }
				DEFINE_PRIM(hx_cairo_surface_write_to_png_stream, 3);
		    					value hx_cairo_svg_surface_create(value filename, value width_in_points, value height_in_points) {
		        	        		val_check(filename, string);
        	        		val_check(width_in_points, number);;
        	        		val_check(height_in_points, number);;
        	
        					cairo_surface_t* _result = cairo_svg_surface_create(val_get_string(filename), val_get_double(width_in_points), val_get_double(height_in_points));
	        		        		;
	        		        		;
	        		        		;
	        					return kind_cairo_surface_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_svg_surface_create, 3);
		    					value hx_cairo_svg_surface_create_for_stream(value __, value writer, value width_in_points, value height_in_points) {
		        	        		;
        	        		value* root_writer = alloc_root(); *root_writer = writer;;
        	        		val_check(width_in_points, number);;
        	        		val_check(height_in_points, number);;
        	
        					cairo_surface_t* _result = cairo_svg_surface_create_for_stream(cairo_write_stream, (void*)writer, val_get_double(width_in_points), val_get_double(height_in_points));
	        		        		;
	        		        		free_root(root_writer);;
	        		        		;
	        		        		;
	        					return kind_cairo_surface_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_svg_surface_create_for_stream, 4);
		    					value hx_cairo_svg_surface_restrict_to_version(value surface, value version) {
		        	        		kind_cairo_surface_t_check(surface);
        	        		val_check(version, int);
        	
        					cairo_svg_surface_restrict_to_version(kind_cairo_surface_t_get(surface), ((cairo_svg_version_t)val_get_int(version)));
	        		        		;
	        		        		;
	        					return val_null;
        	        }
				DEFINE_PRIM(hx_cairo_svg_surface_restrict_to_version, 2);
		    					value hx_cairo_svg_version_to_string(value version) {
		        	        		val_check(version, int);
        	
        					const char* _result = cairo_svg_version_to_string(((cairo_svg_version_t)val_get_int(version)));
	        		        		;
	        					return alloc_string(_result);
        	        }
				DEFINE_PRIM(hx_cairo_svg_version_to_string, 1);
		    					value hx_cairo_pdf_surface_create(value filename, value width, value height) {
		        	        		val_check(filename, string);
        	        		val_check(width, number);;
        	        		val_check(height, number);;
        	
        					cairo_surface_t* _result = cairo_pdf_surface_create(val_get_string(filename), val_get_double(width), val_get_double(height));
	        		        		;
	        		        		;
	        		        		;
	        					return kind_cairo_surface_t_alloc(_result);
        	        }
				DEFINE_PRIM(hx_cairo_pdf_surface_create, 3);
		    }

