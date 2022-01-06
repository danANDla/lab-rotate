#include "transform.h"

static bool clock90(struct image* img, const struct image* source){
    for(size_t i = 0; i < source->width; ++i) {
        for (int j = 0; j < source->height; ++j) {
            img->pixels[(i * source->height) + j] = source->pixels[source->width - 1 - i + source->width * j];
        }
    }

//    for (size_t i = source->width; i > 0; --i) {
//        for (size_t j = 0; j < source->height; j++) {
//            img->pixels[j + (source->height * (source->width - i))] = source->pixels[(i - 1) + j * (source->width)];
//        }
//    }
    return true;
}


enum transform_status transform_image(struct image* source, struct image* transformed, enum transformations type){
    switch (type) {
        case CLOCKWISE_90:{
            if(!clock90(transformed, source)) return TRANSFORM_ERROR;
            break;
        }
        case COUNTERCLOCKWISE_90:
            break;
        default:
            return UNKNOWN_TRANSFORMATION;
    }
    return TRANSFORM_OK;
}

