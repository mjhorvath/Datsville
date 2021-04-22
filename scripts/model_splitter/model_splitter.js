// Authors: Michael Horvath
// Version: 1.1.0
// Created: 2020/02/02
// Updated: 2021/04/21
// 
// This program splits a model into several files based on their XZ 
// coordinates. It strips and skips all meta tags and comments.
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

var fso;
var WshShell;
var inputPath = '';
var numDivisions = 0;
var minX = 0;
var minZ = 0;
var maxX = 0;
var maxZ = 0;
var cellData = [];
var headerText = '0 Split using "model_splitter.js" by Michael Horvath.\n0\n';
var usageText =
'Invalid parameters.\n\n'+
'cscript model_splitter.js [inputfile.ldr] [n] [minX] [maxX] [minZ] [maxZ]\n\n'+
'\t[inputfile.ldr] is the terrain file to split.\n'+
'\t[n] is the number of divisions to make along each side. It should be an even number.\n'+
'\tThe total number of sections overall will be equal to [n] squared.\n'+
'\nNote this program totally ignores/discards comments.\n';

function Main()
{
	// only continue if the script is run via Windows Scripting Host
	// should spawn a message here if the condition is true instead of false
	if (typeof(WScript) != 'undefined')
	{
		var progArgs = WScript.Arguments;
		inputPath = progArgs(0);
		numDivisions = progArgs(1);
		minX = parseFloat(progArgs(2));
		maxX = parseFloat(progArgs(3));
		minZ = parseFloat(progArgs(4));
		maxZ = parseFloat(progArgs(5));
		if ((progArgs.length == 6) && isNumber(numDivisions) && (numDivisions > 0) && isNumber(minX) && isNumber(maxX) && isNumber(minZ) && isNumber(maxZ))
		{
			Get_Input();
		}
		else
		{
			WScript.Echo(usageText);
		}
	}
}

function Get_Input()
{
	fso = new ActiveXObject('Scripting.FileSystemObject');
	WshShell = new ActiveXObject('WScript.Shell');

	// check first whether the file exists
	fso.GetFile(inputPath);

	// list of valid file extensions
	var Test_a = /\.[lL][dD][rR]$/;
	var Test_b = /\.[dD][aA][tT]$/;
	var Test_c = /\.[mM][pP][dD]$/;
	var Test_d = /\.[xX][mM][pP][dD]$/;

	if (Test_a.test(inputPath) || Test_b.test(inputPath))
	{
		var inputRoot = inputPath.substring(0, inputPath.lastIndexOf('\\') + 1);
		if (inputRoot == '')
		{
			inputRoot = WshShell.CurrentDirectory + '\\';
			inputPath = inputRoot + inputPath;
		}
		Process_File();
	}
	else
	{
		WScript.Echo('Invalid file type: input file must have an .ldr extension.\n');
	}
}

// read the input file and store its contents as a table
function Process_File()
{
	// set up the cells needed to contain the data
	for (var i = 0; i < numDivisions; i++)
	{
		cellData[i] = [];
		for (var j = 0; j < numDivisions; j++)
		{
			cellData[i][j] = [];
		}
	}

	var lengthX = Math.abs(maxX - minX);
	var lengthZ = Math.abs(maxZ - minZ);
	var stepX = lengthX/numDivisions;
	var stepZ = lengthZ/numDivisions;

	var InputFileObject = fso.OpenTextFile(inputPath, 1);
	while (!InputFileObject.AtEndOfStream)
	{
		var inputString = InputFileObject.ReadLine();
		var inputArray = inputString.split(' ');
		var partCoords = [inputArray[2],inputArray[3],inputArray[4]];	// x,y,z
		if (inputArray[0] != '0')
		{
			for (var i = 0; i < numDivisions; i++)
			{
				var xPosLow = minX + stepX * i;
				var xPosHgh = minX + stepX * (i + 1);
				// should spawn an error message here if these criteria are not met! need to fix this!
				// if both conditions are <= or >= then in theory some objects may end up being duplicated
				if ((partCoords[0] >= xPosLow) && (partCoords[0] < xPosHgh))
				{
					for (var j = 0; j < numDivisions; j++)
					{
						var zPosLow = minZ + stepZ * j;
						var zPosHgh = minZ + stepZ * (j + 1);
						// should spawn an error message here if these criteria are not met! need to fix this!
						// if both conditions are <= or >= then in theory some objects may end up being duplicated
						if ((partCoords[2] >= zPosLow) && (partCoords[2] < zPosHgh))
						{
							cellData[i][j].push(inputString);
							break;
						}
					}
					break;
				}
			}
		}
	}
	InputFileObject.Close();
	Write_Output();
}

// write copies of the converted file
// multiple periods in the filename could potentially mess up this script
function Write_Output()
{
	var outputPath = inputPath.split(/(\\|\/)/g).pop().split('.')[0];
	var largeHeaderString =
	'0 Split Model Container\n'+
	'0 Name: '+outputPath+'\n'+
	'0 Author: model_splitter.js\n'+
	'0 Unofficial Model\n'+
	'0 ROTATION CENTER 0 0 0 1 "Custom"\n'+
	'0 ROTATION CONFIG 0 0\n';
	var largeModelPath = outputPath + '_container.ldr';
	var largeModelString = largeHeaderString;
	for (var i = 0; i < numDivisions; i++)
	{
		var iChar = i - numDivisions/2;
		iChar = iChar >= 0 ? '+'+(iChar+1): iChar;
		for (var j = 0; j < numDivisions; j++)
		{
			var jChar = j - numDivisions/2;
			jChar = jChar >= 0 ? '+'+(jChar+1): jChar;
			var smallHeaderString =
			'0 Split Model\n'+
			'0 Name: '+outputPath+'\n'+
			'0 Author: model_splitter.js\n'+
			'0 Unofficial Model\n'+
			'0 ROTATION CENTER 0 0 0 1 "Custom"\n'+
			'0 ROTATION CONFIG 0 0\n';
			var smallModelPath = outputPath + '_' + iChar + '_' + jChar + '.ldr';
			var cellDataJoin = cellData[i][j].join('\n');
			var smallModelString = smallHeaderString + cellDataJoin + (cellDataJoin.length > 0 ? '\n' : '') + '0\n';
			var OutputFileObject = fso.OpenTextFile(smallModelPath, 2, 1, 0);
			OutputFileObject.Write(smallModelString);
			OutputFileObject.Close();
//			WScript.Echo(smallModelString);
			largeModelString += '1 16 0 0 0 1 0 0 0 1 0 0 0 1 ' + smallModelPath + '\n';
		}
	}
	var OutputFileObject = fso.OpenTextFile(largeModelPath, 2, 1, 0);
	OutputFileObject.Write(largeModelString + '0\n');
	OutputFileObject.Close();
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

Main();
