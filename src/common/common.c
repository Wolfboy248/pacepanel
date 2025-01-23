#include "common.h"

I_Window c_window = {
	.w = 350,
	.h = 0
};

GameInformation pp_currentGame = {
	.title = "Super Mario Odyssey"
};

// SDL stuff
SDL_Window* SDL_mainWindow = NULL;
SDL_Window* SDL_contextMenuWindow = NULL;
SDL_Window* SDL_debugWindow = NULL;
SDL_Window* SDL_settingsWindow = NULL;
SDL_Window* SDL_prevFocusedWindow = NULL;
SDL_Window* SDL_focusedWindow = NULL;

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

I_Window c_settingsWindow = {
	.windowTitle = "Settings",
	.x = SDL_WINDOWPOS_CENTERED,
	.y = SDL_WINDOWPOS_CENTERED,
	.w = 500,
	.h = 450,
	.isOpen = 0,
};

I_Window* c_windows[128] = {

};

int numWindows = 0;

I_Mouse c_mouse = {
	.LMBDown = 0,
	.RMBDown = 0,
	.LMBClick = 0,
	.RMBClick = 0
};

int running = 1;
int debugMode = 0; // TODO: PLEASE IMPROVE DEBUG MODE IT SUCKS BALLS
int isInit = 0;

const char* c_title = "PacePanel";

PPLayout currentPPLLayout = {};

