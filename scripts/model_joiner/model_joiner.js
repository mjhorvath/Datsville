// Caption: LDraw model joiner
// Authors: Michael Horvath
// Version: 1.0.0
// Created: 2021/04/21
// Updated: 2021/04/21
// 
// This program joins several models into a single file. It strips all meta 
// tags and comments in the process.
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
var usageText = 
'Invalid parameters.\n\n' +
'cscript model_joiner.js [inputfile1.ldr] ... [inputfileN.ldr] -o [outputfile.ldr]\n\n' +
'\t[inputfile1.ldr] to [inputfileN.ldr] are the input files to join.\n' +
'\t-o [outputfile.ldr] is the output file.\n' +
'\nNote this program ignores/discards all comments.\n';
var inputFiles = [];
var outputFile = '';
var outputText = '';

function Main()
{
	// only continue if the script is run via Windows Scripting Host
	// should spawn a message here if the condition is true instead of false
	if (typeof(WScript) != 'undefined')
	{
		var progArgs = WScript.Arguments;
		var numArgs = progArgs.length;
		var extensionA = /\.[lL][dD][rR]$/;
		var extensionB = /\.[dD][aA][tT]$/;
		var canContinue = true;
		for (var i = 0; i < numArgs; i++)
		{
			var thisArg = progArgs(i);
			var nextArg = progArgs(i + 1);
			if (thisArg == '-o')
			{
				outputFile = nextArg;
				i += 1;
			}
			else
			{
				inputFiles.push(thisArg);
			}
		}
		if (!extensionA.test(outputFile) && !extensionB.test(outputFile))
		{
			WScript.Echo('Invalid file type: output file must have an .ldr or .dat extension.\n')
			canContinue = false;
		}
		for (var i = 0, n = inputFiles.length; i < n; i++)
		{
			var thisFile = inputFiles[i];
			if (!extensionA.test(thisFile) && !extensionB.test(thisFile))
			{
				WScript.Echo('Invalid file type: input file must have an .ldr or .dat extension.\n')
				canContinue = false;
				break;
			}
		}
		if (canContinue)
		{
			ReadInput();
		}
		else
		{
			WScript.Echo(usageText);
		}
	}
}

function ReadInput()
{
	fso = new ActiveXObject('Scripting.FileSystemObject');
	WshShell = new ActiveXObject('WScript.Shell');

	// check first whether the files exist
	for (var i = 0, n = inputFiles.length; i < n; i++)
	{
		fso.GetFile(inputFiles[i]);
	}

	for (var i = 0, n = inputFiles.length; i < n; i++)
	{
		DoStuff(inputFiles[i]);
	}

	WriteOutput();
}

// read the input file and store its contents as a table
function DoStuff(inputFile)
{
	var lineCount = 0;
	var InputFileObject = fso.OpenTextFile(inputFile, 1);
	while (!InputFileObject.AtEndOfStream)
	{
		var inputString = InputFileObject.ReadLine();
		var inputArray = inputString.split(/\s/);
		// meta tags and comments
		if (inputArray[0] == '0')
		{
//			if (lineCount == 0)						{}
//			else if (inputString.match(/0\s+FILE/))				{}
//			// not sure yet if apostraphes and quotes need to be escaped further
//			else if (inputString.match(/^0\s+Name\:\s+(.*)$/))		{}
//			else if (inputString.match(/^0\s+Author\:\s+(.*)$/))		{}
//			else if (inputString.match(/^0\s+\!LICENSE\s+(.*)$/))		{}
//			// multiple possible "type" meta tags should be case-insensitive
//			else if (inputString.match(/^0\s+\!LDRAW_ORG\s+(.*)$/))		{}
//			else if (inputString.match(/^0\s+LDRAW_ORG\s+(.*)$/))		{}
//			else if (inputString.match(/^0\s+Official\s+LCAD\s+(.*)$/))	{}
//			else if (inputString.match(/^0\s+Unofficial\s+(.*)$/))		{}
//			else if (inputString.match(/^0\s+Un\-official\s+(.*)$/))	{}
//			// these are MLCAD tags
//			else if (inputString.match(/^0\s+ROTATION CENTER\s+(.*)$/))	{}
//			else if (inputString.match(/^0\s+ROTATION CONFIG\s+(.*)$/))	{}
//			else
//			{
//				outputText += inputString + '\n';
//			}
		}
		// sub-models and parts
		else
		{
			outputText += inputString + '\n';
		}
		lineCount += 1;
	}
	InputFileObject.Close();
}

// write copies of the converted file
function WriteOutput()
{
	var headerText =
	'0 Joined Model\n'+
	'0 Name: '+outputFile+'\n'+
	'0 Author: model_joiner.js\n'+
	'0 Unofficial Model\n'+
	'0 ROTATION CENTER 0 0 0 1 "Custom"\n'+
	'0 ROTATION CONFIG 0 0\n';
	var OutputFileObject = fso.OpenTextFile(outputFile, 2, 1, 0);
	OutputFileObject.Write(headerText + outputText + '0\n');
	OutputFileObject.Close();
}

Main();
