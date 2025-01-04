#include "common/common.h"
#include "common/common_functions.h"

#include "window/window.h"
#include "rendering/render.h"
#include "input/input.h"
#include "rendering/elements/text.h"

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("Unable to init SDL! Error: %s", SDL_GetError());
		return 1;
	}

	SDL_mainWindow = SDL_CreateWindow(
		c_title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		c_window.w,
		c_window.h,
		SDL_WINDOW_BORDERLESS | SDL_WINDOW_RESIZABLE
	);

	if (!SDL_mainWindow) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	c_window.window = SDL_mainWindow;

	printf("Starting %s\n", c_title);
	SDL_Event event;

	// renderer setup
	SDL_Renderer* renderer = SDL_CreateRenderer(SDL_mainWindow, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		SDL_Log("Error creating renderer! Error: %s", SDL_GetError());
		SDL_DestroyWindow(SDL_mainWindow);
		SDL_Quit();
		return 1;
	}

	// text
	if (InitText() < 0) {
		return -1;
	}

	while (running) {
		while (SDL_PollEvent(&event)) {
			HandleInput(event);
		}

		GetWindowInformation(SDL_mainWindow);

		RenderWindows(renderer);
		InputPerFrameChecks();
	}

	CleanupWindows();
	SDL_Quit();

	return 0;
}

