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
		cylinder {<-10240,0,+10240>, <+10240,0,+10240>, 10}
		cylinder {<-10240,0, +5120>, <+10240,0, +5120>, 10}
		cylinder {<-10240,0,     0>, <+10240,0,     0>, 10}
		cylinder {<-10240,0, -5120>, <+10240,0, -5120>, 10}
		cylinder {<-10240,0,-10240>, <+10240,0,-10240>, 10}
		cylinder {<+10240,0,-10240>, <+10240,0,+10240>, 10}
		cylinder {< +5120,0,-10240>, < +5120,0,+10240>, 10}
		cylinder {<     0,0,-10240>, <     0,0,+10240>, 10}
		cylinder {< -5120,0,-10240>, < -5120,0,+10240>, 10}
		cylinder {<-10240,0,-10240>, <-10240,0,+10240>, 10}
		pigment {color srgb +x+z}
	}
#end


// -------------------------------------------------------------
// Checker floor
// Not used for "showcase" scenes
// May conflict with Use_Env_Mode

#declare latitude_pigment_1 = pigment
{
	radial
	color_map
	{
		[0.5 color srgb <040,066,018>/255]
		[0.5 color srgb <067,084,029>/255]
	}
	frequency longitude_div/2
}
#declare latitude_pigment_2 = pigment
{
	radial
	color_map
	{
		[0.5 color srgb <067,084,029>/255]
		[0.5 color srgb <040,066,018>/255]
	}
	frequency longitude_div/2
}

#declare longitude_pigment_1 = pigment
{
	function {f_ph(x,y,z)/pi}
	pigment_map
	{
		[0.5 latitude_pigment_1]
		[0.5 latitude_pigment_2]
	}
	frequency longitude_div/4
}

#declare longitude_pigment_2 = pigment
{
	function {f_ph(x,y,z)/pi}
	pigment_map
	{
		[0.5 latitude_pigment_2]
		[0.5 latitude_pigment_1]
	}
	frequency longitude_div/4
}

#declare radius_pigment = pigment
{
	function {f_r(x,y,z) * earth_radius/plate_size/2}
	pigment_map
	{
		[0.5 longitude_pigment_1]
		[0.5 longitude_pigment_2]
	}
}

#declare checker_sphere_pigment = pigment {radius_pigment}


#switch (Use_Floor_Check)
	// do nothing
	#case (0)
	#break
	// Flat (cube) Checkered Floor
	#case (1)
		difference
		{
			plane { -y, 0 }
			#if (Use_Floor_Cutout = 1)
				box {< -7040,-10240,-10880>,< +7040,+10240,+10240>}
			#end
			texture
			{
				pigment
				{
					checker
					pigment {color srgb <067,084,029>/255}
					pigment {color srgb <040,066,018>/255}
				}
				finish { ambient L3Ambient diffuse L3Diffuse }
				scale plate_size
			}
			translate Use_Floor_Trans
		}
	#break
	// Curved (sphere) Checker Floor
	// not much of a difference from the previous method at planet Earth scales
	#case (2)
		difference
		{
			sphere
			{
				0, 1
				scale		earth_radius
				translate	+y * earth_radius	// this is down not up!
			}
			#if (Use_Floor_Cutout = 1)
				box {< -7040,-10240,-10880>,< +7040,+10240,+10240>}
			#end
			texture
			{
				pigment {checker_sphere_pigment}
				finish { ambient L3Ambient diffuse L3Diffuse }
				rotate		+x * 090
				scale		earth_radius
				translate	+y * earth_radius	// this is down not up!
			}
			translate Use_Floor_Trans
		}
	#break
#end


// -------------------------------------------------------------
// Clouds
// Not used for "showcase" scenes
// Uses spheres not planes or boxes

#if (Use_Clouds)
	#local inner_radius = earth_radius + cloud_min_radius;
	#local outer_radius = earth_radius + cloud_max_radius;
	#local inn_out_ratio = inner_radius/outer_radius;
//	#local bound_radius = sin(acos(earth_radius/outer_radius)) * outer_radius;
	#local cloud_scale = 1000000/2 * earth_fudge;
	#local cloud_media = media
	{
		method 3
		samples 20
		scattering
		{
			2,
			color rgb 2/cloud_scale
			extinction 1
		}

		density
		{
//			wrinkles
			bozo
			color_map
			{
				[0.00 color rgb 1.00]
				[0.40 color rgb 0.80]
				[0.45 color rgb 0.00]
				[1.00 color rgb 0.00]
			}
			warp
			{
				turbulence 0.6
				lambda 4
				octaves 4
			}
			scale sqrt(cloud_scale)
			warp
			{
				turbulence 5
				lambda 4
			}
			scale sqrt(cloud_scale)
		}

		density
		{
			spherical		// spherical = 1 in the middle, 0 at the edge
			color_map
			{
				[0.00 color rgb 0.00]
				[1-(inn_out_ratio + (1-inn_out_ratio)*0.60) color rgb 1.00]
				[1-(inn_out_ratio + (1-inn_out_ratio)*0.10) color rgb 1.00]
				[1-(inn_out_ratio + (1-inn_out_ratio)*0.00) color rgb 0.00]
				[1.00 color rgb 0.00]
			}
			scale outer_radius
		}
    }
	#local cloud_sphere = difference
	{
		sphere {0, outer_radius}
		sphere {0, inner_radius}
//		bounded_by {cylinder {<0,-earth_radius,0,>, <0,-outer_radius,0,>, bound_radius}}
		hollow
		material
		{
			texture {pigment {color srgbft <1,1,1,0,1>}}
//			texture {pigment {color srgbft <1,0,0,0,0>}}
			interior
			{
				media {cloud_media}
			}
		}
		translate +y * earth_radius
	}
	#local inner_radius = earth_radius - 1;
	#local outer_radius = earth_radius + atmos_max_radius;
	#local inn_out_ratio = inner_radius/outer_radius;
//	#local bound_radius = sin(acos(earth_radius/outer_radius)) * outer_radius;
	#local atmos_scale = 100000000 * earth_fudge;
	#local atmos_media = media
	{
		scattering
		{
			1,
			color rgb 2/atmos_scale
			extinction 0.25
		}

		density
		{
			spherical		// spherical = 1 in the middle, 0 at the edge
			color_map
			{
				[0.00 color rgb 0.00]
				[1-inn_out_ratio color rgb 1.00]
				[1-inn_out_ratio color rgb 0.00]
				[1.00 color rgb 0.00]
			}
			scale outer_radius
		}
	}
	#local atmos_sphere = difference
	{
		sphere {0, outer_radius}
		sphere {0, inner_radius}
//		bounded_by {cylinder {<0,-earth_radius,0,>, <0,-outer_radius,0,>, bound_radius}}
		hollow
		material
		{
			texture {pigment {color srgbft <1,1,1,0,1>}}
//			texture {pigment {color srgbft <1,1,0,0,0>}}
			interior
			{
				media {atmos_media}
			}
		}
		translate +y * earth_radius
	}
	object {cloud_sphere}
	object {atmos_sphere}		// precision issues in POV-Ray make this not work
#end


// -------------------------------------------------------------
// Sky
// Not used for "showcase" scenes

#if (Use_Sky = 1)
	#include "SkySim.inc"			// http://news.povray.org/povray.binaries.scene-files/thread/%3C51b1c936%40news.povray.org%3E/?mtop=387744
	// SunPos, UpVector, Turbidity, ExposureFactor
	SkySim(light_source_location, -y, 2, 1e-5 * 5)			// not sure what ExposureFactor should actually be
#end
