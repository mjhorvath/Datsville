// Authors: Michael Horvath
// Version: 1.0.0
// Created: 2021/05/29
// Updated: 2021/05/29
// 
// This program sets all lines of type 1 of a model to the main color #16.
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
var outputPath = '';
var outputString = '';
var headerText = '';
var usageText =
'Invalid parameters.\n\n'+
'cscript model_main_colorer.js [inputfile] [outputfile]\n\n'+
'\t[inputfile.ldr] is the file to recolor.\n'+
'\t[outputfile.ldr] is the file to save over or save as.\n';

function Main()
{
	// only continue if the script is run via Windows Scripting Host
	// should spawn a message here if the condition is true instead of false
	if (typeof(WScript) != 'undefined')
	{
		var progArgs = WScript.Arguments;
		if (progArgs.length == 2)
		{
			inputPath = progArgs(0);
			outputPath = progArgs(1);
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

	// check first whether the input file exists
	fso.GetFile(inputPath);

	// list of valid file extensions
	var Test_a = /\.[lL][dD][rR]$/;
	var Test_b = /\.[dD][aA][tT]$/;
	var Test_c = /\.[mM][pP][dD]$/;
	var Test_d = /\.[xX][mM][pP][dD]$/;

	if (Test_a.test(inputPath) || Test_b.test(inputPath) || Test_c.test(inputPath) || Test_d.test(inputPath))
	{
		Process_File();
	}
	else
	{
		WScript.Echo('Invalid file type: input file must have an LDR, DAT, MPD or XMPD extension.\n');
	}
}

// read the input file and store its contents as a table
function Process_File()
{
	var InputFileObject = fso.OpenTextFile(inputPath, 1);
	while (!InputFileObject.AtEndOfStream)
	{
		var inputLine = InputFileObject.ReadLine();
		var inputArray = inputLine.split(' ');
		var lineType = inputArray[0];
		if (inputArray[0] == '1')	// line type
		{
			inputArray[1] = '16';	// part color
		}
		inputLine = inputArray.join(' ');
		outputString += inputLine + '\r\n';
	}
	InputFileObject.Close();
	Write_Output();
}

// write copies of the converted file
// multiple periods in the filename could potentially mess up this script
function Write_Output()
{
	var OutputFileObject = fso.OpenTextFile(outputPath, 2, 1, 0);
	OutputFileObject.Write(outputString);
	OutputFileObject.Close();
}

Main();
