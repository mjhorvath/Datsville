#version 3.7;


// -------------------------------------------------------------
// Lights
// Light color should be RGB not SRGB!!

#include "CIE.inc"					// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys.inc"				// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys_constants.inc"	// http://www.ignorancia.org/en/index.php?page=Lightsys

#declare light_source_lumens	= 1;					// float
#declare light_source_temp		= Daylight(6500);		// float
#declare light_source_color		= Light_Color(light_source_temp,light_source_lumens);
#declare light_source_distance	= 64000;
#declare light_source_location	= vrotate(<0,0,-light_source_distance>, <-60,-120,+00>);

light_source
{
	light_source_location
	color rgb light_source_color
	#if (Use_Area_Light = true)
		area_light x*320, y*320, 9, 9 adaptive 0 circular orient
		area_illumination on
	#end
//	point_at <0,0,0>		// not for point lights
//	parallel
	fade_distance light_source_distance
	fade_power 1
//	shadowless
}

light_source
{
	light_source_location
	color rgb light_source_color
	#if (Use_Area_Light = true)
		area_light x*320, y*320, 9, 9 adaptive 0 circular orient
		area_illumination on
	#end
//	point_at <0,0,0>		// not for point lights
//	parallel
	fade_distance light_source_distance
	fade_power 1
//	shadowless
	rotate y * 90
}


// -------------------------------------------------------------
// Surrounding environment
// Will conflict with Use_Floor_Check, Use_Floor_Cutout and Use_Sky, so don't enable all of them.

#switch (Use_Env_Mode)
	// plain black background, no floor
	#case (1)
		background { color srgb <0,0,0> }
	#break
	// plain white floor and plain white background
	#case (2)
		background { color srgb <1,1,1> }		// should be same color as used in MJHTex15
		union
		{
			plane { -y, 0 hollow }
			material { MJHMat15 }
		}
	#break
	// gray studded floor and blue background
	#case (3)
		sky_sphere
		{
			pigment
			{
				planar
				poly_wave 2
				pigment_map
				{
					[0.0 colour srgb <0.20,0.40,0.90>]
					[1.0 colour srgb <0.60,0.70,0.95>]
				}
			}
//			emission 1
		}
		union
		{
			plane { -y, 0 hollow }
			#for (X,-Stud_Floor_Size/2,Stud_Floor_Size/2-1)
				#for (Z,-Stud_Floor_Size/2,Stud_Floor_Size/2-1)
					object { lg_knob rotate <90, 0, 0> translate <X+0.5,0,Z+0.5> }
				#end
			#end
			material { MJHMat8 }
			scale 20
		}
	#break
	// dotted floor and light gray background
	#case (4)
		#local Env_Color = 3/4;
		background { color srgb Env_Color }
		union
		{
			plane { z, 0 hollow }
			texture
			{
				pigment { color srgb Env_Color }
			}
			texture
			{
				pigment { image_map { png "grid_square_03.png" } }
				scale 40
			}
			rotate x * 90
		}
	#break
#end
