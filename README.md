# Visualization of a Barnes-Hut tree
## Description
This program takes in a .txt file in the following format:

`<number of bodies>`

`<weight of body 1>  <x-coordinate of body 1>  <y-coordinate of body 1>  <x-velocity of body 1>  <y-velocity of body 1>`
...

An example of an input file is included (`test1.txt`).

Each line of the output consists of the mass, coordinates of the midpoint, bottom left and top right corners of a node in the tree. The first line of the output consists the abovementioned of the root node. If a node has descendants, all 4 descendants will be printed out as well, immediately after the node, in the following order: NE, NW, SW, SE.

## How to run it
$ make

$ ./main `<name of input file>`

Don't forget the input file's path directory if it is not in the root folder!

## Credits
With love and help from Tristan Ang
