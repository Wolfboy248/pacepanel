#include "window.h"

void GetWindowInformation(SDL_Window* window) {
	SDL_GetWindowPosition(window, &c_window.x, &c_window.y);
	// printf("X: %d, Y: %d\n", c_window.x, c_window.y);
}

SDL_Window* CreateContextMenu(SDL_Window* parentWindow) {
	SDL_Window* childWindow = SDL_CreateWindow(
		"Context Menu",
		c_mouse.x + c_window.x,
		c_mouse.y + c_window.y,
		100, contextMenuButton.h,
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

