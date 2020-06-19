#ifndef __TREE_H__
#define __TREE_H__

#include "vector.h"
#include "body.h"

struct Tree;

struct Tree {
	float mass;
	vector_t bl; //bottom left
	vector_t tr; //top right
	struct Tree* NW;
	struct Tree* NE;
	struct Tree* SW;
	struct Tree* SE;
};

float get_mass(Tree tree);

vector_t get_centre(Tree tree);

Body get_body(Tree tree);

bool empty_node(Tree tree);

void initialize_tree(Tree *tree, float mass, vector_t bl, vector_t tr);

void print_tree(Tree tree);

#endif