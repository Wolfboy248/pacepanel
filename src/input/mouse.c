#include "mouse.h"

void HandleMouseInput(SDL_Event event) {
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (event.button.button == SDL_BUTTON_LEFT) {
			printf("Left mouse button clicked\n");
		}
	}
}

