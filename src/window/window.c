#include "window.h"

void GetWindowInformation(SDL_Window* window) {
	SDL_GetWindowPosition(window, &c_window.x, &c_window.y);
	// printf("X: %d, Y: %d\n", c_window.x, c_window.y);
}

SDL_Window* CreateContextMenu(SDL_Window* parentWindow) {
	int x, y;
	x = c_mouse.x + c_window.x;
	y = c_mouse.y + c_window.y;
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
		SDL_DestroyWindow(SDL_contextMenuWindow);
		SDL_Quit();
	}
	SDL_SetRenderDrawBlendMode(contextMenuRenderer, SDL_BLENDMODE_BLEND);
	c_contextMenuWindow.renderer = contextMenuRenderer;

	if (!childWindow) {
		SDL_Log("Error creating child window! Error: %s", SDL_GetError());
		return NULL;
	}

	return childWindow;
}

SDL_Window* CreateSettingsWindow(SDL_Window* parentWindow) {
	SDL_Window* childWindow = SDL_CreateWindow(
		c_settingsWindow.windowTitle,
		c_settingsWindow.x,
		c_settingsWindow.y,
		c_settingsWindow.w, c_settingsWindow.h,
		SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_MAXIMIZED
	);
	c_settingsWindow.window = childWindow;

	SDL_Renderer* settingsWindowRenderer = SDL_CreateRenderer(c_settingsWindow.window, -1, SDL_RENDERER_ACCELERATED);
	if (!settingsWindowRenderer) {
		SDL_Log("Error creating settings renderer! Error: %s", SDL_GetError());
		SDL_DestroyWindow(c_settingsWindow.window);
		SDL_Quit();
	}

	SDL_SetRenderDrawBlendMode(settingsWindowRenderer, SDL_BLENDMODE_BLEND);
	c_settingsWindow.renderer = settingsWindowRenderer;

	if (!childWindow) {
		SDL_Log("Error creating child window! Error: %s", SDL_GetError());
		return NULL;
	}

	return childWindow;
}

SDL_Window* CreateDebugWindow(SDL_Window* parentWindow) {
	SDL_Window* childWindow = SDL_CreateWindow(
		c_debugWindow.windowTitle,
		c_debugWindow.x,
		c_debugWindow.y,
		c_debugWindow.w, c_debugWindow.h,
		SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP
	);
	c_debugWindow.window = childWindow;

	SDL_Renderer* debugRenderer = SDL_CreateRenderer(c_debugWindow.window, -1, SDL_RENDERER_ACCELERATED);
	if (!debugRenderer) {
		SDL_Log("Error creating renderer! Error: %s", SDL_GetError());
		SDL_DestroyWindow(SDL_debugWindow);
		SDL_Quit();
	}
	SDL_SetRenderDrawBlendMode(debugRenderer, SDL_BLENDMODE_BLEND);
	c_debugWindow.renderer = debugRenderer;

	if (!childWindow) {
		SDL_Log("Error creating child window! Error: %s", SDL_GetError());
		return NULL;
	}

	return childWindow;
}

void CleanupWindows() {
	if (debugMode) {
		SDL_DestroyWindow(c_debugWindow.window);
	}
	if (SDL_contextMenuWindow) {
		SDL_DestroyWindow(c_contextMenuWindow.window);
	}
	SDL_DestroyWindow(SDL_mainWindow);
}

