#include "common.h"

I_Window c_window = {
	.w = 200,
	.h = 400
};

// SDL stuff
SDL_Window* SDL_mainWindow = NULL;
SDL_Window* SDL_contextMenuWindow = NULL;

// states 
// context menu 
int contextMenuOpen = 0;

I_Mouse c_mouse = {
	.LMBDown = 0,
	.RMBDown = 0,
	.LMBClick = 0,
	.RMBClick = 0
};

int running = 1;

const char* c_title = "PacePanel";

