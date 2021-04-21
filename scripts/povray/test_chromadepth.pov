#version 3.7;

#include "colors"

//------------------------
#declare CAM_LOCATION = <32, 56, -35>*3;			// easily change location using the (positive) multiplier (actually changes it between location <0,0,0> and farther out)
#declare OBJECT_CENTER_LOCATION = <3,6,22>*1.0;		// ditto
#declare OBJECT_SCALE =  2.7;
#declare CAM_ANGLE = 3;								// 0.9 Just to easily change the camera angle when you change object scale or camera/object distance.


// main camera
camera
{
	perspective
	location  CAM_LOCATION
	look_at   OBJECT_CENTER_LOCATION
	right     x*image_width/image_height  // aspect
	angle CAM_ANGLE
}

/*
// OR, separate camera, 'un-coupled' from code, looking from another location way above
camera
{
	perspective
	location  <0,500,0>
	look_at   OBJECT_CENTER_LOCATION
	right     x*image_width/image_height  // aspect
	angle CAM_ANGLE
}
*/

light_source
{
	0*x
	color rgb .7
	translate <40, 80, 30>
}

background {rgb 0.1}

// stripes are 1-unit apart
plane
{
	y,0
	pigment
	{
		average
		pigment_map
		{
			[
				1
				gradient x
				color_map
				{
					[.05 rgb .8]
					[.05 rgb .3]
				}
			]
			[
				1
				gradient z
				color_map
				{
					[.05 rgb .8]
					[.05 rgb .3]
				}
			]
		}
		scale 1
	}
}

global_settings
{
	assumed_gamma 1
}


/*
// does not need to be centered on origin when made
#declare OBJECT_1 = box
{
	0, <1,0.1,1>
	scale OBJECT_SCALE
	rotate 40
	translate OBJECT_CENTER_LOCATION
}
*/

// does not need to be centered on origin when made
#declare OBJECT_1 = cylinder
{
	-0.05*y, +0.05*y, 1
	scale OBJECT_SCALE
	translate OBJECT_CENTER_LOCATION  // yes, PRE-translated -- it's part of the idea
}

#declare NEAR_CORNER = min_extent(OBJECT_1);
#declare FAR_CORNER = max_extent(OBJECT_1);


#include "materials_chromadepth.inc"



object
{
	OBJECT_1				// already translated
	MakeChromadepthTextureObjectRGB(CAM_LOCATION, NEAR_CORNER, FAR_CORNER)
	translate -OBJECT_CENTER_LOCATION
//	rotate x * 180
	translate OBJECT_CENTER_LOCATION
}

#debug concat("\n", "object SCALE = ",str(OBJECT_SCALE,0,9),"\n")
#debug concat("\n", "distance to bounding box NEAR corner (L_1) = ",str(vlength(NEAR_CORNER - CAM_LOCATION) - 0,0,9),"\n")
#debug concat("\n", "distance to bounding box FAR corner (L_2) = ",str(vlength(FAR_CORNER - CAM_LOCATION) - 0,0,9),"\n")
