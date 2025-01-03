#include "rect.h"

void InitRect() {

}

void DrawRect(int x, int y, int w, int h, SDL_Color color, SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_Rect rect = {x, y, w, h};
	SDL_RenderFillRect(renderer, &rect);
}

