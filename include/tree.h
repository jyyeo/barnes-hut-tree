#ifndef __TREE_H__
#define __TREE_H__

#include "vector.h"
#include "body.h"

struct Tree;

struct Tree {
	Body body;
	vector_t bl; //bottom left
	vector_t tr; //top right
	struct Tree* NW;
	struct Tree* NE;
	struct Tree* SW;
	struct Tree* SE;
};

vector_t get_centre(Tree tree);

Body get_body(Tree tree);

bool empty_node(Tree tree);

void initialize_tree(Tree *tree, vector_t bl, vector_t tr);

void initialize_quad(Tree *tree);

void print_tree(Tree tree);

void print_entire_tree(Tree *tree);

bool no_quads(Tree *tree);

void insert_body(Tree *tree, Body b);

#endif