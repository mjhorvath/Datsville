// POV-Ray scripts for LDraw models and scenes
// Copyright (C) 2019  Michael Horvath
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA


#version 3.7;


// -------------------------------------------------------------
// L3P materials and settings without LGEO

//#include "settings_common_before.inc"
//#include "settings_showcase_normal_lq.inc"		// lq
//#include "settings_showcase_normal_hq.inc"		// hq
//#include "settings_common_after.inc"
//#include "materials_l3p_defs.inc"
//#include "materials_l3p_out.inc"
//#include "materials_all_missing.inc"
//#include "materials_all_convert.inc"
//#include "settings_showcase_normal_last.inc"


// -------------------------------------------------------------
// LDC materials and settings with LGEO

#include "settings_common_before.inc"
#include "settings_showcase_normal_lq.inc"		// lq
//#include "settings_showcase_normal_hq.inc"		// hq
#include "settings_common_after.inc"
#include "lg_defs.inc"							// needed if your model contains LGEO parts
#include "lg_color.inc"							// needed if your model contains LGEO parts
#include "materials_blurred_reflections.inc"	// only supported by "materials_ldc_defs_clipka.inc" and "materials_ldc_defs_mjh.inc" currently
#include "materials_ldc_defs_mjh.inc"
#include "materials_ldc_out.inc"
#include "materials_all_missing.inc"
#include "materials_all_convert.inc"
#include "settings_showcase_normal_last.inc"


// -------------------------------------------------------------
// L3P models

//#include "l3p_building_007_firecompany_inlined_n_boxed_n_lgeo_y.pov"
//#include "l3p_building_021_houseporchyard_inlined_n_boxed_n_lgeo_y.pov"
#include "l3p_building_031_carriagehouse_inlined_n_boxed_h_lgeo_y.pov"
//#include "l3p_building_036_shoppingcenter_inlined_n_boxed_n_lgeo_y.pov"
