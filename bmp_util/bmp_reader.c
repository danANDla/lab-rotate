#include "bmp_reader.h"

void print_header(const struct bmp_header* const header) {
    printf("\n--------------------------/bmp_header/--------------------------\n");
    printf("bfTYpe: %" PRIu16 "\n", header->bfType);
    printf("bfileSize: %" PRIu32 "\n", header->bfileSize);
    printf("bfReserved: %" PRIu32 "\n", header->bfReserved);
    printf("bOffBits: %" PRIu32 "\n", header->bOffBits);
    printf("biSize: %" PRIu32 "\n", header->biSize);
    printf("biWidth: %" PRIu32 "\n", header->biWidth);
    printf("biHeight: %" PRIu32 "\n", header->biHeight);
    printf("biPlanes: %" PRIu32 "\n", header->biPlanes);
    printf("biBitCount: %" PRIu16 "\n", header->biBitCount);
    printf("biCompression: %" PRIu32 "\n", header->biCompression);
    printf("biSizeImage: %" PRIu32 "\n", header->biSizeImage);
    printf("biXPelsPerMeter: %" PRIu32 "\n", header->biXPelsPerMeter);
    printf("biYPelsPerMeter: %" PRIu32 "\n", header->biYPelsPerMeter);
    printf("biClrUsed: %" PRIu32 "\n", header->biClrUsed);
    printf("biClrImportant: %" PRIu32 "\n", header->biClrImportant);
    printf("--------------------------/bmp_header/--------------------------\n");
}

enum read_status from_bmp(FILE* in, struct image* img) {
    struct bmp_header new_header;
    if (!fread(&new_header, sizeof(struct bmp_header), 1, in)) return READ_INVALID_HEADER;
    print_header(&new_header);

    *img = create_image(new_header.biHeight, new_header.biWidth);
    const uint8_t offset = calculate_padding(new_header.biWidth);

    fseek(in, new_header.bOffBits, SEEK_SET);
//    for (size_t i = 0; i < new_header.biHeight; i++) {
//        void* pos = img->pixels + img->width * i;
//        if (!fread(pos, sizeof(struct pixel) , new_header.biWidth, in)) return READ_INVALID_BITS;
//        fseek(in, offset, SEEK_CUR);
//    }

//    for (size_t i = new_header.biHeight-1; i > 0; i--) {
//        void* pos = img->pixels + img->width * i;
//        if (!fread(pos, sizeof(struct pixel) , new_header.biWidth, in)) return READ_INVALID_BITS;
//        fseek(in, offset, SEEK_CUR);
//    }

    for (size_t i = 0; i < new_header.biHeight; i++) {
        void* pos = img->pixels + img->width * i;
        if (!fread(pos, sizeof(struct pixel) , new_header.biWidth, in)) return READ_INVALID_BITS;
        fseek(in, offset, SEEK_CUR);
    }
    return READ_OK;
}