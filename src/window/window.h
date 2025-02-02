#ifndef WINDOW_H
#define WINDOW_H

#include "../common/common.h"
#include "../common/common_elements.h"
#include "../common/common_functions.h"

void GetWindowInformation(SDL_Window* window);
SDL_Window* CreateContextMenu(SDL_Window* parentWindow);
SDL_Window* CreateDebugWindow(SDL_Window* parentWindow);
SDL_Window* CreateSettingsWindow(SDL_Window* parentWindow);
void CleanupWindows();

#endif

