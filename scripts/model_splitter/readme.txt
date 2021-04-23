This program splits a model into several files based on their XZ coordinates. 
It strips all meta tags and comments in the process.

cscript model_splitter.js [inputfile.ldr] [n] [minX] [maxX] [minZ] [maxZ]

[inputfile.ldr] is the terrain file to split.

[n] is the number of divisions to make along each side. It should be divisible by 2.

[minX] [maxX] [minZ] [maxZ] are the minimum and maximum extents of the model.

The total number of sections overall will be equal to [n] squared.
