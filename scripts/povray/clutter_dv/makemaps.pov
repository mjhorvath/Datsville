// render this as a square image, typically 128x128px

// http://news.povray.org/povray.newusers/thread/%3C5473da29%40news.povray.org%3E/
#macro pigment_multiply(p1, p2)
	pigment
	{
		#local PR1 = function {pigment{p1}}
		#local PR2 = function {pigment{p2}}	
		#local PR_FR=function (x,y,z) {PR1(x,y,z).red     * PR2(x,y,z).red}
		#local PR_FG=function (x,y,z) {PR1(x,y,z).green   * PR2(x,y,z).green}
		#local PR_FB=function (x,y,z) {PR1(x,y,z).blue    * PR2(x,y,z).blue}
		#local PR_FF=function (x,y,z) {PR1(x,y,z).filter  * PR2(x,y,z).filter}
		#local PR_FT=function (x,y,z) {PR1(x,y,z).transmit* PR2(x,y,z).transmit}
		average
		pigment_map
		{
			[function{PR_FR(x,y,z)} color_map{[0 rgb 0][1 rgbft 5*<1,0,0,0,0>]}]
			[function{PR_FG(x,y,z)} color_map{[0 rgb 0][1 rgbft 5*<0,1,0,0,0>]}]
			[function{PR_FB(x,y,z)} color_map{[0 rgb 0][1 rgbft 5*<0,0,1,0,0>]}]
			[function{PR_FF(x,y,z)} color_map{[0 rgb 0][1 rgbft 5*<0,0,0,1,0>]}]
			[function{PR_FT(x,y,z)} color_map{[0 rgb 0][1 rgbft 5*<0,0,0,0,1>]}]
		}
	}
#end

#macro power_map(max_steps, in_color, in_power)
	#for (i, 0, max_steps)
		[i/max_steps rgb in_color * pow(i/max_steps, in_power)]
	#end
#end

// low slopes are large best
#declare pigment_1a = pigment
{
	slope {-y}
	color_map
	{
		power_map(100, 1, 2/1)
	}
}

// low slopes are middle best
#declare pigment_1b = pigment
{
	slope {-y}
	color_map
	{
		power_map(100, 1, 1/1)
	}
}

// low slopes are small best
#declare pigment_1c = pigment
{
	slope {-y}
	color_map
	{
		power_map(100, 1, 1/2)
	}
}

// stage 2, necessary because slope patterns don't work inside functions
#declare pigment_2a = pigment
{
	image_map {png "pigment_1a.png"}
	rotate +x * 90
	rotate -y * 90
}

// high altitude is large best
#declare pigment_3a = pigment
{
	gradient -y
	color_map
	{
		power_map(100, 1, 2/1)
	}
	scale 1/10
}

// high altitude is middle best
#declare pigment_3b = pigment
{
	gradient -y
	color_map
	{
		power_map(100, 1, 1/1)
	}
	scale 1/10
}


// high altitude is small best
#declare pigment_3c = pigment
{
	gradient -y
	color_map
	{
		power_map(100, 1, 1/2)
	}
	scale 1/10
}

// low altitude is large best
#declare pigment_4a = pigment
{
	gradient +y
	color_map
	{
		power_map(100, 1, 2/1)
	}
	translate -y
	scale 1/10
}

// low altitude is middle best
#declare pigment_4b = pigment
{
	gradient +y
	color_map
	{
		power_map(100, 1, 1/1)
	}
	translate -y
	scale 1/10
}


// low altitude is small best
#declare pigment_4c = pigment
{
	gradient +y
	color_map
	{
		power_map(100, 1, 1/2)
	}
	translate -y
	scale 1/10
}

// deciduous average
#declare pigment_5a = pigment
{
	average
	pigment_map
	{
	    [1.0  pigment_2a]
	    [1.0  pigment_4a]
	}
}

// deciduous multiply
#declare pigment_5b = pigment_multiply(pigment_2a, pigment_4a)


// coniferous average
#declare pigment_6a = pigment
{
	average
	pigment_map
	{
	    [1.0  pigment_2a]
	    [1.0  pigment_3c]
	}
}

// coniferous multiply
#declare pigment_6b = pigment_multiply(pigment_2a, pigment_3c)

#declare land = height_field
{
	png "heightmap.png"
	scale -y * 30720/163840/2
}

object
{
	land
	pigment {pigment_6b}
	finish {ambient 0 diffuse 0 emission 1}
}


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
/*
light_source
{
	light_source_location
	rgb light_source_color
	parallel
	point_at <0,0,0>
}
*/

camera
{
	orthographic
	location	-y
	direction	+y/10
	up			-x
	right		+z
	translate	<1/2,0,1/2>
}
