#include "vector.h"
#include "plane.h"

#define EPS (-1e6f)
bool plane4_inside(Plane4 P, Vec4f x) {
	return plane4_sdf(P,x) >= EPS;
}

float plane4_sdf(Plane4 P, Vec4f x){
	return vec4f_dot(P.n, vec4f_add(x, vec4f_scale(P.p, -1.0f) ));
}	

float plane4_compute_intersect_t(Plane4 P, Vec4f u, Vec4f v) {
	float fu = plane4_sdf(P,u);
	float fv = plane4_sdf(P,v);
		
	float denom = fu - fv;
	if (fabsf(denom) < 1e-8f) return 0.0f;

	float t = fu / denom;
	t = fminf(1.0f, fmaxf(0.0f, t));

	return t;
}

