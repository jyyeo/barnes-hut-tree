#include "vector.h"
#include "math.h"

vector_t vec_add(vector_t v1, vector_t v2) {
    vector_t output = {v1.x + v2.x, v1.y + v2.y};
    return output;
}

vector_t vec_subtract(vector_t v1, vector_t v2) {
    vector_t output = {v1.x - v2.x, v1.y - v2.y};
    return output;
}

vector_t vec_negate(vector_t v) {
    vector_t output = {-v.x, -v.y};
    return output;
}

vector_t vec_multiply(float scalar, vector_t v) {
    vector_t output = {scalar * v.x, scalar * v.y};
    return output;
}

float vec_mag(vector_t v1) {
	return sqrt(v1.x * v1.x + v1.y * v1.y);
}

float vec_distance(vector_t v1, vector_t v2) {
	return vec_mag(vec_subtract(v1, v2));
}

bool vec_same(vector_t v1, vector_t v2) {
	if ((v1.x == v2.x) && (v1.y == v2.y)) {
		return true;
	}
	return false;
}

vector_t vec_norm(vector_t v1) {
	vector_t output = { v1.x/vec_mag(v1), v1.y/vec_mag(v1) };
	return output;
}