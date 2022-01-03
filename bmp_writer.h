#ifndef BMP_WRITER_H
#define BMP_WRITER_H
#include "image.h"
#include "bmp_header.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

enum  write_status {
	WRITE_OK = 0,
	WRITE_STRING_ERROR,
	WRITE_HEADER_ERROR,
	WRITE_PADDING_ERROR,
	WRITE_ERROR
};

enum write_status fill_header(struct bmp_header *const header, const struct image *const img);
static bool write_header(struct bmp_header* const header, FILE* const out);
static bool write_string(size_t string_number, struct bmp_header* const header, const struct image* const img, FILE* const out);
enum write_status to_bmp(FILE* out, struct image const* img);

#endif // !BMP_WRITER_H
