// +am3 +r9 +a0.002 +ac0.99
// +am = sampling method
// +r = antialias depth
// +a = antialias threshold
// +ac = ???
// +q = quality level

#version 3.7;


// -------------------------------------------------------------
// Global settings

global_settings
{
	assumed_gamma	1
}


// -------------------------------------------------------------
// Standard includes

#include "stdinc.inc"


// -------------------------------------------------------------
// Universe

#declare feet_units			= 20;									// LDU per foot
#declare mile_units			= 5280 * feet_units;
#declare plate_size			=   32 * feet_units;
#declare earth_fudge		= 1/10;									// precision issues in POV-Ray necessitate this
#declare earth_radius		= 3959 * mile_units * earth_fudge;
#declare earth_circum		= floor(2 * pi * earth_radius / plate_size) * plate_size;
#declare earth_radius		= earth_circum/2/pi;
#declare longitude_div		= earth_circum/plate_size;
#declare sun_fudge			= 1/1000000 * earth_fudge;			// precision issues in POV-Ray necessitate this
#declare sun_radius			=   432288 * mile_units * sun_fudge;	//   432288 * 5280 * 20 =   45649612800 units
#declare sun_distance		= 92960000 * mile_units * sun_fudge;	// 92960000 * 5280 * 20 = 9816576000000 units
#declare cloud_min_radius	=  1 * mile_units * earth_fudge;
#declare cloud_max_radius	=  2 * mile_units * earth_fudge;
#declare atmos_max_radius	= 10 * mile_units * earth_fudge;


// -------------------------------------------------------------
// Vectors

#macro vanglesXY(tVec2)
	#local fSgnX = 1;
	#local fSgnY = 1;
	#local tPrjB1 = vnormalize(<tVec2.x, 0, tVec2.z>);

	#if (tPrjB1.x != 0)
		#local fSgnX = tPrjB1.x/abs(tPrjB1.x) * -1;
	#end

	#local tPrjB1 = <tPrjB1.x, tPrjB1.y, max(min(tPrjB1.z,1),-1)>;
	#local fAngY = acosd(tPrjB1.z) * fSgnX;
	#local tPrjB2 = vnormalize(vrotate(tVec2, <0, fAngY, 0>));

	#if (tPrjB2.y != 0)
		#local fSgnY = tPrjB2.y/abs(tPrjB2.y);
	#end

	#local tPrjB2 = <tPrjB2.x, tPrjB2.y, max(min(tPrjB2.z,1),-1)>;
	#local fAngX = acosd(tPrjB2.z) * fSgnY;
	<fAngX, (fAngY + 180) * -1, 0>
#end


#macro tflip(in_vector)
	transform
	{
		rotate <+000,+000,+180>
		rotate in_vector + <+180,+000,+000>
	}
#end


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

#ifndef (Use_Radiosity)		#declare Use_Radiosity		=false;		#end				// turns radiosity on/off, recommend leaving this off, must decrease diffuse if it is on
#ifndef (Use_Rad_Setting)	#declare Use_Rad_Setting	= 8;		#end				// radiosity presets, see chart above
#ifndef (Use_Uber)			#declare Use_Uber			=false;		#end				// toggle blurred reflections method depending on whether you are using POV-Ray or UberPOV
#ifndef (Use_SSLT)			#declare Use_SSLT			=false;		#end				// subsurface light transport, only present in "materials_ldc_defs_clipka.inc" and "materials_ldc_defs_mjh.inc" currently
#ifndef (Use_Guides)		#declare Use_Guides			=false;		#end				// axis markers, street sector markers, mainly for maps
#ifndef (Use_Floor_Cutout)	#declare Use_Floor_Cutout	=false;		#end				// cut a hole in the ground plane to fit the city into?
#ifndef (Use_Floor_Check)	#declare Use_Floor_Check	= 0;		#end				// 0 = none, 1 = flat (cube) checkered floor, 2 = curved (sphere) checker floor
#ifndef (Use_Sky)			#declare Use_Sky			=false;		#end				// colored sky sphere
#ifndef (Use_Shadows)		#declare Use_Shadows		=false;		#end				// turns sprite shadows on/off, recommend turning this off for walls that are always covered by rooves, only used for Datsville RPG sprites
#ifndef (Use_BlurRef)		#declare Use_BlurRef		=false;		#end				// slow, blurred surface reflections, requires camera focal blur or antialiasing as well, or else the textures will look really grainy
#ifndef (Use_BlurTyp)		#declare Use_BlurTyp		= 1;		#end				// type of blurred reflections, method 1 requires focal blur and lots of antialiasing or the texture will look grainy, method 3 does not require these things but is much much slower, method 2 lies somewhere in between
#ifndef (Use_BlurSmp)		#declare Use_BlurSmp		= 8;		#end				// number of samples in blurred reflections
#ifndef (Use_BlurAmt)		#declare Use_BlurAmt		= 1/32;		#end				// amount of surface reflection blurring
#ifndef (Use_BlurFoc)		#declare Use_BlurFoc		=false;		#end				// slow, camera focal blur
#ifndef (Use_Clouds)		#declare Use_Clouds			=false;		#end				// does not include haze yet
#ifndef (Use_Floor_Trans)	#declare Use_Floor_Trans	= <0,0,0>;	#end				// translate the floor up, down or sideways by this amount
#ifndef (Use_Uber)			#declare Use_Uber			=false;		#end				// use uberpov instead of regular povray
#ifndef (Use_Area_Light)	#declare Use_Area_Light		=false;		#end				// turn the sun into an area light vs regular point light, spot light or parallel light
#ifndef (Use_Seed)			#declare Use_Seed			= seed(08763);		#end		// seed for some random stuff


// -------------------------------------------------------------
// New L3P settings

#ifndef (L3Version)			#declare L3Version		= 1.4;			#end
#ifndef (L3Quality)			#declare L3Quality		= 2;			#end	// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo, 4=stud2logo
#ifndef (L3SW)				#declare L3SW			= 0.5;			#end	// Width of seam between two bricks
#ifndef (L3Studs)			#declare L3Studs		= 1;			#end	// 1=on 0=off
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
// Camera

#declare Camera_Diagonal	= cosd(45);
#declare Camera_Aspect		= image_height / image_width;
#declare Camera_Width		= 10240;	// was 7680 * 4/3
#declare Camera_Vertical	= 225;		// was 225
#declare Camera_Horizontal	= 30;
#declare Camera_Distance	= Camera_Width;
#declare Camera_Up			= -y * Camera_Diagonal * Camera_Width * Camera_Aspect;
#declare Camera_Right		= +x * Camera_Diagonal * Camera_Width;
#declare Camera_Location	= -z * Camera_Distance;
#declare Camera_Direction	= +z * Camera_Distance;
#declare Camera_LookAt		= Camera_Location + Camera_Direction;
#declare Camera_Rotate		= <-Camera_Horizontal,Camera_Vertical,0,>;
#declare Camera_Scale		= 4;
#declare Camera_Translate	= <0,0,0>;
#declare Camera_Transform = transform
{
	rotate		Camera_Rotate
	scale		Camera_Scale
	translate	Camera_Translate
}

camera
{
	orthographic
	up			Camera_Up
	right		Camera_Right
	location	Camera_Location
	direction	Camera_Direction
	transform {Camera_Transform}
}

#declare Camera_Location	= vtransform(Camera_Location,Camera_Transform);
#declare Camera_LookAt		= vtransform(Camera_LookAt,Camera_Transform);


// -------------------------------------------------------------
// Default textures

// diffuse should really vary depending on whether radiosity is turned on or off
#default
{
	texture
	{
		pigment { color srgb 0 }
		finish { ambient 0 diffuse 0 reflection 0 }
	}
}

#declare MJHMissingTex = texture {pigment {color srgb <1,0,1>}}
#declare MJHMissingMat = material {texture {MJHMissingTex}}

background {color srgb 1}
