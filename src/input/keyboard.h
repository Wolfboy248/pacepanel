#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "../common/common.h"

#ifdef _WIN32
void RegisterGlobalHotkey();
void ListenForGlobalHotkey();

#elif __linux__
void RegisterGlobalHotkey();
void ListenForGlobalHotkey();

#elif __APPLE__
void RegisterGlobalHotkey();
void ListenForGlobalHotkey();

#endif

void HandleKeyboardInput(SDL_Event event);

#endif

