#ifndef RECT_H
#define RECT_H

#include "../../common/common.h"

void InitRect();
void DrawRect(int x, int y, int w, int h, SDL_Color color, SDL_Renderer* renderer);
void FreeRect();

#endif

