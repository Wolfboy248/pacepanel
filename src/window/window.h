#ifndef WINDOW_H
#define WINDOW_H

#include "../common/common.h"

void GetWindowInformation(SDL_Window* window);
SDL_Window* CreateChildWindow(SDL_Window* parentWindow);

#endif

