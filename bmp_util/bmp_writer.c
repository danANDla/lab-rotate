#include "bmp_writer.h"

enum write_status fill_header(struct bmp_header *const header, const struct image *const img) {
    header->bfType = 19778; // 'BM'
    header->bfileSize = get_image_full_size(img);
    header->bfReserved = 0;
    header->bOffBits = 54;
    header->biSize = 40;
    header->biWidth = img->width;
    header->biHeight = img->height;
    header->biPlanes = 1;
    header->biBitCount = 24;
    header->biCompression = 0;
    header->biSizeImage = get_image_net_size(img);
    header->biXPelsPerMeter = 2834;
    header->biYPelsPerMeter = 2834; 
    header->biClrUsed = 0;
    header->biClrImportant = 0;
    return WRITE_OK;
}

static bool write_header(struct bmp_header* const header, FILE* const out) {
    return fwrite(header, sizeof(struct bmp_header), 1, out);
}

static bool write_string(size_t string_number, struct bmp_header* const header, const struct image* const img, FILE* const out) {
    return fwrite(img->pixels + img->width * string_number, header->biBitCount, img->width, out) == img->width; // maybe using header->biBitCount rather than sizeof(struct pixel) is more flexible
}

enum write_status to_bmp(FILE* out, struct image const* img) {
	struct bmp_header header;
    fill_header(&header, img);
    print_header(&header);
    if(!write_header(&header, out)) return WRITE_HEADER_ERROR;
    uint8_t blank = 0;
    for (size_t i = 0; i < header.biHeight; ++i) {
        void* pos = img->pixels + img->width * i;
        if(!fwrite(pos, sizeof(struct pixel) * img->width, 1, out)) return WRITE_STRING_ERROR;
        for (size_t j = 0; j < calculate_padding(img->width); ++j) {
            if (!fwrite(&blank, sizeof(uint8_t), 1, out)) return WRITE_PADDING_ERROR;
        }
    }
    return WRITE_OK;
}
