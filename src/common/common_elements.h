#ifndef COMMONELEMENTS_H
#define COMMONELEMENTS_H

#include "common.h"

enum textAlign {
	LEFT,
	CENTER,
	RIGHT
};

typedef struct {
	int x, y, w, h, fontSize;
	SDL_Color textColor, bgColor, textColorH, bgColorH;
	const char* text;
	const char* fontPath;
	enum textAlign alignment;
} Button;

extern Button contextMenuButton;

#endif	

