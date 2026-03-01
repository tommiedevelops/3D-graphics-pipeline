#ifndef MATERIAL_H
#define MATERIAL_H

#include "game_math/vector.h"
#include "renderer/frag_shader.h"
#include "renderer/vert_shader.h"

typedef struct Material Material;
typedef struct Texture Texture;

typedef struct Material {
	Vec4f color; // fallback color if no texture
	Texture* texture; // for base
	Vec4f diffuse;
	Vec4f specular;
	const char* handle;
	VertShaderF vert_shader;
	FragShaderF frag_shader;
} Material;

Material* material_default(); 
Material* material_create(Vec4f color, Texture* tex, 
			  VertShaderF vs, FragShaderF fs);

void      material_destroy(Material* mat);
Vec4f     material_get_base_color(Material* mat);
Texture*  material_get_texture(Material* mat);
Vec4f     material_get_albedo(Material* mat, Vec2f uv);

#endif
