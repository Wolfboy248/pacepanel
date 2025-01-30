#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "common_colours.h"

enum CMDs {
	CMD_Invalid,
	CMD_Quit,
	CMD_OpenSettings,
	CMD_CloseSettings,
	CMD_SaveLayout,
	CMD_LoadLayoutFromFile,
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
	int windowWidth, windowHeight;
} PPLayoutSettings;

typedef struct {
	const char* filePath;
	PPLayoutSettings settings;
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

// DOC //
// int x, y, w, h
// bool fill
typedef struct {
	int x, y, w, h;
	int cornerRadius;
	int fill;
	int borderWidth;
	SDL_Color color;
} Rect;

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
extern SDL_Window* SDL_focusedWindow;

// states
// context menu
extern int contextMenuOpen;

extern int numWindows;
extern I_Window* c_windows[128];

extern I_Window c_window;
extern I_Window c_contextMenuWindow;
extern I_Window c_debugWindow;
extern I_Window c_settingsWindow;

extern I_Mouse c_mouse;

extern int running;
extern int debugMode;
extern int isInit;
extern int openFileDialog;

extern const char* c_title;
extern char workingDir[256];
	
extern PPLayout currentPPLLayout;

#endif // COMMON_H
