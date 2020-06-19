#include "vector.h"
#include "body.h"
#include "tree.h"
#include <stdio.h>

vector_t get_centre(Tree tree) {
	float pos_x = (tree.bl).x + 0.5 * ((tree.tr).x - (tree.bl).x);
	float pos_y = (tree.bl).y + 0.5 * ((tree.tr).y - (tree.bl).y);
	vector_t centre = {pos_x, pos_y};
	return centre;
}

Body get_body(Tree tree) {
	return tree.body;
}

bool empty_node(Tree tree) {
	if (get_mass(get_body(tree)) == 0.0 && vec_same(tree.bl,tree.tr)) {
		return true;
	}
	else {
		return false;
	}
}
void initialize_tree(Tree *tree, vector_t bl, vector_t tr) {
	(tree->body).mass = 0.0;
	tree->bl = bl;
	tree->tr = tr;
	tree->NW = 0;
	tree->NE = 0;
	tree->SW = 0;
	tree->SE = 0;
}

void initialize_quads(Tree *tree) {
	vector_t bl = tree->bl;
	vector_t tr = tree->tr;

	Tree *NW;
	NW = new Tree;
	NW->body.mass = 0.0;
	vector_t NW_bl = {bl.x, bl.y + 0.5 * (tr.y - bl.y)};
	NW->bl = NW_bl;
	vector_t NW_tr = {bl.x + 0.5 * (tr.x - bl.x), tr.y};
	NW->tr = NW_tr;
	tree->NW = NW;

	Tree *NE;
	NE = new Tree;
	NE->body.mass = 0.0;
	vector_t NE_bl = {bl.x + 0.5 * (tr.x - bl.x), bl.y + 0.5 * (tr.y - bl.y)};
	NE->bl = NE_bl;
	vector_t NE_tr = tr;
	NE->tr = NE_tr;
	tree->NE = NE;

	Tree *SW;
	SW = new Tree;
	SW->body.mass = 0.0;
	vector_t SW_bl = bl;
	SW->bl = SW_bl;
	vector_t SW_tr = {bl.x + 0.5 * (tr.x - bl.x), bl.y + 0.5 * (tr.y - bl.y)};
	SW->tr = SW_tr;
	tree->SW = SW;

	Tree *SE;
	SE = new Tree;
	SE->body.mass = 0.0;
	vector_t SE_bl = {bl.x + 0.5 * (tr.x - bl.x), bl.y};
	SE->bl = SE_bl;
	vector_t SE_tr = {tr.x, bl.y + 0.5 * (tr.y - bl.y)};
	SE->tr = SE_tr;
	tree->SE = SE;
}

void print_tree(Tree tree) {
	float mass = get_mass(get_body(tree));
	float pos_x = get_centre(tree).x;
	float pos_y = get_centre(tree).y;
	printf("mass: %.3f; centre: (%.3f, %.3f); ", mass, pos_x, pos_y);	
	printf("bl: (%.3f, %.3f); tr: (%.3f, %.3f)\n", tree.bl.x, tree.bl.y, tree.tr.x, tree.tr.y);
}	

void print_entire_tree(Tree *tree) {
	Tree curr_node;
	curr_node = *tree;
	print_tree(curr_node);
	if (no_quads(tree) == false) {
		printf("NW: ");
		print_entire_tree(tree->NW);
		printf("NE: ");
		print_entire_tree(tree->NE);
		printf("SW: ");
		print_entire_tree(tree->SW);
		printf("SE: ");
		print_entire_tree(tree->SE);
	}
}

bool no_quads(Tree *tree) {
	if (tree->NW == 0 && tree->NE == 0 &&
		tree->SW == 0 && tree->SE == 0) {
		return true;
	}
	else {
		return false;
	}
}

int check_quad(Tree *tree, Body b) {
	vector_t bl = tree->bl;
	vector_t tr = tree->tr;
	float mid_x = bl.x + 0.5 * (tr.x - bl.x);
	float mid_y = bl.y + 0.5 * (tr.y - bl.y);
	float pos_x = get_position(b).x;
	float pos_y = get_position(b).y;

	if (pos_x >= mid_x && pos_y >= mid_y) { //NE
		return 1;
	}
	if (pos_x < mid_x && pos_y >= mid_y) { //NW
		return 2;
	}
	if (pos_x < mid_x && pos_y < mid_y) { //SW
		return 3;
	}
	if (pos_x >= mid_x && pos_y < mid_y) { //SE
		return 4;
	}
	return 0;
}

void insert_body(Tree *tree, Body b) {
	// node does not contain a body
	if (get_mass(get_body(*tree)) == 0.0) {
		(tree->body).mass = get_mass(b);
	}
	// node is an internal node
	else if (no_quads(tree) == false) {
		(tree->body).mass += get_mass(b);
		int quad = check_quad(tree, b);
		if (quad == 1) {
			insert_body(tree->NE, b);
		}
		if (quad == 2) {
			insert_body(tree->NW, b);
		}
		if (quad == 3) {
			insert_body(tree->SW, b);
		}
		if (quad == 4) {
			insert_body(tree->SE, b);
		}
	}
	// node is an external node with a body 'c'
	else {
		initialize_quads(tree);
		Body c;
		c.mass = get_mass(tree->body);
		c.position = get_position(tree->body);
		c.velocity = get_velocity(tree->body);
		int quad_c = check_quad(tree, c);
		if (quad_c == 1) {
			insert_body(tree->NE, c);
		}
		if (quad_c == 2) {
			insert_body(tree->NW, c);
		}
		if (quad_c == 3) {
			insert_body(tree->SW, c);
		}
		if (quad_c == 4) {
			insert_body(tree->SE, c);
		}

		(tree->body).mass += get_mass(b);
		int quad_b = check_quad(tree, b);
		if (quad_b == 1) {
			insert_body(tree->NE, b);
		}
		if (quad_b == 2) {
			insert_body(tree->NW, b);
		}
		if (quad_b == 3) {
			insert_body(tree->SW, b);
		}
		if (quad_b == 4) {
			insert_body(tree->SE, b);
		}
	}
}