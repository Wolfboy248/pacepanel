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
	if (h <= 24) h = 24;
	if (w <= 50) w = 50;
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

char* endptr;

int charToInt(const char* str) {
	int num = (int)strtol(str, &endptr, 10);

	return num;
}

void CloseWindow(I_Window* windowToClose) {
	for (int i = 0; i < numWindows; i++) {
		if (SDL_GetWindowID(c_windows[i]->window) == SDL_GetWindowID(windowToClose->window)) {
			
			c_windows[i]->isOpen = 0;
			SDL_DestroyWindow(c_windows[i]->window);
			SDL_DestroyRenderer(c_windows[i]->renderer);
			c_windows[i]->window = NULL;
		}
	}
}

void A_Quit() {
	int changes = 0;
	if (!changes) {
		running = 0;
	}
}

void A_SettingsClose() {
	c_settingsWindow.isOpen = 0;
}

void A_LoadLayoutFromFile() {
	openFileDialog = 1;
}

