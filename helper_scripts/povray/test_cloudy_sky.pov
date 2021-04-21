// +am3 +r9 +a0.002 +j
// +a0.1 +j +ag1.0 +am2 +r4
// +r4 +am2 +a0.1 +j
// +r4 +a0.1 +j +am2 +wt3

#version 3.7;

#include "settings_common_before.inc"


// -------------------------------------------------------------
// Standard includes

#include "stdinc.inc"


// -------------------------------------------------------------
// Scene settings

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

#ifndef (Use_Radiosity)		#declare Use_Radiosity		=true;		#end				// slow, turns radiosity on/off. (Recommend leaving this off. have to decrease diffuse if it is on.)
#ifndef (Use_Rad_Setting)	#declare Use_Rad_Setting	=8;			#end				// radiosity presets, see "rad_def.inc" for a list of them
#ifndef (Use_SSLT)			#declare Use_SSLT			=false;		#end				// subsurface scattering, don't use this
#ifndef (Use_Guides)		#declare Use_Guides			=false;		#end				// axis markers, street sector markers, mainly for maps
#ifndef (Use_Floor_Cutout)	#declare Use_Floor_Cutout	=false;		#end				// hole in green checkered floor made to fit the town in
#ifndef (Use_Floor_Check)	#declare Use_Floor_Check	=2;			#end				// green checkered floor, 0 = none, 1 = cube, 2 = sphere
#ifndef (Use_Sky)			#declare Use_Sky			=true;		#end				// colored sky sphere
#ifndef (Use_Shadows)		#declare Use_Shadows		=false;		#end				// turns shadows on/off, recommend turning this off for walls that are always covered by rooves, not used often
#ifndef (Use_BlurRef)		#declare Use_BlurRef		=true;		#end				// slow, blurred surface reflections, requires camera focal blur or antialiasing as well, or else the textures will look really grainy
#ifndef (Use_BlurFoc)		#declare Use_BlurFoc		=true;		#end				// slow, camera focal blur
#ifndef (Use_Clouds)		#declare Use_Clouds			=true;		#end				// slow, looks crappy
#ifndef (Use_Floor_Trans)	#declare Use_Floor_Trans	=<0,52,0>;	#end				// translate the floor up, down or sideways by this amount
#ifndef (Use_Uber)			#declare Use_Uber			=false;		#end				// use uberpov instead of regular povray
#ifndef (Use_Area_Light)	#declare Use_Area_Light		=true;		#end				// turn the sun into an area light vs point light or parallel light


// -------------------------------------------------------------
// New L3P settings

#ifndef (L3Version)			#declare L3Version		= 1.4;			#end
#ifndef (L3Quality)			#declare L3Quality		= 2;			#end	// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo, 4=stud2logo
#ifndef (L3SW)				#declare L3SW			= 0.5;			#end	// Width of seam between two bricks
#ifndef (L3Studs)			#declare L3Studs		= 1;			#end	// 1=on 0=off
#ifndef (L3Bumps)			#declare L3Bumps		= 1;			#end	// 1=on 0=off
#ifndef (L3Ambient)			#declare L3Ambient		= 0.1;			#end	// was 0.4
#ifndef (L3Diffuse)			#declare L3Diffuse		= 0.9;			#end	// was 0.4
#ifndef (L3Ior)				#declare L3Ior			= 1.25;			#end
#ifndef (L3NormalBumps)		#declare L3NormalBumps	= normal { bumps 0.01 scale 20 }	#end
#ifndef (L3NormalSlope)		#declare L3NormalSlope	= normal { bumps 0.3 scale 0.5 }	#end
#ifndef (L3Phong)			#declare L3Phong		= 0.5;			#end
#ifndef (L3PhongSize)		#declare L3PhongSize	= 40;			#end
#ifndef (L3Reflection)		#declare L3Reflection	= 0.04;			#end	// was 0.08


// -------------------------------------------------------------
// Old L3P settings

#ifndef (QUAL)				#declare QUAL			= L3Quality;		#end		// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo
#ifndef (SW)				#declare SW				= L3SW;				#end		// Width of seam between two bricks
#ifndef (STUDS)				#declare STUDS			= L3Studs;			#end		// 1=on 0=off
#ifndef (BUMPS)				#declare BUMPS			= L3Bumps;			#end		// 1=on 0=off
#ifndef (BUMPNORMAL)		#declare BUMPNORMAL		= L3NormalBumps;	#end
#ifndef (AMB)				#declare AMB			= L3Ambient;		#end
#ifndef (DIF)				#declare DIF			= L3Diffuse;		#end


// -------------------------------------------------------------
// LDCad settings

#if (L3SW > 0)
	#ifndef (doSeams)	#declare doSeams	= true;		#end	//This will fake seams in between parts by slightly scaling them.
#else
	#ifndef (doSeams)	#declare doSeams	=false;		#end	//This will fake seams in between parts by slightly scaling them.
#end
#ifndef (seamSize)		#declare seamSize	= L3SW;		#end	//Width of seams.
#ifndef (doFloor)		#declare doFloor	=false;		#end
#ifndef (doSky)			#declare doSky		=false;		#end


// -------------------------------------------------------------
// LGEO settings

#ifndef (lg_quality)	#declare lg_quality	= L3Quality;	#end
#ifndef (lg_studs)		#declare lg_studs	= L3Studs;		#end


// -------------------------------------------------------------
// Global settings

global_settings
{
	assumed_gamma	1
}






// -------------------------------------------------------------
// Lights
// Sun is not at realistic distance and is not an area light like it should be.
// Could use "sunpos.inc" here too to determine a correct position and angle.
// Light color should be RGB not SRGB!!

#include "CIE.inc"					// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys.inc"				// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys_constants.inc"	// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "sunpos.inc"

#declare light_source_lumens	= 3;				// float
#declare light_source_temp		= Daylight(6100);	// float
#declare light_source_color		= Light_Color(light_source_temp,light_source_lumens);	// float
#declare light_source_location	= <1,-1,1> * vnormalize(SunPos(2018, 3, 6, 12, 0, -75, 43.2087409, -71.7123404));	// Year, Month, Day, Hour, Minute, Lstm, LAT, LONG
//#declare light_source_location	= vrotate(<0,0,-sun_distance>, <-060,-060,+000>);			// needs to be far enough above the clouds to cast shadows, need to test with <-075, -075, +000>
#declare light_source_rotation	= <-Al,Az+180,0>;

#debug "\n"
#debug concat("angles = ", vstr(3, light_source_rotation, ",", 0, -1), "\n")
#debug "\n"

#if (Use_Area_Light = false)
	light_source
	{
		<0,0,0>
		rgb light_source_color
		looks_like
		{
			sphere
			{
				<0,0,0>, sun_radius
				pigment {color rgb light_source_color}
				finish {emission 1}
			}
		}
		translate -z * sun_distance
		rotate light_source_rotation
		parallel
		point_at <0,0,0>
	}
#else
	light_source
	{
		<0,0,0>
		rgb light_source_color
		area_light
		x * sun_radius, y * sun_radius, 3, 3
		circular
		orient
		looks_like
		{
			sphere
			{
				<0,0,0>, sun_radius
				pigment {color rgb light_source_color}
				finish {emission 1}
			}
		}
		translate -z * sun_distance
		rotate light_source_rotation
	}
#end

/*
// -------------------------------------------------------------
// Camera

#declare Camera_Eye			= 0;				// 0 = normal, 1 = left eye, 2 = right eye
#declare Camera_Aspect		= image_height/image_width;
#declare Camera_Vertical	= 315;
#declare Camera_Horizontal	= 0;
#declare Camera_Width		= 1024*16;
#declare Camera_Distance	= 1024*16;
#declare Camera_Scale		= 1/4;				// closeup = 1/4
#declare Camera_Rotate		= <-Camera_Horizontal,Camera_Vertical,0,>;
#declare Camera_Translate	= <-320,-320,+320>;
#declare Camera_Up			= -y * Camera_Width * Camera_Aspect;
#declare Camera_Right		= +x * Camera_Width;
#declare Camera_Location	= -z * Camera_Distance;
#declare Camera_Direction	= +z * Camera_Distance;
#declare Camera_LookAt		= Camera_Location + Camera_Direction;
#declare Camera_FocalPoint	= Camera_LookAt + Camera_Direction * (Camera_Scale - 1) + Camera_Translate;		// needs lots of testing, may not work properly if Camera_LookAt is not located at the coordinate system origin
#declare Camera_BlurSamples	= 16;					// was 16
#declare Camera_Aperture	= 32 * Camera_Scale;	// was 16
#declare Camera_Transform = transform
{
	#switch (Camera_Eye)
		// do nothing
		#case (0)
		#break
		// left eye
		#case (1)
//			translate -x * 100
			rotate +y * 2.5
		#break
		// right eye
		#case (2)
//			translate +x * 100
			rotate -y * 2.5
		#break
	#end
	scale		Camera_Scale
	rotate		Camera_Rotate
	translate	Camera_Translate
}
camera
{
//	orthographic
	perspective
	up				Camera_Up
	right			Camera_Right
	location		Camera_Location
	direction		Camera_Direction
	#if (Use_BlurFoc = true)
		focal_point 	Camera_FocalPoint
		aperture		Camera_Aperture
		blur_samples	Camera_BlurSamples
	#end
	transform {Camera_Transform}
}
#declare Camera_Location	= vtransform(Camera_Location,Camera_Transform);
#declare Camera_LookAt		= vtransform(Camera_LookAt,Camera_Transform);
*/

camera
{
	location		<0,0,0>
	direction		+z * 2
	up				-y * 2
	right			+x * 2 * image_width/image_height
	transform {tflip(light_source_rotation*<1/2,1,1>)}
	translate -y * 24
}


#include "settings_common_after.inc"
