// +am3 +r9 +a0.002 +j
// +a0.1 +j +ag1.0 +am2

#version 3.7;


// -------------------------------------------------------------
// Scene settings

#ifndef (Use_Radiosity)		#declare Use_Radiosity		=false;		#end				// turns radiosity on/off. (Recommend leaving this off. have to decrease diffuse if it is on.)
#ifndef (Use_Rad_Setting)	#declare Use_Rad_Setting	= 6;		#end				// radiosity presets, see "rad_def.inc" for a list of them
#ifndef (Use_SSLT)			#declare Use_SSLT			=false;		#end				// subsurface scattering, don't use this
#ifndef (Use_Uber)			#declare Use_Uber			=false;		#end				// toggle blurred reflections method depending on whether you are using POV-Ray or UberPOV
#ifndef (Use_Guides)		#declare Use_Guides			=false;		#end				// axis markers, street sector markers
#ifndef (Use_Floor_Cutout)	#declare Use_Floor_Cutout	=false;		#end				// hole in green checkered floor made to fit the town in
#ifndef (Use_Floor_Check)	#declare Use_Floor_Check	= 0;		#end				// green checkered floor, 0 = none, 1 = cube, 2 = sphere
#ifndef (Use_Sky)			#declare Use_Sky			=false;		#end				// sky sphere
#ifndef (Use_Shadows)		#declare Use_Shadows		=false;		#end				// turns shadows on/off. (Recommend turning this off for walls that are always covered by rooves.) Not used often.
#ifndef (Use_BlurRef)		#declare Use_BlurRef		=false;		#end				// blurred reflections, requires focal blur as well or else the textures will look really grainy
#ifndef (Use_BlurFoc)		#declare Use_BlurFoc		=false;		#end				// focal_blur
#ifndef (Use_Clouds)		#declare Use_Clouds			=false;		#end				// does not include haze yet
#ifndef (Use_Floor_Trans)	#declare Use_Floor_Trans	= <0,0,0>;	#end				// translate the floor up, down or sideways by this amount


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
#if (lg_quality = 3)
	#declare lg_quality = 4;
#end
#ifndef (lg_studs)		#declare lg_studs	= L3Studs;		#end


// -------------------------------------------------------------
// LeoCad settings
// This is a variable I created.

#ifndef (lc_ior)		#declare lc_ior		= L3Ior;		#end


// -------------------------------------------------------------
// Lights
// Light color should be RGB not SRGB!!

#include "CIE.inc"			// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys.inc"			// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys_constants.inc"	// http://www.ignorancia.org/en/index.php?page=Lightsys

#declare light_source_lumens		= 2;					// float
#declare light_source_temp			= Daylight(6100);			// float
#declare light_source_color			= Light_Color(light_source_temp,light_source_lumens);
#declare light_source_location		= vrotate(<0,0,-320000>, <-060,-120 + 090,+000>);

light_source
{
	light_source_location
//	rgb light_color
	rgb 1
	parallel
}


// -------------------------------------------------------------
// Camera

#declare Camera_Eye			= 0;				// 0 = normal, 1 = left eye, 2 = right eye
#declare Camera_Aspect		= image_height/image_width;
#declare Camera_Vertical	= 315;
#declare Camera_Horizontal	= 22.5;
#declare Camera_Width		= 1024*16;
#declare Camera_Distance	= 1024*16;
#declare Camera_Scale		= 1;
#declare Camera_Rotate		= <-Camera_Horizontal,Camera_Vertical,0,>;
#declare Camera_Translate	= <-320,0,+320>;
#declare Camera_Up			= -y * Camera_Width * Camera_Aspect;
#declare Camera_Right		= +x * Camera_Width;
#declare Camera_Location	= -z * Camera_Distance;
#declare Camera_Direction	= +z * Camera_Distance;
#declare Camera_LookAt		= Camera_Location + Camera_Direction;
#declare Camera_FocalPoint	= Camera_LookAt + Camera_Direction * (Camera_Scale - 1) + Camera_Translate;		// needs testing, may not work properly if Camera_LookAt is not located at the coordinate system origin
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
//		variance		1/1024
	#end
	transform {Camera_Transform}
}
#declare Camera_Location	= vtransform(Camera_Location,Camera_Transform);
#declare Camera_LookAt		= vtransform(Camera_LookAt,Camera_Transform);


//#debug concat("\ntotal_length = ",str(total_length,0,-1),"\n")
#debug concat("\nCamera_Location = <",vstr(3,Camera_Location,",",0,-1),">\n")
#debug concat("\nCamera_LookAt = <",vstr(3,Camera_LookAt,",",0,-1),">\n")
