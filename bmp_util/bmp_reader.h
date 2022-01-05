#ifndef BMP_READER_H
#define BMP_READER_H
#include "bmp_header.h"
#include "../image/image.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

enum read_status {
	READ_OK = 0,
	READ_INVALID_SIGNATURE,
	READ_INVALID_BITS,
	READ_INVALID_HEADER
};

static bool read_header(struct bmp_header*,  FILE*);
static bool read_string(void* pos, size_t width, FILE* in);
enum read_status from_bmp(FILE*, struct image*);

#endif // !BMP_READER_H

