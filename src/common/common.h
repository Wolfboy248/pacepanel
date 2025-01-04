#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

enum CMDs {
	CMD_Invalid,
	CMD_Quit,
};

enum alignH {
	LEFT,
	CENTER,
	RIGHT
};

enum alignV {
	TOP,
	MIDDLE,
	BOTTOM
};

typedef struct {
	int x, y, w, h;
	const char* windowTitle;
	SDL_Window* window;
	SDL_Renderer* renderer;
} I_Window;

typedef struct {
	int x, y, absX, absY;
	int LMBDown, RMBDown, LMBClick, RMBClick;
} I_Mouse;

typedef struct {
	const char* text;
	const char* fontPath;
	int x, y, fontSize;
	int w, h;
	int paddingL, paddingR, paddingT, paddingB;
	enum alignV textAlignV;
	enum alignH textAlignH;
	SDL_Color color;
} Text;

// SDL stuff
extern SDL_Window* SDL_mainWindow;
extern SDL_Window* SDL_contextMenuWindow;

// states
// context menu
extern int contextMenuOpen;

extern I_Window c_window;
extern I_Window c_contextMenuWindow;
extern I_Mouse c_mouse;

extern int running;

extern const char* c_title;

#endif // COMMON_H
