// Script authored by: Michael Horvath
// Version: 1.0.0
// Created: 2013/11/06
// Updated: 
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

var fso
var WshShell
var InputPath = ''
var NumDivisions = 0
var InputPath = ''
var CellData = []
var HeaderString = ''

// only continue if the script is run via Windows Scripting Host
function main()
{
	if (typeof(WScript) != 'undefined')
	{
		var ProgArgs = WScript.Arguments
		InputPath = ProgArgs(0)
		NumDivisions = ProgArgs(2)
		if ((ProgArgs.length != 3) || (ProgArgs(1) != '-p') || !isNumber(NumDivisions) || (!isPowerOfTwo(NumDivisions)))
		{
			WScript.Echo
			(
				'Invalid parameters.\n\n' +
				'cscript terrain_splitter.js <inputfile.ldr> -p <n>\n\n' +
				'\t<inputfile.ldr> is the terrain file to split.\n' +
				'\t<n> is the number of divisions to make along each side.\n' +
				'\tThe total number of sections overall will be equal to <n> squared.\n' +
				'\t<n> itself also must be a power of two.\n'
			)
		}
		else
		{
			Get_Input()
		}
	}
}

function Get_Input()
{
	fso = new ActiveXObject('Scripting.FileSystemObject')
	WshShell = new ActiveXObject('WScript.Shell')

	// quickly test whether the file exists
	fso.GetFile(InputPath)

	// list of valid file extensions
	var Test_a = /\.[lL][dD][rR]$/
	var Test_b = /\.[dD][aA][tT]$/

	if (Test_a.test(InputPath) || Test_b.test(InputPath))
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
		WScript.Echo('Invalid file type: input file must have an .ldr or .dat extension.')
	}
}

// read the input file and store its contents as a table
function Convert_File()
{
	var maxPos = [0,0,0]
	var minPos = [0,0,0]

	// set up the cells needed to contain the data
	for (var i = 0; i < NumDivisions; i++)
	{
		CellData[i] = []
		for (var j = 0; j < NumDivisions; j++)
		{
			CellData[i][j] = []
		}
	}

	// first pass
	var InputFileObject = fso.OpenTextFile(InputPath, 1)
	while (!InputFileObject.AtEndOfStream)
	{
		var TempString = InputFileObject.ReadLine()
		var TempArray = TempString.split(' ')
		if ((TempArray[0] == '0') || (TempArray.length == 0))
		{
			HeaderString += TempString + '\n'
		}
		else if (TempArray[0] == '3')
		{
			// maximum
			maxPos[0] = Math.max(maxPos[0], TempArray[2])
			maxPos[1] = Math.max(maxPos[1], TempArray[3])
			maxPos[2] = Math.max(maxPos[2], TempArray[4])
			maxPos[0] = Math.max(maxPos[0], TempArray[5])
			maxPos[1] = Math.max(maxPos[1], TempArray[6])
			maxPos[2] = Math.max(maxPos[2], TempArray[7])
			maxPos[0] = Math.max(maxPos[0], TempArray[8])
			maxPos[1] = Math.max(maxPos[1], TempArray[9])
			maxPos[2] = Math.max(maxPos[2], TempArray[10])
			// minimum
			minPos[0] = Math.min(minPos[0], TempArray[2])
			minPos[1] = Math.min(minPos[1], TempArray[3])
			minPos[2] = Math.min(minPos[2], TempArray[4])
			minPos[0] = Math.min(minPos[0], TempArray[5])
			minPos[1] = Math.min(minPos[1], TempArray[6])
			minPos[2] = Math.min(minPos[2], TempArray[7])
			minPos[0] = Math.min(minPos[0], TempArray[8])
			minPos[1] = Math.min(minPos[1], TempArray[9])
			minPos[2] = Math.min(minPos[2], TempArray[10])
		}
	}
	InputFileObject.Close()
	HeaderString += '0 Split using "terrain_splitter.js" by Michael Horvath.\n0\n'

	var lengthX = maxPos[0] - minPos[0]
//	var lengthY = maxPos[1] - minPos[1]
	var lengthZ = maxPos[2] - minPos[2]
	var stepX = lengthX/NumDivisions
//	var stepY = lengthY/NumDivisions
	var stepZ = lengthZ/NumDivisions

	// second pass
	InputFileObject = fso.OpenTextFile(InputPath, 1)
	while (!InputFileObject.AtEndOfStream)
	{
		var TempString = InputFileObject.ReadLine()
		var TempArray = TempString.split(' ')
		var TriCoords =
		[
			[TempArray[2],TempArray[3],TempArray[4]],	// x,y,z
			[TempArray[5],TempArray[6],TempArray[7]],	// x,y,z
			[TempArray[8],TempArray[9],TempArray[10]]	// x,y,z
		]
		if (TempArray[0] == '3')
		{
			for (var i = 0; i < NumDivisions; i++)
			{
				var xPosLow = minPos[0] + stepX * i
				var xPosHgh = minPos[0] + stepX * (i + 1)
				if ((TriCoords[0][0] >= xPosLow) && (TriCoords[0][0] <= xPosHgh) && (TriCoords[1][0] >= xPosLow) && (TriCoords[1][0] <= xPosHgh) && (TriCoords[2][0] >= xPosLow) && (TriCoords[2][0] <= xPosHgh))
				{
					for (var j = 0; j < NumDivisions; j++)
					{
						var zPosLow = minPos[2] + stepZ * j
						var zPosHgh = minPos[2] + stepZ * (j + 1)
						if ((TriCoords[0][2] >= zPosLow) && (TriCoords[0][2] <= zPosHgh) && (TriCoords[1][2] >= zPosLow) && (TriCoords[1][2] <= zPosHgh) && (TriCoords[2][2] >= zPosLow) && (TriCoords[2][2] <= zPosHgh))
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
function Write_Output()
{
	var iCount = 0
	var LargeModelString = HeaderString
	var OutputPath = InputPath.split(/(\\|\/)/g).pop().split('.')[0]
	var LargeModelPath = OutputPath + '_all.ldr'
	for (var i = 0; i < NumDivisions; i++)
	{
		for (var j = 0; j < NumDivisions; j++)
		{
			iCount += 1
			var addZeros = iCount < 10 ? '0' + iCount : iCount				// this means the total number of output objects must be 99 or less! need to fix this!
			var SmallModelPath = OutputPath + '_' + addZeros + '.ldr'
			OutputFileString = HeaderString + CellData[i][j].join('\n')
			LargeModelString += '1 16 0 0 0 1 0 0 0 1 0 0 0 1 ' + SmallModelPath + '\n'
			var OutputFileObject = fso.OpenTextFile(SmallModelPath, 2, 1, 0)
			OutputFileObject.Write(OutputFileString)
			OutputFileObject.Close()
//			WScript.Echo(OutputFileString)
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

main()
