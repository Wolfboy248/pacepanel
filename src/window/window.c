#include "window.h"

void GetWindowInformation(SDL_Window* window) {
	SDL_GetWindowPosition(window, &c_window.x, &c_window.y);
	// printf("X: %d, Y: %d\n", c_window.x, c_window.y);
}

SDL_Window* CreateContextMenu(SDL_Window* parentWindow) {
	SDL_Window* childWindow = SDL_CreateWindow(
		"Child Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		300, 100,
		SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP
	);

	if (!childWindow) {
		SDL_Log("Error creating child window! Error: %s", SDL_GetError());
		return NULL;
	}

	return childWindow;
}

void CleanupWindows() {
	if (SDL_contextMenuWindow) {
		SDL_DestroyWindow(SDL_contextMenuWindow);
	}
	SDL_DestroyWindow(SDL_mainWindow);
}

