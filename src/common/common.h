#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

enum CMDs {
	CMD_Invalid,
	CMD_Quit,
	CMD_OpenSettings,
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
	const char* type;
} PPLComponent;

typedef struct {
	struct {
		int windowWidth, windowHeight;
	} settings;
	int numComponents;
	PPLComponent components[64];
} PPLayout;

typedef struct {
	int x, y, w, h;
	const char* windowTitle;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int isOpen;
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

typedef struct {
	const char* title;
} GameInformation;

extern GameInformation pp_currentGame;

// SDL stuff
extern SDL_Window* SDL_mainWindow;
extern SDL_Window* SDL_contextMenuWindow;
extern SDL_Window* SDL_debugWindow;
extern SDL_Window* SDL_settingsWindow;
extern SDL_Window* SDL_prevFocusedWindow;

// states
// context menu
extern int contextMenuOpen;

extern I_Window c_window;
extern I_Window c_contextMenuWindow;
extern I_Window c_debugWindow;
extern I_Window c_settingsWindow;

extern I_Mouse c_mouse;

extern int running;
extern int debugMode;

extern const char* c_title;

#endif // COMMON_H
