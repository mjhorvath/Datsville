// +kfi0 +kff3 +ki0 +kf1 +kc
// +am3 +r9 +a0.002 +ac0.99
// +am = Sampling_Method
// +r = Antialias_Depth
// +a = Antialias_Threshold
// +j = jitter
// +ag = Antialias_Gamma
// +a0.1 +j +am2 +r4

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

#ifndef (Use_Radiosity)		#declare Use_Radiosity		= true;		#end				// turns radiosity on/off, recommend leaving this off, must decrease diffuse if it is on
#ifndef (Use_Rad_Setting)	#declare Use_Rad_Setting	= 5;		#end				// radiosity presets, see chart above
#ifndef (Use_Uber)			#declare Use_Uber			=false;		#end				// toggle blurred reflections method depending on whether you are using POV-Ray or UberPOV
#ifndef (Use_SSLT)			#declare Use_SSLT			=false;		#end				// subsurface light transport, only supported by "materials_ldc_defs_clipka.inc" and "materials_ldc_defs_mjh.inc" currently
#ifndef (Use_Guides)		#declare Use_Guides			=false;		#end				// axis markers, street sector markers, mainly for maps
#ifndef (Use_Floor_Cutout)	#declare Use_Floor_Cutout	=false;		#end				// cut a hole in the ground plane to fit the city into?
#ifndef (Use_Floor_Check)	#declare Use_Floor_Check	=false;		#end				// 0 = none, 1 = Flat (cube) Checkered Floor, 2 = Curved (sphere) Checker Floor
#ifndef (Use_Sky)			#declare Use_Sky			=false;		#end				// sky sphere
#ifndef (Use_Shadows)		#declare Use_Shadows		=false;		#end				// turns shadows on/off, recommend turning this off for walls that are always covered by rooves, not used often
#ifndef (Use_BlurRef)		#declare Use_BlurRef		= true;		#end				// blurred surface reflections, requires camera focal blur or antialiasing as well, or else the textures will look really grainy
#ifndef (Use_BlurTyp)		#declare Use_BlurTyp		= 1;		#end				// type of blurred reflections, method 1 requires focal blur and lots of antialiasing or the texture will look grainy, method 3 does not require these things but is much much slower, method 2 lies somewhere in between
#ifndef (Use_BlurSmp)		#declare Use_BlurSmp		= 8;		#end				// number of samples in blurred reflections
#ifndef (Use_BlurAmt)		#declare Use_BlurAmt		= 1/32;		#end				// amount of surface reflection blurring
#ifndef (Use_Env_Mode)		#declare Use_Env_Mode		= 4;		#end				// 1 = black, 2 = white, 3 = gray and blue with studs, 4 = light gray with dotted floor; this setting will conflict with Use_Floor_Check, Use_Floor_Cutout and Use_Sky, so don't enable all of them at the same time
#ifndef (Use_LGEO)			#declare Use_LGEO			= true;		#end				// can't remember what this is for
#ifndef (Use_BlurFoc)		#declare Use_BlurFoc		= true;		#end				// camera focal_blur
#ifndef (Use_Clouds)		#declare Use_Clouds			=false;		#end				// does not include haze yet
#ifndef (Use_Floor_Trans)	#declare Use_Floor_Trans	= <0,0,0>;	#end				// translate the floor up, down or sideways by this amount
#ifndef (Use_Area_Light)	#declare Use_Area_Light		= true;		#end				// turn the sun into an area light vs regular point light, spot light or parallel light
#ifndef (Use_Seed)			#declare Use_Seed			= seed(08763);		#end		// seed for some random stuff
#declare Stud_Floor_Size = 400;


// -------------------------------------------------------------
// Newer L3P settings

#ifndef (L3Version)			#declare L3Version		= 1.4;		#end
#ifndef (L3Quality)			#declare L3Quality		= 3;		#end	// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo, 4=stud2logo
#ifndef (L3SW)				#declare L3SW			= 0.5;		#end	// Width of seam between two bricks
#ifndef (L3Studs)			#declare L3Studs		= 1;		#end	// 1=on 0=off
#ifndef (L3Bumps)			#declare L3Bumps		= 1;		#end	// 1=on 0=off
#ifndef (L3Ambient)			#declare L3Ambient		= 0.1;		#end	// was 0.4
#ifndef (L3Diffuse)			#declare L3Diffuse		= 0.9;		#end	// was 0.4
#ifndef (L3Ior)				#declare L3Ior			= 1.25;		#end
#ifndef (L3NormalBumps)		#declare L3NormalBumps	= normal { bumps 0.01 scale 20 }	#end
#ifndef (L3NormalSlope)		#declare L3NormalSlope	= normal { bumps 0.3 scale 0.5 }	#end
#ifndef (L3Phong)			#declare L3Phong		= 0.5;		#end
#ifndef (L3PhongSize)		#declare L3PhongSize	= 40;		#end
#ifndef (L3Reflection)		#declare L3Reflection	= 0.04;		#end	// was 0.08
#declare L3SWT = (L3SW ? L3SW : 0.001);  // At least a small seam when transparent


// -------------------------------------------------------------
// Older L3P settings

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
