#ifndef FILE_IO_H
#define FILE_IO_H
#include <stdlib.h>
#include <stdio.h>

enum file_status {
	READ_FILE_OK = 0,
	WRITE_FILE_OK,
	CLOSE_FILE_OK,
	READ_FILE_ERROR,
	WRITE_FILE_ERROR,
	CLOSE_FILE_ERROR
};

enum file_status open_r_file(const char* const fname, FILE** const file);
enum file_status open_w_file(const char* const fname, FILE** const file);
enum file_status close_file(FILE* const file);

#endif // !FILE_IO_H

