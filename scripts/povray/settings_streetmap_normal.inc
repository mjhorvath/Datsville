// +KFI0 +KFF3 +KI0.0 +KF1.0 +KC
// +KFI0 +KFF7 +KI0.0 +KF1.0 +KC

#version 3.7;


// -------------------------------------------------------------
// Scene settings

#ifndef (Use_Radiosity)		#declare Use_Radiosity		= true;		#end				// turns radiosity on/off. (Recommend leaving this off. have to decrease diffuse if it is on.)
#ifndef (Use_Rad_Setting)	#declare Use_Rad_Setting	= 8;		#end
#ifndef (Use_SSLT)			#declare Use_SSLT			=false;		#end				// too slow, not needed for most parts
#ifndef (Use_Uber)			#declare Use_Uber			=false;		#end				// toggle blurred reflections method depending on whether you are using POV-Ray or UberPOV
#ifndef (Use_Guides)		#declare Use_Guides			=false;		#end
#ifndef (Use_Floor_Cutout)	#declare Use_Floor_Cutout	= true;		#end
#ifndef (Use_Floor_Check)	#declare Use_Floor_Check	= true;		#end
#ifndef (Use_Sky)			#declare Use_Sky			= true;		#end				// sky sphere
#ifndef (Use_Shadows)		#declare Use_Shadows		=false;		#end				// turns shadows on/off. (Recommend turning this off for walls that are always covered by rooves.) Not used often.
#ifndef (Use_BlurRef)		#declare Use_BlurRef		=false;		#end				// too slow
#ifndef (Use_BlurTyp)		#declare Use_BlurTyp		= 1;		#end				// type of blurred reflections, method 1 requires focal blur and lots of antialiasing or the texture will look grainy, method 3 does not require these things but is much much slower, method 2 lies somewhere in between
#ifndef (Use_BlurSmp)		#declare Use_BlurSmp		= 8;		#end				// number of samples in blurred reflections
#ifndef (Use_BlurAmt)		#declare Use_BlurAmt		= 1/32;		#end				// amount of surface reflection blurring
#ifndef (Use_BlurFoc)		#declare Use_BlurFoc		=false;		#end				// focal_blur
#ifndef (Use_Clouds)		#declare Use_Clouds			=false;		#end				// does not include haze yet
#ifndef (Use_Floor_Trans)	#declare Use_Floor_Trans	= <0,0,0>;	#end				// translate the floor up, down or sideways by this amount
#ifndef (Use_Uber)			#declare Use_Uber			=false;		#end				// use uberpov instead of regular povray
#ifndef (Use_Area_Light)	#declare Use_Area_Light		= true;		#end				// turn the sun into an area light vs regular point light, spot light or parallel light
#ifndef (Use_Seed)			#declare Use_Seed			= seed(08763);		#end		// seed for some random stuff


// -------------------------------------------------------------
// New L3P settings

#ifndef (L3Version)			#declare L3Version		= 1.4;		#end
#ifndef (L3Quality)			#declare L3Quality		= 2;		#end	// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo, 4=stud2logo
#ifndef (L3SW)				#declare L3SW			= 0.5;		#end	// Width of seam between two bricks
#ifndef (L3Studs)			#declare L3Studs		= 0;		#end	// 1=on 0=off
#ifndef (L3Bumps)			#declare L3Bumps		= 0;		#end	// 1=on 0=off
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
#ifndef (LDXFloor) 			#declare LDXFloor		= 0;			#end	// Include Floor? (1 = YES; 0 = NO)


// -------------------------------------------------------------
// New LDCad settings

#if (L3SW > 0)
	#ifndef (doSeams)	#declare doSeams	= true;		#end		//This will fake seams in between parts by slightly scaling them.
#else
	#ifndef (doSeams)	#declare doSeams	=false;		#end	//This will fake seams in between parts by slightly scaling them.
#end
#ifndef (seamSize)		#declare seamSize	= L3SW;		#end //Width of seams.
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
// Set the tile direction based on the clock value.

#declare Count = clock * 16;
#declare No1 = mod(Count,4);
#declare No2 = floor(Count/4);
#if ((No1 = 1) | (No1 = 3))
	#declare North = true;		// Is the tile connected on this side?
#else
	#declare North = false;
#end
#if ((No1 = 2) | (No1 = 3))
	#declare East  = true;
#else
	#declare East  = false;
#end
#if ((No2 = 1) | (No2 = 3))
	#declare South = true;
#else
	#declare South = false;
#end
#if ((No2 = 2) | (No2 = 3))
	#declare West  = true;
#else
	#declare West  = false;
#end


// -------------------------------------------------------------
// Lights
// Light color should use RGB not SRGB!!

#include "CIE.inc"					// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys.inc"				// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys_constants.inc"	// http://www.ignorancia.org/en/index.php?page=Lightsys

#declare light_source_lumens	= 2;						// float, was 2
#declare light_source_temp		= Daylight(6500);			// float
#declare light_source_color		= Light_Color(light_source_temp,light_source_lumens);
#declare light_source_distance	= 149600;
#declare light_source_diameter	= 696*2;
#declare light_source_location	= vrotate(<0,0,-light_source_distance>, <-60,-120,+0>);

/*
light_source
{
	light_source_location
	rgb light_source_color
	parallel
	point_at <0,0,0>
}
*/

light_source
{
	light_source_location
	rgb light_source_color
	#if (Use_Area_Light = true)
		area_light x*light_source_diameter, y*light_source_diameter, 9, 9 adaptive 0 circular orient
		area_illumination on
	#end
	fade_distance light_source_distance
	fade_power 1
//	shadowless
	parallel
	point_at <0,0,0>		// not for point lights
}


// -------------------------------------------------------------
// Camera

#declare TileWidth			= 640;				// float
#declare TilesNum			= 32;				// integer
#declare cam_mode			= 2;				// integer
#switch (cam_mode)
	// orthographic
	#case (0)
		#declare Diagonal_horz		= cos(pi/4);
		#declare Diagonal_vert		= sin(pi/4);
		camera
		{
			orthographic
			up			-y * Diagonal_horz * TileWidth * 2 * TilesNum * image_height/image_width
			right		+x * Diagonal_horz * TileWidth * 2 * TilesNum
			location	-z * 4096 * TilesNum
			direction	+z * 4096 * TilesNum
			rotate		-x * 30
			rotate		+y * 45
			translate	+x * 960
			translate	+z * 960
		}
	#break
	// oblique, top down
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
		}
		camera
		{
			orthographic
			location	cam_loca
			direction	cam_dirc
			up			cam_upvc
			right		cam_rgvc
			transform {cam_tran}
		}
	#break
	// oblique, Ultima VII style
	#case (2)
		#local cam_aspc =     image_width/image_height;
		#local cam_dist =     100000;
		#local cam_area =     TileWidth * TilesNum;
		#local cam_loca =     <+1,-1,-1> * cam_dist;
		#local cam_dirc =     <-1,+1,+1> * cam_dist;
		#local cam_upvc =     +z * cam_area;
		#local cam_rgvc =     +x * cam_area * cam_aspc;
		#local cam_tran = transform
		{
			scale		<1,2,1>
			rotate		-y * 90
		}
		camera
		{
			orthographic
			location	cam_loca
			direction	cam_dirc
			up			cam_upvc
			right		cam_rgvc
			transform {cam_tran}
		}
	#break
#end
