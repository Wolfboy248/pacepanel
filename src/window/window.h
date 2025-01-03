#ifndef WINDOW_H
#define WINDOW_H

#include "../common/common.h"

void GetWindowInformation(SDL_Window* window);
SDL_Window* CreateContextMenu(SDL_Window* parentWindow);
void CleanupWindows();

#endif

