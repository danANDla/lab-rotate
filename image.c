#include "image.h"

struct image create_image(const uint64_t height, const uint64_t width) {
	return (struct image) { .height = height, .width = width, .pixels = (struct pixel*) malloc(sizeof(struct pixel) * width * height)};
}

uint8_t calculate_padding(const uint64_t width) {
	//if ((width * sizeof(struct pixel)) % 4 != 0) return (uint8_t) ( 4 - ((width * sizeof(struct pixel)) % 4) );
	if (width  % 4 != 0) return (uint8_t) ( 4 - (width % 4) );
	return (uint8_t) 0;
}

size_t get_image_net_size(const struct image *const img) {
	return (size_t)(img->height * (img->width * sizeof(struct pixel) +  calculate_padding(img->width)));
}

size_t get_image_full_size(const struct image *const img) {
	return get_image_net_size(img) + sizeof(struct bmp_header);
}