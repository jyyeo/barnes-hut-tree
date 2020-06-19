#include "vector.h"
#include "body.h"
#include "tree.h"
#include <stdio.h>

float get_mass(Tree tree) {
	return tree.mass;
}

vector_t get_centre(Tree tree) {
	float pos_x = (tree.bl).x + 0.5 * ((tree.tr).x - (tree.bl).x);
	float pos_y = (tree.bl).y + 0.5 * ((tree.tr).y - (tree.bl).y);
	vector_t centre = {pos_x, pos_y};
	return centre;
}

Body get_body(Tree tree) {
	float mass = get_mass(tree);
	vector_t position = get_centre(tree);
	vector_t velocity = {0.0, 0.0};
	Body body;
	body.mass = mass;
	body.position = position;
	body.velocity = velocity;
	return body;
}

bool empty_node(Tree tree) {
	if (get_mass(get_body(tree)) == 0.0 && vec_same(tree.bl,tree.tr)) {
		return true;
	}
	else {
		return false;
	}
}
void initialize_tree(Tree *tree, float mass, vector_t bl, vector_t tr) {
	tree->mass = mass;
	tree->bl = bl;
	tree->tr = tr;

	Tree *NW;
	NW = new Tree;
	NW->mass = 0.0;
	vector_t NW_bl = {bl.x, bl.y + 0.5 * (tr.y - bl.y)};
	NW->bl = NW_bl;
	vector_t NW_tr = {bl.x + 0.5 * (tr.x - bl.x), tr.y};
	NW->tr = NW_tr;
	tree->NW = NW;

	Tree *NE;
	NE = new Tree;
	NE->mass = 0.0;
	vector_t NE_bl = {bl.x + 0.5 * (tr.x - bl.x), bl.y + 0.5 * (tr.y - bl.y)};
	NE->bl = NE_bl;
	vector_t NE_tr = tr;
	NE->tr = NE_tr;
	tree->NE = NE;

	Tree *SW;
	SW = new Tree;
	SW->mass = 0.0;
	vector_t SW_bl = bl;
	SW->bl = SW_bl;
	vector_t SW_tr = {bl.x + 0.5 * (tr.x - bl.x), bl.y + 0.5 * (tr.y - bl.y)};
	SW->tr = SW_tr;
	tree->SW = SW;

	Tree *SE;
	SE = new Tree;
	SE->mass = 0.0;
	vector_t SE_bl = {bl.x, bl.y + 0.5 * (tr.y - bl.y)};
	SE->bl = SE_bl;
	vector_t SE_tr = {tr.x, bl.y + 0.5 * (tr.y - bl.y)};
	SE->tr = SE_tr;
	tree->SE = SE;

	// haven't finish!
}

void print_tree(Tree tree) {
	float mass = get_mass(tree);
	float pos_x = get_centre(tree).x;
	float pos_y = get_centre(tree).y;
	printf("mass: %.3f; centre: (%.3f, %.3f)\n", mass, pos_x, pos_y);	
	printf("bl: (%.3f, %.3f)\n", tree.bl.x, tree.bl.y);
	printf("tr: (%.3f, %.3f)\n", tree.tr.x, tree.tr.y);
}	