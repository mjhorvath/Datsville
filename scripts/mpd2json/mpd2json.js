// Caption: LDraw MPD to JSON converter
// Authors: Michael Horvath
// Version: 0.2.2
// Created: 2020/02/20
// Updated: 2021/04/20
// 
// This program reads an MPD or XMPD model and ouputs a JSON representation of 
// it. It currently totally ignores most meta tags such as BFC. It also ignores 
// all comment lines. You should not expect the conversion process to be 
// reversible for these reasons.
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

var fso;
var wshShell;
var usageText =
'Invalid number of parameters.\n\n'+
'syntax example: cscript mpd2json.js [input path]\n\n'+
'[input path] must be an MPD or XMPD file.\n\n'+
'Note that XMPD files will work, but the file naming is not properly handled in the JSON output. You will have to fix the file names manually. Sorry.\n';

// only continue if the script is run via Windows Scripting Host
if (typeof(WScript) != 'undefined')
{
	var progArgs = WScript.Arguments;
	var fileArg = progArgs(0);
	var canContinue = true;
	var extensionA = /\.[mM][pP][dD]$/;
	var extensionB = /\.[xX][mM][pP][dD]$/;
	if (progArgs.length != 1)
		canContinue = false;
	else if (!extensionA.test(fileArg) && !extensionB.test(fileArg))
		canContinue = false;
	if (canContinue)
	{
		try
		{
			fso = new ActiveXObject('Scripting.FileSystemObject');
			var inputPath = fso.GetFile(fileArg).Path;
			ProcessFile(inputPath);
		}
		catch (e1)
		{
			WScript.echo
			(
				'Error name: '			+ e1.name
				+ '\nError message: '		+ e1.message
				+ '\nError number: '		+ e1.number
				+ '\nError description: '	+ e1.description
			);
		}
	}
	else
		WScript.Echo(usageText);
}

function ProcessFile(thisPath)
{
	WScript.Echo('Processing file: ' + thisPath);

	// read the input file and store its contents as a string
	WScript.Echo('Reading input.');
	var inputFileObject = fso.OpenTextFile(thisPath, 1);
	var outputArray = [];
	var objectCount = -1;
	var subFilesCount = -1;
	var hasDescription = false;

	WScript.Echo('Reading and processing input.');
	while (!inputFileObject.AtEndOfStream)
	{
		var inputString = inputFileObject.ReadLine();
		var stringArray = inputString.split(/\s/);
		var tempObject;
		var tempSubFile;

		// meta tags and comments
		if (stringArray[0] == '0')
		{
			if (inputString.match(/0\s+FILE/))
			{
				objectCount += 1;
				subFilesCount = -1;
				outputArray[objectCount] = {};
				tempObject = outputArray[objectCount];
				tempObject.fileName = stringArray[2];
				tempObject.subFiles = [];
				hasDescription = false;
			}
			// not sure yet if apostraphes and quotes need to be escaped further
			else if (inputString.match(/^0\s+Name\:\s+(.*)$/))
				tempObject.name = EscapeQuotes(inputString.replace(/^0\s+Name\:\s+(.*)$/,'$1'));		// string!
			else if (inputString.match(/^0\s+Author\:\s+(.*)$/))
				tempObject.author = EscapeQuotes(inputString.replace(/^0\s+Author\:\s+(.*)$/,'$1'));		// string!
			else if (inputString.match(/^0\s+\!LICENSE\s+(.*)$/))
				tempObject.license = EscapeQuotes(inputString.replace(/^0\s+\!LICENSE\s+(.*)$/,'$1'));		// string!
			// multiple possible "type" meta tags should be case-insensitive
			else if (inputString.match(/^0\s+\!LDRAW_ORG\s+(.*)$/))
				tempObject.type = EscapeQuotes(inputString.replace(/^0\s+\!LDRAW_ORG\s+(.*)$/,'$1'));		// string!
			else if (inputString.match(/^0\s+LDRAW_ORG\s+(.*)$/))
				tempObject.type = EscapeQuotes(inputString.replace(/^0\s+LDRAW_ORG\s+(.*)$/,'$1'));		// string!
			else if (inputString.match(/^0\s+Official\s+LCAD\s+(.*)$/))
				tempObject.type = EscapeQuotes(inputString.replace(/^0\s+Official\s+LCAD\s+(.*)$/,'$1'));		// string!
			else if (inputString.match(/^0\s+Unofficial\s+(.*)$/))
				tempObject.type = EscapeQuotes(inputString.replace(/^0\s+Unofficial\s+(.*)$/,'$1'));		// string!
			else if (inputString.match(/^0\s+Un\-official\s+(.*)$/))
				tempObject.type = EscapeQuotes(inputString.replace(/^0\s+Un\-official\s+(.*)$/,'$1'));		// string!
			else if (hasDescription == false)
			{
				tempObject.description = EscapeQuotes(inputString.replace(/^0\s+(.*)$/,'$1'));		// string!
				hasDescription = true;
			}
			// these are MLCAD tags
			else if (inputString.match(/^0\s+ROTATION CENTER\s+(.*)$/))
				tempObject.rotationCenter = [parseFloat(stringArray[3]),parseFloat(stringArray[4]),parseFloat(stringArray[5]),parseFloat(stringArray[6]),stringArray[7].replace(/"/g,'')];		// string!
			else if (inputString.match(/^0\s+ROTATION CONFIG\s+(.*)$/))
				tempObject.rotationConfig = [parseFloat(stringArray[3]),parseFloat(stringArray[4])];
		}
		// sub-models and parts
		else if (stringArray[0] == '1')
		{
			// 1 <colour> x y z a b c d e f g h i <file>
			subFilesCount += 1;
			tempObject.subFiles[subFilesCount] = {};
			tempSubFile			= tempObject.subFiles[subFilesCount];
			tempSubFile.color		=   parseFloat(stringArray[ 1]);
			tempSubFile.x			=   parseFloat(stringArray[ 2]);
			tempSubFile.y			=   parseFloat(stringArray[ 3]);
			tempSubFile.z			=   parseFloat(stringArray[ 4]);
			tempSubFile.a			=   parseFloat(stringArray[ 5]);
			tempSubFile.b			=   parseFloat(stringArray[ 6]);
			tempSubFile.c			=   parseFloat(stringArray[ 7]);
			tempSubFile.d			=   parseFloat(stringArray[ 8]);
			tempSubFile.e			=   parseFloat(stringArray[ 9]);
			tempSubFile.f			=   parseFloat(stringArray[10]);
			tempSubFile.g			=   parseFloat(stringArray[11]);
			tempSubFile.h			=   parseFloat(stringArray[12]);
			tempSubFile.i			=   parseFloat(stringArray[13]);
			tempSubFile.fileName		= EscapeQuotes(stringArray[14]);		// string!
		}
	}
	inputFileObject.Close();
	
	// write a copy of the output
	WScript.Echo('Writing output.');
	var outputFileString = ObjToSource(outputArray);
	var outFile = thisPath + '.json';
	var outputFileObject = fso.OpenTextFile(outFile, 2, 1, 0);
	outputFileObject.Write(outputFileString);
	outputFileObject.Close();
	WScript.Echo('Done.');
}

function EscapeQuotes(inString)
{
	return inString.replace(/\\/g,'\\\\').replace(/\"/g,'\\"');
}

// https://stackoverflow.com/questions/957537/how-can-i-display-a-javascript-object
// cc by-sa 4.0
// with modifications, no indentation sadly
function ObjToSource(o)
{
    if (!o)
		return 'null';
    var k = '';
	var na = typeof(o.length) == 'undefined';
	var str = '';
    for (var p in o)
	{
        if (na)
			k = '"' + p + '":';
        if (typeof o[p] == 'string')
			str += k + '"' + o[p] + '",';
        else if (typeof o[p] == 'object')
			str += k + ObjToSource(o[p]) + ',';
        else
			str += k + o[p] + ',';
    }
    if (na)
		return '{' + str.slice(0, -1) + '}';
    else
		return '[' + str.slice(0, -1) + ']';
}
