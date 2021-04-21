// Authors: Michael Horvath
// Version: 1.0.2
// Created: 2020/02/02
// Updated: 2021/04/20
// 
// This program splits terrain model into a grid of chunks based on the XZ coordinates.
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3 of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
// 
// Note that the 'ichar' and 'jchar' variables have issues. Read the comments in the code.

var fso
var WshShell
var InputPath = ''
var NumDivisions = 0
var MinX = 0
var MinZ = 0
var MaxX = 0
var MaxZ = 0
var InputPath = ''
var CellData = []
var HeaderString = '0 Split using "model_splitter.js" by Michael Horvath.\n0\n'
// NumDivisions must be less than or equal to the length of the LettersTable array.
// Could start doubling up letters AA, AB, AC, etc. like in Excel.
// In which case I should do this using a script instead of a hardcoded table.
var LettersTable = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

function main()
{
	// only continue if the script is run via Windows Scripting Host
	// should spawn a message here if the condition is true instead of false
	if (typeof(WScript) != 'undefined')
	{
		var ProgArgs = WScript.Arguments
		InputPath = ProgArgs(0)
		NumDivisions = ProgArgs(1)
		MinX = parseFloat(ProgArgs(2))
		MaxX = parseFloat(ProgArgs(3))
		MinZ = parseFloat(ProgArgs(4))
		MaxZ = parseFloat(ProgArgs(5))
		if ((ProgArgs.length == 6) && isNumber(NumDivisions) && (NumDivisions > 0) && isNumber(MinX) && isNumber(MaxX) && isNumber(MinZ) && isNumber(MaxZ))
		{
			Get_Input()
		}
		else
		{
			WScript.Echo
			(
				'Invalid parameters.\n\n' +
				'cscript model_splitter.js <inputfile.ldr> <n> <minX> <maxX> <minZ> <maxZ>\n\n' +
				'\t<inputfile.ldr> is the terrain file to split.\n' +
				'\t<n> is the number of divisions to make along each side.\n' +
				'\tThe maximum allowed value for <n> is 26.\n' +
				'\tThe total number of sections overall will be equal to <n> squared.\n' +
				'\nNote this program only recognizes line type 1 and completely ignores/discards any other line types, including comments.\n'
			)
		}
	}
}

function Get_Input()
{
	fso = new ActiveXObject('Scripting.FileSystemObject')
	WshShell = new ActiveXObject('WScript.Shell')

	// check first whether the file exists
	fso.GetFile(InputPath)

	// list of valid file extensions
	var Test_a = /\.[lL][dD][rR]$/
	var Test_b = /\.[dD][aA][tT]$/
	var Test_c = /\.[mM][pP][dD]$/
	var Test_d = /\.[xX][mM][pP][dD]$/

	if (Test_a.test(InputPath))
	{
		var InputRoot = InputPath.substring(0, InputPath.lastIndexOf('\\') + 1)
		if (InputRoot == '')
		{
			InputRoot = WshShell.CurrentDirectory + '\\'
			InputPath = InputRoot + InputPath
		}
		Convert_File()
	}
	else
	{
		WScript.Echo('Invalid file type: input file must have an .ldr extension.\n')
	}
}

// read the input file and store its contents as a table
function Convert_File()
{
	// set up the cells needed to contain the data
	for (var i = 0; i < NumDivisions; i++)
	{
		CellData[i] = []
		for (var j = 0; j < NumDivisions; j++)
		{
			CellData[i][j] = []
		}
	}

	var lengthX = Math.abs(MaxX - MinX)
	var lengthZ = Math.abs(MaxZ - MinZ)
	var stepX = lengthX/NumDivisions
	var stepZ = lengthZ/NumDivisions

	var InputFileObject = fso.OpenTextFile(InputPath, 1)
	while (!InputFileObject.AtEndOfStream)
	{
		var TempString = InputFileObject.ReadLine()
		var TempArray = TempString.split(' ')
		var PartCoords = [TempArray[2],TempArray[3],TempArray[4]]	// x,y,z
		if (TempArray[0] == '1')
		{
			for (var i = 0; i < NumDivisions; i++)
			{
				var xPosLow = MinX + stepX * i
				var xPosHgh = MinX + stepX * (i + 1)
				// should spawn an error message here if these criteria are not met! need to fix this!
				if ((PartCoords[0] >= xPosLow) && (PartCoords[0] < xPosHgh))		// if both conditions are <= or >= then in theory some objects may end up being duplicated
				{
					for (var j = 0; j < NumDivisions; j++)
					{
						var zPosLow = MinZ + stepZ * j
						var zPosHgh = MinZ + stepZ * (j + 1)
						// should spawn an error message here if these criteria are not met! need to fix this!
						if ((PartCoords[2] >= zPosLow) && (PartCoords[2] < zPosHgh))		// if both conditions are <= or >= then in theory some objects may end up being duplicated
						{
							CellData[i][j].push(TempString)
							break
						}
					}
					break
				}
			}
		}
	}
	InputFileObject.Close()
	Write_Output()
}

// write copies of the converted file
// multiple periods in the filename could potentially mess up this script
function Write_Output()
{
	var OutputPath = InputPath.split(/(\\|\/)/g).pop().split('.')[0]
	var LargeModelPath = OutputPath + '_all.ldr'
	var LargeModelString = HeaderString
	for (var i = 0; i < NumDivisions; i++)
	{
		var ichar = LettersTable[i]				// this means NumDivisions should be limited to 26 or fewer, or else the file numbering will go wrong! need to fix this!
		for (var j = 0; j < NumDivisions; j++)
		{
			var jchar = j < 10 ? '0' + j : j				// this means NumDivisions should be limited to 100 or fewer, or else the file numbering will go wrong! need to fix this!
			var SmallModelPath = OutputPath + '_' + ichar + jchar + '.ldr'
			var SmallModelString = HeaderString + CellData[i][j].join('\n')
			var OutputFileObject = fso.OpenTextFile(SmallModelPath, 2, 1, 0)
			OutputFileObject.Write(SmallModelString)
			OutputFileObject.Close()
//			WScript.Echo(SmallModelString)
			LargeModelString += '1 16 0 0 0 1 0 0 0 1 0 0 0 1 ' + SmallModelPath + '\n'
		}
	}
	var OutputFileObject = fso.OpenTextFile(LargeModelPath, 2, 1, 0)
	OutputFileObject.Write(LargeModelString)
	OutputFileObject.Close()
}

function isPowerOfTwo(iNum)
{
	return Math.abs((iNum != 0) && ((iNum & (iNum - 1)) == 0))
}

function isNumber(iNum)
{
	return !isNaN(parseFloat(iNum)) && isFinite(iNum);
}

function padZeros(iNum, iMax)
{
	// to do
}

main()
