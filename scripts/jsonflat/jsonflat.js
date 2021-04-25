// Caption: JSON model flattener
// Authors: Michael Horvath
// Version: 0.3.0
// Created: 2020/02/21
// Updated: 2021/04/24
// 
// This program calculates the positions of MPD sub-models in 3D space after 
// all matrix transformations have been applied. Requires as input a JSON file 
// created using mpd2json. The output is another JSON file. Note that the 
// format and structure of the JSON file outputted by this program and the 
// format and structure of the JSON file outputted by mpd2json are different! 
// The output file name is the same as the input file name plus the 
// ".flattened.json" extension.
//
// To do: the output JSON should really have an identical format to the input 
// JSON, except with the rotation matrices replaced by the identity matrix 
// where appropriate.
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
var InputFileObject;
var OutputFileObject;
var arrayOne = [];
var arrayTwo = [];
var partCount = 0;
var modelCount = 0;
var outMode = 0;
var usageText = 
'Invalid usage.\n\n' +
'Example:\n' +
'\tcscript jsonflat.js [input path] [-p|-m|-b]\n\n' +
'\t[input path] must point to a JSON file.\n' +
'\t[-p] parts only.\n' +
'\t[-s] sub-models only.\n' +
'\t[-b] both parts and sub-models.\n';

// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/repeat
if (!String.prototype.repeat)
{
	String.prototype.repeat = function(count)
	{
		'use strict';
		if (this == null)
		{
			throw new TypeError('can\'t convert ' + this + ' to object');
		}

		var str = '' + this;
		// To convert string to integer.
		count = +count;
		// Check NaN
		if (count != count)
		{
			count = 0;
		}

		if (count < 0)
		{
			throw new RangeError('repeat count must be non-negative');
		}

		if (count == Infinity)
		{
			throw new RangeError('repeat count must be less than infinity');
		}

		count = Math.floor(count);
		if (str.length == 0 || count == 0)
		{
			return '';
		}

		// Ensuring count is a 31-bit integer allows us to heavily optimize the
		// main part. But anyway, most current (August 2014) browsers can't handle
		// strings 1 << 28 chars or longer, so:
		if (str.length * count >= 1 << 28)
		{
			throw new RangeError('repeat count must not overflow maximum string size');
		}

		var maxCount = str.length * count;
		count = Math.floor(Math.log(count) / Math.log(2));
		while (count)
		{
			str += str;
			count--;
		}
		str += str.substring(0, maxCount - str.length);
		return str;
	}
}

// only continue if the script is run via Windows Scripting Host
if (typeof(WScript) != 'undefined')
{
	var progArgs = WScript.Arguments;
	var extensionA = /\.[jJ][sS][oO][nN]$/;
	var failCode = 0;	// needs to always be a power of 2
	if (progArgs.length != 2)
	{
		failCode += 1;
	}
	if (!extensionA.test(progArgs(0)))
	{
		failCode += 2;
	}
	if (progArgs(1) == '-b')
	{
		outMode = 0;
	}
	else if (progArgs(1) == '-p')
	{
		outMode = 1;
	}
	else if (progArgs(1) == '-m')
	{
		outMode = 2;
	}
	else
	{
		failCode += 4;
	}
	if (failCode == 0)
	{
		ProcessFile(progArgs(0));
	}
	else
	{
		WScript.Echo(usageText + '\nFailure code: ' + failCode);
	}
}

function ProcessFile(thisPath)
{
	var startDate = new Date();
	WScript.Echo('Processing file: ' + thisPath);
	fso = new ActiveXObject('Scripting.FileSystemObject');

	// read the input and store its contents as an array
	WScript.Echo('Reading input.');
	inputFileObject = fso.OpenTextFile(thisPath, 1);
	var inputCodeString = inputFileObject.ReadAll();
	inputFileObject.Close();
	arrayOne = eval('(' + inputCodeString + ')');

	// process the model
	WScript.Echo('Walking the tree.');
	var outModel = arrayOne[0];
	var outCoos = {x:0,y:0,z:0,a:1,b:0,c:0,d:0,e:1,f:0,g:0,h:0,i:1};
	PushItem(outModel.fileName, outCoos, 0);
	modelCount += 1;
	WalkTree(outModel.subFiles, outCoos, 0);

	// write a copy of the output
	WScript.Echo('Writing output.');
	var OutputFileString = ObjectToString(arrayTwo);
	var OutFile = thisPath + '.flattened.json';
	OutputFileObject = fso.OpenTextFile(OutFile, 2, 1, 0);
	OutputFileObject.Write(OutputFileString);
	OutputFileObject.Close();

	// finishing up
	WScript.Echo('Finishing up.');
	WScript.Echo(modelCount + ' models.');
	WScript.Echo(partCount + ' parts.');
	WScript.Echo((modelCount + partCount) + ' objects.');
	var endDate = new Date();
	WScript.Echo(((endDate - startDate)/1000) + ' seconds.');
}

function DoMatrix(inModel, inCoord)
{
	var outX = inCoord.a*inModel.x + inCoord.b*inModel.y + inCoord.c*inModel.z + inCoord.x;
	var outY = inCoord.d*inModel.x + inCoord.e*inModel.y + inCoord.f*inModel.z + inCoord.y;
	var outZ = inCoord.g*inModel.x + inCoord.h*inModel.y + inCoord.i*inModel.z + inCoord.z;
	var outA = inCoord.a*inModel.a + inCoord.b*inModel.d + inCoord.c*inModel.g;
	var outB = inCoord.a*inModel.b + inCoord.b*inModel.e + inCoord.c*inModel.h;
	var outC = inCoord.a*inModel.c + inCoord.b*inModel.f + inCoord.c*inModel.i;
	var outD = inCoord.d*inModel.a + inCoord.e*inModel.d + inCoord.f*inModel.g;
	var outE = inCoord.d*inModel.b + inCoord.e*inModel.e + inCoord.f*inModel.h;
	var outF = inCoord.d*inModel.c + inCoord.e*inModel.f + inCoord.f*inModel.i;
	var outG = inCoord.g*inModel.a + inCoord.h*inModel.d + inCoord.i*inModel.g;
	var outH = inCoord.g*inModel.b + inCoord.h*inModel.e + inCoord.i*inModel.h;
	var outI = inCoord.g*inModel.c + inCoord.h*inModel.f + inCoord.i*inModel.i;
	return {x:outX,y:outY,z:outZ,a:outA,b:outB,c:outC,d:outD,e:outE,f:outF,g:outG,h:outH,i:outI};
}

function WalkTree(inSubFiles, inCoord, indentLevel)
{
	for (var k in inSubFiles)
	{
		var kModel = inSubFiles[k];
		var kFile = kModel.subFileName;
		var kCoord = DoMatrix(kModel, inCoord);
		var outModel = {};
		var isSubModel = false;
		for (var i in arrayOne)
		{
			var iModel = arrayOne[i];
			var iFile = iModel.fileName;
			if (kFile.toLowerCase() == iFile.toLowerCase())
			{
				outSubFiles = iModel.subFiles;
				isSubModel = true;
				break;
			}
		}
		if (isSubModel == true)
		{
			if ((outMode == 2) || (outMode == 0)) {PushItem(kFile, kCoord, indentLevel);}
			modelCount += 1;
			WalkTree(outSubFiles, kCoord, indentLevel+1);
		}
		else
		{
			if ((outMode == 1) || (outMode == 0)) {PushItem(kFile, kCoord, indentLevel);}
			partCount += 1;
		}
	}
}

function PushItem(inFile, inCoos, indentLevel)
{
	WScript.Echo('  '.repeat(indentLevel) + inFile);
	arrayTwo.push({fileName:inFile,matrix:RoundObject(inCoos)});
}

// https://stackoverflow.com/questions/11832914/round-to-at-most-2-decimal-places-only-if-necessary
// cc by-sa 4.0
// with modifications
function RoundValue(n, p)
{
	if (Number.EPSILON === undefined) {Number.EPSILON = Math.pow(2, -52);}
	var r = 0.5 * Number.EPSILON * n;
	var o = 1;
	while (p-- > 0) {o *= 10;}
	if (n < 0) {o *= -1;}
	return Math.round((n + r) * o) / o;
}

function RoundObject(inArray)
{
	for (var i in inArray) {inArray[i] = RoundValue(inArray[i], 6);}
	return inArray;
}

// https://stackoverflow.com/questions/957537/how-can-i-display-a-javascript-object
// cc by-sa 4.0
// with modifications, no indentation sadly
function ObjectToString(o)
{
	if (!o) {return 'null';}
	var k = '';
	var na = typeof(o.length) == 'undefined';
	var str = '';
	for (var p in o)
	{
		if (na) {k = '"' + p + '":';}
		if (typeof o[p] == 'string') {str += k + '"' + o[p] + '",';}
		else if (typeof o[p] == 'object') {str += k + ObjectToString(o[p]) + ',';}
		else {str += k + o[p] + ',';}
	}
	if (na) {return '{' + str.slice(0, -1) + '}';}
	else {return '[' + str.slice(0, -1) + ']';}
}
