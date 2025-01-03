#include "button.h"

void DrawContextMenuButton(SDL_Renderer* contextMenuRenderer) {
	DrawRect(contextMenuButton.x, contextMenuButton.y, contextMenuButton.w, contextMenuButton.h, (SDL_Color){255, 0, 0, 255}, contextMenuRenderer);
}

