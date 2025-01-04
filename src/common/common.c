#include "common.h"

I_Window c_window = {
	.w = 200,
	.h = 400
};

// SDL stuff
SDL_Window* SDL_mainWindow = NULL;
SDL_Window* SDL_contextMenuWindow = NULL;
SDL_Window* SDL_debugWindow = NULL;

// states 
// context menu 
int contextMenuOpen = 0;

I_Window c_contextMenuWindow = {
	.w = 100,
	.h = 32,
	.windowTitle = "Context Menu",
};

I_Window c_debugWindow = {
	.windowTitle = "Debug",
	.x = 0,
	.y = 0,
	.w = 200,
	.h = 50,
};

I_Mouse c_mouse = {
	.LMBDown = 0,
	.RMBDown = 0,
	.LMBClick = 0,
	.RMBClick = 0
};

int running = 1;
int debugMode = 1;

const char* c_title = "PacePanel";

