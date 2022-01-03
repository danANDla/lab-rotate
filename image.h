#ifndef IMAGE_H
#define IMAGE_H
#include "bmp_header.h"
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
struct image {
	uint64_t width, height;
	struct pixel* pixels;
};
#pragma pack(pop)
#pragma pack(push, 1)
struct pixel { uint8_t b, g, r; };
#pragma pack(pop)
struct image create_image(const uint64_t height, const uint64_t width);
uint8_t calculate_padding(const uint64_t width);
size_t get_image_net_size(const struct image *const img);
size_t get_image_full_size(const struct image *const img);
#endif // !IMAGE_H