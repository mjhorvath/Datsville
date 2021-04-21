#version 3.7;


// -------------------------------------------------------------
// Global settings and radiosity

//Values for Use_Rad_Setting:
//Default		= 0
//Debug			= 1
//Fast			= 2
//Normal		= 3
//2Bounce		= 4
//Final			= 5
//OutdoorLQ		= 6
//OutdoorHQ		= 7
//OutdoorLight	= 8
//IndoorLQ		= 9
//IndoorHQ		= 10

#if (Use_Radiosity = 1)
	global_settings
	{
		assumed_gamma	1
		adc_bailout		0.005
		max_trace_level	8
		ambient_light	0
		radiosity
		{
			#include "rad_def.inc"
			Rad_Settings(Use_Rad_Setting,false,false)
		}
		#if (Use_SSLT = true)
			mm_per_unit 0.4			// http://www.brickwiki.info/wiki/LDraw_unit
			subsurface
			{
				samples 50, 5
				radiosity true
			}
		#end
	}
#else
	global_settings
	{
		assumed_gamma	1
		max_trace_level 8
		ambient_light	1
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


// -------------------------------------------------------------
// Guides

#if (Use_Guides = 1)
	// coordinate axes
	union
	{
		cylinder {0, +x*32000, 20 pigment {color srgb x}}
		cylinder {0, +y*32000, 20 pigment {color srgb y}}
		cylinder {0, +z*32000, 20 pigment {color srgb z}}
		cylinder {0, -x*32000, 20 pigment {color srgb y+z}}
		cylinder {0, -y*32000, 20 pigment {color srgb x+z}}
		cylinder {0, -z*32000, 20 pigment {color srgb x+y}}
		sphere {0, 20 pigment {color srgb 0}}
	}
	// street grid
	union
	{
		#declare grid_x_min = -2;
		#declare grid_x_max = +2;
		#declare grid_z_min = -2;
		#declare grid_z_max = +2;
		#declare grid_distance = 5120;
		#local beg_y = 0;
		#local end_y = -128;
		#for (step_x, grid_x_min, grid_x_max, 1)
			#local beg_x = (step_x + 0) * grid_distance;
			#local end_x = (step_x + 1) * grid_distance;
			#local beg_z = grid_z_min * grid_distance;
			#local end_z = grid_z_max * grid_distance;
			polygon {4, <beg_x, beg_y, beg_z>, <beg_x, end_y, beg_z>, <beg_x, end_y, end_z>, <beg_x, beg_y, end_z>}
		#end
		#for (step_z, grid_z_min, grid_z_max, 1)
			#local beg_x = grid_x_min * grid_distance;
			#local end_x = grid_x_max * grid_distance;
			#local beg_z = (step_z + 0) * grid_distance;
			#local end_z = (step_z + 1) * grid_distance;
			polygon {4, <beg_x, beg_y, beg_z>, <beg_x, end_y, beg_z>, <end_x, end_y, beg_z>, <end_x, beg_y, beg_z>}
		#end
		pigment {color srgb +x+z}
	}
#end


// -------------------------------------------------------------
// Clouds
// Not used for "showcase" scenes

#if (Use_Clouds)

#end


// -------------------------------------------------------------
// Sky
// Not used for "showcase" scenes

#if (Use_Sky = 1)
	#include "SkySim.inc"			// http://news.povray.org/povray.binaries.scene-files/thread/%3C51b1c936%40news.povray.org%3E/?mtop=387744
	// SunPos, UpVector, Turbidity, ExposureFactor
	SkySim(light_source_location, -y, 2, 1e-5 * 5)			// not sure what ExposureFactor should actually be
#end
