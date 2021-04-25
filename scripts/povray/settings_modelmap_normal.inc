// +am3 +r9 +a0.002 +ac0.99

// INI settings:
// -------------
// +kfi = starting frame
// +kff = ending frame
// +kc  = cyclical animation
// +am  = sampling method
// +r   = antialias depth
// +a   = antialias threshold
// +ac  = ???
// +q   = quality level

#version 3.8;


// -------------------------------------------------------------
// Scene settings

// Use_Rad_Setting:
// ----------------
// Default		=  0
// Debug		=  1
// Fast			=  2
// Normal		=  3
// 2Bounce		=  4
// Final		=  5
// OutdoorLQ	=  6
// OutdoorHQ	=  7
// OutdoorLight	=  8
// IndoorLQ		=  9
// IndoorHQ		= 10

#ifndef (Use_Radiosity)		#declare Use_Radiosity		=false;		#end				// turns radiosity on/off, recommend leaving this off, must decrease diffuse if it is on
#ifndef (Use_Rad_Setting)	#declare Use_Rad_Setting	= 8;		#end				// radiosity presets, see chart above
#ifndef (Use_Uber)			#declare Use_Uber			=false;		#end				// toggle blurred reflections method depending on whether you are using POV-Ray or UberPOV
#ifndef (Use_SSLT)			#declare Use_SSLT			=false;		#end				// subsurface light transport, only present in "materials_ldc_defs_clipka.inc" and "materials_ldc_defs_mjh.inc" currently
#ifndef (Use_2DGuides)		#declare Use_2DGuides		= true;		#end				// axis markers, street sector markers, etc. mainly for maps
#ifndef (Use_3DGuides)		#declare Use_3DGuides		= true;		#end				// axis markers, street sector markers, etc. mainly for maps
#ifndef (Use_GridGuides)	#declare Use_GridGuides		= true;		#end				// show guides marking baseplate corners
#ifndef (Use_Floor_Cutout)	#declare Use_Floor_Cutout	= true;		#end				// cut a hole in the ground plane to fit the city into?
#ifndef (Use_Floor_Check)	#declare Use_Floor_Check	= 1;		#end				// 0 = none, 1 = Flat (cube) Checkered Floor, 2 = Curved (sphere) Checker Floor
#ifndef (Use_Sky)			#declare Use_Sky			= true;		#end				// colored sky sphere
#ifndef (Use_Shadows)		#declare Use_Shadows		=false;		#end				// turns shadows on/off, recommend turning this off for walls that are always covered by rooves, not used often
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
#ifndef (Use_Isometric)		#declare Use_Isometric		= true;		#end				// is an isometric camera used? needed for text labels, replace this with camera mode check once the camera code is unified


// -------------------------------------------------------------
// New L3P settings

#ifndef (L3Version)			#declare L3Version			= 1.4;			#end
#ifndef (L3Quality)			#declare L3Quality			= 2;			#end	// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo, 4=stud2logo
#ifndef (L3SW)				#declare L3SW				= 0.5;			#end	// Width of seam between two bricks
#ifndef (L3Studs)			#declare L3Studs			= 0;			#end	// 1=on 0=off
#ifndef (L3Bumps)			#declare L3Bumps			= 0;			#end	// 1=on 0=off
#ifndef (L3Ambient)			#declare L3Ambient			= 0.1;			#end	// was 0.4
#ifndef (L3Diffuse)			#declare L3Diffuse			= 0.9;			#end	// was 0.4
#ifndef (L3Ior)				#declare L3Ior				= 1.25;			#end	// I think clipka said this should be 1.6
#ifndef (L3NormalBumps)		#declare L3NormalBumps		= normal { bumps 0.01 scale 20 }	#end
#ifndef (L3NormalSlope)		#declare L3NormalSlope		= normal { bumps 0.3 scale 0.5 }	#end
#ifndef (L3Phong)			#declare L3Phong			= 0.5;			#end	// was 0.5
#ifndef (L3PhongSize)		#declare L3PhongSize		= 40;			#end	// was 40
#ifndef (L3Reflection)		#declare L3Reflection		= 0.04;			#end	// was 0.08
#declare L3SWT = (L3SW ? L3SW : 0.001);  // At least a small seam when transparent


// -------------------------------------------------------------
// Old L3P settings

#ifndef (QUAL)				#declare QUAL				= L3Quality;		#end		// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo
#ifndef (SW)				#declare SW					= L3SW;				#end		// Width of seam between two bricks
#ifndef (STUDS)				#declare STUDS				= L3Studs;			#end		// 1=on 0=off
#ifndef (BUMPS)				#declare BUMPS				= L3Bumps;			#end		// 1=on 0=off
#ifndef (BUMPNORMAL)		#declare BUMPNORMAL			= L3NormalBumps;	#end
#ifndef (AMB)				#declare AMB				= L3Ambient;		#end
#ifndef (DIF)				#declare DIF				= L3Diffuse;		#end


// -------------------------------------------------------------
// LDView settings

#ifndef (LDXQual)			#declare LDXQual			= L3Quality;	#end
#ifndef (LDXSW)				#declare LDXSW				= L3SW;			#end
#ifndef (LDXStuds)			#declare LDXStuds			= L3Studs;		#end
#ifndef (LDXRefls)			#declare LDXRefls			= 1;			#end
#ifndef (LDXShads)			#declare LDXShads			= 1;			#end
#ifndef (LDXAmb)			#declare LDXAmb				= L3Ambient;	#end
#ifndef (LDXDif)			#declare LDXDif				= L3Diffuse;	#end
#ifndef (LDXRefl)			#declare LDXRefl			= L3Reflection;	#end
#ifndef (LDXPhong)			#declare LDXPhong			= L3Phong;		#end
#ifndef (LDXPhongS)			#declare LDXPhongS			= L3PhongSize;	#end
#ifndef (LDXTRefl)			#declare LDXTRefl			= 0.2;			#end
#ifndef (LDXTFilt)			#declare LDXTFilt			= 0.85;			#end
#ifndef (LDXIoR)			#declare LDXIoR				= L3Ior;		#end
#ifndef (LDXRubberRefl)		#declare LDXRubberRefl		= 0;			#end
#ifndef (LDXRubberPhong)	#declare LDXRubberPhong		= 0.1;			#end
#ifndef (LDXRubberPhongS)	#declare LDXRubberPhongS	= 10;			#end
#ifndef (LDXChromeRefl)		#declare LDXChromeRefl		= 0.85;			#end
#ifndef (LDXChromeBril)		#declare LDXChromeBril		= 5;			#end
#ifndef (LDXChromeSpec)		#declare LDXChromeSpec		= 0.8;			#end
#ifndef (LDXChromeRough)	#declare LDXChromeRough		= 0.01;			#end
#ifndef (LDXSkipLight1)		#declare LDXSkipLight1		= true;			#end
#ifndef (LDXSkipLight2)		#declare LDXSkipLight2		= true;			#end
#ifndef (LDXSkipLight3)		#declare LDXSkipLight3		= true;			#end
#ifndef (LDXSkipCamera)		#declare LDXSkipCamera		= true;			#end
#ifndef (LDXFloor)			#declare LDXFloor			=false;			#end
//#ifndef (LDXFloorLoc)		#declare LDXFloorLoc		= LDXMaxY;		#end	// Floor location. (Dependent on floor axis; MAX_Y is bottom of model)
//#ifndef (LDXFloorAxis)		#declare LDXFloorAxis	= y;			#end	// Floor axis (x, y, or z)
//#ifndef (LDXFloorR)			#declare LDXFloorR		= 0.8;			#end	// Floor Red
//#ifndef (LDXFloorG)			#declare LDXFloorG		= 0.8;			#end	// Floor Green
//#ifndef (LDXFloorB)			#declare LDXFloorB		= 0.8;			#end	// Floor Blue
//#ifndef (LDXFloorAmb)		#declare LDXFloorAmb		= 0.4;			#end	// Floor Ambient
//#ifndef (LDXFloorDif)		#declare LDXFloorDif		= 0.4;			#end	// Floor Diffuse
#ifndef (LDXBackground)		#declare LDXBackground		=false;			#end	// I invented this
#ifndef (LDXBgR)			#declare LDXBgR				= 0.752941;		#end	// Background Red
#ifndef (LDXBgG)			#declare LDXBgG				= 0.752941;		#end	// Background Green
#ifndef (LDXBgB)			#declare LDXBgB				= 0.752941;		#end	// Background Blue


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
// Lights
// Light color should use RGB not SRGB!!

#include "CIE.inc"					// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys.inc"				// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys_constants.inc"	// http://www.ignorancia.org/en/index.php?page=Lightsys

#declare light_source_lumens	= 2;						// float
#declare light_source_temp		= Daylight(6100);			// float
#declare light_source_color		= Light_Color(light_source_temp,light_source_lumens);
#declare light_source_location	= vrotate(<0,0,-320000>, <-60,-120,+00>);

light_source
{
	light_source_location
	rgb light_source_color
	parallel
	point_at <0,0,0>
}


// -------------------------------------------------------------
// Camera

#declare TileWidth			= 640;				// float
#declare TilesNum			= 48;				// integer
#declare cam_mode			= 1;				// integer
#switch (cam_mode)
	// isometric, old
	#case (0)
		#declare cam_orth = true;
		#declare cam_aspc = image_width/image_height;
		#declare cam_skew = cosd(045);
		#declare cam_dist = 4096 * TilesNum;
		#declare cam_area = cam_skew * TileWidth * 2 * TilesNum;
		#declare cam_loca = -z * cam_dist;
		#declare cam_dirc = cam_loca * -1;
		#declare cam_look = cam_loca + cam_dirc;
		#declare cam_upvc = -y * cam_area * cam_aspc;
		#declare cam_rgvc = +x * cam_area;
		#declare cam_tran = transform
		{
			rotate		-x * 30
			rotate		+y * 45
			translate	+x * 960
			translate	+z * 960
		}
		camera
		{
			#if (cam_orth)
				orthographic
			#else
				perspective
			#end
			up			cam_upvc
			right		cam_rgvc
			location	cam_loca
			direction	cam_dirc
			transform {cam_tran}
		}
	#break
	// isometric, new
	#case (1)
		#declare cam_orth = true;
		#declare cam_skew = cosd(45);
		#declare cam_aspc = image_height / image_width;
		#declare cam_widt = 10240;	// was 7680 * 4/3
		#declare cam_vert = 225;		// was 225
		#declare cam_horz = 30;
		#declare cam_dist = 100000;
		#declare cam_loca = -z * cam_dist;
		#declare cam_dirc = +z;
		#declare cam_look = cam_loca + cam_dirc;
		#declare cam_upvc = -y * cam_skew * cam_widt * cam_aspc;
		#declare cam_rgvc = +x * cam_skew * cam_widt;
		#declare cam_tran = transform
		{
			rotate		<-cam_horz,cam_vert,0,>
			scale		4
			translate	<0,0,0>
		}
		camera
		{
			#if (cam_orth)
				orthographic
			#else
				perspective
			#end
			location	cam_loca
			direction	cam_dirc
			up			cam_upvc
			right		cam_rgvc
			transform {cam_tran}
		}
	#break
	// oblique, top down
	#case (2)
		#declare cam_orth = true;
		#declare cam_aspc = image_width/image_height;
		#declare cam_skew = sind(045);
		#declare cam_dist = 100000;
		#declare cam_area = TileWidth * TilesNum;
		#declare cam_loca = -z * cam_dist;
		#declare cam_dirc = cam_loca * -1;
		#declare cam_look = cam_loca + cam_dirc;
		#declare cam_upvc = -y * cam_area * cam_skew;
		#declare cam_rgvc = +x * cam_area * cam_aspc;
		#declare cam_tran = transform
		{
			rotate		-x * 045
		}
		camera
		{
			#if (cam_orth)
				orthographic
			#else
				perspective
			#end
			location	cam_loca
			direction	cam_dirc
			up			cam_upvc
			right		cam_rgvc
			transform {cam_tran}
		}
	#break
	// oblique, Ultima VII style
	#case (3)
		#declare cam_orth = true;
		#declare cam_aspc = image_width/image_height;
		#declare cam_dist = 100000;
		#declare cam_area = TileWidth * TilesNum;
		#declare cam_loca = vnormalize(<+1,-1,-1>) * cam_dist;
		#declare cam_dirc = vnormalize(<+1,-1,-1>) * -1;
		#declare cam_look = cam_loca + cam_dirc;
		#declare cam_upvc = +z * cam_area;
		#declare cam_rgvc = +x * cam_area * cam_aspc;
		#declare cam_tran = transform
		{
			scale		<1,2,1>
			rotate		-y * 90
		}
		camera
		{
			#if (cam_orth)
				orthographic
			#else
				perspective
			#end
			location	cam_loca
			direction	cam_dirc
			up			cam_upvc
			right		cam_rgvc
			transform {cam_tran}
		}
	#break
#end

#declare cam_loca = vtransform(cam_loca,cam_tran);
#declare cam_dirc = vtransform(cam_dirc,cam_tran);
#declare cam_look = vtransform(cam_look,cam_tran);
#declare cam_upvc = vtransform(cam_upvc,cam_tran);
#declare cam_rgvc = vtransform(cam_rgvc,cam_tran);

Set_Camera_Orthographic(cam_orth)
Set_Camera_Alt(cam_loca, cam_dirc, cam_rgvc, cam_upvc)


// -------------------------------------------------------------
// Guides & labels

// Compass rose
#declare Compass_Object = polygon
{
	4, <0,0>, <0,1>, <1,1>, <1,0>
	pigment
	{
		image_map {png "compass_isometric.png"}
	}
	finish {emission 1 diffuse 0 ambient 0}
	no_shadow			// shouldn't cast shadows in the scene
	no_reflection		// shouldn't be reflected in scene elements
	no_radiosity		// also make the object invisible to radiosity rays
	scale y/2
	scale 1/8
}
Screen_Object(Compass_Object, <15/16,15/16>, 0, false, 0)
