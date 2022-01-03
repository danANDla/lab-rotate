#include"lib.h"

int main() {
	char* fname1 = "./tests/image1.bmp";
	char* fname2 = "./tests/image1res.bmp";
	char* fname3 = "./tests/image1resres.bmp";

	FILE* source;
	if (open_r_file(fname1, &source) != READ_FILE_OK) {
		printf("smth wrong\n");
		return;
	}
	struct image new_image;
	switch (from_bmp(source, &new_image))
	{
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

	FILE* result;
	if (open_w_file(fname2, &result) != WRITE_FILE_OK) {
		printf("smth wrong\n");
		return;
	}

	switch (to_bmp(result, &new_image))
	{
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
}