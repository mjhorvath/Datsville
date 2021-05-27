// Persistence of Vision Ray Tracer Scene Description File
// File: test.pov
// Vers: MegaPov 0.7
// Desc: test for Clutter macro
// Date: 9th July 2001 22.24
// Auth: Jonathan Rafael Ghiglia
// Updated: 2021 Michael Horvath
// See: povray.advanced-users, "Need a script to randomly scatter objects vertically", 20 Apr 2021 00:02:48 -0400
// See: povray.advanced-users, "clutter.mcr and trace()", 17 May 2021 01:12:14 -0400
// To do: use dictionaries instead of multiple arrays
// To do: use map for transforms interpolation

#version 3.8;

// Converts a color given in sRGB space to one in the ordinary RGB
// space determined by ‘assumed_gamma’.
#macro CsRGB2RGB(Color)
	#local Result = srgbft Color;
	(Result)
#end

#include "l3p_plant_bigtree_01_inlined_n_boxed_n_lgeo_n.pov"
#include "l3p_plant_bigtree_03_inlined_n_boxed_n_lgeo_n.pov"
#include "l3p_plant_bigtree_04_inlined_n_boxed_n_lgeo_n.pov"
#include "l3p_plant_bigtree_05_inlined_n_boxed_n_lgeo_n.pov"
#include "l3p_plant_bigtree_06_inlined_n_boxed_n_lgeo_n.pov"


// ----------------------------------------

#declare Scene_Scale = 16384;
#declare Width_Scale = 163840;
#declare Height_Scale = 30720/2;

#declare Location = <-2, 3, -4>;
#declare Look_at = <0, 0, 0>;

camera
{
	location	Location
	look_at		Look_at
	scale		2
	translate	<5,0,5>
	scale		Scene_Scale
}

global_settings
{
	assumed_gamma	1
}

sky_sphere { pigment { rgb <0.6, 0.8, 1.0> } }

light_source
{
	<0, 3.5, 5>
	rgb <60/255,60/255,90/255>
	parallel
	point_at 0
	scale Scene_Scale
}


light_source
{
	<4, 5, -5>
	rgb <1, 1, 1>
	parallel
	point_at 0
	scale Scene_Scale
}


// ---------------------------------------- 

#include "clutter.mcr"   

#declare total_objects = 24000;
#declare total_types = 6;


//------land

#declare land = height_field
{
	png "heightmap.png"
//	smooth
	scale <Width_Scale,Height_Scale,Width_Scale>
}

//------objects array
#declare obj_obj_ar = array[total_types]
#declare obj_obj_ar[0] = object {plant__bigtree__05_dot_ldr scale -y}
#declare obj_obj_ar[1] = object {plant__bigtree__04_dot_ldr scale -y}
#declare obj_obj_ar[2] = object {plant__bigtree__03_dot_ldr scale -y}
#declare obj_obj_ar[3] = object {plant__bigtree__01_dot_ldr scale -y}
#declare obj_obj_ar[4] = object {plant__bigtree__01_dot_ldr scale -y}	// temporary duplicate
#declare obj_obj_ar[5] = object {plant__bigtree__06_dot_mpd scale -y}

//------objects numbers array
#declare obj_num_ar = array[total_types]
#declare obj_num_ar[0] = total_objects/total_types;
#declare obj_num_ar[1] = total_objects/total_types;
#declare obj_num_ar[2] = total_objects/total_types;
#declare obj_num_ar[3] = total_objects/total_types;
#declare obj_num_ar[4] = total_objects/total_types;
#declare obj_num_ar[5] = total_objects/total_types;

//------objects radii array
#declare obj_rad_ar = array[total_types]
#declare obj_rad_ar[0] = 240;
#declare obj_rad_ar[1] = 180;
#declare obj_rad_ar[2] = 160;
#declare obj_rad_ar[3] = 100;
#declare obj_rad_ar[4] = 100;
#declare obj_rad_ar[5] = 60;

//------objects names array
#declare obj_nam_ar = array[total_types]
#declare obj_nam_ar[0] = "plant_bigtree_05.ldr";
#declare obj_nam_ar[1] = "plant_bigtree_04.ldr";
#declare obj_nam_ar[2] = "plant_bigtree_03.ldr";
#declare obj_nam_ar[3] = "plant_bigtree_01.ldr";
#declare obj_nam_ar[4] = "plant_bigtree_01.ldr";
#declare obj_nam_ar[5] = "plant_bigtree_06.mpd";

//------probabilities array
#declare obj_p_ar = array[total_types][2]
#declare obj_p_ar[0][0] = 0;
#declare obj_p_ar[0][1] = 1;
#declare obj_p_ar[1][0] = 0;
#declare obj_p_ar[1][1] = 1;
#declare obj_p_ar[2][0] = 0;
#declare obj_p_ar[2][1] = 1;
#declare obj_p_ar[3][0] = 0;
#declare obj_p_ar[3][1] = 1;
#declare obj_p_ar[4][0] = 0;
#declare obj_p_ar[4][1] = 1;
#declare obj_p_ar[5][0] = 0;
#declare obj_p_ar[5][1] = 1;

//------probabilities map array
#declare obj_pmap_ar = array[total_types]
#declare obj_pmap_ar[0] = pigment {image_map {png "pigment_5b.png"} translate <-1/2,-1/2,0> rotate x * 90 rotate y * 270 translate <1/2,0,1/2> scale Width_Scale} // valleys
#declare obj_pmap_ar[1] = pigment {image_map {png "pigment_5b.png"} translate <-1/2,-1/2,0> rotate x * 90 rotate y * 270 translate <1/2,0,1/2> scale Width_Scale} // valleys
#declare obj_pmap_ar[2] = pigment {image_map {png "pigment_5b.png"} translate <-1/2,-1/2,0> rotate x * 90 rotate y * 270 translate <1/2,0,1/2> scale Width_Scale} // valleys
#declare obj_pmap_ar[3] = pigment {image_map {png "pigment_6b.png"} translate <-1/2,-1/2,0> rotate x * 90 rotate y * 270 translate <1/2,0,1/2> scale Width_Scale} // hills
#declare obj_pmap_ar[4] = pigment {image_map {png "pigment_6b.png"} translate <-1/2,-1/2,0> rotate x * 90 rotate y * 270 translate <1/2,0,1/2> scale Width_Scale} // hills
#declare obj_pmap_ar[5] = pigment {image_map {png "pigment_6b.png"} translate <-1/2,-1/2,0> rotate x * 90 rotate y * 270 translate <1/2,0,1/2> scale Width_Scale} // hills

//------textures array
#declare obj_t_ar = array[total_types][2]
#declare obj_t_ar[0][0] = texture {}
#declare obj_t_ar[0][1] = texture {}
#declare obj_t_ar[1][0] = texture {}
#declare obj_t_ar[1][1] = texture {}
#declare obj_t_ar[2][0] = texture {}
#declare obj_t_ar[2][1] = texture {}
#declare obj_t_ar[3][0] = texture {}
#declare obj_t_ar[3][1] = texture {}
#declare obj_t_ar[4][0] = texture {}
#declare obj_t_ar[4][1] = texture {}
#declare obj_t_ar[5][0] = texture {}
#declare obj_t_ar[5][1] = texture {}

//------textures map array
#declare obj_tmap_ar = array[total_types]
#declare obj_tmap_ar[0] = pigment {}
#declare obj_tmap_ar[1] = pigment {}
#declare obj_tmap_ar[2] = pigment {}
#declare obj_tmap_ar[3] = pigment {}
#declare obj_tmap_ar[4] = pigment {}
#declare obj_tmap_ar[5] = pigment {}

//------to do: transforms array

//------to do: transforms map array


//------obstacles array
#declare obstacle_ar = array[1][2]
#declare obstacle_ar[0][0] = <0,0,0>; // no obstacle
#declare obstacle_ar[0][1] = <0,0,0>; // no obstacle


// ---------------------------------------- 

object
{
	clutter
	(
		obj_obj_ar,		// object objects array
		obj_num_ar,		// object numbers array
		obj_rad_ar,		// object radii array
		obj_nam_ar,		// object names array
		obstacle_ar,	// obstacle array
		Width_Scale,	// x limit
		Width_Scale,	// z limit
		<20,8,20>,		// pos rounding amounts
		<10,0,10>,		// pos rounding offsets
		obj_p_ar,		// probabilities array
		obj_pmap_ar,	// probabilities interpolation map array
		true,			// switch texture interpolation on/off
		obj_t_ar,		// textures array
		obj_tmap_ar,	// textures interpolation map array
		land,			// environment you want to place the objects on
		false,			// switch normal orientation on/off
		360,			// max random rotation around y axis
		90,				// rotation rounding amount around y axis
		seed(1000000),	// random seed
		3,				// 0 do not save array file, 1 write array file, 2 read array file, 3 write array file only
		"clutter.inc"	// name of the file you want to write or read
	)
}

object
{
	land 
	pigment {color rgb 1}
	finish {ambient 0 diffuse 0.5 specular 0.4 roughness 0.01 reflection 0.2}
}
