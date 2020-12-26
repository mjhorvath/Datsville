#version 3.7;

// -------------------------------------------------------------
// Misc. settings

#declare L3Studs			= 1;
//#declare Use_Floor_Cutout	=false;				// needed for the oldest scenes created by John VanZwieten and Tore Eriksson
//#declare Use_Floor_Trans	= <0,4,0>;			// needed for the oldest scenes created by John VanZwieten and Tore Eriksson
#declare Use_Floor_Cutout	= true;				// needed for the latest scenes by Michael Horvath
#declare Use_Floor_Trans	= <0,52,0>;			// needed for the latest scenes by Michael Horvath

// -------------------------------------------------------------
// Settings & materials

#include "settings_common_before.inc"
#include "settings_streetmap_normal.inc"
#include "settings_common_after.inc"
#include "lg_defs.inc"							// needed if your model contains LGEO parts
#include "lg_color.inc"							// needed if your model contains LGEO parts
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
// OL = Michael Horvath (offline)
// GH = Michael Horvath (GitHub)
// SF = Michael Horvath (SourceForge)
// GC = Michael Horvath (Google Code)
// TE = Tore Eriksson
// JVZ = John VanZwieten
// inlined = LDraw models have been processed using MPDCenter to create a single larger "flattened" model file out of many smaller hierarchical model files
// boxed = LDraw models have been processed using LDBoxer or MyBoxer to replace partially hidden parts with simple boxes
// lgeo = POV-Ray models are using LGEO parts

//#include "l3p_datsville_te_rev013_inlined_n_boxed_f_lgeo_n.pov"
//object {datsville__te__rev013__noinline__boxed__full_dot_mpd material { L3Color7 } translate <+2240,0,-320>}

//#include "ldc_datsville_sf_rev528_inlined_n_boxed_n_lgeo_n.pov"

//#include "l3p_datsville_sf_rev531_inlined_y_boxed_h_lgeo_n.pov"

// Sadly, 16GB is not enough RAM to render this scene.
// Also, references some LGEO files that I have since misplaced.
//#include "ldv_datsville_sf_rev531_inlined_y_boxed_h_lgeo_y.pov"

// If you turn a lot of fancy features off you will be able to barely render this with 16GB RAM.
//#include "ldv_datsville_sf_rev531_inlined_y_boxed_h_lgeo_n.pov"

// If you turn a lot of fancy features off you will be able to barely render this with 16GB RAM.
//#include "ldv_datsville_gh_rev442_inlined_n_boxed_n_lgeo_n.pov"

// If you turn a lot of fancy features off you will be able to barely render this with 16GB RAM.
//#include "l3p_datsville_gh_rev497_inlined_n_boxed_n_lgeo_n.pov"

// If you turn a lot of fancy features off you will be able to barely render this with 16GB RAM.
#include "l3p_datsville_ol_rev001_inlined_n_boxed_n_lgeo_n.pov"
