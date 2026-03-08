#ifndef COLOR_H
#define COLOR_H
#include <stdint.h>

typedef struct Vec4f Vec4f;

typedef struct Color {
	uint32_t value;
} Color;

Color vec4f_to_color(Vec4f c);
Color color_create(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

uint32_t color_value(Color col);

#endif

