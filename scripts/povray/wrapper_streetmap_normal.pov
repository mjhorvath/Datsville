#version 3.8;


// -------------------------------------------------------------
// Misc. settings

#declare L3Studs			= 1;
//#declare Use_Floor_Cutout	=false;				// needed for rev001 and rev002
//#declare Use_Floor_Trans	= <0,4,0>;			// needed for rev001 and rev002
#declare Use_Floor_Cutout	= true;				// needed for rev005
#declare Use_Floor_Trans	= <0,52,0>;			// needed for rev005
#declare Use_2DGuides		= true;				// axis markers, street sector markers, etc. mainly for maps
#declare Use_3DGuides		= true;				// axis markers, street sector markers, etc. mainly for maps
#declare Use_GridGuides		=false;				// show guides marking baseplate corners


// -------------------------------------------------------------
// Settings & materials

#include "settings_common_before.inc"
#include "settings_streetmap_normal.inc"
#include "settings_common_after.inc"
//#include "lg_defs.inc"							// needed if your model contains LGEO parts
//#include "lg_color.inc"							// needed if your model contains LGEO parts
#include "materials_blurred_reflections.inc"	// currently only supported by "materials_ldc_defs_clipka.inc" and "materials_ldc_defs_mjh.inc"
#include "materials_ldc_defs_mjh.inc"
#include "materials_ldc_out.inc"
#include "materials_all_missing.inc"
#include "materials_all_convert.inc"


// -------------------------------------------------------------
// Models

// L3P = L3P.exe
// LDV = LDview
// LDC = LDCad
// LEO = LeoCAD
// rev006.xxx = Michael Horvath (GitHub #2)
// rev005.xxx = Michael Horvath (GitHub #1)
// rev004.xxx = Michael Horvath (SourceForge)
// rev003.xxx = Michael Horvath (Google Code)
// rev002.xxx = Tore Eriksson (SkyDrive)
// rev001.xxx = John VanZwieten (LUGNET)
// inlined = LDraw models have been processed using MPDCenter to create a single larger "flattened" model file out of many smaller hierarchical model files
// boxed = LDraw models have been processed using LDBoxer or MyBoxer to replace totally or partially hidden parts with simpler box parts
// lgeo = POV-Ray models use LGEO parts

//#include "l3p_datsville_rev002.013_inlined_n_boxed_f_lgeo_n.pov"
//object {datsville__rev002_dot_013__noinline__boxed__full_dot_mpd material { L3Color7 } translate <+2240,0,-320>}

//#include "ldc_datsville_rev004.528_inlined_n_boxed_n_lgeo_n.pov"

//#include "l3p_datsville_rev004.531_inlined_y_boxed_h_lgeo_n.pov"

// References some LGEO files that I have misplaced. 16GiB is not enough RAM to render this scene on my Windows 10 machine.
//#include "ldv_datsville_rev004.531_inlined_y_boxed_h_lgeo_y.pov"

// If I turn a lot of fancy features off I can barely render this scene on my Windows 10 machine with 16GiB RAM.
//#include "ldv_datsville_rev004.531_inlined_y_boxed_h_lgeo_n.pov"

// If I turn a lot of fancy features off I can barely render this scene on my Windows 10 machine with 16GiB RAM.
//#include "ldv_datsville_rev005.442_inlined_n_boxed_n_lgeo_n.pov"

// If I turn a lot of fancy features off I can barely render this scene on my Windows 10 machine with 16GiB RAM.
//#include "l3p_datsville_rev005.497_inlined_n_boxed_n_lgeo_n.pov"

// If I turn a lot of fancy features off I can barely render this scene on my Windows 10 machine with 16GiB RAM.
#include "l3p_datsville_rev006.106_inlined_n_boxed_n_lgeo_n.pov"
