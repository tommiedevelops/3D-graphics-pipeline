#ifndef RENDER_H
#define RENDER_H

#include "renderer/vert_shader.h"
#include "renderer/frag_shader.h"

typedef struct Triangle Triangle;
typedef struct Scene Scene;
typedef struct FrameBuffer FrameBuffer;
typedef struct Renderer Renderer;

typedef struct RenderPass {
	VSUniforms*  vs_u;
	VertShaderF  vs;

	FSUniforms*  fs_u;
	FragShaderF  fs;
	
	FrameBuffer* fb;
} RenderPass;

typedef struct Pipeline {
	VertShaderF vs;
	FragShaderF fs;
} Pipeline;

typedef struct Renderer { 
	VSUniforms* vs_u;
	FSUniforms* fs_u;
	Pipeline* p;
} Renderer;

Renderer* renderer_create();
void renderer_destroy(Renderer* r);
void render_wireframe(FrameBuffer* fb, Triangle* triangles, int num_triangles);
void renderer_draw_scene(Renderer* r, FrameBuffer* fb ,Scene* scene);

#endif


/*
 *  A render pass should be something that the user can create themselves and add.
 *  RenderPass* rp = RenderPass_Create(VertShaderF vs, FragShaderF fs, TargetBuffer target);
 *  Renderer_AddRenderPass(RenderPass* rp);
 *  
 *  Then when Renderer_Draw_Scene() is called, it should loop through each render pass, fill in the Uniforms and execute 
 *  the pass.
 *
 */
