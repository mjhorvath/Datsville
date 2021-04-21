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
// 
// +r9 +a0.002 +j +am3
// +r4 +a0.1 +j +am2 +ag1.0
// +r4 +a0.1 +j +am2 +wt3


#version 3.7;


// -------------------------------------------------------------
// Scene settings

//Use_Rad_Setting:
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

#ifndef (Use_Radiosity)		#declare Use_Radiosity		=false;		#end				// slow, turns radiosity on/off, recommend leaving this off, must decrease diffuse if it is on
#ifndef (Use_Rad_Setting)	#declare Use_Rad_Setting	= 8;		#end				// radiosity presets, see chart above
#ifndef (Use_Uber)			#declare Use_Uber			=false;		#end				// toggle blurred reflections method depending on whether you are using POV-Ray or UberPOV
#ifndef (Use_SSLT)			#declare Use_SSLT			=false;		#end				// subsurface light transport, only supported by "materials_ldc_defs_clipka.inc" and "materials_ldc_defs_mjh.inc" currently
#ifndef (Use_Guides)		#declare Use_Guides			=false;		#end				// axis markers, street sector markers, mainly for maps
#ifndef (Use_Floor_Cutout)	#declare Use_Floor_Cutout	= true;		#end				// cut a hole in the ground plane to fit the city into?
#ifndef (Use_Floor_Check)	#declare Use_Floor_Check	= 1;		#end				// 0 = none, 1 = Flat (cube) Checkered Floor, 2 = Curved (sphere) Checker Floor
#ifndef (Use_Sky)			#declare Use_Sky			= true;		#end				// colored sky sphere
#ifndef (Use_Shadows)		#declare Use_Shadows		=false;		#end				// turns shadows on/off, recommend turning this off for walls that are always covered by rooves, not used often
#ifndef (Use_BlurRef)		#declare Use_BlurRef		=false;		#end				// slow, blurred surface reflections, requires camera focal blur or antialiasing as well, or else the textures will look really grainy
#ifndef (Use_BlurTyp)		#declare Use_BlurTyp		= 1;		#end				// type of blurred reflections, method 1 requires focal blur and lots of antialiasing or the texture will look grainy, method 3 does not require these things but is much much slower, method 2 lies somewhere in between
#ifndef (Use_BlurSmp)		#declare Use_BlurSmp		= 8;		#end				// number of samples in blurred reflections
#ifndef (Use_BlurAmt)		#declare Use_BlurAmt		= 1/32;		#end				// amount of surface reflection blurring
#ifndef (Use_BlurFoc)		#declare Use_BlurFoc		=false;		#end				// slow, camera focal blur
#ifndef (Use_Clouds)		#declare Use_Clouds			=false;		#end				// very slow, looks like crap, assumes Use_Floor_Check is set to 2
#ifndef (Use_Floor_Trans)	#declare Use_Floor_Trans	= <0,0,0>;	#end				// translate the floor up, down or sideways by this amount
#ifndef (Use_Uber)			#declare Use_Uber			=false;		#end				// use uberpov instead of regular povray
#ifndef (Use_Area_Light)	#declare Use_Area_Light		=false;		#end				// turn the sun into an area light vs regular point light, spot light or parallel light
#ifndef (Use_Seed)			#declare Use_Seed			= seed(08763);		#end		// seed for some random stuff


// -------------------------------------------------------------
// New L3P settings

#ifndef (L3Version)			#declare L3Version		= 1.4;			#end
#ifndef (L3Quality)			#declare L3Quality		= 2;			#end	// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo, 4=stud2logo
#ifndef (L3SW)				#declare L3SW			= 0.5;			#end	// Width of seam between two bricks
#ifndef (L3Studs)			#declare L3Studs		= 0;			#end	// 1=on 0=off
#ifndef (L3Bumps)			#declare L3Bumps		= 0;			#end	// 1=on 0=off
#ifndef (L3Ambient)			#declare L3Ambient		= 0.1;			#end	// was 0.4
#ifndef (L3Diffuse)			#declare L3Diffuse		= 0.9;			#end	// was 0.4
#ifndef (L3Ior)				#declare L3Ior			= 1.25;			#end	// I think clipka said this should be 1.6
#ifndef (L3NormalBumps)		#declare L3NormalBumps	= normal { bumps 0.01 scale 20 }	#end
#ifndef (L3NormalSlope)		#declare L3NormalSlope	= normal { bumps 0.3 scale 0.5 }	#end
#ifndef (L3Phong)			#declare L3Phong		= 0.5;			#end	// was 0.5
#ifndef (L3PhongSize)		#declare L3PhongSize	= 40;			#end	// was 40
#ifndef (L3Reflection)		#declare L3Reflection	= 0.04;			#end	// was 0.08
#declare L3SWT = (L3SW ? L3SW : 0.001);  // At least a small seam when transparent


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
// LDView settings

#ifndef (LDXQual)			#declare LDXQual		= L3Quality;	#end
#ifndef (LDXSW)				#declare LDXSW			= L3SW;			#end
#ifndef (LDXStuds)			#declare LDXStuds		= L3Studs;		#end
#ifndef (LDXRefls)			#declare LDXRefls		= 1;			#end
#ifndef (LDXShads)			#declare LDXShads		= 1;			#end
#ifndef (LDXAmb)			#declare LDXAmb			= L3Ambient;	#end
#ifndef (LDXDif)			#declare LDXDif			= L3Diffuse;	#end
#ifndef (LDXRefl)			#declare LDXRefl		= L3Reflection;	#end
#ifndef (LDXPhong)			#declare LDXPhong		= L3Phong;		#end
#ifndef (LDXPhongS)			#declare LDXPhongS		= L3PhongSize;	#end
#ifndef (LDXTRefl)			#declare LDXTRefl		= 0.2;			#end
#ifndef (LDXTFilt)			#declare LDXTFilt		= 0.85;			#end
#ifndef (LDXIoR)			#declare LDXIoR			= L3Ior;		#end
#ifndef (LDXRubberRefl)		#declare LDXRubberRefl	= 0;			#end
#ifndef (LDXRubberPhong)	#declare LDXRubberPhong	= 0.1;			#end
#ifndef (LDXRubberPhongS)	#declare LDXRubberPhongS	= 10;		#end
#ifndef (LDXChromeRefl)		#declare LDXChromeRefl	= 0.85;			#end
#ifndef (LDXChromeBril)		#declare LDXChromeBril	= 5;			#end
#ifndef (LDXChromeSpec)		#declare LDXChromeSpec	= 0.8;			#end
#ifndef (LDXChromeRough)	#declare LDXChromeRough	= 0.01;			#end
#ifndef (LDXSkipLight1)		#declare LDXSkipLight1	= true;			#end
#ifndef (LDXSkipLight2)		#declare LDXSkipLight2	= true;			#end
#ifndef (LDXSkipLight3)		#declare LDXSkipLight3	= true;			#end
#ifndef (LDXSkipCamera)		#declare LDXSkipCamera	= true;			#end
#ifndef (LDXFloor)			#declare LDXFloor		=false;			#end
//#ifndef (LDXFloorLoc)		#declare LDXFloorLoc	= LDXMaxY;		#end	// Floor location. (Dependent on floor axis; MAX_Y is bottom of model)
//#ifndef (LDXFloorAxis)		#declare LDXFloorAxis	= y;			#end	// Floor axis (x, y, or z)
//#ifndef (LDXFloorR)			#declare LDXFloorR		= 0.8;			#end	// Floor Red
//#ifndef (LDXFloorG)			#declare LDXFloorG		= 0.8;			#end	// Floor Green
//#ifndef (LDXFloorB)			#declare LDXFloorB		= 0.8;			#end	// Floor Blue
//#ifndef (LDXFloorAmb)		#declare LDXFloorAmb	= 0.4;			#end	// Floor Ambient
//#ifndef (LDXFloorDif)		#declare LDXFloorDif	= 0.4;			#end	// Floor Diffuse
#ifndef (LDXBackground)		#declare LDXBackground	=false;			#end	// I invented this
#ifndef (LDXBgR)			#declare LDXBgR			= 0.752941;		#end	// Background Red
#ifndef (LDXBgG)			#declare LDXBgG			= 0.752941;		#end	// Background Green
#ifndef (LDXBgB)			#declare LDXBgB			= 0.752941;		#end	// Background Blue


// -------------------------------------------------------------
// LDCad settings

#if (L3SW > 0)
	#ifndef (doSeams)	#declare doSeams	= true;		#end	// This will fake seams in between parts by slightly scaling them.
#else
	#ifndef (doSeams)	#declare doSeams	=false;		#end	// This will fake seams in between parts by slightly scaling them.
#end
#ifndef (seamSize)		#declare seamSize	= L3SW;		#end	// Width of seams.
#ifndef (doFloor)		#declare doFloor	=false;		#end
#ifndef (doSky)			#declare doSky		=false;		#end


// -------------------------------------------------------------
// LGEO settings

#ifndef (lg_quality)	#declare lg_quality	= L3Quality;	#end
#if (lg_quality = 3)
	#declare lg_quality = 4;
#end
#ifndef (lg_studs)		#declare lg_studs	= L3Studs;		#end


// -------------------------------------------------------------
// LeoCad settings

#ifndef (lc_ior)		#declare lc_ior		= L3Ior;		#end	// This is a variable I created.


// -------------------------------------------------------------
// New lights
// Sun is not at realistic distance and is not an area light like it should be.
// Could use "sunpos.inc" here too to determine a correct position and angle.
// Light color should be RGB not SRGB!!
// Should turn this into an area light too.

#include "CIE.inc"					// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys.inc"				// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys_constants.inc"	// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "sunpos.inc"

#declare light_source_lumens	= 3;				// float
#declare light_source_temp		= Daylight(6100);	// float
#declare light_source_color		= Light_Color(light_source_temp,light_source_lumens);	// float
#declare light_source_location	= <1,-1,1> * vnormalize(SunPos(2018, 6, 6, 11, 00, -75, 39.766667, -86.15));	// Year, Month, Day, Hour, Minute, Lstm, LAT, LONG
#declare light_source_rotation	= <-Al,Az+180,0>;

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
		translate	-z * sun_distance
		rotate		light_source_rotation
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
		translate	-z * sun_distance
		rotate		light_source_rotation
	}
#end


// -------------------------------------------------------------
// Old lights
/*
#declare light_source_lumens	= 3;					// float
#declare light_source_temp		= Daylight(6100);			// float
#declare light_source_color		= Light_Color(light_source_temp,light_source_lumens);
#declare light_source_location	= vrotate(<0,0,-320000>, <-060,-120 + 090,+000>);

// Lights:
light_source
{
	light_source_location
	light_source_color
	parallel
}
*/


// -------------------------------------------------------------
// New camera

#declare Camera_Eye			= 0;				// 0 = normal, 1 = left eye, 2 = right eye
#declare Camera_Diagonal	= cosd(45);
#declare Camera_Aspect		= image_height/image_width;
#declare Camera_Vertical	= 315;
#declare Camera_Horizontal	= 22.5;		// was 22.5
#declare Camera_Width		= 640*16*Camera_Diagonal;	// was 1024*16
#declare Camera_Distance	= 640*16*Camera_Diagonal;	// was 1024*16
#declare Camera_Scale		= 2;				// 1/4 = closeup
#declare Camera_Rotate		= <-Camera_Horizontal,Camera_Vertical,0,>;
#declare Camera_Translate	= <+1920,0,-1920>;	// <-320,0,+320> = the center of the JJ memorial
#declare Camera_Up			= -y * Camera_Width * Camera_Aspect;
#declare Camera_Right		= +x * Camera_Width;
#declare Camera_Location	= -z * Camera_Distance;
#declare Camera_Direction	= +z * Camera_Distance;
#declare Camera_LookAt		= Camera_Location + Camera_Direction;
#declare Camera_FocalPoint	= Camera_LookAt + Camera_Direction * (Camera_Scale - 1) + Camera_Translate;		// needs lots of testing, may not work properly if Camera_LookAt is not located at the coordinate system origin
#declare Camera_BlurSamples	= 16;					// was 16
#declare Camera_Aperture	= 16 * Camera_Scale;	// was 16
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
//		variance		1/1024
	#end
	transform {Camera_Transform}
}

#declare Camera_Location	= vtransform(Camera_Location,Camera_Transform);
#declare Camera_LookAt		= vtransform(Camera_LookAt,Camera_Transform);


// -------------------------------------------------------------
// Old camera
/*
#declare Camera_Diagonal	= cosd(45);
#declare Camera_Aspect		= image_height / image_width;
#declare Camera_Width		= 2048;
#declare Camera_Vertical	= 315;
#declare Camera_Horizontal	= 20;
#declare Camera_Distance	= Camera_Width;
#declare Camera_Scale		= 4;
#declare Camera_Translate	= <+1280,0,-1280>;
#declare Camera_Up			= -y * Camera_Diagonal * Camera_Width * Camera_Aspect;
#declare Camera_Right		= +x * Camera_Diagonal * Camera_Width;
#declare Camera_Location	= -z * Camera_Distance;
#declare Camera_Direction	= +z * Camera_Distance/2;		// +z * Camera_Distance;
#declare Camera_LookAt		= Camera_Location + Camera_Direction;
#declare Camera_Rotate		= <-Camera_Horizontal,Camera_Vertical,0,>;
camera
{
//	orthographic
	up			Camera_Up
	right		Camera_Right
	location	Camera_Location
	direction	Camera_Direction
	rotate		Camera_Rotate
	scale		Camera_Scale
	translate	Camera_Translate
}
#declare Camera_Location	= Camera_Scale * (Camera_Translate + vrotate(Camera_Location,Camera_Rotate));
#declare Camera_LookAt		= Camera_Scale * (Camera_Translate + vrotate(Camera_LookAt,Camera_Rotate));
*/
