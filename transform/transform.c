#include "transform.h"
static bool clock90(struct image *img, const struct image *source) {
    for (size_t i = 0; i < source->width; ++i) {
        for (int j = 0; j < source->height; ++j) {
            img->pixels[(i * source->height) + j] = source->pixels[source->width - 1 - i + source->width * j];
        }
    }
    return true;
}

static bool counter_clock90(struct image *img, const struct image *source) {
    for (size_t i = 0; i < source->width; ++i) {
        for (int j = 0; j < source->height; ++j) {
            img->pixels[(i * source->height) + j] = source->pixels[(source->height - 1 - j) * source->width + i];
        }
    }
    return true;
}

struct transform_result transform_image(struct image *source, enum transformations type) {
    switch (type) {
        case CLOCKWISE_90: {
            struct image transformed = create_image(source->width, source->height);
            if (!clock90(&transformed, source))
                return (struct transform_result) {.type = TRANSFORM_ERROR,
                        .img = (struct image) {.width = 0, .height = 0, .pixels = NULL}};
            return (struct transform_result) {.type = TRANSFORM_OK, .img = transformed};
        }
        case COUNTERCLOCKWISE_90: {
            struct image transformed = create_image(source->width, source->height);
            if (!counter_clock90(&transformed, source))
                return (struct transform_result) {.type = TRANSFORM_ERROR,
                        .img = (struct image) {.width = 0, .height = 0, .pixels = NULL}};
            return (struct transform_result) {.type = TRANSFORM_OK, .img = transformed};
        }
        default:
            return (struct transform_result) {.type = UNKNOWN_TRANSFORMATION,
                    .img = (struct image) {.width = 0, .height = 0, .pixels = NULL}};
    }
}

