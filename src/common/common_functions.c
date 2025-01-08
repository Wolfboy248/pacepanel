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

void SetWindowPosition(int x, int y, I_Window* window) {
	window->x = x;
	window->y = y;
	SDL_SetWindowPosition(window->window, x, y);
}

void SetWindowDimensions(int w, int h, I_Window* window) {
	window->w = w;
	window->h = h;
	SDL_SetWindowSize(window->window, w, h);
}

char* intToChar(int num) {
	char* buffer = malloc(12 * sizeof(char));
	if (buffer == NULL) {
		printf("Mem alloc failed!\n");
		return NULL;
	}

	snprintf(buffer, 12, "%d", num);
	return buffer;
}

void A_Quit() {
	int changes = 0;
	if (!changes) {
		running = 0;
	}
}

