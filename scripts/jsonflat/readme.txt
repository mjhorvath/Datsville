This program calculates the positions of MPD sub-models in 3D space after 
all matrix transformations have been applied. Requires as input a JSON file 
created using mpd2json. The output is another JSON file. Note that the 
format and structure of the JSON file outputted by this program and the 
format and structure of the JSON file outputted by mpd2json are different! 
The output file name is the same as the input file name plus the 
".flattened.json" extension.

To do: the output JSON should really have an identical format to the input 
JSON, except with the rotation matrices replaced by the identity matrix 
where appropriate.

cscript jsonflat.js [input path] [-p|-m|-b]

[input path] must point to a JSON file
[-p] parts only
[-s] sub-models only
[-b] both parts and sub-models
