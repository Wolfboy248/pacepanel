#ifndef BUTTON_H
#define BUTTON_H

#include "../../common/common.h"
#include "../../common/common_elements.h"
#include "../../common/common_functions.h"
#include "rect.h"
#include "text.h"

int IsButtonHover(I_Window desiredWindow, Button button);
int IsButtonClick(I_Window desiredWindow, Button button);
void DrawButton(Button button, I_Window desiredWindow, SDL_Renderer* contextMenuRenderer);

#endif
