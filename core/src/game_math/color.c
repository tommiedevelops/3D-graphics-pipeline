#include "error_log.h"
#include "vector.h"
#include "color.h"

#include <stdint.h>

Color vec4f_to_color(Vec4f c) {
    // Clamp
    float r = c.x < 0 ? 0 : (c.x > 1 ? 1 : c.x);
    float g = c.y < 0 ? 0 : (c.y > 1 ? 1 : c.y);
    float b = c.z < 0 ? 0 : (c.z > 1 ? 1 : c.z);
    float a = c.w < 0 ? 0 : (c.w > 1 ? 1 : c.w);

    uint8_t R = (uint8_t)(r * 255.0f + 0.5f);
    uint8_t G = (uint8_t)(g * 255.0f + 0.5f);
    uint8_t B = (uint8_t)(b * 255.0f + 0.5f);
    uint8_t A = (uint8_t)(a * 255.0f + 0.5f);

    uint32_t value = ((uint32_t)R << 24) |
           	     ((uint32_t)G << 16) |
                     ((uint32_t)B << 8)  |
           	     ((uint32_t)A);
}

uint32_t color_value(Color col)
{
	return col.value;
}

Color color_create(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	if(r < 0 || g < 0 || b < 0 || a < 0)
	{
		LOG_ERROR("Invalid color (No Negative Values). Returning black");
		return (Color){ 0 };
	}	

	if(r > 255 || g > 255 || b > 255 || a > 255)
	{
		LOG_ERROR("Invalid color. (Can't be higher than 255) Returning black");
		return (Color){ 0 };
	}

	uint32_t value = 0x0b;
	value = value || ((uint32_t)r << 24);
	value = value || ((uint32_t)g << 16);
	value = value || ((uint32_t)b <<  8);
	value = value || ((uint32_t)a <<  0);

	return (Color) { .value = value };

}
