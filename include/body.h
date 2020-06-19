#ifndef __BODY_H__
#define __BODY_H__

#include "vector.h"

struct Body {
	float mass;
	vector_t position;
	vector_t velocity;
};

float get_mass(Body b);

vector_t get_position(Body b);

vector_t get_velocity(Body b);

float sum_mass (Body bodies[], int n);

float max_x (Body bodies[], int n);

float min_x (Body bodies[], int n);

float min_y (Body bodies[], int n);

float max_y (Body bodies[], int n);

#endif