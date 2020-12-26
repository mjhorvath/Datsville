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


// this method is much much slower, but does not require focal blur or extra antialiasing or downsampling
#macro BlurredReflectionMultiTextures(InPigment, InFinish, InNormal, InAmount, InSamples)
//	texture
//	{
		average
		texture_map
		{
			#for (iCount, 1, InSamples)
				[
					// The strength of this item:
					1
					// The pigment of the object:
					pigment { InPigment }
					// The surface finish:
					finish { InFinish }
					// This is the actual trick:
					normal
					{
						average
						normal_map
						{
							[1 bumps InAmount translate <rand(Use_Seed),rand(Use_Seed),rand(Use_Seed)>*120 scale 1/960]
							[1 InNormal]
						}
					}
				]
			#end
		}
//	}
#end


// this method is somewhere in between in terms of performance, not sure it works correctly
#macro BlurredReflectionMultiNormals(InPigment, InFinish, InNormal, InAmount, InSamples)
//	texture
//	{
		// The pigment of the object:
		pigment { InPigment }
		// The surface finish:
		finish { InFinish }
		// This is the actual trick:
		normal
		{
			average
			normal_map
			{
				#for (iCount, 1, InSamples)
					[1/InSamples bumps InAmount*InSamples translate <rand(Use_Seed),rand(Use_Seed),rand(Use_Seed)>*120 scale 1/960]
				#end
				[1 InNormal]
			}
		}
//	}
#end


// this method is faster, but requires focal blur and/or extra antialiasing or downsampling to smooth out the graininess
// double check whether having two normals in the same block is okay
#macro BlurredReflectionSingleNormals(InPigment, InFinish, InNormal, InAmount)
//	texture
//	{
		pigment { InPigment }
		finish { InFinish }
		normal { InNormal }
		normal {bumps InAmount translate <rand(Use_Seed),rand(Use_Seed),rand(Use_Seed)>*120 scale 1/960}
//	}
#end
