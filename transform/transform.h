#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../image/image.h"
#include <stdbool.h>

struct transform_result{
    enum transform_status{
        TRANSFORM_OK = 0,
        TRANSFORM_ERROR,
        UNKNOWN_TRANSFORMATION
    } type;
    struct image img;
};


enum transformations{
    CLOCKWISE_90 = 0,
    COUNTERCLOCKWISE_90
};

struct transform_result transform_image(struct image* source, enum transformations type);
static bool clock90(struct image* img, const struct image* source);
static bool counter_clock90(struct image* img, const struct image* source);
#endif // !TRANSFORM_H