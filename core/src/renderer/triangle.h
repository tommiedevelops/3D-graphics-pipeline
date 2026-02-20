#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "game_math/vector.h"
#include "game_math/matrix.h"

typedef struct Bounds3 Bounds3;
typedef struct VSout VSout;

typedef struct Triangle {
	VSout *v[3]; //array of 3 VSout ptrs
	int id;
} Triangle;

void   tri_print(Triangle* tri);
Bounds3 tri_get_bounds(const Triangle* tri);
void   tri_apply_perspective_divide(Triangle* tri);
void   tri_apply_transformation(Mat4 tr, Triangle* tri);
void   tri_precompute_interpolated_values(Triangle* tri);
#endif
