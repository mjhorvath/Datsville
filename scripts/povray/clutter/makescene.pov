// Persistence of Vision Ray Tracer Scene Description File
// File: test.pov
// Vers: MegaPov 0.7
// Desc: test for Clutter macro
// Date: 9th July 2001 22.24
// Auth: Jonathan Rafael Ghiglia
// Updated: 2021 Michael Horvath
// See: povray.advanced-users, "Need a script to randomly scatter objects vertically", Tue, 20 Apr 2021 00:02:48 -0400
// See: povray.advanced-users, "clutter.mcr and trace()", 

#version 3.8;

// Converts a color given in sRGB space to one in the ordinary RGB
// space determined by ‘assumed_gamma’.
#macro CsRGB2RGB(Color)
	#local Result = srgbft Color;
	(Result)
#end


// ----------------------------------------

#declare Location = <-2, 3, -4>;
#declare Look_at = <0, 0, 0>;

camera
{
	location	Location
	look_at		Look_at
	rotate		y * 90
	scale		2
}

global_settings
{
	assumed_gamma	1
}

sky_sphere { pigment { rgb <0.6, 0.8, 1> } }

light_source
{
	<0,3.5,5>
	rgb <60/255,60/255,90/255>*2.5
	fade_distance 5
	fade_power 3
}


light_source
{
	<4, 5, -5>
	rgb <1, 1, 1>*2.5
	fade_power 2
	fade_distance 5
}


// ---------------------------------------- 

#include "clutter.mcr"   

#declare total_objects = 2048;


//---------land

#declare land = height_field
{
	png "heightmap.png"
	smooth
	scale y/10
	scale 10
}


//-----objects array-
#declare ob_ar = array[2]
#declare ob_ar[0] = sphere {0,0.05 translate 0.05*y}
#declare ob_ar[1] = cone {0,0.025,0.2*y,0}

//------objects related array
#declare ob_rel_ar = array[2][2]
#declare ob_rel_ar[0][0] = total_objects*1/2;
#declare ob_rel_ar[0][1] = 0.05;
#declare ob_rel_ar[1][0] = total_objects*1/2;
#declare ob_rel_ar[1][1] = 0.025;  

//--------obstacles array
#declare obstacle_ar = array[1][2]
#declare obstacle_ar[0][0] = <5,0,5>;
#declare obstacle_ar[0][1] = <0,0,0>; // no obstacle   

//----------probability array
#declare p = array[2][2]
#declare p[0][0] = 0;
#declare p[0][1] = 1;
#declare p[1][0] = 0;
#declare p[1][1] = 1;

//------------probability map array
#declare map = array[2]
#declare map[0] = pigment {image_map {png "pigment_5b.png"} translate <-1/2,-1/2,0> rotate x * 90 rotate y * 270 translate <1/2,0,1/2> scale 10} // spheres
#declare map[1] = pigment {image_map {png "pigment_6b.png"} translate <-1/2,-1/2,0> rotate x * 90 rotate y * 270 translate <1/2,0,1/2> scale 10} // cones
//#declare map[0] = pigment {function {max(0,min(1,x))} color_map {[0.0 rgb 1][0.8 rgb 0]} scale 10} //more spheres on the left
//#declare map[1] = pigment {function {max(0,min(1,x))} color_map {[0.2 rgb 0][1.0 rgb 1]} scale 10} //more cones on the right

//----------textures array
#declare tex_ar = array[2][2]
#declare tex_ar[0][0] = texture {pigment {color CsRGB2RGB(<1.0,0.3,0.1>)} finish {specular 0.7 roughness 0.005}}
#declare tex_ar[0][1] = texture {pigment {color CsRGB2RGB(<0.1,0.3,1.0>)} finish {specular 0.7 roughness 0.005}}
#declare tex_ar[1][0] = texture {pigment {color CsRGB2RGB(<1.0,0.6,0.2>)*0.9} finish {ambient 0 diffuse 0.2 specular 1.5 roughness 0.03 reflection 0.5*<1.0,0.6,0.2> brilliance 1.5}}
#declare tex_ar[1][1] = texture {pigment {color CsRGB2RGB(<1.0,0.95,0.9>)*0.9} finish {ambient 0 diffuse 0.2 specular 1.5 roughness 0.03 reflection 0.5*<1.0,0.95,0.9> brilliance 1.5}}

//----------map for textures interpolati0n array
#declare map_tex = array[2]
#declare map_tex[0] = pigment {image_map {png "pigment_5b.png"} translate <-1/2,-1/2,0> rotate x * 90 rotate y * 270 translate <1/2,0,1/2> scale 10} //from blue to red
#declare map_tex[1] = pigment {image_map {png "pigment_6b.png"} translate <-1/2,-1/2,0> rotate x * 90 rotate y * 270 translate <1/2,0,1/2> scale 10} //from chrome to gold
//#declare map_tex[0] = pigment {function {max(0,min(1,x))} color_map {[0.0 rgb 0][1.0 rgb 1]} scale 10} //from blue to red
//#declare map_tex[1] = pigment {function {max(0,min(1,x))} color_map {[0.0 rgb 0][1.0 rgb 1]} scale 10} //from chrome to gold

//----------to do: map for transforms interpolation array


#debug concat("Weee! ",vstr(3,trace(land, <2.5,5,2.5>,-y),",",0,-1), "\n")


object
{
	clutter
	(
		ob_ar,			// objects array
		ob_rel_ar,		// objects related array
		obstacle_ar,	// obstacle array
		10,				// x limit
		10,				// z limit
		p,				// probability array
		map,			// probability map array
		true,			// switch texture interpolation on/off
		tex_ar,			// textures array
		map_tex,		// map for textures interpolation
		land,			// environment you want to place the objects on
		false,			// switch normal orientation on/off
		1000,			// max random rotation around y axis
		seed(1000000),	// random seed
		1,				// 0 do not save array file, 1 write array file, 2 read array file
		"clu.inc"		// name of the file you want to write or read
	)
	translate <-5,0,-5>
}

object
{
	land 
	pigment {rgb 1}
	translate <-5,0,-5>
	finish { ambient 0 diffuse 0.5 specular 0.4 roughness 0.01 reflection 0.2 }
}
