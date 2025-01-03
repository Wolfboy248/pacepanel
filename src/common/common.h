#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <SDL2/SDL.h>

typedef struct {
	int x, y, w, h;
} I_Window;

typedef struct {
	int x, y;
	int LMBDown, RMBDown, LMBClick, RMBClick;
} I_Mouse;

// SDL stuff
extern SDL_Window* SDL_mainWindow;
extern SDL_Window* SDL_contextMenuWindow;

extern I_Window c_window;
extern I_Mouse c_mouse;

extern int running;

extern const char* c_title;

#endif // COMMON_H
