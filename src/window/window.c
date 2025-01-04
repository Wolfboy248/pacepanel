#include "window.h"

void GetWindowInformation(SDL_Window* window) {
	SDL_GetWindowPosition(window, &c_window.x, &c_window.y);
	// printf("X: %d, Y: %d\n", c_window.x, c_window.y);
}

SDL_Window* CreateContextMenu(SDL_Window* parentWindow) {
	int x, y;
	x = c_mouse.x + c_window.x - 20;
	y = c_mouse.y + c_window.y - 20;
	c_contextMenuWindow.x = x;
	c_contextMenuWindow.y = y;
	SDL_Window* childWindow = SDL_CreateWindow(
		c_contextMenuWindow.windowTitle,
		c_contextMenuWindow.x,
		c_contextMenuWindow.y,
		c_contextMenuWindow.w, c_contextMenuWindow.h,
		SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_SKIP_TASKBAR
	);
	c_contextMenuWindow.window = childWindow;
	SDL_Renderer* contextMenuRenderer = SDL_CreateRenderer(c_contextMenuWindow.window, -1, SDL_RENDERER_ACCELERATED);
	if (!contextMenuRenderer) {
		SDL_Log("Error creating renderer! Error: %s", SDL_GetError());
		SDL_DestroyWindow(SDL_mainWindow);
		SDL_Quit();
	}
	c_contextMenuWindow.renderer = contextMenuRenderer;

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

