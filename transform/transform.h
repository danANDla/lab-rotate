#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../image/image.h"
#include <stdbool.h>

enum transform_status{
    TRANSFORM_OK = 0,
    TRANSFORM_ERROR,
    UNKNOWN_TRANSFORMATION
};

enum transformations{
    CLOCKWISE_90 = 0,
    COUNTERCLOCKWISE_90
};

enum transform_status transform_image(struct image* source, struct image* transformed, enum transformations type);
static bool clock90(struct image* img, const struct image* source);
#endif // !TRANSFORM_H