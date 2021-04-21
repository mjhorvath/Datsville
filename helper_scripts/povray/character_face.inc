#version 3.7

// +KFI0 +KFF3 +KI0.0 +KF1.0 +KC
// +KFI0 +KFF7 +KI0.0 +KF1.0 +KC

// -------------------------------------------------------------
// Includes

#include "stdinc.inc"
#include "textures.inc"
#include "woods.inc"
#include "stones.inc"
#include "glass.inc"
#include "metals.inc"
//#include "fastrad.inc"		// slooowwwwwww!!!
#include "CIE.inc"			// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys.inc"			// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys_constants.inc"	// http://www.ignorancia.org/en/index.php?page=Lightsys

// -------------------------------------------------------------
// Default values. These can be pre-declared in your scene.

#ifndef (Use_Radiosity)		#declare Use_Radiosity		= 0;			#end	// turns radiosity on/off. (Recommend leaving this off. have to decrease diffuse if it is on.)
#ifndef (Use_Shadows)		#declare Use_Shadows		= 0;			#end	// turns shadows on/off. (Recommend turning this off for walls that are always covered by rooves.) Not used often.
#ifndef (Show_GridMarker)	#declare Show_GridMarker	= 0;			#end	// use this to orient the sprite within a template
#ifndef (Show_BasicFloor)	#declare Show_BasicFloor	= 0;			#end	// renders a plain, 1-tile floor beneath the scene.
#ifndef (Show_AxisMarker)	#declare Show_AxisMarker	= 0;			#end	// renders crosshairs in the center of the scene
#ifndef (Seed)			#declare Seed			= seed(8829464);	#end	// the default seed value for random functions.
#ifndef (Rand_Colors)		#declare Rand_Colors		= true;		#end	//
#ifndef (Use_Uber)			#declare Use_Uber			=false;		#end				// toggle blurred reflections method depending on whether you are using POV-Ray or UberPOV
#ifndef (Use_SSLT)			#declare Use_SSLT			=false;		#end				// subsurface light transport, only supported by "materials_ldc_defs_clipka.inc" and "materials_ldc_defs_mjh.inc" currently
#ifndef (Use_BlurRef)		#declare Use_BlurRef		= true;		#end				// blurred surface reflections, requires camera focal blur or antialiasing as well, or else the textures will look really grainy
#ifndef (Use_BlurTyp)		#declare Use_BlurTyp		= 1;		#end				// type of blurred reflections, method 1 requires focal blur and lots of antialiasing or the texture will look grainy, method 3 does not require these things but is much much slower, method 2 lies somewhere in between
#ifndef (Use_BlurSmp)		#declare Use_BlurSmp		= 8;		#end				// number of samples in blurred reflections
#ifndef (Use_BlurAmt)		#declare Use_BlurAmt		= 1/32;		#end				// amount of surface reflection blurring
#ifndef (Use_Seed)			#declare Use_Seed			= seed(08763);		#end		// seed for some random stuff

#declare TileWidth		= 128;
#declare TilesNum		= 1;
#declare L3Version		= 1.4;
#declare L3Quality		= 1;		// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo, 4=stud2logo
#declare L3SW			= 0;		// Width of seam between two bricks
#declare L3Studs		= 0;		// 1=on 0=off
#declare L3Bumps		= 0;		// 1=on 0=off
#declare L3Ambient		= 0.1;
#declare L3Diffuse		= 0.9;
#declare L3Ior			= 1.25;
#declare L3NormalBumps		= normal { bumps 0.01 scale 20 }
#declare L3NormalSlope		= normal { bumps 0.3 scale 0.5 }
#declare QUAL			= L3Quality;	// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo
#declare SW			= L3SW;		// Width of seam between two bricks
#declare STUDS			= L3Studs;	// 1=on 0=off
#declare BUMPS			= L3Bumps;	// 1=on 0=off
#declare BUMPNORMAL		= L3NormalBumps;
#declare AMB			= L3Ambient;
#declare DIF			= L3Diffuse;
#declare L3Phong		= 0.5;
#declare L3PhongSize		= 40;
#declare L3Reflection		= 0.08;	// was 0.08
#declare light_lumens		= 2;					// float
#declare light_temp		= Daylight(6100);			// float
#declare light_color		= Light_Color(light_temp,light_lumens);

// -------------------------------------------------------------
// Set direction based on the clock value.

#declare Count = clock * 16;
#declare No1 = mod(Count,4);
#declare No2 = floor(Count/4);
#if ((No1 = 1) | (No1 = 3))
	#ifndef (North) #declare North = true; #end		// Is the object connected on this side?
#else
	#ifndef (North) #declare North = false; #end
#end
#if ((No1 = 2) | (No1 = 3))
	#ifndef (East) #declare East  = true; #end		// ...
#else
	#ifndef (East) #declare East  = false; #end
#end
#if ((No2 = 1) | (No2 = 3))
	#ifndef (South) #declare South = true; #end		// ...
#else
	#ifndef (South) #declare South = false; #end
#end
#if ((No2 = 2) | (No2 = 3))
	#ifndef (West) #declare West  = true; #end		// ...
#else
	#ifndef (West) #declare West  = false; #end
#end


// -------------------------------------------------------------
// Misc. scene settings

#if (Use_Radiosity = 1)
	global_settings
	{
		assumed_gamma	1
		adc_bailout	0.005
		max_trace_level	50
		ambient_light	0
		radiosity
		{
			pretrace_start	0.08
			pretrace_end	0.02	// Try 0.01 if you see random black spots.
			count		20
			error_bound	1
			recursion_limit	1
			normal		on
//			brightness	1.4
			brightness	pow(1.4,2.2)
			always_sample	no
			gray_threshold	0.8
			media		on
		}
	}
#else
	global_settings
	{
		assumed_gamma	1
	}
#end





// -------------------------------------------------------------
// Default textures

// diffuse should really vary depending on whether radiosity is turned on or off
#default
{
	texture
	{
		finish { ambient L3Ambient diffuse L3Diffuse }
	}
}

#declare MJHMissingTex = texture {pigment {color srgb <1,0,1>}}
#declare MJHMissingMat = material {texture {MJHMissingTex}}


//#include "ldr_materials_figure_1.4.inc"	// used by L3P
//#include "settings_common_before.inc"
//#include "settings_showcase_normal_hq.inc"
//#include "settings_common_after.inc"
#include "lg_defs.inc"							// needed if your model contains LGEO parts
#include "lg_color.inc"							// needed if your model contains LGEO parts
#include "materials_blurred_reflections.inc"	// currently only supported by "materials_ldc_defs_clipka.inc" and "materials_ldc_defs_mjh.inc"
#include "materials_ldc_defs_mjh.inc"
#include "materials_ldc_out.inc"
#include "materials_all_missing.inc"
#include "materials_all_convert.inc"


// -------------------------------------------------------------
// Camera

#declare cam_mode = 2;
#switch (cam_mode)
	// orthographic
	#case (0)
		#declare Diagonal_horz		= cos(pi/4);
		#declare Diagonal_vert		= sin(pi/4);
		camera
		{
			orthographic
			up		-y * Diagonal_horz * TileWidth * 2 * TilesNum * image_height/image_width
			right		+x * Diagonal_horz * TileWidth * 2 * TilesNum
			location	-z * 4096 * TilesNum
			direction	+z * 4096 * TilesNum
			rotate		-x * 30
			rotate		+y * 45
			translate	+x * 960
			translate	+z * 960
		}
	#break
	// oblique
	#case (1)
		#local cam_aspc =     image_width/image_height;
		#local cam_dist =     100000;
		#local cam_area =     TileWidth * TilesNum;
		#local cam_loca =     -z * cam_dist;
		#local cam_dirc =     +z * cam_dist;
		#local cam_upvc =     -y * cam_area * sind(045);
		#local cam_rgvc =     +x * cam_area * cam_aspc;
		#local cam_tran = transform
		{
			rotate		-x * 045
			scale		1.5
			translate	+z * 64
//			translate	+x * 40
		}
		camera
		{
			orthographic
			location	cam_loca
			direction	cam_dirc
			up		cam_upvc
			right		cam_rgvc
			transform {cam_tran}
		}
	#break
	// perspective
	#case (2)
		camera
		{
			//orthographic
			up		-y * 40 * image_height/image_width
			right		+x * 40
			location	-z * 160 * TilesNum
			direction	+z * 160 * TilesNum
			translate	-y * 80
		}
	#break
#end
// -------------------------------------------------------------
// Lights. There are several methods inconsistantly used within GearHead. I try and mimic them here.

light_source
{
	-z * 4096
	light_color
	rotate		-x * 15
	rotate		+y * 15
	parallel
	point_at	<0,0,0>
//	shadowless
}


// -------------------------------------------------------------
// Orientation markers

#declare Axis_Markers = union
{
	sphere
	{
		0,2
		pigment{color srgb <0,0,0,>}
	}
	cylinder
	{
		0,+x*1024,2
		pigment{color srgb <1,0,0,>}
	}
	cylinder
	{
		0,-y*1024,2
		pigment{color srgb <0,1,0,>}
	}
	cylinder
	{
		0,+z*1024,2
		pigment{color srgb <0,0,1,>}
	}
}

#declare Grid_Marker = polygon
{
	#local Wid = TileWidth/4;
	#local NW = <0000,+000,-Wid,>;
	#local NE = <-Wid,+000,-Wid,>;
	#local SE = <-Wid,+000,0000,>;
	#local SW = <-Wid/2,+000,-Wid/2,>;
	4, NW, NE, SE, SW
	translate x * TileWidth
	translate z * TileWidth
}

#declare Basic_Floor = polygon
{
	#local Wid = TileWidth/4;
	#local NW = <+Wid,+000,-Wid,>;
	#local NE = <-Wid,+000,-Wid,>;
	#local SE = <-Wid,+000,+Wid,>;
	#local SW = <+Wid,+000,+Wid,>;
	4, NW, NE, SE, SW
}

#declare Clip_Cylinder = cylinder
{
	#local Hgh = 24 / sin(pi/3);
	#local Rad = cos(pi/4) * TileWidth;
	0, y * Hgh, Rad
	scale y * 2
}

#if (Show_AxisMarker = 1)
	object
	{
		Axis_Markers
	}
#end

#if (Show_GridMarker = 1)
	object
	{
		Grid_Marker
		uv_mapping
		pigment {color srgbt <1,0,1,1/2>}
	}
#end

#if (Show_BasicFloor = 1)
	object
	{
		Basic_Floor
		uv_mapping
		pigment {color srgbt <1,0,1,1/2>}
	}
#end

#if (Use_Shadows = 1)
	object
	{
		Basic_Floor
		pigment
		{
			cylindrical
			color_map
			{
				[0 srgbt <0,0,0,1>]
				[1 srgbt <0,0,0,1/2>]
			}
			scale TileWidth/2
		}
	}
#end
