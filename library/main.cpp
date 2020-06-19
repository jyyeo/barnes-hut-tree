#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <sstream>

#include "vector.h"
#include "body.h"
#include "tree.h"

using std::string;
using std::ifstream;
using std::getline;
using std::stringstream;

int main(int argc, char const *argv[]) {
	// read bodies from txt file
	ifstream file;
	file.open("test1.txt");
	string line;
	getline(file, line);
	int n;
	n = stoi(line); //number of bodies

	Body bodies[n];
	for (int i = 0; i < n; i++) {
		getline(file, line);
		stringstream s(line);
		float token[5];
		for (int j = 0; j < 5; j++) {
			s >> token[j];
		}
		float mass = token[0];
		vector_t position = {token[1], token[2]};
		vector_t velocity = {token[3], token[4]};
		bodies[i].mass = mass;
		bodies[i].position = position;
		bodies[i].velocity = velocity;
	}

	file.close();

	// create barnes-hut tree
	printf("%f\n", min_x(bodies, n));
	vector_t bl = {min_x(bodies, n), min_y(bodies, n)};
	vector_t tr = {max_x(bodies, n), max_y(bodies, n)};
	Tree *tree;
	tree = new Tree;
	initialize_tree(tree, 0.0, bl, tr);

	print_tree(*tree);
	Tree *NW;
	NW = tree->NW;
	print_tree(*NW);
	return 0;
}