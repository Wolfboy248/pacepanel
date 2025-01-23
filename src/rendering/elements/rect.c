#include "rect.h"

void InitRect() {

}

void DrawRect(Rect inpRect, SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, inpRect.color.r, inpRect.color.g, inpRect.color.b, inpRect.color.a);
	SDL_Rect rect = {inpRect.x, inpRect.y, inpRect.w, inpRect.h};
	SDL_RenderFillRect(renderer, &rect);
}

