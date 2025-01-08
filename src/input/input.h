#ifndef INPUT_H
#define INPUT_H

#include "../common/common.h"

#include "mouse.h"
#include "keyboard.h"

void InitInput();
void CleanupInput();
void InputPerFrameChecks();
void HandleInput(SDL_Event event);

#endif

