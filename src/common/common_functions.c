#include "common_functions.h"

char* format(const char* format, ...) {
	va_list args;
	va_start(args, format);

	int size = vsnprintf(NULL, 0, format, args);

	va_end(args);

	if (size < 0) {
		return NULL;
	}

	char* buffer = (char*)malloc(size + 1);
	if (buffer == NULL) {
		return NULL;
	}

	va_start(args, format);
	vsnprintf(buffer, size + 1, format, args);
	va_end(args);

	return buffer;
}

