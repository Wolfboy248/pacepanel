#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct {
	int x, y, w, h;
} I_Window;

typedef struct {
	int x, y;
	int LMBDown, RMBDown, LMBClick, RMBClick;
} I_Mouse;

typedef struct {
	const char* text;
	const char* fontPath;
	int x, y, fontSize;
	SDL_Color color;
} Text;

// SDL stuff
extern SDL_Window* SDL_mainWindow;
extern SDL_Window* SDL_contextMenuWindow;

// states
// context menu
extern int contextMenuOpen;

extern I_Window c_window;
extern I_Mouse c_mouse;

extern int running;

extern const char* c_title;

#endif // COMMON_H
