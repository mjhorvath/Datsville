// POV-Ray scripts for LDraw models and scenes
// Copyright (C) 2019  Michael Horvath
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// When I get a chance, this file should be reverted as much as possible 
// back to the LDCad defaults.

#version 3.7;

//=====LDraw materials====================================================================================================
#declare ldColorCount=160;
#declare ldColor=array[ldColorCount][5] {
 {0,0.019608,0.07451,0.113725,1},
 {1,0,0.333333,0.74902,1},
 {2,0.145098,0.478431,0.243137,1},
 {3,0,0.513726,0.560784,1},
 {4,0.788235,0.101961,0.035294,1},
 {5,0.784314,0.439216,0.627451,1},
 {6,0.345098,0.223529,0.152941,1},
 {7,0.607843,0.631373,0.615686,1},
 {8,0.427451,0.431373,0.360784,1},
 {9,0.705882,0.823529,0.890196,1},
 {10,0.294118,0.623529,0.290196,1},
 {11,0.333333,0.647059,0.686275,1},
 {12,0.94902,0.439216,0.368627,1},
 {13,0.988235,0.592157,0.67451,1},
 {14,0.94902,0.803922,0.215686,1},
 {15,1,1,1,1},
 {17,0.760784,0.854902,0.721569,1},
 {18,0.984314,0.901961,0.588235,1},
 {19,0.894118,0.803922,0.619608,1},
 {20,0.788235,0.792157,0.886275,1},
 {21,0.878431,1,0.690196,0.941176},
 {22,0.505882,0,0.482353,1},
 {23,0.12549,0.196078,0.690196,1},
 {25,0.996078,0.541176,0.094118,1},
 {26,0.572549,0.223529,0.470588,1},
 {27,0.733333,0.913725,0.043137,1},
 {28,0.584314,0.541176,0.45098,1},
 {29,0.894118,0.678431,0.784314,1},
 {30,0.67451,0.470588,0.729412,1},
 {31,0.882353,0.835294,0.929412,1},
 {32,0,0,0,0.823529},
 {33,0,0.12549,0.627451,0.501961},
 {34,0.137255,0.470588,0.254902,0.501961},
 {35,0.337255,0.901961,0.27451,0.501961},
 {36,0.788235,0.101961,0.035294,0.501961},
 {37,0.87451,0.4,0.584314,0.501961},
 {38,1,0.501961,0.05098,0.501961},
 {39,0.756863,0.87451,0.941176,0.501961},
 {40,0.388235,0.372549,0.321569,0.501961},
 {41,0.333333,0.603922,0.717647,0.501961},
 {42,0.752941,1,0,0.501961},
 {43,0.682353,0.913725,0.937255,0.501961},
 {44,0.588235,0.439216,0.623529,0.501961},
 {45,0.988235,0.592157,0.67451,0.501961},
 {46,0.960784,0.803922,0.184314,0.501961},
 {47,0.988235,0.988235,0.988235,0.501961},
 {52,0.647059,0.647059,0.796078,0.501961},
 {54,0.854902,0.690196,0,0.501961},
 {57,0.941176,0.560784,0.109804,0.501961},
 {60,0.392157,0.352941,0.298039,1},
 {61,0.423529,0.588235,0.74902,1},
 {62,0.235294,0.701961,0.443137,1},
 {63,0.666667,0.301961,0.556863,1},
 {64,0.105882,0.164706,0.203922,1},
 {65,0.960784,0.803922,0.184314,1},
 {66,0.792157,0.690196,0,0.501961},
 {67,1,1,1,0.501961},
 {68,0.952941,0.811765,0.607843,1},
 {69,0.803922,0.384314,0.596078,1},
 {70,0.345098,0.164706,0.070588,1},
 {71,0.627451,0.647059,0.662745,1},
 {72,0.423529,0.431373,0.407843,1},
 {73,0.360784,0.615686,0.819608,1},
 {74,0.45098,0.862745,0.631373,1},
 {75,0,0,0,1},
 {76,0.388235,0.372549,0.380392,1},
 {77,0.996078,0.8,0.811765,1},
 {78,0.964706,0.843137,0.701961,1},
 {79,1,1,1,0.941176},
 {80,0.647059,0.662745,0.705882,1},
 {81,0.537255,0.607843,0.372549,1},
 {82,0.858824,0.67451,0.203922,1},
 {83,0.101961,0.156863,0.192157,1},
 {84,0.8,0.439216,0.164706,1},
 {85,0.247059,0.211765,0.568627,1},
 {86,0.486275,0.313726,0.227451,1},
 {87,0.427451,0.431373,0.360784,1},
 {89,0.298039,0.380392,0.858824,1},
 {92,0.815686,0.568627,0.407843,1},
 {100,0.996078,0.729412,0.741176,1},
 {110,0.262745,0.329412,0.639216,1},
 {112,0.407843,0.454902,0.792157,1},
 {114,0.87451,0.4,0.584314,0.501961},
 {115,0.780392,0.823529,0.235294,1},
 {117,1,1,1,0.501961},
 {118,0.701961,0.843137,0.819608,1},
 {120,0.85098,0.894118,0.654902,1},
 {125,0.976471,0.729412,0.380392,1},
 {128,0.678431,0.380392,0.25098,1},
 {129,0.392157,0,0.380392,0.501961},
 {132,0,0,0,1},
 {133,0,0,0,1},
 {134,0.588235,0.290196,0.152941,1},
 {135,0.611765,0.639216,0.658824,1},
 {137,0.337255,0.466667,0.729412,1},
 {142,0.862745,0.745098,0.380392,1},
 {148,0.341176,0.345098,0.341176,1},
 {150,0.733333,0.741176,0.737255,1},
 {151,0.901961,0.890196,0.878431,1},
 {178,0.705882,0.533333,0.243137,1},
 {179,0.537255,0.529412,0.533333,1},
 {183,0.94902,0.952941,0.94902,1},
 {184,0.839216,0,0.14902,1},
 {186,0,0.556863,0.235294,1},
 {189,0.67451,0.509804,0.278431,1},
 {191,0.972549,0.733333,0.239216,1},
 {212,0.52549,0.756863,0.882353,1},
 {216,0.701961,0.062745,0.015686,1},
 {218,0.556863,0.333333,0.592157,1},
 {219,0.337255,0.305882,0.615686,1},
 {226,1,0.941176,0.227451,1},
 {231,0.988235,0.717647,0.427451,0.501961},
 {232,0.337255,0.745098,0.839216,1},
 {234,0.984314,0.909804,0.564706,0.501961},
 {256,0.129412,0.129412,0.129412,1},
 {272,0.05098,0.196078,0.356863,1},
 {273,0,0.2,0.698039,1},
 {284,0.760784,0.505882,0.647059,0.501961},
 {285,0.490196,0.760784,0.568627,0.501961},
 {288,0.094118,0.27451,0.196078,1},
 {293,0.419608,0.670588,0.894118,0.501961},
 {294,0.741176,0.776471,0.678431,0.941176},
 {295,1,0.580392,0.760784,1},
 {297,0.8,0.611765,0.168627,1},
 {300,0.760784,0.498039,0.32549,1},
 {302,0.682353,0.913725,0.937255,0.501961},
 {308,0.207843,0.129412,0,1},
 {313,0.329412,0.662745,0.784314,1},
 {320,0.447059,0.054902,0.058824,1},
 {321,0.078431,0.596078,0.843137,1},
 {322,0.243137,0.760784,0.866667,1},
 {323,0.741176,0.862745,0.847059,1},
 {324,0.768627,0,0.14902,1},
 {326,0.87451,0.933333,0.647059,1},
 {329,0.960784,0.952941,0.843137,0.941176},
 {330,0.607843,0.603922,0.352941,1},
 {334,0.733333,0.647059,0.239216,1},
 {335,0.839216,0.458824,0.447059,1},
 {339,0.752941,1,0,0.501961},
 {350,0.815686,0.4,0.062745,1},
 {351,0.968627,0.521569,0.694118,1},
 {366,0.980392,0.611765,0.109804,1},
 {373,0.517647,0.368627,0.517647,1},
 {375,0.756863,0.760784,0.756863,1},
 {378,0.627451,0.737255,0.67451,1},
 {379,0.34902,0.443137,0.517647,1},
 {383,0.878431,0.878431,0.878431,1},
 {406,0,0.113725,0.407843,1},
 {449,0.505882,0,0.482353,1},
 {450,0.713726,0.482353,0.313726,1},
 {462,1,0.654902,0.043137,1},
 {484,0.662745,0.333333,0,1},
 {490,0.843137,0.941176,0,1},
 {493,0.396078,0.403922,0.380392,1},
 {494,0.815686,0.815686,0.815686,1},
 {495,0.682353,0.478431,0.34902,1},
 {496,0.639216,0.635294,0.643137,1},
 {503,0.901961,0.890196,0.854902,1},
 {504,0.537255,0.529412,0.533333,1},
 {511,0.980392,0.980392,0.980392,1}
}

#macro getColorIndex(ldCode)
 #local result=-1;
 #local i=0;
 #while (result=-1 & i<ldColorCount)
  #if (ldColor[i][0]=ldCode)
    #local result=i;
  #else
    #local i=i+1;
  #end
 #end
 result
#end


//-----Base tex/mat properties--------------------------------------------------------------------------------------------

#declare ldTranslucency = <0.1,0.1,0.1>;

#local ldrawPlasticNor=normal {
 bumps 0.001
 scale 0.5
 turbulence 0
};

#local ldrawPlasticFin=finish {
 brilliance 1
 diffuse 1
 specular albedo 0.1
 roughness 0.01
 reflection 0.05
 conserve_energy
};

#local ldrawPlasticTrans_ior=1.6;

#local ldrawRubberNor=normal {
 dents 0.01
 scale 0.25
 turbulence 0
}

#local ldrawRubberFin=finish {
 diffuse 1
 brilliance 0.05
 specular albedo 0.1
 roughness 0.05
 conserve_energy
}

#local ldrawRubberTrans_ior=2.5;

#local ldrawMetalNor=normal {
 dents 0.01
 scale 0.25
 turbulence 0
};

#local ldrawMetalFin=finish {
 brilliance 3
 diffuse 0.9
 metallic
 specular 0.70
 roughness 1/60
 reflection 0.25
};

#local ldrawMatteMetalNor=normal {
 dents 0.01
 scale 0.25
 turbulence 0
};

#local ldrawMatteMetalFin=finish {
 brilliance 3
 diffuse 0.9
 metallic
 specular 0.70
 roughness 1/60
 reflection 0.25
};

#local ldrawChromeNor=normal {
 bumps 0.01
 scale 0.1
 turbulence 0
};

#local ldrawChromeFin=finish {
 brilliance 6
 diffuse 0.7
 metallic
 specular 0.80
 roughness 1/120
 reflection 0.8
};

#local ldrawPearlNor=normal {
 dents 0.01
 scale 0.25
 turbulence 0
};

#local ldrawPearlFin=finish {
 brilliance 3
 diffuse 0.9
 metallic
 specular 0.70
 roughness 1/60
 reflection 0.25
};


//-----tex/mat helper macros----------------------------------------------------------------------------------------------
#macro ldrawPigment(colIdx, forMat)

 #local r=ldColor[colIdx][1];
 #local g=ldColor[colIdx][2];
 #local b=ldColor[colIdx][3];
 #local a=ldColor[colIdx][4];
 #local isTrans=(a<1.0);

 #if (isTrans)
  #if (forMat)
    //Transparency is done trough interior
    #local flt=0.0;
    #local tr=1.0;
  #else
    #local flt=a;
    #local tr=1.0-a;
  #end

  #local result=pigment { srgbft <r,g,b, flt, tr> };
  result
 #else
  #local result=pigment { srgb <r,g,b> };
  result
 #end
#end

#macro ldrawBuildTex(basePigment, baseNormal, baseFinish, pngIdx)
	#if (pngIdx < 0)
		pigment { basePigment }
		normal { baseNormal }
		finish { baseFinish }
	#else
		#local texPigment= pigment
		{
			uv_mapping
			image_map
			{
				png getPngName(pngIdx)
				getPngMapType(pngIdx)
				interpolate 2
			}
			getPngWarp(pngIdx)
		}
		texture
		{
			pigment { texPigment }
		}
		texture
		{
			pigment { basePigment }
			normal { baseNormal }
			finish { baseFinish }
		}
	#end
#end

#macro ldrawBuildMat(ldCode, tex, iorValue)

 texture { tex }
 #local idx=getColorIndex(ldCode);
 #if (ldColor[idx][4]<1.0)
  interior {
    ior iorValue
    fade_power 1
    fade_distance 1
    fade_color <ldColor[idx][1], ldColor[idx][2], ldColor[idx][3]>
  }
 #end
#end


//-----Main tex/mat macros------------------------------------------------------------------------------------------------
#macro ldrawTexPlastic(ldCode, pngIdx, forMat)
 ldrawBuildTex(ldrawPigment(getColorIndex(ldCode), forMat), ldrawPlasticNor, ldrawPlasticFin, pngIdx)
#end

#macro ldrawMatPlastic(ldCode, tex)
 ldrawBuildMat(ldCode, tex, ldrawPlasticTrans_ior)
#end

#macro ldrawTexRubber(ldCode, pngIdx, forMat)
 ldrawBuildTex(ldrawPigment(getColorIndex(ldCode), forMat), ldrawRubberNor, ldrawRubberFin, pngIdx)
#end

#macro ldrawMatRubber(ldCode, tex)
 ldrawBuildMat(ldCode, tex, ldrawRubberTrans_ior)
#end

#macro ldrawTexMetal(ldCode, pngIdx, forMat)
 ldrawBuildTex(ldrawPigment(getColorIndex(ldCode), forMat), ldrawMetalNor, ldrawMetalFin, pngIdx)
#end

#macro ldrawMatMetal(ldCode, tex)
 ldrawBuildMat(ldCode, tex, -1)
#end

#macro ldrawTexMatteMetal(ldCode, pngIdx, forMat)
 ldrawBuildTex(ldrawPigment(getColorIndex(ldCode), forMat), ldrawMatteMetalNor, ldrawMatteMetalFin, pngIdx)
#end

#macro ldrawMatMatteMetal(ldCode, tex)
 ldrawBuildMat(ldCode, tex, -1)
#end

#macro ldrawTexChrome(ldCode, pngIdx, forMat)
 ldrawBuildTex(ldrawPigment(getColorIndex(ldCode), forMat), ldrawChromeNor, ldrawChromeFin, pngIdx)
#end

#macro ldrawMatChrome(ldCode, tex)
 ldrawBuildMat(ldCode, tex, -1)
#end

#macro ldrawTexPearl(ldCode, pngIdx, forMat)
 ldrawBuildTex(ldrawPigment(getColorIndex(ldCode), forMat), ldrawPearlNor, ldrawPearlFin, pngIdx)
#end

#macro ldrawMatPearl(ldCode, tex)
 ldrawBuildMat(ldCode, tex, -1)
#end


//-----Tex/mat defines----------------------------------------------------------------------------------------------------
#declare ldTex0=texture {
 ldrawTexPlastic(0, -1, false)
}

#declare ldMat0=material {
 ldrawMatPlastic(0, texture { ldrawTexPlastic(0, -1, true) })
}

#declare ldTex1=texture {
 ldrawTexPlastic(1, -1, false)
}

#declare ldMat1=material {
 ldrawMatPlastic(1, texture { ldrawTexPlastic(1, -1, true) })
}

#declare ldTex2=texture {
 ldrawTexPlastic(2, -1, false)
}

#declare ldMat2=material {
 ldrawMatPlastic(2, texture { ldrawTexPlastic(2, -1, true) })
}

#declare ldTex3=texture {
 ldrawTexPlastic(3, -1, false)
}

#declare ldMat3=material {
 ldrawMatPlastic(3, texture { ldrawTexPlastic(3, -1, true) })
}

#declare ldTex4=texture {
 ldrawTexPlastic(4, -1, false)
}

#declare ldMat4=material {
 ldrawMatPlastic(4, texture { ldrawTexPlastic(4, -1, true) })
}

#declare ldTex5=texture {
 ldrawTexPlastic(5, -1, false)
}

#declare ldMat5=material {
 ldrawMatPlastic(5, texture { ldrawTexPlastic(5, -1, true) })
}

#declare ldTex6=texture {
 ldrawTexPlastic(6, -1, false)
}

#declare ldMat6=material {
 ldrawMatPlastic(6, texture { ldrawTexPlastic(6, -1, true) })
}

#declare ldTex7=texture {
 ldrawTexPlastic(7, -1, false)
}

#declare ldMat7=material {
 ldrawMatPlastic(7, texture { ldrawTexPlastic(7, -1, true) })
}

#declare ldTex8=texture {
 ldrawTexPlastic(8, -1, false)
}

#declare ldMat8=material {
 ldrawMatPlastic(8, texture { ldrawTexPlastic(8, -1, true) })
}

#declare ldTex9=texture {
 ldrawTexPlastic(9, -1, false)
}

#declare ldMat9=material {
 ldrawMatPlastic(9, texture { ldrawTexPlastic(9, -1, true) })
}

#declare ldTex10=texture {
 ldrawTexPlastic(10, -1, false)
}

#declare ldMat10=material {
 ldrawMatPlastic(10, texture { ldrawTexPlastic(10, -1, true) })
}

#declare ldTex11=texture {
 ldrawTexPlastic(11, -1, false)
}

#declare ldMat11=material {
 ldrawMatPlastic(11, texture { ldrawTexPlastic(11, -1, true) })
}

#declare ldTex12=texture {
 ldrawTexPlastic(12, -1, false)
}

#declare ldMat12=material {
 ldrawMatPlastic(12, texture { ldrawTexPlastic(12, -1, true) })
}

#declare ldTex13=texture {
 ldrawTexPlastic(13, -1, false)
}

#declare ldMat13=material {
 ldrawMatPlastic(13, texture { ldrawTexPlastic(13, -1, true) })
}

#declare ldTex14=texture {
 ldrawTexPlastic(14, -1, false)
}

#declare ldMat14=material {
 ldrawMatPlastic(14, texture { ldrawTexPlastic(14, -1, true) })
}

#declare ldTex15=texture {
 ldrawTexPlastic(15, -1, false)
}

#declare ldMat15=material {
 ldrawMatPlastic(15, texture { ldrawTexPlastic(15, -1, true) })
}

#declare ldTex17=texture {
 ldrawTexPlastic(17, -1, false)
}

#declare ldMat17=material {
 ldrawMatPlastic(17, texture { ldrawTexPlastic(17, -1, true) })
}

#declare ldTex18=texture {
 ldrawTexPlastic(18, -1, false)
}

#declare ldMat18=material {
 ldrawMatPlastic(18, texture { ldrawTexPlastic(18, -1, true) })
}

#declare ldTex19=texture {
 ldrawTexPlastic(19, -1, false)
}

#declare ldMat19=material {
 ldrawMatPlastic(19, texture { ldrawTexPlastic(19, -1, true) })
}

#declare ldTex20=texture {
 ldrawTexPlastic(20, -1, false)
}

#declare ldMat20=material {
 ldrawMatPlastic(20, texture { ldrawTexPlastic(20, -1, true) })
}

#declare ldTex21=texture {
 ldrawTexPlastic(21, -1, false)
}

#declare ldMat21=material {
 ldrawMatPlastic(21, texture { ldrawTexPlastic(21, -1, true) })
}

#declare ldTex22=texture {
 ldrawTexPlastic(22, -1, false)
}

#declare ldMat22=material {
 ldrawMatPlastic(22, texture { ldrawTexPlastic(22, -1, true) })
}

#declare ldTex23=texture {
 ldrawTexPlastic(23, -1, false)
}

#declare ldMat23=material {
 ldrawMatPlastic(23, texture { ldrawTexPlastic(23, -1, true) })
}

#declare ldTex25=texture {
 ldrawTexPlastic(25, -1, false)
}

#declare ldMat25=material {
 ldrawMatPlastic(25, texture { ldrawTexPlastic(25, -1, true) })
}

#declare ldTex26=texture {
 ldrawTexPlastic(26, -1, false)
}

#declare ldMat26=material {
 ldrawMatPlastic(26, texture { ldrawTexPlastic(26, -1, true) })
}

#declare ldTex27=texture {
 ldrawTexPlastic(27, -1, false)
}

#declare ldMat27=material {
 ldrawMatPlastic(27, texture { ldrawTexPlastic(27, -1, true) })
}

#declare ldTex28=texture {
 ldrawTexPlastic(28, -1, false)
}

#declare ldMat28=material {
 ldrawMatPlastic(28, texture { ldrawTexPlastic(28, -1, true) })
}

#declare ldTex29=texture {
 ldrawTexPlastic(29, -1, false)
}

#declare ldMat29=material {
 ldrawMatPlastic(29, texture { ldrawTexPlastic(29, -1, true) })
}

#declare ldTex30=texture {
 ldrawTexPlastic(30, -1, false)
}

#declare ldMat30=material {
 ldrawMatPlastic(30, texture { ldrawTexPlastic(30, -1, true) })
}

#declare ldTex31=texture {
 ldrawTexPlastic(31, -1, false)
}

#declare ldMat31=material {
 ldrawMatPlastic(31, texture { ldrawTexPlastic(31, -1, true) })
}

#declare ldTex32=texture {
 ldrawTexPlastic(32, -1, false)
}

#declare ldMat32=material {
 ldrawMatPlastic(32, texture { ldrawTexPlastic(32, -1, true) })
}

#declare ldTex33=texture {
 ldrawTexPlastic(33, -1, false)
}

#declare ldMat33=material {
 ldrawMatPlastic(33, texture { ldrawTexPlastic(33, -1, true) })
}

#declare ldTex34=texture {
 ldrawTexPlastic(34, -1, false)
}

#declare ldMat34=material {
 ldrawMatPlastic(34, texture { ldrawTexPlastic(34, -1, true) })
}

#declare ldTex35=texture {
 ldrawTexPlastic(35, -1, false)
}

#declare ldMat35=material {
 ldrawMatPlastic(35, texture { ldrawTexPlastic(35, -1, true) })
}

#declare ldTex36=texture {
 ldrawTexPlastic(36, -1, false)
}

#declare ldMat36=material {
 ldrawMatPlastic(36, texture { ldrawTexPlastic(36, -1, true) })
}

#declare ldTex37=texture {
 ldrawTexPlastic(37, -1, false)
}

#declare ldMat37=material {
 ldrawMatPlastic(37, texture { ldrawTexPlastic(37, -1, true) })
}

#declare ldTex38=texture {
 ldrawTexPlastic(38, -1, false)
}

#declare ldMat38=material {
 ldrawMatPlastic(38, texture { ldrawTexPlastic(38, -1, true) })
}

#declare ldTex39=texture {
 ldrawTexPlastic(39, -1, false)
}

#declare ldMat39=material {
 ldrawMatPlastic(39, texture { ldrawTexPlastic(39, -1, true) })
}

#declare ldTex40=texture {
 ldrawTexPlastic(40, -1, false)
}

#declare ldMat40=material {
 ldrawMatPlastic(40, texture { ldrawTexPlastic(40, -1, true) })
}

#declare ldTex41=texture {
 ldrawTexPlastic(41, -1, false)
}

#declare ldMat41=material {
 ldrawMatPlastic(41, texture { ldrawTexPlastic(41, -1, true) })
}

#declare ldTex42=texture {
 ldrawTexPlastic(42, -1, false)
}

#declare ldMat42=material {
 ldrawMatPlastic(42, texture { ldrawTexPlastic(42, -1, true) })
}

#declare ldTex43=texture {
 ldrawTexPlastic(43, -1, false)
}

#declare ldMat43=material {
 ldrawMatPlastic(43, texture { ldrawTexPlastic(43, -1, true) })
}

#declare ldTex44=texture {
 ldrawTexPlastic(44, -1, false)
}

#declare ldMat44=material {
 ldrawMatPlastic(44, texture { ldrawTexPlastic(44, -1, true) })
}

#declare ldTex45=texture {
 ldrawTexPlastic(45, -1, false)
}

#declare ldMat45=material {
 ldrawMatPlastic(45, texture { ldrawTexPlastic(45, -1, true) })
}

#declare ldTex46=texture {
 ldrawTexPlastic(46, -1, false)
}

#declare ldMat46=material {
 ldrawMatPlastic(46, texture { ldrawTexPlastic(46, -1, true) })
}

#declare ldTex47=texture {
 ldrawTexPlastic(47, -1, false)
}

#declare ldMat47=material {
 ldrawMatPlastic(47, texture { ldrawTexPlastic(47, -1, true) })
}

#declare ldTex52=texture {
 ldrawTexPlastic(52, -1, false)
}

#declare ldMat52=material {
 ldrawMatPlastic(52, texture { ldrawTexPlastic(52, -1, true) })
}

#declare ldTex54=texture {
 ldrawTexPlastic(54, -1, false)
}

#declare ldMat54=material {
 ldrawMatPlastic(54, texture { ldrawTexPlastic(54, -1, true) })
}

#declare ldTex57=texture {
 ldrawTexPlastic(57, -1, false)
}

#declare ldMat57=material {
 ldrawMatPlastic(57, texture { ldrawTexPlastic(57, -1, true) })
}

#declare ldTex60=texture {
 ldrawTexChrome(60, -1, false)
}

#declare ldMat60=material {
 ldrawMatChrome(60, texture { ldrawTexChrome(60, -1, true) })
}

#declare ldTex61=texture {
 ldrawTexChrome(61, -1, false)
}

#declare ldMat61=material {
 ldrawMatChrome(61, texture { ldrawTexChrome(61, -1, true) })
}

#declare ldTex62=texture {
 ldrawTexChrome(62, -1, false)
}

#declare ldMat62=material {
 ldrawMatChrome(62, texture { ldrawTexChrome(62, -1, true) })
}

#declare ldTex63=texture {
 ldrawTexChrome(63, -1, false)
}

#declare ldMat63=material {
 ldrawMatChrome(63, texture { ldrawTexChrome(63, -1, true) })
}

#declare ldTex64=texture {
 ldrawTexChrome(64, -1, false)
}

#declare ldMat64=material {
 ldrawMatChrome(64, texture { ldrawTexChrome(64, -1, true) })
}

#declare ldTex65=texture {
 ldrawTexRubber(65, -1, false)
}

#declare ldMat65=material {
 ldrawMatRubber(65, texture { ldrawTexRubber(65, -1, true) })
}

#declare ldTex66=texture {
 ldrawTexRubber(66, -1, false)
}

#declare ldMat66=material {
 ldrawMatRubber(66, texture { ldrawTexRubber(66, -1, true) })
}

#declare ldTex67=texture {
 ldrawTexRubber(67, -1, false)
}

#declare ldMat67=material {
 ldrawMatRubber(67, texture { ldrawTexRubber(67, -1, true) })
}

#declare ldTex68=texture {
 ldrawTexPlastic(68, -1, false)
}

#declare ldMat68=material {
 ldrawMatPlastic(68, texture { ldrawTexPlastic(68, -1, true) })
}

#declare ldTex69=texture {
 ldrawTexPlastic(69, -1, false)
}

#declare ldMat69=material {
 ldrawMatPlastic(69, texture { ldrawTexPlastic(69, -1, true) })
}

#declare ldTex70=texture {
 ldrawTexPlastic(70, -1, false)
}

#declare ldMat70=material {
 ldrawMatPlastic(70, texture { ldrawTexPlastic(70, -1, true) })
}

#declare ldTex71=texture {
 ldrawTexPlastic(71, -1, false)
}

#declare ldMat71=material {
 ldrawMatPlastic(71, texture { ldrawTexPlastic(71, -1, true) })
}

#declare ldTex72=texture {
 ldrawTexPlastic(72, -1, false)
}

#declare ldMat72=material {
 ldrawMatPlastic(72, texture { ldrawTexPlastic(72, -1, true) })
}

#declare ldTex73=texture {
 ldrawTexPlastic(73, -1, false)
}

#declare ldMat73=material {
 ldrawMatPlastic(73, texture { ldrawTexPlastic(73, -1, true) })
}

#declare ldTex74=texture {
 ldrawTexPlastic(74, -1, false)
}

#declare ldMat74=material {
 ldrawMatPlastic(74, texture { ldrawTexPlastic(74, -1, true) })
}

#declare ldTex75=texture {
 ldrawTexPlastic(75, -1, false)
}

#declare ldMat75=material {
 ldrawMatPlastic(75, texture { ldrawTexPlastic(75, -1, true) })
}

#declare ldTex76=texture {
 ldrawTexPlastic(76, -1, false)
}

#declare ldMat76=material {
 ldrawMatPlastic(76, texture { ldrawTexPlastic(76, -1, true) })
}

#declare ldTex77=texture {
 ldrawTexPlastic(77, -1, false)
}

#declare ldMat77=material {
 ldrawMatPlastic(77, texture { ldrawTexPlastic(77, -1, true) })
}

#declare ldTex78=texture {
 ldrawTexPlastic(78, -1, false)
}

#declare ldMat78=material {
 ldrawMatPlastic(78, texture { ldrawTexPlastic(78, -1, true) })
}

#declare ldTex79=texture {
 ldrawTexPlastic(79, -1, false)
}

#declare ldMat79=material {
 ldrawMatPlastic(79, texture { ldrawTexPlastic(79, -1, true) })
}

#declare ldTex80=texture {
 ldrawTexMetal(80, -1, false)
}

#declare ldMat80=material {
 ldrawMatMetal(80, texture { ldrawTexMetal(80, -1, true) })
}

#declare ldTex81=texture {
 ldrawTexMetal(81, -1, false)
}

#declare ldMat81=material {
 ldrawMatMetal(81, texture { ldrawTexMetal(81, -1, true) })
}

#declare ldTex82=texture {
 ldrawTexMetal(82, -1, false)
}

#declare ldMat82=material {
 ldrawMatMetal(82, texture { ldrawTexMetal(82, -1, true) })
}

#declare ldTex83=texture {
 ldrawTexMetal(83, -1, false)
}

#declare ldMat83=material {
 ldrawMatMetal(83, texture { ldrawTexMetal(83, -1, true) })
}

#declare ldTex84=texture {
 ldrawTexPlastic(84, -1, false)
}

#declare ldMat84=material {
 ldrawMatPlastic(84, texture { ldrawTexPlastic(84, -1, true) })
}

#declare ldTex85=texture {
 ldrawTexPlastic(85, -1, false)
}

#declare ldMat85=material {
 ldrawMatPlastic(85, texture { ldrawTexPlastic(85, -1, true) })
}

#declare ldTex86=texture {
 ldrawTexPlastic(86, -1, false)
}

#declare ldMat86=material {
 ldrawMatPlastic(86, texture { ldrawTexPlastic(86, -1, true) })
}

#declare ldTex87=texture {
 ldrawTexMetal(87, -1, false)
}

#declare ldMat87=material {
 ldrawMatMetal(87, texture { ldrawTexMetal(87, -1, true) })
}

#declare ldTex89=texture {
 ldrawTexPlastic(89, -1, false)
}

#declare ldMat89=material {
 ldrawMatPlastic(89, texture { ldrawTexPlastic(89, -1, true) })
}

#declare ldTex92=texture {
 ldrawTexPlastic(92, -1, false)
}

#declare ldMat92=material {
 ldrawMatPlastic(92, texture { ldrawTexPlastic(92, -1, true) })
}

#declare ldTex100=texture {
 ldrawTexPlastic(100, -1, false)
}

#declare ldMat100=material {
 ldrawMatPlastic(100, texture { ldrawTexPlastic(100, -1, true) })
}

#declare ldTex110=texture {
 ldrawTexPlastic(110, -1, false)
}

#declare ldMat110=material {
 ldrawMatPlastic(110, texture { ldrawTexPlastic(110, -1, true) })
}

#declare ldTex112=texture {
 ldrawTexPlastic(112, -1, false)
}

#declare ldMat112=material {
 ldrawMatPlastic(112, texture { ldrawTexPlastic(112, -1, true) })
}

#declare ldTex114=texture {
 ldrawTexPlastic(114, -1, false)
}

#declare ldMat114=material {
 ldrawMatPlastic(114, texture { ldrawTexPlastic(114, -1, true) })
}

#declare ldTex115=texture {
 ldrawTexPlastic(115, -1, false)
}

#declare ldMat115=material {
 ldrawMatPlastic(115, texture { ldrawTexPlastic(115, -1, true) })
}

#declare ldTex117=texture {
 ldrawTexPlastic(117, -1, false)
}

#declare ldMat117=material {
 ldrawMatPlastic(117, texture { ldrawTexPlastic(117, -1, true) })
}

#declare ldTex118=texture {
 ldrawTexPlastic(118, -1, false)
}

#declare ldMat118=material {
 ldrawMatPlastic(118, texture { ldrawTexPlastic(118, -1, true) })
}

#declare ldTex120=texture {
 ldrawTexPlastic(120, -1, false)
}

#declare ldMat120=material {
 ldrawMatPlastic(120, texture { ldrawTexPlastic(120, -1, true) })
}

#declare ldTex125=texture {
 ldrawTexPlastic(125, -1, false)
}

#declare ldMat125=material {
 ldrawMatPlastic(125, texture { ldrawTexPlastic(125, -1, true) })
}

#declare ldTex128=texture {
 ldrawTexPlastic(128, -1, false)
}

#declare ldMat128=material {
 ldrawMatPlastic(128, texture { ldrawTexPlastic(128, -1, true) })
}

#declare ldTex129=texture {
 ldrawTexPlastic(129, -1, false)
}

#declare ldMat129=material {
 ldrawMatPlastic(129, texture { ldrawTexPlastic(129, -1, true) })
}

#declare ldTex132=texture {
 ldrawTexPlastic(132, -1, false)
}

#declare ldMat132=material {
 ldrawMatPlastic(132, texture { ldrawTexPlastic(132, -1, true) })
}

#declare ldTex133=texture {
 ldrawTexPlastic(133, -1, false)
}

#declare ldMat133=material {
 ldrawMatPlastic(133, texture { ldrawTexPlastic(133, -1, true) })
}

#declare ldTex134=texture {
 ldrawTexPearl(134, -1, false)
}

#declare ldMat134=material {
 ldrawMatPearl(134, texture { ldrawTexPearl(134, -1, true) })
}

#declare ldTex135=texture {
 ldrawTexPearl(135, -1, false)
}

#declare ldMat135=material {
 ldrawMatPearl(135, texture { ldrawTexPearl(135, -1, true) })
}

#declare ldTex137=texture {
 ldrawTexPearl(137, -1, false)
}

#declare ldMat137=material {
 ldrawMatPearl(137, texture { ldrawTexPearl(137, -1, true) })
}

#declare ldTex142=texture {
 ldrawTexPearl(142, -1, false)
}

#declare ldMat142=material {
 ldrawMatPearl(142, texture { ldrawTexPearl(142, -1, true) })
}

#declare ldTex148=texture {
 ldrawTexPearl(148, -1, false)
}

#declare ldMat148=material {
 ldrawMatPearl(148, texture { ldrawTexPearl(148, -1, true) })
}

#declare ldTex150=texture {
 ldrawTexPearl(150, -1, false)
}

#declare ldMat150=material {
 ldrawMatPearl(150, texture { ldrawTexPearl(150, -1, true) })
}

#declare ldTex151=texture {
 ldrawTexPlastic(151, -1, false)
}

#declare ldMat151=material {
 ldrawMatPlastic(151, texture { ldrawTexPlastic(151, -1, true) })
}

#declare ldTex178=texture {
 ldrawTexPearl(178, -1, false)
}

#declare ldMat178=material {
 ldrawMatPearl(178, texture { ldrawTexPearl(178, -1, true) })
}

#declare ldTex179=texture {
 ldrawTexPearl(179, -1, false)
}

#declare ldMat179=material {
 ldrawMatPearl(179, texture { ldrawTexPearl(179, -1, true) })
}

#declare ldTex183=texture {
 ldrawTexPearl(183, -1, false)
}

#declare ldMat183=material {
 ldrawMatPearl(183, texture { ldrawTexPearl(183, -1, true) })
}

#declare ldTex184=texture {
 ldrawTexMetal(184, -1, false)
}

#declare ldMat184=material {
 ldrawMatMetal(184, texture { ldrawTexMetal(184, -1, true) })
}

#declare ldTex186=texture {
 ldrawTexMetal(186, -1, false)
}

#declare ldMat186=material {
 ldrawMatMetal(186, texture { ldrawTexMetal(186, -1, true) })
}

#declare ldTex189=texture {
 ldrawTexPearl(189, -1, false)
}

#declare ldMat189=material {
 ldrawMatPearl(189, texture { ldrawTexPearl(189, -1, true) })
}

#declare ldTex191=texture {
 ldrawTexPlastic(191, -1, false)
}

#declare ldMat191=material {
 ldrawMatPlastic(191, texture { ldrawTexPlastic(191, -1, true) })
}

#declare ldTex212=texture {
 ldrawTexPlastic(212, -1, false)
}

#declare ldMat212=material {
 ldrawMatPlastic(212, texture { ldrawTexPlastic(212, -1, true) })
}

#declare ldTex216=texture {
 ldrawTexPlastic(216, -1, false)
}

#declare ldMat216=material {
 ldrawMatPlastic(216, texture { ldrawTexPlastic(216, -1, true) })
}

#declare ldTex218=texture {
 ldrawTexPlastic(218, -1, false)
}

#declare ldMat218=material {
 ldrawMatPlastic(218, texture { ldrawTexPlastic(218, -1, true) })
}

#declare ldTex219=texture {
 ldrawTexPlastic(219, -1, false)
}

#declare ldMat219=material {
 ldrawMatPlastic(219, texture { ldrawTexPlastic(219, -1, true) })
}

#declare ldTex226=texture {
 ldrawTexPlastic(226, -1, false)
}

#declare ldMat226=material {
 ldrawMatPlastic(226, texture { ldrawTexPlastic(226, -1, true) })
}

#declare ldTex231=texture {
 ldrawTexPlastic(231, -1, false)
}

#declare ldMat231=material {
 ldrawMatPlastic(231, texture { ldrawTexPlastic(231, -1, true) })
}

#declare ldTex232=texture {
 ldrawTexPlastic(232, -1, false)
}

#declare ldMat232=material {
 ldrawMatPlastic(232, texture { ldrawTexPlastic(232, -1, true) })
}

#declare ldTex234=texture {
 ldrawTexPlastic(234, -1, false)
}

#declare ldMat234=material {
 ldrawMatPlastic(234, texture { ldrawTexPlastic(234, -1, true) })
}

#declare ldTex256=texture {
 ldrawTexRubber(256, -1, false)
}

#declare ldMat256=material {
 ldrawMatRubber(256, texture { ldrawTexRubber(256, -1, true) })
}

#declare ldTex272=texture {
 ldrawTexPlastic(272, -1, false)
}

#declare ldMat272=material {
 ldrawMatPlastic(272, texture { ldrawTexPlastic(272, -1, true) })
}

#declare ldTex273=texture {
 ldrawTexRubber(273, -1, false)
}

#declare ldMat273=material {
 ldrawMatRubber(273, texture { ldrawTexRubber(273, -1, true) })
}

#declare ldTex284=texture {
 ldrawTexPlastic(284, -1, false)
}

#declare ldMat284=material {
 ldrawMatPlastic(284, texture { ldrawTexPlastic(284, -1, true) })
}

#declare ldTex285=texture {
 ldrawTexPlastic(285, -1, false)
}

#declare ldMat285=material {
 ldrawMatPlastic(285, texture { ldrawTexPlastic(285, -1, true) })
}

#declare ldTex288=texture {
 ldrawTexPlastic(288, -1, false)
}

#declare ldMat288=material {
 ldrawMatPlastic(288, texture { ldrawTexPlastic(288, -1, true) })
}

#declare ldTex293=texture {
 ldrawTexPlastic(293, -1, false)
}

#declare ldMat293=material {
 ldrawMatPlastic(293, texture { ldrawTexPlastic(293, -1, true) })
}

#declare ldTex294=texture {
 ldrawTexPlastic(294, -1, false)
}

#declare ldMat294=material {
 ldrawMatPlastic(294, texture { ldrawTexPlastic(294, -1, true) })
}

#declare ldTex295=texture {
 ldrawTexPlastic(295, -1, false)
}

#declare ldMat295=material {
 ldrawMatPlastic(295, texture { ldrawTexPlastic(295, -1, true) })
}

#declare ldTex297=texture {
 ldrawTexPearl(297, -1, false)
}

#declare ldMat297=material {
 ldrawMatPearl(297, texture { ldrawTexPearl(297, -1, true) })
}

#declare ldTex300=texture {
 ldrawTexMetal(300, -1, false)
}

#declare ldMat300=material {
 ldrawMatMetal(300, texture { ldrawTexMetal(300, -1, true) })
}

#declare ldTex302=texture {
 ldrawTexPlastic(302, -1, false)
}

#declare ldMat302=material {
 ldrawMatPlastic(302, texture { ldrawTexPlastic(302, -1, true) })
}

#declare ldTex308=texture {
 ldrawTexPlastic(308, -1, false)
}

#declare ldMat308=material {
 ldrawMatPlastic(308, texture { ldrawTexPlastic(308, -1, true) })
}

#declare ldTex313=texture {
 ldrawTexPlastic(313, -1, false)
}

#declare ldMat313=material {
 ldrawMatPlastic(313, texture { ldrawTexPlastic(313, -1, true) })
}

#declare ldTex320=texture {
 ldrawTexPlastic(320, -1, false)
}

#declare ldMat320=material {
 ldrawMatPlastic(320, texture { ldrawTexPlastic(320, -1, true) })
}

#declare ldTex321=texture {
 ldrawTexPlastic(321, -1, false)
}

#declare ldMat321=material {
 ldrawMatPlastic(321, texture { ldrawTexPlastic(321, -1, true) })
}

#declare ldTex322=texture {
 ldrawTexPlastic(322, -1, false)
}

#declare ldMat322=material {
 ldrawMatPlastic(322, texture { ldrawTexPlastic(322, -1, true) })
}

#declare ldTex323=texture {
 ldrawTexPlastic(323, -1, false)
}

#declare ldMat323=material {
 ldrawMatPlastic(323, texture { ldrawTexPlastic(323, -1, true) })
}

#declare ldTex324=texture {
 ldrawTexRubber(324, -1, false)
}

#declare ldMat324=material {
 ldrawMatRubber(324, texture { ldrawTexRubber(324, -1, true) })
}

#declare ldTex326=texture {
 ldrawTexPlastic(326, -1, false)
}

#declare ldMat326=material {
 ldrawMatPlastic(326, texture { ldrawTexPlastic(326, -1, true) })
}

#declare ldTex329=texture {
 ldrawTexPlastic(329, -1, false)
}

#declare ldMat329=material {
 ldrawMatPlastic(329, texture { ldrawTexPlastic(329, -1, true) })
}

#declare ldTex330=texture {
 ldrawTexPlastic(330, -1, false)
}

#declare ldMat330=material {
 ldrawMatPlastic(330, texture { ldrawTexPlastic(330, -1, true) })
}

#declare ldTex334=texture {
 ldrawTexChrome(334, -1, false)
}

#declare ldMat334=material {
 ldrawMatChrome(334, texture { ldrawTexChrome(334, -1, true) })
}

#declare ldTex335=texture {
 ldrawTexPlastic(335, -1, false)
}

#declare ldMat335=material {
 ldrawMatPlastic(335, texture { ldrawTexPlastic(335, -1, true) })
}

#declare ldTex339=texture {
 ldrawTexPlastic(339, -1, false)
}

#declare ldMat339=material {
 ldrawMatPlastic(339, texture { ldrawTexPlastic(339, -1, true) })
}

#declare ldTex350=texture {
 ldrawTexRubber(350, -1, false)
}

#declare ldMat350=material {
 ldrawMatRubber(350, texture { ldrawTexRubber(350, -1, true) })
}

#declare ldTex351=texture {
 ldrawTexPlastic(351, -1, false)
}

#declare ldMat351=material {
 ldrawMatPlastic(351, texture { ldrawTexPlastic(351, -1, true) })
}

#declare ldTex366=texture {
 ldrawTexPlastic(366, -1, false)
}

#declare ldMat366=material {
 ldrawMatPlastic(366, texture { ldrawTexPlastic(366, -1, true) })
}

#declare ldTex373=texture {
 ldrawTexPlastic(373, -1, false)
}

#declare ldMat373=material {
 ldrawMatPlastic(373, texture { ldrawTexPlastic(373, -1, true) })
}

#declare ldTex375=texture {
 ldrawTexRubber(375, -1, false)
}

#declare ldMat375=material {
 ldrawMatRubber(375, texture { ldrawTexRubber(375, -1, true) })
}

#declare ldTex378=texture {
 ldrawTexPlastic(378, -1, false)
}

#declare ldMat378=material {
 ldrawMatPlastic(378, texture { ldrawTexPlastic(378, -1, true) })
}

#declare ldTex379=texture {
 ldrawTexPlastic(379, -1, false)
}

#declare ldMat379=material {
 ldrawMatPlastic(379, texture { ldrawTexPlastic(379, -1, true) })
}

#declare ldTex383=texture {
 ldrawTexChrome(383, -1, false)
}

#declare ldMat383=material {
 ldrawMatChrome(383, texture { ldrawTexChrome(383, -1, true) })
}

#declare ldTex406=texture {
 ldrawTexRubber(406, -1, false)
}

#declare ldMat406=material {
 ldrawMatRubber(406, texture { ldrawTexRubber(406, -1, true) })
}

#declare ldTex449=texture {
 ldrawTexRubber(449, -1, false)
}

#declare ldMat449=material {
 ldrawMatRubber(449, texture { ldrawTexRubber(449, -1, true) })
}

#declare ldTex450=texture {
 ldrawTexPlastic(450, -1, false)
}

#declare ldMat450=material {
 ldrawMatPlastic(450, texture { ldrawTexPlastic(450, -1, true) })
}

#declare ldTex462=texture {
 ldrawTexPlastic(462, -1, false)
}

#declare ldMat462=material {
 ldrawMatPlastic(462, texture { ldrawTexPlastic(462, -1, true) })
}

#declare ldTex484=texture {
 ldrawTexPlastic(484, -1, false)
}

#declare ldMat484=material {
 ldrawMatPlastic(484, texture { ldrawTexPlastic(484, -1, true) })
}

#declare ldTex490=texture {
 ldrawTexRubber(490, -1, false)
}

#declare ldMat490=material {
 ldrawMatRubber(490, texture { ldrawTexRubber(490, -1, true) })
}

#declare ldTex493=texture {
 ldrawTexMetal(493, -1, false)
}

#declare ldMat493=material {
 ldrawMatMetal(493, texture { ldrawTexMetal(493, -1, true) })
}

#declare ldTex494=texture {
 ldrawTexMetal(494, -1, false)
}

#declare ldMat494=material {
 ldrawMatMetal(494, texture { ldrawTexMetal(494, -1, true) })
}

#declare ldTex495=texture {
 ldrawTexMetal(495, -1, false)
}

#declare ldMat495=material {
 ldrawMatMetal(495, texture { ldrawTexMetal(495, -1, true) })
}

#declare ldTex496=texture {
 ldrawTexRubber(496, -1, false)
}

#declare ldMat496=material {
 ldrawMatRubber(496, texture { ldrawTexRubber(496, -1, true) })
}

#declare ldTex503=texture {
 ldrawTexPlastic(503, -1, false)
}

#declare ldMat503=material {
 ldrawMatPlastic(503, texture { ldrawTexPlastic(503, -1, true) })
}

#declare ldTex504=texture {
 ldrawTexRubber(504, -1, false)
}

#declare ldMat504=material {
 ldrawMatRubber(504, texture { ldrawTexRubber(504, -1, true) })
}

#declare ldTex511=texture {
 ldrawTexRubber(511, -1, false)
}

#declare ldMat511=material {
 ldrawMatRubber(511, texture { ldrawTexRubber(511, -1, true) })
}
