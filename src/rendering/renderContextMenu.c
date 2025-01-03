#include "renderContextMenu.h"
#include "elements/button.h"

void RenderContextMenu() {
	SDL_Renderer* contextMenuRenderer = SDL_CreateRenderer(SDL_contextMenuWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(contextMenuRenderer, 12, 12, 24, 255);
	
	// stuff
	DrawContextMenuButton(contextMenuRenderer);

	SDL_RenderClear(contextMenuRenderer);
	SDL_RenderPresent(contextMenuRenderer);
}

