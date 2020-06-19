#include "vector.h"
#include "body.h"

float get_mass (Body b) {
	return b.mass;
}

vector_t get_position (Body b) {
	return b.position;
}

vector_t get_velocity (Body b) {
	return b.velocity;
}

float sum_mass (Body bodies[], int n) {
	float total_mass = 0.0;
	for (int i = 0; i < n; i++) {
		total_mass += get_mass(bodies[i]);
	}
	return total_mass;
}

float max_x (Body bodies[], int n) {
	float max_x = get_position(bodies[0]).x;
	for (int i = 1; i < n; i++) {
		if (max_x < get_position(bodies[i]).x) {
			max_x = get_position(bodies[i]).x;
		}
	}
	return max_x;
}

float min_x (Body bodies[], int n) {
	float min_x = get_position(bodies[0]).x;
	for (int i = 1; i < n; i++) {
		if (min_x > get_position(bodies[i]).x) {
			min_x = get_position(bodies[i]).x;
		}
	}
	return min_x;
}

float max_y (Body bodies[], int n) {
	float max_y = get_position(bodies[0]).y;
	for (int i = 1; i < n; i++) {
		if (max_y < get_position(bodies[i]).y) {
			max_y = get_position(bodies[i]).y;
		}
	}
	return max_y;
}

float min_y (Body bodies[], int n) {
	float min_y = get_position(bodies[0]).y;
	for (int i = 1; i < n; i++) {
		if (min_y < get_position(bodies[i]).y) {
			min_y = get_position(bodies[i]).y;
		}
	}
	return min_y;
}
