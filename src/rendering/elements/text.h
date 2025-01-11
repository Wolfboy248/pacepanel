#ifndef TEXT_H
#define TEXT_H

#include "../../common/common.h"

typedef struct {
	TTF_Font* font;
	int size;
} Font;

int InitText();
Text CreateText();

int GetTextHeight(Text* textStruct);
int GetTextWidth(Text* textStruct);

void DrawText(Text* textStruct, SDL_Renderer* renderer);
void FreeText();

#endif

