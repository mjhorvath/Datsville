This program calculates the positions of MPD sub-models in 3D space after 
all matrix transformations have been applied. Requires as input a JSON file 
created using mpd2json. The output is another JSON file.

cscript mpdcalcpos.js [input path] [-p|-m|-b]

[input path] must point to a JSON file
[-p] parts only
[-s] sub-models only
[-b] both parts and sub-models
