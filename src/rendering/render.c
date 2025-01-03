#include "render.h"
#include "renderContextMenu.h"

void RenderMainWindow(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 12, 12, 24, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void RenderWindows(SDL_Renderer* renderer) {
	RenderContextMenu();
	RenderMainWindow(renderer);
}

