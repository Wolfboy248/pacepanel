#include "input.h"

void InputPerFrameChecks() {
	MouseChecks();
}

void HandleInput(SDL_Event event) {
	if (event.type == SDL_QUIT) {
		running = 0;
	}

	HandleMouseInput(event);
	HandleKeyboardInput(event);
};

