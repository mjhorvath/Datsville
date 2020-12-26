// +q7

#if (version < 3.7)
	#error "This POV code requires at least version 3.7\n"
#end

#declare NoRadiosity		= 1;	// not used currently

#declare L3Quality		= 1;	// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo, 4=stud2logo
#declare L3SW			= 0;	// Width of seam between two bricks
#declare L3Studs		= 0;	// 1=on 0=off
#declare L3Bumps		= 0;	// 1=on 0=off
#declare L3Ambient		= 0.1;
#declare L3Diffuse		= 0.9;
#declare L3Ior			= 1.25;
#declare L3NormalBumps		= normal { bumps 0.01 scale 20 }
#declare L3NormalSlope		= normal { bumps 0.3 scale 0.5 }
#declare QUAL			= L3Quality;	// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo
#declare SW			= L3SW;		// Width of seam between two bricks
#declare STUDS			= L3Studs;	// 1=on 0=off
#declare BUMPS			= L3Bumps;	// 1=on 0=off
#declare BUMPNORMAL		= L3NormalBumps;
#declare AMB			= L3Ambient;
#declare DIF			= L3Diffuse;
#declare L3Phong		= 0.5;
#declare L3PhongSize		= 40;
#declare L3Reflection		= 0.04;	// was 0.08
#declare L3SWT			= (L3SW ? L3SW : 0.001);  // At least a small seam when transparent

//#include "fastrad.inc"		// slooowwwwwww!!!

global_settings
{
	assumed_gamma	2.2
	adc_bailout	0.005
	max_trace_level	0	//50
	ambient_light	1
//	radiosity
//	{
//		pretrace_start	0.08
//		pretrace_end	0.02 // Try 0.01 if you see random black spots.
//		count		20
//		error_bound	1
//		recursion_limit	1
//		normal		on
//		brightness	1.4
//		always_sample	no
//		gray_threshold	0.8
//		media		on
//	}
}


//#include "ldr_materials_1.4.inc"
#include "stdinc.inc"
#include "CIE.inc"			// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys.inc"			// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys_constants.inc"	// http://www.ignorancia.org/en/index.php?page=Lightsys

#declare trans_amount		= <2240,0,-320>;
#declare light_lumens		= 2;					// float
#declare light_temp		= Daylight(6100);			// float
#declare light_color		= Light_Color(light_temp,light_lumens);
#declare Camera_Diagonal	= cosd(45);
#declare Camera_Aspect		= image_height / image_width;
#declare Camera_Width		= 7680;
#declare Camera_Vertical	= 225;
#declare Camera_Horizontal	= 30;
#declare Camera_Distance	= Camera_Width;
#declare Camera_Scale		= 1;
#declare Camera_Translate	= <-1280,0,0> + trans_amount;
#declare Camera_Up		= -y * Camera_Diagonal * Camera_Width * Camera_Aspect;
#declare Camera_Right		= +x * Camera_Diagonal * Camera_Width;
#declare Camera_Location	= -z * Camera_Distance;
#declare Camera_Direction	= +z * Camera_Distance;
#declare Camera_LookAt		= Camera_Location + Camera_Direction;
#declare Camera_Rotate		= <-Camera_Horizontal,Camera_Vertical,0,>;
camera
{
	orthographic
	up		Camera_Up
	right		Camera_Right
	location	Camera_Location
	direction	Camera_Direction
	rotate		Camera_Rotate
	scale		Camera_Scale
	translate	Camera_Translate
}
#declare Camera_Location	= Camera_Scale * (Camera_Translate + vrotate(Camera_Location,Camera_Rotate));
#declare Camera_LookAt		= Camera_Scale * (Camera_Translate + vrotate(Camera_LookAt,Camera_Rotate));

// Lights:
#declare light_source_location	= vrotate(<0,0,-320000>, <-60,-120,+00>);

light_source
{
	light_source_location
	color rgb light_color
	parallel
}

//// Floor
object
{
	plane { y, 4 hollow }
	texture
	{
		pigment
		{
			checker
			pigment {color rgb <067,084,029>/255}
			pigment {color rgb <040,066,018>/255}
		}
		finish { ambient L3Ambient diffuse L3Diffuse }
		translate <1/2,0,1/2>
		scale 640
		translate trans_amount
	}
}

// Sky
sky_sphere
{
	pigment
	{
		gradient -y
		color_map
		{
			[0.0 color rgb <0.6,0.7,1.0>]
			[0.7 color rgb <0.0,0.1,0.8>]
		}
	}
}

// Axes
cylinder
{
	0, x*32000, 10
	pigment {color rgb x}
}
cylinder
{
	0, y*32000, 10
	pigment {color rgb y}
}
cylinder
{
	0, z*32000, 10
	pigment {color rgb z}
}

// street grid
union
{
	plane
	{
		x,0
	}
	plane
	{
		x,5120
	}
	plane
	{
		x,10240
	}
	plane
	{
		-x,5120
	}
	plane
	{
		-x,10240
	}
	plane
	{
		z,0
	}
	plane
	{
		z,5120
	}
	plane
	{
		z,10240
	}
	plane
	{
		-z,5120
	}
	plane
	{
		-z,10240
	}
	pigment
	{
		color rgb x+z
	}
	clipped_by
	{
		box
		{
			<-10241,-72,-10241>, <+10241,+72,+10241>
		}
	}
}
