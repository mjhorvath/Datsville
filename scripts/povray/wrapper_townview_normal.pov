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
// Misc. settings

#declare L3Studs			= 1;
//#declare Use_Floor_Cutout	=false;				// needed for the oldest scenes created by John VanZwieten and Tore Eriksson
//#declare Use_Floor_Trans	= <0,4,0>;			// needed for the oldest scenes created by John VanZwieten and Tore Eriksson
#declare Use_Floor_Cutout	= true;				// needed for the latest scenes created by Michael Horvath
#declare Use_Floor_Trans	= <0,52,0>;			// needed for the latest scenes created by Michael Horvath

// -------------------------------------------------------------
// Settings & materials

#include "settings_common_before.inc"
#include "settings_townview_normal.inc"
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

// Sadly, 16GB is not enough RAM to render this scene.
// Also, references some LGEO files that I have since misplaced.
//#include "ldv_datsville_rev004.531_inlined_y_boxed_h_lgeo_y.pov"

// If you turn a lot of fancy features off you will be able to barely render this with 16GB RAM.
//#include "ldv_datsville_rev004.531_inlined_y_boxed_h_lgeo_n.pov"

// If you turn a lot of fancy features off you will be able to barely render this with 16GB RAM.
//#include "ldv_datsville_rev005.442_inlined_n_boxed_n_lgeo_n.pov"

// If you turn a lot of fancy features off you will be able to barely render this with 16GB RAM.
#include "l3p_datsville_rev005.464_inlined_n_boxed_n_lgeo_n.pov"
