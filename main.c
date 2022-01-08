#include"lib.h"

int main(int args, char **argv) {
    if (args < 3) {
        printf("too few arguments\n");
        return 0;
    }
    if (args > 3) {
        printf("too many arguments\n");
        return 0;
    }
    const char *fname1 = argv[1];
    const char *fname2 = argv[2];

    FILE *source;
    if (open_r_file(fname1, &source) != READ_FILE_OK) {
        printf("Can't open the file %s\n", fname1);
        return 1;
    }
    struct image src_image;
    switch (from_bmp(source, &src_image)) {
        case READ_INVALID_HEADER:
            printf("Invalid bmp header\n");
            break;
        case READ_INVALID_BITS:
            printf("Invalid bits in bitmap\n");
            break;
        case READ_OK:
            printf("Read success\n");
        default:
            break;
    }
    close_file(source);
    struct transform_result transformed = transform_image(&src_image,  COUNTERCLOCKWISE_90);
    FILE *result;
    if (open_w_file(fname2, &result) != WRITE_FILE_OK) {
        printf("Can't open the file %s\n", fname2);
        return 1;
    }
    switch (to_bmp(result, &transformed.img)) {
        case WRITE_STRING_ERROR:
            printf("Error in writing a row of the output bitmap\n");
        case WRITE_HEADER_ERROR:
            printf("Error in writing a header of the output bitmap\n");
        case WRITE_PADDING_ERROR:
            printf("Error in writing a padding of the output bitmap\n");
        case WRITE_ERROR:
            printf("Error in writing file\n");
        case WRITE_OK:
            printf("Write success\n");
        default:
            break;
    }
    close_file(result);
    return 0;
}
