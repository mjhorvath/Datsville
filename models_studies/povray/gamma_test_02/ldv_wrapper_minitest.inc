////////////////////////////////////////////////////////////////////////////////

#include "CIE.inc"			// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys.inc"			// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys_constants.inc"	// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "stdinc.inc"

#declare light_lumens		= 3;					// float
#declare light_temp		= Daylight(6100);			// float
#declare light_color		= Light_Color(light_temp,light_lumens);
#declare trans_amount		= <2240,0,-320>;
#declare LDXSkipLight1		= true;
#declare LDXSkipLight2		= true;
#declare LDXSkipLight3		= true;
#declare LDXSkipCamera		= true;

// Camera:
#declare Camera_Diagonal	= cosd(45);
#declare Camera_Aspect		= image_height / image_width;
#declare Camera_Width		= 2048;
#declare Camera_Vertical	= 315;
#declare Camera_Horizontal	= 15;
#declare Camera_Distance	= Camera_Width;
#declare Camera_Scale		= 4;
#declare Camera_Translate	= <-1280,0,0> + trans_amount;
#declare Camera_Up		= -y * Camera_Diagonal * Camera_Width * Camera_Aspect;
#declare Camera_Right		= +x * Camera_Diagonal * Camera_Width;
#declare Camera_Location	= -z * Camera_Distance;
#declare Camera_Direction	= +z * Camera_Distance/2;		// +z * Camera_Distance;
#declare Camera_LookAt		= Camera_Location + Camera_Direction;
#declare Camera_Rotate		= <-Camera_Horizontal,Camera_Vertical,0,>;
camera
{
//	orthographic
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
#declare light_source_location	= vrotate(<0,0,-320000>, <-60,-120 + 90,+00>);

light_source
{
	light_source_location
	light_color
	parallel
}

// Floor
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
		scale 640
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

global_settings
{
	assumed_gamma	2.2
	adc_bailout	0.005
	max_trace_level	8	//50
	ambient_light	1
	radiosity
	{
		pretrace_start	0.08
		pretrace_end	0.02 // Try 0.01 if you see random black spots.
		count		20
		error_bound	1
		recursion_limit	1
		normal		on
		brightness	1.4
		always_sample	no
		gray_threshold	0.8
		media		on
	}
}

////////////////////////////////////////////////////////////////////////////////
