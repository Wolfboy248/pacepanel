#include "input.h"
#include "mouse.h"

void HandleInput(SDL_Event event) {
	if (event.type == SDL_QUIT) {
		running = 0;
	}

	HandleMouseInput(event);
};

