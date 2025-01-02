#include "common.h"

I_Window c_window = {
	.w = 200,
	.h = 400
};

// SDL stuff
SDL_Window* SDL_childWindow = NULL;

I_Mouse c_mouse = {};

int running = 1;

const char* c_title = "PacePanel";

