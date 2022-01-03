#include "file_io.h"

enum file_status open_r_file(const char *const fname, FILE** const file) {
	*file = fopen(fname, "r");
	if (*file == NULL) return READ_FILE_ERROR;
	return READ_FILE_OK;
}

enum file_status open_w_file(const char* const fname, FILE** const file) {
	*file = fopen(fname, "w");
	if (*file == NULL) return WRITE_FILE_ERROR;
	return WRITE_FILE_OK;
}

enum file_status close_file(FILE* const file) {
	if (fclose(file) != 0) return CLOSE_FILE_ERROR;
	return CLOSE_FILE_OK;
}