#include <stdlib.h>
#include "game_math/vector.h"
#include "texture.h"

void texture_destroy(Texture* tex){
	if(!tex) return;
	if(tex->map) free(tex->map);
	free(tex);
}

Vec4f texture_sample(Texture* tex, float u, float v){
	if(!tex || !tex->map) return VEC4F_0;

	// Tiling mode is Repeat / Wrap
	float my_u = u - floorf(u);		
	float my_v = v - floorf(v);

	// Nearest neighbour sampling (point sampling)
	float xf = my_u * (tex->width - 1);
	float yf = my_v * (tex->height - 1);

	int x = (int)(xf + 0.5f);
	int y = (int)(yf + 0.5f);

	if (x < 0) x = 0;
	if (x >= tex->width)  x = tex->width - 1;
	if (y < 0) y = 0;
	if (y >= tex->height) y = tex->height - 1;

	Vec4f value = tex->map[y*tex->width + x];

	return value;
}

