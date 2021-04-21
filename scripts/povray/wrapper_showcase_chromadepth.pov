// Have no idea what is going wrong here. Some sort of perturbation?

#version 3.7;

// -------------------------------------------------------------
// chromadepth render with lgeo

#include "settings_common_before.inc"
#include "settings_showcase_chromadepth.inc"
#include "settings_common_after.inc"
#include "lg_defs.inc"							// needed if your model contains LGEO parts
#include "lg_color.inc"							// needed if your model contains LGEO parts
#include "materials_chromadepth.inc"
#include "materials_lgeo_defs.inc"			// missing "lg_slope_bumps"! oops!
#include "materials_lgeo_out.inc"
#include "materials_all_blank.inc"
#include "materials_all_convert.inc"

// -------------------------------------------------------------
// Models

#include "l3p_building_036_shoppingcenter_lgeo_y.pov"
//object { building__036__shoppingcenter_dot_ldr texture { MakeChromadepthTextureCameraRWB(L3Location, L3LookAt, 75) } }
object { building__036__shoppingcenter_dot_ldr texture { MakeChromadepthTextureObjectRWB(L3Location, L3ModelBBoxMin, L3ModelBBoxMax) } }
