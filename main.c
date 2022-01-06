#include"lib.h"

int main(int args, char **argv) {
//	char* fname1 = "./tests/image1.bmp";
//	char* fname2 = "./tests/image1res.bmp";
//	char* fname3 = "./tests/image1resres.bmp";
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
        printf("smth wrong with opening a file\n");
        return 1;
    }
    struct image new_image;
    switch (from_bmp(source, &new_image)) {
        case READ_INVALID_HEADER:
            printf("invalid header\n");
            break;
        case READ_INVALID_BITS:
            printf("invalid bits\n");
            break;
        case READ_OK:
            printf("read succses\n");
        default:
            break;
    }
    close_file(source);
    struct image transformed = create_image(new_image.width,new_image.height);
    transform_image(&new_image, &transformed, CLOCKWISE_90);
    FILE *result;
    if (open_w_file(fname2, &result) != WRITE_FILE_OK) {
        printf("smth wrong\n");
        return 1;
    }
    switch (to_bmp(result, &transformed)) {
        case WRITE_STRING_ERROR:
            printf("write string error\n");
        case WRITE_HEADER_ERROR:
            printf("write header error\n");
        case WRITE_PADDING_ERROR:
            printf("write padding error\n");
        case WRITE_ERROR:
            printf("write error\n");
        default:
            break;
    }
    close_file(result);

    return 0;
}
