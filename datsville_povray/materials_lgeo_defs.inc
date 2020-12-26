/*******************************************************************************/
/*                                                                             */
/* LGEO Libray Include File     (C) lgeo@digitalbricks.org (Lutz Uhlmann)      */
/*                                                                             */
/* lg_color.inc: Color Definitions for LGEO POV-Ray Library                    */
/*                                                                             */ 
/* This file is in no way related to the LEGO(tm) Group.                       */
/* It is provided for private non-commercial use only.                         */
/*                                                                             */
/* 1997-06-23 Lutz Uhlmann                                                     */
/* 2007-09-29 Lutz Uhlmann changed to use predefined finishes.                 */
/* 2007-09-29 Lutz Uhlmann changed to use RGB values from ldconfig.ldr.        */
/* 2007-11-24 Lutz Uhlmann added lg_quality for L3P compatibility.             */
/* 2012-03-01 Owen Burgoyne updated colours to official RGB where possible     */
/*            and utilized other sources to make models appear as accurate as  */
/*            possible. Also added more LDraw colours.                         */
/* 2013-05-27 Owen Burgoyne altered reflection for transparent parts.          */
/*                                                                             */
/* This file was updated to match the color definitions from the Peeron        */
/* color list found at http://www.peeron.com/inv/colors/                       */
/*                                                                             */
/* Where no information was available, LEGO Digital Designer was used as the   */
/* colour reference.                                                           */
/*                                                                             */
/* Colors are ordered by LDraw number, followed by the LDraw name, the         */
/* official LEGO number and name (if it is available), and then the origin of  */
/* the chosen rgb of the color is shown within square brackets.                */
/*                                                                             */
/*******************************************************************************/

#ifndef (assumed_gamma)
global_settings { assumed_gamma 1.0 }
#end

/************************/
/*   QUALITY SETTINGS   */
/************************/

#ifndef(lg_quality)
#declare lg_quality = 2;
#end
#ifdef(LG_COLOR_INC)
#else
#declare LG_COLOR_INC = 1;
#include "colors.inc"

/**************************/
/*   FINISHES & NORMALS   */
/**************************/

#declare lg_solid_finish =
  finish {
    ambient 0
    #if (lg_quality > 1)
      diffuse 1
      brilliance 1
      phong 1
      phong_size 40
      reflection { 0.025 falloff 1 exponent 1 }
    #end
    conserve_energy
  }

#declare lg_chrome_finish =
  finish {
    ambient 0.25
    #if (lg_quality > 1)
      brilliance 5
      diffuse 0.6
      metallic
      specular 0.7
      roughness 1/100
      reflection 0.6
    #end
    conserve_energy
  }

#declare lg_chrome_normal =
  normal {
    bumps 0.05
    scale 50
    turbulence 0
  }

#declare lg_metallic_finish =
  finish {
    ambient 0
    #if (lg_quality > 1)
      brilliance 1
      diffuse 1
      phong 1
      phong_size 10
      metallic 0.5
      reflection { 0.1 metallic 0.25 falloff 1 exponent 1 }
      roughness 0.1
      specular 1
    #end
    conserve_energy
  }

#declare lg_pearl_finish =
  finish {
    ambient 0
    #if (lg_quality > 1)
      diffuse 1
      brilliance 1
      phong 1
      phong_size 40
      metallic 0.5
      reflection 0.025
      roughness 0.1
      specular 1
    #end
    conserve_energy
  }

#declare lg_pearl_normal =
  normal {
    bumps 0.05
    scale 0.01
    turbulence 0
  }

#declare lg_rubber_finish = 
  finish {
    ambient 0
    diffuse 1
    phong 0.5
    phong_size 20
    reflection 0
    conserve_energy
  }

#declare lg_rubber_normal =
  normal {
    bumps 0.1
    scale 0.1
    turbulence 0
  }

#declare lg_transparent_finish =
  finish {
    ambient 0 #if (version >= 3.7) emission 0 #end
    #if (lg_quality > 1)
      diffuse 1
      brilliance 1
      reflection { 0.015 falloff 1 exponent 1 }
      phong 1
      phong_size 40
    #end
    conserve_energy
  }

// BASED ON LUGNET
#declare lg_transparent_neon_finish =
  finish {
    ambient 0.05 #if (version >= 3.7) emission 0.05 #end
    #if (lg_quality > 1)
      diffuse 2
      brilliance 1
      reflection { 0.01 falloff 1 exponent 1 }
      phong 1
      phong_size 40
    #end
    conserve_energy
  }

#declare lg_transparent_normal =
  normal {
    bumps 0
    // scale 1
    turbulence 0
  }

#declare lg_ior =
  interior {
    ior 1.2
  }

/*****************************************/
/*   VARIABLES FOR TRANSPARENT COLOURS   */
/*****************************************/

// NORMAL TRANSPARENT
#declare TransFilter = 0.9;
#declare TransTransmit = 0;

// NEON TRANSPARENT
#declare NeonFilter = 0.5;
#declare NeonTransmit = 0.3;

/********************/
/*   SOLID COLORS   */
/********************/

// 0 BLACK / 26 BLACK [ORIGINAL LGEO srgb]
// LDRAW
// PEERON                    <27,42,52> (LOOKS TOO BLUE)
#declare lg_black = texture {
  pigment { color srgb <33,33,33>/255 }
  finish  { lg_solid_finish }
}

// 1 BLUE / 23 BRIGHT BLUE [PEERON]
// PEERON                    <13,105,171>
#declare lg_blue = texture {
  pigment { color srgb <13,105,171>/255 }
  finish  { lg_solid_finish }
}

// 2 GREEN / 28 DARK GREEN [PEERON]
// PEERON                    <40/255, 127/255, 70/255>
#declare lg_green = texture {
 pigment { color srgb <40,127,70>/255 }
 finish  { lg_solid_finish }
}

// 3 DARK TURQUOISE / 107 BRIGHT BLUISH GREEN [PEERON]
// PEERON                    <0,143,155>
#declare lg_teal = texture {
 pigment { color srgb <0,143,155>/255 }
 finish  { lg_solid_finish }
}
#declare lg_cyan = lg_teal			///////////////////!!!

// 4 RED / 21 BRIGHT RED [PEERON]
// PEERON                    <196,40,27>/255
#declare lg_red = texture {
  pigment { color srgb <196,40,27>/255 }
  finish  { lg_solid_finish }
}

// 5 DARK PINK / 221 BRIGHT PURPLE [PEERON]
// PEERON                    <205/255, 98/255, 152/255>
#declare lg_dark_pink = texture {
 pigment { color srgb <205,98,152>/255 }
 finish  { lg_solid_finish }
}

// 6 BROWN / 25 EARTH ORANGE [PEERON]
// PEERON                    <98/255, 71/255, 50/255>
#declare lg_brown = texture {
 pigment { color srgb <98/255, 71/255, 50/255> }
 finish  { lg_solid_finish }
}

// 7 LIGHT GRAY / 2 GREY [PEERON]
// PEERON                    <161/255, 165/255, 162/255>
#declare lg_grey = texture {
 pigment { color srgb <161/255, 165/255, 162/255> }
 finish  { lg_solid_finish }
}

// 8 DARK GRAY / 27 DARK GREY [PEERON]
// PEERON                    <109/255, 110/255, 108/255>
#declare lg_dark_grey = texture {
 pigment { color srgb <109/255, 110/255, 108/255> }
 finish  { lg_solid_finish }
}

// 9 LIGHT BLUE / 45 LIGHT BLUE [PEERON]
// PEERON                    <180/255, 210/255, 227/255>
#declare lg_light_blue = texture {
 pigment { color srgb <180/255, 210/255, 227/255> }
 finish  { lg_solid_finish }
}

// 10 BRIGHT GREEN / 37 BRIGHT GREEN [PEERON]
// PEERON
// <75/255, 151/255, 74/255>
#declare lg_bright_green = texture {
 pigment { color srgb <75/255, 151/255, 74/255> }
 finish  { lg_solid_finish }
}

// 11 LIGHT TURQUOISE / 116 MEDIUM BLUISH GREEN [PEERON]
// PEERON                    <85/255, 165/255, 175/255>
#declare lg_turquoise = texture {
  pigment { color srgb <85,165,175>/255 }
  finish  { lg_solid_finish }
}

#declare lg_blue_green = lg_turquoise			///////////////////!!!

// 12 SALMON / 4 BRICK RED [LDRAW]
// LDRAW <242,112,94>
#declare lg_salmon = texture {
  pigment { color srgb <242,112,94>/255 }
  finish  { lg_solid_finish }
}

// 13 PINK / 16 PINK [LDRAW]
// LDRAW                     <252,151,172>
#declare lg_pink = texture {
 pigment { color srgb <252,151,172>/255 }
 finish  { lg_solid_finish }
}
#declare lg_rose = lg_pink			///////////////////!!!

// 14 YELLOW / 24 BRIGHT YELLOW [PEERON]
// PEERON                    <245,205,47>
#declare lg_yellow = texture {
  pigment { color srgb <245,205,47>/255 }
  finish  { lg_solid_finish }
}

// 15 WHITE / 1 WHITE [PEERON]
// LEGO COLOUR PALETTE 2011  <255,255,255>
// PEERON                    <242,243,242>
#declare lg_white = texture {
  pigment { color srgb <242,243,242>/255 }
  finish  { lg_solid_finish }
}

// 16 MAIN COLOUR [LDRAW]

// 17 LIGHT GREEN / 6 LIGHT GREEN [PEERON]
// PEERON                    <194/255, 218/255, 184/255>
#declare lg_light_green = texture {
  pigment { color srgb <194/255, 218/255, 184/255> }
  finish  { lg_solid_finish }
}

// 18 LIGHT YELLOW / 3 LIGHT YELLOW [PEERON]
// PEERON                    <249/255, 233/255, 153/255>
#declare lg_light_yellow = texture {
  pigment { color srgb <249/255, 233/255, 153/255> }
  finish  { lg_solid_finish }
}

// 19 TAN / 5 BRICK YELLOW [PEERON]
// PEERON                    <215/255, 197/255, 153/255>
#declare lg_tan = texture {
  pigment { color srgb <215/255, 197/255, 153/255> }
  finish  { lg_solid_finish }
}

// 20 LIGHT VIOLET / 39 LIGHT BLUISH VIOLET [PEERON]
// PEERON                    <193/255, 202/255, 222/255>
#declare lg_light_violet = texture {
 pigment { color srgb <193/255, 202/255, 222/255> }
 finish  { lg_solid_finish }
}

// 21 GLOW IN DARK OPAQUE / 50 PHOSPHORESCENT WHITE [LDRAW]
// LDRAW                     <224/255, 255/255, 176/255>
// PEERON                    <236/255, 232/255, 222/255>
#declare lg_glow_in_dark_opaque = texture {
 pigment { color srgb <224/255, 255/255, 176/255> }
 finish  { lg_solid_finish }
}

// 22 PURPLE / 104 BRIGHT VIOLET [PEERON]
// PEERON                    <107/255, 50/255, 123/255>
#declare lg_purple = texture {
  pigment { color srgb <107/255, 50/255, 123/255> }
  finish  { lg_solid_finish }
}

#declare lg_violet = lg_purple			///////////////////!!!

// 23 DARK BLUE-VIOLET / 196 DARK ROYAL BLUE [PEERON]
// PEERON                    <35/255, 71/255, 139/255>
#declare lg_violet_blue = texture {
  pigment { color srgb <35/255, 71/255, 139/255> }
  finish  { lg_solid_finish }
}

// 24 EDGE COLOUR [LDRAW]

// 25 ORANGE / 106 BRIGHT ORANGE [PEERON]
// PEERON                    <218,133,64>
#declare lg_orange = texture {
  pigment { color srgb <218,133,64>/255 }
  finish  { lg_solid_finish }
}

// 26 MAGENTA / 124 BRIGHT REDDISH VIOLET [PEERON]
// PEERON                    <146/255, 57/255, 120/255>
#declare lg_magenta = texture {
  pigment { color srgb <146/255, 57/255, 120/255> }
  finish  { lg_solid_finish }
}

// 27 LIME / 119 BRIGHT YELLOWISH GREEN [PEERON]
// PEERON                    <164/255, 189/255, 70/255>
#declare lg_lime = texture {
  pigment { color srgb <164/255, 189/255, 70/255> }
  finish  { lg_solid_finish }
}

// 28 DARK TAN / 138 SAND YELLOW [PEERON]
// PEERON                    <149/255, 138/255, 115/255>
#declare lg_dark_tan = texture {
  pigment { color srgb <149/255, 138/255, 115/255> }
  finish  { lg_solid_finish }
}

// 29 BRIGHT PINK / 222 LIGHT PURPLE [PEERON]
// PEERON                    <228/255, 173/255, 200/255>
#declare lg_light_purple = texture {
  pigment { color srgb <228/255, 173/255, 200/255> }
  finish  { lg_solid_finish }
}

// 30 MEDIUM LAVENDER / 324 MEDIUM LAVENDER [LDRAW]
// LDRAW                     <172/255, 120/255, 186/255>
#declare lg_medium_lavender = texture {
  pigment { color srgb <172/255, 120/255, 186/255> }
  finish  { lg_solid_finish }
}

// 31 LAVENDER / 325 LAVENDER [LDRAW]
// LDRAW                     <225,213,237>
#declare lg_lavender = texture {
  pigment { color srgb <225,213,237>/255 }
  finish  { lg_solid_finish }
}

/**************************/
/*   TRANSPARENT COLORS   */
/**************************/

// 32 TRANSPARENT BLACK IR LENS / 109 BLACK IR
#declare lg_black_ir = texture {
  pigment { color srgb <0,20,20>/255
    #if (lg_quality > 1)
      filter 0.14
    #end
  }
  finish  { lg_transparent_finish }
}

// 33 TRANSPARENT DARK BLUE / 43 TRANSPARENT BLUE [PEERON]
// PEERON                    <123/255, 182/255, 232/255>
#declare lg_clear_blue = texture {
  pigment { color srgb <123/255, 182/255, 232/255>
    #if (lg_quality > 1)
      filter TransFilter
      transmit TransTransmit
    #end
  }
  finish  { lg_transparent_finish }
}

// 34 TRANSPARENT GREEN / 48 TRANSPARENT GREEN [PEERON]
// PEERON                    <132/255, 182/255, 141/255>
#declare lg_clear_green = texture {
 pigment { color srgb <132/255, 182/255, 141/255>
  #if (lg_quality > 1)
   filter TransFilter
   transmit TransTransmit
  #end
 }
 finish  { lg_transparent_finish }
}

// 35 TRANSPARENT BRIGHT GREEN / 311 TRANSPARENT BRIGHT GREEN [LDRAW]
// LDRAW                     <217/255, 228/255, 167/255>
#declare lg_clear_bright_green = texture {
  pigment { color srgb <217/255, 228/255, 167/255>
    #if (lg_quality > 1)
      filter TransFilter
      transmit TransTransmit
    #end
  }
  finish  { lg_transparent_finish }
}

// 36 TRANSPARENT RED / 41 TRANSPARENT RED [PEERON]
// PEERON                    <205/255, 84/255, 75/255>
#declare lg_clear_red = texture {
  pigment { color srgb <205/255, 84/255, 75/255>
    #if (lg_quality > 1)
      filter TransFilter
      transmit TransTransmit
    #end
  }
  finish  { lg_transparent_finish }
}

// 37 TRANSPARENT DARK PINK / 113 TRANSPARENT MEDIUM REDDISH VIOLET [PEERON]
// PEERON                    <228/255, 173/255, 200/255>
#declare lg_clear_pink = texture {
  pigment { color srgb <228/255, 173/255, 200/255>
    #if (lg_quality > 1)
      filter TransFilter
      transmit TransTransmit
    #end
  }
  finish  { lg_transparent_finish }
}

// 38 TRANSPARENT NEON ORANGE / 47 TRANSPARENT FLUORESCENT REDDISH ORANGE [LUGNET]
// LUGNET                   <255/255, 43/255, 0/225>
// PEERON                   <217/255, 133/255, 108/255>
#declare lg_clear_neon_orange = texture {
  pigment { color srgb <255/255, 43/255, 0/225>
    #if (lg_quality > 1)
      filter NeonFilter
      transmit NeonTransmit
    #end
  }
  finish  { lg_transparent_neon_finish }
}

// 40 TRANSPARENT BLACK / 111 TRANSPARENT BROWN [LDRAW]
// KOYAN                     <85,79,68>
// LDRAW                     <99,95,82>
// LDRAW (DARKER)            <74,71,62>
// LEGO DIGITAL DESIGNER     <166,145,130>
// PEERON                    <191,183,177>
// CUSTOM                    <77,51,25> [http://www.flickr.com/photos/mtbin/5435835970/]
#declare lg_clear_brown = texture {
  pigment { color srgb <166,145,130>/255  // LEGO DIGITAL DESIGNER
  #if (lg_quality > 1)
   filter 0.5
   transmit 0.6
  #end
  }
  finish  { lg_transparent_finish }
}

// 41 TRANSPARENT LIGHT BLUE / 42 TRANSPARENT LIGHT BLUE [PEERON]
// LEGO COLOUR PALETTE 2011  <182,224,234>
// LUGNET                    <170,229,255>
// PEERON                    <193,223,240>
#declare lg_clear_cyan = texture {
  pigment  { color srgb <170,229,255>/255
  #if (lg_quality > 1)
    filter TransFilter
    transmit TransTransmit
  #end
  }
  finish   { lg_transparent_finish }
}

// 42 TRANS-NEON GREEN / 49 TRANSPARENT FLUORESCENT GREEN [LUGNET]
// LUGNET                    <198,255,0>
// PEERON                    <248,241,132>
#declare lg_clear_neon_green = texture {
  pigment { color srgb <198/255, 255/255, 0/255>
    #if (lg_quality > 1)
      filter NeonFilter
      transmit NeonTransmit
    #end
  }
  finish  { lg_transparent_neon_finish }
}

// 43 TRANSPARENT VERY LIGHT BLUE [LDRAW]
#declare lg_clear_light_blue = texture {
  pigment { color srgb <193,223,240>/255
    #if (lg_quality > 1)
      filter TransFilter
      transmit TransTransmit
    #end
  }
  finish  { lg_transparent_finish }
}

// 44 TRANSPARENT LIGHT PURPLE [LDRAW]
// LDRAW                     <150/255, 112/255, 159/255>
#declare lg_clear_light_purple = texture {
  pigment { color srgb <150/255, 112/255, 159/255>
    #if (lg_quality > 1)
      filter TransFilter
      transmit TransTransmit
    #end
  }
  finish  { lg_transparent_finish }
}

// 46 TRANSPARENT YELLOW / 44 TRANSPARENT YELLOW [PEERON]
// PEERON                    <247/255, 241/255, 141/255>
#declare lg_clear_yellow = texture {
  pigment { color srgb <247/255, 241/255, 141/255>
    #if (lg_quality > 1)
      filter TransFilter
      transmit TransTransmit
    #end
  }
  finish  { lg_transparent_finish }
}

// 47 TRANSPARENT CLEAR / 40 TRANSPARENT [LDRAW]
// LDRAW                     <252,252,252>
// PEERON                    <236,236,236>
#declare lg_clear = texture {
  pigment { color srgb <252,252,252>/255
    #if (lg_quality > 1)
      filter TransFilter
      transmit TransTransmit
    #end
  }
  finish  { lg_transparent_finish }
}

// 52 TRANSPARENT PURPLE / 126 TRANSPARENT BRIGHT BLUISH VIOLET [LEGO COLOUR PALETTE 2011]
// LEGO COLOUR PALETTE 2011  <156,149,199>
// PEERON                    <165,165,203>
#declare lg_clear_violet = texture {
  pigment { color srgb <156,149,199>/255
    #if (lg_quality > 1)
      filter TransFilter
      transmit TransTransmit
    #end
  }
  finish  { lg_transparent_finish }
}

// 54 TRANS-NEON YELLOW / 157 TRANSPARENT FLUORESCENT YELLOW [PEERON]
// PEERON                    <255,246,123>
#declare lg_clear_neon_yellow = texture {
  pigment { color srgb <255/255, 246/255, 123/255>
    #if (lg_quality > 1)
      filter NeonFilter
      transmit NeonTransmit
    #end
  }
  finish  { lg_transparent_neon_finish }
}

// 57 TRANSPARENT ORANGE / 182 TRANSPARENT BRIGHT ORANGE [LDRAW]
// LDRAW                     <240,143,28>
// LEGO DIGITAL DESIGNER     <226,176,96>
// LEGO COLOUR PALETTE 2011  <236,118,14>
#declare lg_clear_orange = texture {
  pigment { color srgb <226,176,96>/255
    #if (lg_quality > 1)
      filter TransFilter
      transmit TransTransmit
    #end
  }
  finish  { lg_transparent_finish }
}

/*******************************/
/*   SOLID COLOURS CONTINUED   */
/*******************************/

// 68 VERY LIGHT ORANGE / 36 LIGHT YELLOWISH ORANGE [PEERON]
// PEERON                    <243/255, 207/255, 155/255>
#declare lg_very_light_orange = texture {
 pigment { color srgb <243/255, 207/255, 155/255> }
 finish  { lg_solid_finish }
}

// 69 BRIGHT PURPLE / 198 BRIGHT REDDISH LILAC [PEERON]
// PEERON                    <142/255, 66/255, 133/255>
#declare lg_bright_purple = texture {
 pigment { color srgb <142/255, 66/255, 133/255> }
 finish  { lg_solid_finish }
}

// 70 REDDISH BROWN / 192 REDDISH BROWN [PEERON]
// PEERON                    <105/255, 64/255, 39/255>
#declare lg_reddish_brown = texture {
 pigment { color srgb <105/255, 64/255, 39/255> }
 finish  { lg_solid_finish }
}

// 71 LIGHT BLUISH GRAY / 194 MEDIUM STONE GREY [PEERON]
// PEERON                    <163/255, 162/255, 164/255>
#declare lg_bluish_grey = texture {
 pigment { color srgb <163/255, 162/255, 164/255> }
 finish  { lg_solid_finish }
}

// 72 DARK BLUISH GREY / 199 DARK STONE GREY [PEERON]
// PEERON                    <99/255, 95/255, 97/255>
#declare lg_dark_bluish_grey = texture {
 pigment { color srgb <99/255, 95/255, 97/255> }
 finish  { lg_solid_finish }
}

// 73 MEDIUM BLUE / 102 MEDIUM BLUE
// PEERON                    <110/255, 153/255, 201/255>
#declare lg_medium_blue = texture {
 pigment { color srgb <110/255, 153/255, 201/255> }
 finish  { lg_solid_finish }
}

// 74 MEDIUM GREEN / 29 MEDIUM GREEN [PEERON]
// PEERON                    <161/255, 196/255, 139/255>
#declare lg_medium_green = texture {
 pigment { color srgb <161/255, 196/255, 139/255> }
 finish  { lg_solid_finish }
}

// 75 SPECKLE BLACK COPPER

// 76 SPECKLE DARK BLUISH GRAY SILVER

// 77 LIGHT PINK / 223 LIGHT PINK [PEERON]
// PEERON                    <220,144,149>
#declare lg_paradisa_pink = texture {
  pigment { color srgb <220,144,149>/255 }
  finish  { lg_solid_finish }
}

// 78 LIGHT FLESH / 283 LIGHT NOUGAT [LDRAW]
// LEGO COLOUR PALETTE 2011  <245,193,137>
// LDRAW                     <246,215,179>
#declare lg_light_flesh = texture {
  pigment { color srgb <246,215,179>/255 }
  finish  { lg_solid_finish }
}

// 79 MILKY WHITE / 20 NATURE [LDRAW]
// LDRAW                     <255,255,255>/255
#declare lg_milky_white = texture {
  pigment { color srgb <255,255,255>/255
    #if (lg_quality > 1)
      filter NeonFilter
      transmit NeonTransmit
    #end
  }
  finish  { lg_transparent_neon_finish }
}

// 80 METALLIC SILVER [LEGO DIGITAL DESIGNER]
// LDRAW                     <165,169,180>/255
// LEGO COLOUR PALETTE 2011  <141,148,150>/255
// LEGO DIGITAL DESIGNER     <140,140,140>/255
#declare lg_metallic_silver = texture {
  pigment { color srgb <140,140,140>/255 }
  finish  { lg_metallic_finish }
  normal  { lg_pearl_normal }
}

// 82 METALLIC GOLD [LDRAW]
// LDRAW                     <219,172,52>
#declare lg_metallic_gold = texture {
  pigment { color srgb <219,172,52>/255 }
  finish  { lg_metallic_finish }
  normal  { lg_pearl_normal }
}

// 84 MEDIUM DARK FLESH	/ 312 MEDIUM NOUGAT [LEGO DIGITAL DESIGNER]
// LDRAW                     <204,112,42>/255
// LEGO DIGITAL DESIGNER     <170,125,85>/255
#declare lg_medium_dark_flesh = texture {
  pigment { color srgb <170,125,85>/255 }
  finish  { lg_solid_finish }
}

// 85 DARK PURPLE / 268 MEDIUM LILAC [PEERON]
// PEERON                    <52/255, 43/255, 117/255>
#declare lg_dark_purple = texture {
  pigment { color srgb <52/255, 43/255, 117/255> }
  finish  { lg_solid_finish }
}

// 86 DARK FLESH / 217 BROWN [PEERON]
// PEERON                    <124/255, 92/255, 69/255>
#declare lg_dark_flesh = texture {
 pigment { color srgb <124/255, 92/255, 69/255> }
 finish  { lg_solid_finish }
}

// 87 METALLIC DARK GREEY / 309 METALIZED SILVER

// 89 BLUE VIOLET
#declare lg_royal_blue = texture {
 pigment { color srgb <155/255, 178/255, 239/255> }
 finish  { lg_solid_finish }
}

// 92 FLESH / 18 NOUGAT [PEERON]
#declare lg_flesh = texture {
 pigment { color srgb <204/255, 142/255, 104/255> }
 finish  { lg_solid_finish }
}

// 100 LIGHT SALMON / 100 LIGHT RED [PEERON]
#declare lg_light_salmon = texture {
 pigment { color srgb <238,196,182>/255 }
 finish  { lg_solid_finish }
}
#declare lg_light_red = lg_light_salmon			///////////////////!!!

// 110 VIOLET / 110 BRIGHT BLUISH VIOLET

// 112 MEDIUM VIOLET / 112 MEDIUM BLUISH VIOLET
#declare lg_medium_violet = texture {
 pigment { color srgb <201,202,226>/255 }
 finish  { lg_solid_finish }
}

// 114 GLITTER TRANS DARK PINK

// 115 MEDIUM LIME / MEDIUM YELLOWISH GREEN
#declare lg_medium_lime = texture {
 pigment { color srgb <199/255, 210/255, 60/255> }
 finish  { lg_solid_finish }
}

// 117 GLITTER TRANS CLEAR

// 118 AQUA / 118 LIGHT BLUISH GREEN

// 120 LIGHT LIME / 120 LIGHT YELLOWISH GREEN

// 125 LIGHT ORANGE / 125 LIGHT ORANGE

// 129 GLITTER TRANS PURPLE

// 132 SPECKLE BLACK SILVER

// 133 SPECKLE BLACK GOLD

// 134 COPPER / 139 COPPER [LDRAW]
#declare lg_pearl_copper = texture {
 pigment { color srgb <174/255, 122/255, 89/255> }
 finish  { lg_pearl_finish }
}

// 135 PEARL LIGHT GREY / SILVER
#declare lg_pearl_grey = texture {
  pigment { color srgb <171/255, 173/255, 172/255> }
  finish  { lg_pearl_finish }
  normal  { lg_pearl_normal }
}

// 137 METAL BLUE / 145 SAND BLUE METALLIC
#declare lg_pearl_blue = texture {
  pigment { color srgb <106,122,150>/255 }
  finish  { lg_pearl_finish }
}

// 142 PEARL LIGHT GOLD / 127 GOLD
#declare lg_pearl_light_gold = texture {
  pigment { color srgb <220,188,129>/255 }
  finish  { lg_pearl_finish }
  normal  { lg_pearl_normal }
}

// 143 TRANSPARENT MEDIUM BLUE

// 148 PEARL DARK GRAY / 148 METALLIC DARK GREY
// LDRAW ORIGINAL            <87,88,87>
// LEGO COLOUR PALETTE 2011  <73,63,59>
// LEGO DIGITAL DESIGNER     <62,60,57>
#declare lg_pearl_dark_grey = texture {
  pigment { color srgb <62,60,57>/255 }
  finish  { lg_pearl_finish }
  normal  { lg_pearl_normal }
}

// 150 PEARL VERY LIGHT GRAY

// 151 VERY LIGHT BLUISH GRAY / 208 LIGHT STONE GREY [PEERON]
#declare lg_very_light_bluish_grey = texture {
  pigment { color srgb <14,94,77>/255 }
  finish  { lg_solid_finish }

}

// 178 FLAT DARK GOLD / 187 SAND YELLOW METALLIC

// 179 FLAT SILVER / 131 SILVER [LEGO DIGITAL DESIGNER]
#declare lg_flat_silver = texture {
  pigment { color srgb <160,160,160>/255 }
  finish  { lg_pearl_finish }
  normal  { lg_pearl_normal }
}

// 183 PEARL WHITE [LDRAW]
#declare lg_pearl_white = texture {
  pigment { color srgb <242,243,242>/255 }
  finish  { lg_pearl_finish }
  normal  { lg_pearl_normal }
}

// 191 BRIGHT LIGHT ORANGE / 191 FLAME YELLOWISH ORANGE [PEERON]
// PEERON <248,187,61>/255
#declare lg_bright_light_orange = texture {
  pigment { color srgb <248,187,61>/255 }
  finish  { lg_solid_finish }

}

// 212 BRIGHT LIGHT BLUE / 212 LIGHT ROYAL BLUE [PEERON]
#declare lg_bright_light_blue = texture {
  pigment { color srgb <159,195,233>/255 }
  finish  { lg_solid_finish }

}

// 216 RUST / 216 RUST [PEERON]
// LEGO DIGITAL DESIGNER     <135,43,23>
// LDRAW                     <179,16,4>
// PEERON                    <143,76,42>
#declare lg_rust = texture {
  pigment { color srgb <143,76,42>/255 }
  finish  { lg_solid_finish }
}

// 226 BRIGHT LIGHT YELLOW / 226 COOL YELLOW [PEERON]
// PEERON                    <253,234,140>
#declare lg_bright_light_yellow = texture {
  pigment { color srgb <253,234,140>/255 }
  finish  { lg_solid_finish }

}

// 232 SKY BLUE / 232 DOVE BLUE [PEERON]
// PEERON                    <125/255, 187/255, 221/255>
#declare lg_sky_blue = texture {
  pigment { color srgb <125/255, 187/255, 221/255> }
  finish  { lg_solid_finish }
}

// 236 TRANSPARENT LIGHT PURPLE

// 272 DARK BLUE / 140 EARTH BLUE [PEERON]
#declare lg_dark_blue = texture {
  pigment { color srgb <32/255, 58/255, 86/255> }
  finish  { lg_solid_finish }
}

// 288 DARK GREEN / 141 EARTH GREEN [PEERON]
#declare lg_dark_green = texture {
  pigment { color srgb <39,70,44>/255 }
  finish  { lg_solid_finish }
}

// 294 TRANSPARENT GLOW IN THE DARK / 50 PHOSPHORESCENT WHITE [LDRAW]
// LDRAW                     <189,198,173>/255
#declare lg_glow_in_dark_clear = texture {
  pigment { color srgb <189,198,173>/255
    #if (lg_quality > 1)
      filter TransFilter
    #end
  }
  finish  { lg_transparent_neon_finish }
  normal  { lg_transparent_normal }
}

// 297 PEARL GOLD / 297 WARM GOLD [LDRAW]
#declare lg_pearl_gold = texture {
  pigment { color srgb <170/255, 127/255, 46/255> }
  finish  { lg_pearl_finish }
  normal  { lg_pearl_normal }
}

// 308 DARK BROWN / 308 DARK BROWN
#declare lg_dark_brown = texture {
  pigment { color srgb <53,33,0>/255 }
  finish  { lg_solid_finish }
}

// 313 MAERSK BLUE / 11 PASTEL BLUE [LDD]
#declare lg_maersk_blue = texture {
  pigment { color srgb <171/255, 217/255, 255/255> }
  finish  { lg_solid_finish }
}

// 320 DARK RED / 154 DARK RED [PEERON]
#declare lg_dark_red = texture {
  pigment { color srgb <123,46,47>/255 }
  finish  { lg_solid_finish }
}

// 321 DARK AZURE / 321 DARK AZUR
#declare lg_dark_azur = texture {
  pigment { color srgb <70,155,195>/255 }
  finish  { lg_solid_finish }
}

// 322 MEDIUM AZURE / 322 MEDIUM AZUR
#declare lg_medium_azur = texture {
  pigment { color srgb <104,195,226>/255 }
  finish  { lg_solid_finish }
}

// 323 LIGHT AQUA / 323 AQUA [LEGO COLOR PALETTE 2011]
#declare lg_light_aqua = texture {
  pigment { color srgb <211,242,234>/255 }
  finish  { lg_solid_finish }
}

// 326 SPRING YELLOWISH GREEN [LEGO DIGITAL DESIGNER]
#declare lg_spring_yellowish_green = texture {
  pigment { color srgb <226,249,154>/255 }
  finish  { lg_solid_finish }
}

// 330 OLIVE GREEN / 330 OLIVE GREEN [LEGO DIGITAL DESIGNER]
#declare lg_olive_green = texture {
  pigment { color srgb <119,119,78>/255 }
  finish  { lg_solid_finish }
}

// 334 CHROME GOLD [LDRAW]
#declare lg_chrome_gold = texture {
  pigment { color srgb <187,165,61>/255 }
  finish  { lg_chrome_finish }
  normal  { lg_chrome_normal }
}

// 335 SAND RED / 153 SAND RED [PEERON]
// PEERON                    <149/255, 121/255, 118/255>
#declare lg_sand_red = texture {
 pigment { color srgb <149/255, 121/255, 118/255> }
 finish  { lg_solid_finish }
}

// 351 MEDIUM DARK PINK / 22 MEDIUM REDDISH VIOLET

// 366 EARTH ORANGE / 12 LIGHT ORANGE BROWN
#declare lg_earth_orange = texture {
 pigment { color srgb <209/255, 131/255, 4/255> }
 finish  { lg_solid_finish }
}

// 373 SAND PURPLE / 136 SAND VIOLET [PEERON]
#declare lg_sand_purple = texture {
 pigment { color srgb <135/255, 124/255, 144/255> }
 finish  { lg_solid_finish }
}

// 378 SAND GREEN / 151 SAND GREEN [PEERON]
#declare lg_sand_green = texture {
 pigment { color srgb <120/255, 144/255, 129/255> }
 finish  { lg_solid_finish }
}

// 379 SAND BLUE [OFFICIAL]
#declare lg_sand_blue = texture {
 pigment { color srgb <94/255, 116/255, 140/255> }
 finish  { lg_solid_finish }
}

// 383 CHROME SILVER [LDRAW]
#declare lg_chrome = texture {
  pigment { color srgb <224,224,224>/255 }
  finish  { lg_chrome_finish }
  normal  { lg_chrome_normal }
}

// 450 FABULAND BROWN / 12 LIGHT ORANGE BROWN [PEERON]
// PEERON                    <203/255, 132/255, 66/255>
#declare lg_fabuland_brown = texture {
  pigment { color srgb <203/255, 132/255, 66/255> }
  finish  { lg_solid_finish }

}

// 462 MEDIUM ORANGE / 105 BRIGHT YELLOWISH ORANGE [PEERON]
// PEERON                    <226/255, 155/255, 63/255>
#declare lg_light_orange = texture {
  pigment { color srgb <226/255, 155/255, 63/255> }
  finish  { lg_solid_finish }

}

// 484 DARK ORANGE / 38 DARK ORANGE [PEERON]
// PEERON                    <160/255, 95/255, 52/255>
#declare lg_dark_orange = texture {
  pigment { color srgb <160/255, 95/255, 52/255> }
  finish  { lg_solid_finish }

}

// 493 MAGNET [LDRAW]
#declare lg_magnet = texture {
  pigment { color srgb <101/255, 103/255, 97/255> }
  finish  { lg_rubber_finish }
  normal  { lg_pearl_normal }
}

// 494 ELECTRIC CONTACT ALLOY [LDRAW]
#declare lg_electric_contact_alloy = texture {
  pigment { color srgb <208,208,208>/255 }
  finish  { lg_metallic_finish }
}

// 495 ELECTRIC CONTACT COPPER

// 503 VERY LIGHT GREY / 103 LIGHT GREY [PEERON]
// PEERON                    <199/255, 193/255, 183/255>
#declare lg_very_light_grey = texture {
  pigment { color srgb <199/255, 193/255, 183/255> }
  finish  { lg_solid_finish }

}

// 999
#declare lg_undefined = texture {
  pigment { color srgb <0.5, 0.7, 0.9> }
}

// 998 (no code known) / 137 MEDIUM ORANGE [PEERON]
#declare lg_medium_orange = texture {
  pigment { color srgb <224/255, 152/255, 100/255> }
  finish  { lg_solid_finish }

}

/*********************/
/*   RUBBER COLORS   */
/*********************/

// 65 RUBBER YELLOW [LDRAW]
#declare lg_rubber_yellow = texture {
  pigment { color srgb <236/255, 201/255, 53/255> }
  finish  { lg_rubber_finish }
  normal  { lg_rubber_normal }
}

// 66 RUBBER TRANSPARENT YELLOW [LDRAW]
#declare lg_rubber_clear_yellow = texture {
  pigment { color srgb <202/255, 176/255, 0/255>
    filter TransFilter
    transmit TransTransmit
  }
  finish  { lg_rubber_finish }
  normal  { lg_rubber_normal }
}

// 67 RUBBER TRANSPARENT CLEAR [LDRAW]
#declare lg_rubber_clear = texture {
  pigment { color srgb <255/255, 255/255, 255/255>
    filter TransFilter
    transmit TransTransmit
  }
  finish  { lg_rubber_finish }
  normal  { lg_rubber_normal }
}

// 256 RUBBER BLACK [LDRAW]
#declare lg_rubber_black = texture {
  pigment { color srgb <33/255, 33/255, 33/255> }
  finish  { lg_rubber_finish }
  normal  { lg_rubber_normal }
}

// 273 RUBBER BLUE [LDRAW]
// LDRAW                     <0,51,178>
// BRIGHT BLUE               <13,105,171>
#declare lg_rubber_blue = texture {
  pigment { color srgb <13,105,171>/255 }
  finish  { lg_rubber_finish }
  normal  { lg_rubber_normal }
}

// 324 RUBBER RED [LDRAW]
#declare lg_rubber_red = texture {
  pigment { color srgb <196/255, 0/255, 38/255> }
  finish  { lg_rubber_finish }
  normal  { lg_rubber_normal }
}

// 375 RUBBER LIGHT GRAY [LDRAW]
#declare lg_rubber_light_gray = texture {
  pigment { color srgb <193/255, 194/255, 193/255> }
  finish  { lg_rubber_finish }
  normal  { lg_rubber_normal }
}

// 406 RUBBER DARK BLUE [LDRAW]
#declare lg_rubber_dark_blue = texture {
  pigment { color srgb <0/255, 29/255, 104/255> }
  finish  { lg_rubber_finish }
  normal  { lg_rubber_normal }
}

// 449 RUBBER PURPLE [LDRAW]
#declare lg_rubber_purple = texture {
  pigment { color srgb <129/255, 0/255, 123/255> }
  finish  { lg_rubber_finish }
}

// 490 RUBBER LIME [LDRAW]
#declare lg_rubber_lime = texture {
  pigment { color srgb <215/255, 240/255, 0/255> }
  finish  { lg_rubber_finish }
  normal  { lg_rubber_normal }
}

// 496 RUBBER LIGHT BLUISH GRAY [LDRAW]
#declare lg_rubber_light_bluish_gray = texture {
  pigment { color srgb <163/255, 162/255, 164/255> }
  finish  { lg_rubber_finish }
  normal  { lg_rubber_normal }
}

// 504 RUBBER FLAT SILVER [LDRAW]
#declare lg_rubber_flat_silver = texture {
  pigment { color srgb <137/255, 135/255, 136/255> }
  finish  { lg_rubber_finish }
  normal  { lg_rubber_normal }
}

// 511 RUBBER WHITE [LDRAW]
#declare lg_rubber_white = texture {
  pigment { color srgb <250/255, 250/255, 250/255> }
  finish  { lg_rubber_finish }
  normal  { lg_rubber_normal }
}

#end
