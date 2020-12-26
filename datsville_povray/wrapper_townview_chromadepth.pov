#version 3.7;

// -------------------------------------------------------------
// LDC settings with LGEO and ChromaDepth

#include "settings_common_before.inc"
#include "settings_townview_chromadepth.inc"
#include "settings_common_after.inc"
#include "lg_defs.inc"							// needed if your model contains LGEO parts
#include "lg_color.inc"							// needed if your model contains LGEO parts
#include "materials_blurred_reflections.inc"	// only supported by "materials_ldc_defs_clipka.inc" and "materials_ldc_defs_mjh.inc" currently
#include "materials_chromadepth.inc"
#include "materials_ldc_defs.inc"
#include "materials_ldc_out.inc"
#include "materials_all_blank.inc"
#include "materials_all_convert.inc"

// -------------------------------------------------------------
// Models

#declare ThisTranslate	= <+2240,0,-320>;
#include "l3p_datsville_te_rev013_inlined_n_boxed_f_lgeo_n.pov"
object
{
	datsville__te__rev013__noinline__boxed__full_dot_mpd
	translate ThisTranslate
	//texture { MakeChromadepthTextureCameraRGB(Camera_Location, Camera_LookAt, 50) }
	texture { MakeChromadepthTextureObjectRWB(Camera_Location, L3ModelBBoxMin + ThisTranslate, L3ModelBBoxMax + ThisTranslate) }
}

/*
// z bounding info not reported by LDCad, so must wrap the texture to the camera and not the object
#include "ldc_datsville_rev528_inlined_n_boxed_n_lgeo_n.pov"
object
{
	sf_datsville_dot_ldr
	texture { MakeChromadepthTextureCameraRWB(Camera_Location, Camera_LookAt, 60) }
}
*/
