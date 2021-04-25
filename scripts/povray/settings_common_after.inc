#version 3.8;


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
// Guides & labels

#if (Use_3DGuides = 1)
	// coordinate axes
	union
	{
		cylinder {0, +x*32000, 20 pigment {color srgb x}}
//		cylinder {0, +y*32000, 20 pigment {color srgb y}}
		cylinder {0, +z*32000, 20 pigment {color srgb z}}
		cylinder {0, -x*32000, 20 pigment {color srgb y+z}}
//		cylinder {0, -y*32000, 20 pigment {color srgb x+z}}
		cylinder {0, -z*32000, 20 pigment {color srgb x+y}}
		sphere {0, 20 pigment {color srgb 0}}
	}

	// sector grid lines
	union
	{
		#declare grid_x_min = -8;
		#declare grid_x_max = +8;
		#declare grid_z_min = -8;
		#declare grid_z_max = +8;
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

	// baseplate grid lines
	#if (Use_GridGuides)
		union
		{
			#declare grid_x_min = -64;
			#declare grid_x_max = +64;
			#declare grid_z_min = -64;
			#declare grid_z_max = +64;
			#declare grid_distance = 640;
			#local beg_y = 0;
			#local end_y = -64;
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
			pigment {color srgb +x}
		}
	#end
#end

#if (Use_2DGuides = 1)
	#if (Use_Isometric)
		#declare Iso_ScaleAmount = 4/2;
	#else
		#declare Iso_ScaleAmount = 3/2;
	#end

	// sector grid labels
	#declare Sectors_FontSize = 1/128 * Iso_ScaleAmount;
	#declare Sectors_FontColor = <1,0,1>;
	#declare Sectors_ZIndex = 1;
	#for (i, 0, 7)
		#for (j, 0, 7)
			#local PosX = i - 4;
			#local PosZ = j - 4;
			#if (PosX >= 0)
				#local CharX = concat("+", str(abs(PosX+1), -2, 0));
			#else
				#local CharX = concat("-", str(abs(PosX), -2, 0));
			#end
			#if (PosZ >= 0)
				#local CharZ = concat("+", str(abs(PosZ+1), -2, 0));
			#else
				#local CharZ = concat("-", str(abs(PosZ), -2, 0));
			#end
			#local PosString = concat("(", CharX, ",", CharZ, ")");
			#declare Text_Object = text
			{
				ttf "cyrvetic.ttf" PosString, 1/1024, 0
				scale <Sectors_FontSize,Sectors_FontSize,1>
				pigment {color srgb Sectors_FontColor}
				finish {emission 1 diffuse 0 ambient 0}
				no_shadow			// shouldn't cast shadows in the scene
				no_reflection		// shouldn't be reflected in scene elements
				no_radiosity		// also make the object invisible to radiosity rays
			}
			#declare Text_Object = object
			{
				Text_Object
				Center_Trans(Text_Object, x+y+z)
			}
			#declare Marker_Object = sphere
			{
				0, 1
				scale Sectors_FontSize/8
				pigment {color srgb Sectors_FontColor}
				finish {emission 1 diffuse 0 ambient 0}
				no_shadow			// shouldn't cast shadows in the scene
				no_reflection		// shouldn't be reflected in scene elements
				no_radiosity		// also make the object invisible to radiosity rays
			}
			#local Text_Coo3D			= <(PosX+0.5)*640*8,0,(PosZ+0.5)*640*8>;
			#local Text_Coo2D			= Get_Screen_XY(Text_Coo3D);
			#local Text_Coo2D			= Text_Coo2D/<image_width,image_height>;
			#local Text_Coo2D			= <0+Text_Coo2D.x,1-Text_Coo2D.y>;
			Screen_Object(Text_Object, Text_Coo2D, 0, false, -Sectors_ZIndex/1000)
//			Screen_Object(Marker_Object, Text_Coo2D, 0, false, -Sectors_ZIndex/1000)
		#end
	#end

	// baseplate grid labels
	#if (Use_GridGuides)
		#declare Baseplates_FontSize = 1/256 * Iso_ScaleAmount;
		#declare Baseplates_FontColor = <1,0,0>;
		#declare Baseplates_ZIndex = 2;
		#for (i, 0, 63)
			#for (j, 0, 63)
				#local PosX = i - 32;
				#local PosZ = j - 32;
				#if (PosX >= 0)
					#local CharX = concat("+", str(abs(PosX), -2, 0));
				#else
					#local CharX = concat("-", str(abs(PosX), -2, 0));
				#end
				#if (PosZ >= 0)
					#local CharZ = concat("+", str(abs(PosZ), -2, 0));
				#else
					#local CharZ = concat("-", str(abs(PosZ), -2, 0));
				#end
				#local PosString = concat("(", CharX, " ", CharZ, ")");
				#declare Text_Object = text
				{
					ttf "crystal.ttf" PosString, 1/1024, 0
					scale <Baseplates_FontSize,Baseplates_FontSize,1>
					pigment {color srgb Baseplates_FontColor}
					finish {emission 1 diffuse 0 ambient 0}
					no_shadow			// shouldn't cast shadows in the scene
					no_reflection		// shouldn't be reflected in scene elements
					no_radiosity		// also make the object invisible to radiosity rays
				}
				#declare Text_Object = object
				{
					Text_Object
					Center_Trans(Text_Object, x+y+z)
				}
				#declare Marker_Object = sphere
				{
					0, 1
					scale Baseplates_FontSize/8
					pigment {color srgb Baseplates_FontColor}
					finish {emission 1 diffuse 0 ambient 0}
					no_shadow			// shouldn't cast shadows in the scene
					no_reflection		// shouldn't be reflected in scene elements
					no_radiosity		// also make the object invisible to radiosity rays
				}
				#local Text_Coo3D			= <PosX*640,0,PosZ*640>;
				#local Text_Coo2D			= Get_Screen_XY(Text_Coo3D);
				#local Text_Coo2D			= Text_Coo2D/<image_width,image_height>;
				#local Text_Coo2D			= <0+Text_Coo2D.x,1-Text_Coo2D.y>;
				Screen_Object(Text_Object, Text_Coo2D, 0, false, -Baseplates_ZIndex/1000)
				Screen_Object(Marker_Object, Text_Coo2D, 0, false, -Baseplates_ZIndex/1000)
			#end
		#end
	#end

	// street labels
	#declare Streets_FontSize = 1/64 * Iso_ScaleAmount;
	#declare Streets_FontColor = <1,1,1>;
	#declare Streets_ZIndex = 3;
	#include "data_streets.inc"
	#for (i, 0, Streets_Number - 1)
		#declare Text_Object = text
		{
			ttf "cyrvetic.ttf" Streets_Labels[i], 1/1024, 0
			#if (Use_Isometric)
				#if (Streets_Angles[i] = 0)
					// if I used some trig here I could support any arbitrary angle
					// can be merged into the matrix transformation probably
					// these are a bit off
					matrix
					<
					  +1, +0, +0,
                      +3/4, +1, +0,
                      +0, +0, +1,
                      +0, +0, +0
					>
					rotate -z * atand(1/2)
				#elseif (Streets_Angles[i] = 90)
					// if I used some trig here I could support any arbitrary angle
					// can be merged into the matrix transformation probably
					// these are a bit off
					matrix
					<
					  +1, +0, +0,
                      -3/4, +1, +0,
                      +0, +0, +1,
                      +0, +0, +0
					>
					rotate +z * atand(1/2)
				#end
			#else
				rotate +z * Streets_Angles[i]
			#end
			scale <Streets_FontSize,Streets_FontSize,1>
			pigment {color srgb Streets_FontColor}
			finish {emission 1 diffuse 0 ambient 0}
			no_shadow			// shouldn't cast shadows in the scene
			no_reflection		// shouldn't be reflected in scene elements
			no_radiosity		// also make the object invisible to radiosity rays
		}
		#declare Text_Object = object
		{
			Text_Object
			Center_Trans(Text_Object, x+y+z)
		}
		#declare Marker_Object = sphere
		{
			0, 1
			scale Streets_FontSize/8
			pigment {color srgb Streets_FontColor}
			finish {emission 1 diffuse 0 ambient 0}
			no_shadow			// shouldn't cast shadows in the scene
			no_reflection		// shouldn't be reflected in scene elements
			no_radiosity		// also make the object invisible to radiosity rays
		}
		#local Text_Coo3D			= <Streets_Coords[i].x,Streets_Coords[i].y,Streets_Coords[i].z>;
		#local Text_Coo2D			= Get_Screen_XY(Text_Coo3D);
		#local Text_Coo2D			= Text_Coo2D/<image_width,image_height>;
		#local Text_Coo2D			= <0+Text_Coo2D.x,1-Text_Coo2D.y>;
		Screen_Object(Text_Object, Text_Coo2D, 0, false, -Streets_ZIndex/1000)
//		Screen_Object(Marker_Object, Text_Coo2D, 0, false, -Streets_ZIndex/1000)
	#end

	// block labels
	#declare Blocks_FontSize = 1/64 * Iso_ScaleAmount;
	#declare Blocks_FontColor = <0,1,1>;
	#declare Blocks_ZIndex = 4;
	#include "data_blocks.inc"
	#for (i, 0, Blocks_Number - 1)
		#declare Text_Object = text
		{
			ttf "cyrvetic.ttf" Blocks_Labels[i], 1/1024, 0
			scale <Blocks_FontSize,Blocks_FontSize,1>
			pigment {color srgb Blocks_FontColor}
			finish {emission 1 diffuse 0 ambient 0}
			no_shadow			// shouldn't cast shadows in the scene
			no_reflection		// shouldn't be reflected in scene elements
			no_radiosity		// also make the object invisible to radiosity rays
		}
		#declare Text_Object = object
		{
			Text_Object
			Center_Trans(Text_Object, x+y+z)
		}
		#declare Marker_Object = sphere
		{
			0, 1
			scale Blocks_FontSize/8
			pigment {color srgb Blocks_FontColor}
			finish {emission 1 diffuse 0 ambient 0}
			no_shadow			// shouldn't cast shadows in the scene
			no_reflection		// shouldn't be reflected in scene elements
			no_radiosity		// also make the object invisible to radiosity rays
		}
		#local Text_Coo3D			= <Blocks_Coords[i].x,Blocks_Coords[i].y,Blocks_Coords[i].z>;
		#local Text_Coo2D			= Get_Screen_XY(Text_Coo3D);
		#local Text_Coo2D			= Text_Coo2D/<image_width,image_height>;
		#local Text_Coo2D			= <0+Text_Coo2D.x,1-Text_Coo2D.y>;
		Screen_Object(Text_Object, Text_Coo2D, 0, false, -Blocks_ZIndex/1000)
//		Screen_Object(Marker_Object, Text_Coo2D, 0, false, -Blocks_ZIndex/1000)
	#end

	// building labels
	#declare Buildings_FontSize = 1/128 * Iso_ScaleAmount;
	#declare Buildings_FontColor = <1,1,0>;
	#declare Buildings_ZIndex = 5;
	#include "data_buildings.inc"
	#for (i, 0, Buildings_Number - 1)
		#declare Text_Object = text
		{
			ttf "cyrvetic.ttf" Buildings_Labels[i], 1/1024, 0
			rotate +z * Buildings_Angles[i]
			scale <Buildings_FontSize,Buildings_FontSize,1>
			pigment {color srgb Buildings_FontColor}
			finish {emission 1 diffuse 0 ambient 0}
			no_shadow			// shouldn't cast shadows in the scene
			no_reflection		// shouldn't be reflected in scene elements
			no_radiosity		// also make the object invisible to radiosity rays
		}
		#declare Text_Object = object
		{
			Text_Object
			Center_Trans(Text_Object, x+y+z)
		}
		#declare Marker_Object = sphere
		{
			0, 1/16
			scale Buildings_FontSize/8
			pigment {color srgb Buildings_FontColor}
			finish {emission 1 diffuse 0 ambient 0}
			no_shadow			// shouldn't cast shadows in the scene
			no_reflection		// shouldn't be reflected in scene elements
			no_radiosity		// also make the object invisible to radiosity rays
		}
		#local Text_Coo3D			= <Buildings_Coords[i].x,Buildings_Coords[i].y,Buildings_Coords[i].z>;
		#local Text_Coo2D			= Get_Screen_XY(Text_Coo3D);
		#local Text_Coo2D			= Text_Coo2D/<image_width,image_height>;
		#local Text_Coo2D			= <0+Text_Coo2D.x,1-Text_Coo2D.y>;
		Screen_Object(Text_Object, Text_Coo2D, 0, false, -Buildings_ZIndex/1000)
//		Screen_Object(Marker_Object, Text_Coo2D, 0, false, -Buildings_ZIndex/1000)
	#end
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
