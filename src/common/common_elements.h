#ifndef COMMONELEMENTS_H
#define COMMONELEMENTS_H

#include "common.h"
#include "../components/component.h"

typedef struct {
	int x, y, w, h;
	SDL_Color textColor, bgColor, textColorH, bgColorH;
	Text text;
	enum alignH alignmentH;
	enum alignV alignmentV;
	int paddingL, paddingR, paddingT, paddingB;
	enum CMDs cmd;
} Button;

extern Text contextMenuButtonText;
extern Button contextMenuButton;

extern ComponentContext componentContext;

#endif	

