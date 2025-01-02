#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <SDL2/SDL.h>

typedef struct {
	int x, y, w, h;
} I_Window;

typedef struct {
	int x, y;
} I_Mouse;

// SDL stuff
extern SDL_Window* SDL_childWindow;

extern I_Window c_window;
extern I_Mouse c_mouse;

extern int running;

extern const char* c_title;

#endif // COMMON_H
