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
	file.open(argv[1]);
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
	vector_t bl = {min_x(bodies, n), min_y(bodies, n)};
	vector_t tr = {max_x(bodies, n), max_y(bodies, n)};

	Tree *tree;
	tree = new Tree;
	initialize_tree(tree, bl, tr);

	// insert bodies
	for (int i = 0; i < n; i++) {
		// printf("inserting body %d...\n", i);
		insert_body(tree, bodies[i]);
		// print_entire_tree(tree);
	}

	// print tree
	print_entire_tree(tree);

	return 0;
}