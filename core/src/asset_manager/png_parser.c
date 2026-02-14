#include <stdlib.h>
#include "game_math/vector.h"
#include "renderer/texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "third_party/stb_image.h"

struct PNG
{
	int width;
	int height;
	int channels;
	uint8_t* img;
};

typedef struct PNG PNG;

Texture* png_load(char* filename)
{
	int width, height, channels;
	uint8_t* img = stbi_load(filename, &width, &height, &channels, 4);

	if(NULL == img) return NULL;

	Texture* tex = texture_create(width, height);
	
	for(int i = 0; i < width;  i++)
	for(int j = 0; j < height; j++)
	{
		int index = (j * width + i) * 4;

		Vec4f col_rgb = {
			.x = (float)img[index + 0] / 255.0f,
			.y = (float)img[index + 1] / 255.0f,
			.z = (float)img[index + 2] / 255.0f,
			.w = (float)img[index + 3] / 255.0f
		};
		
		texture_set_map_value(tex, i, j, col_rgb);
	}
	
	stbi_image_free(img);
	return tex;
}
	
