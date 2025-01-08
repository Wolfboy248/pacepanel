#include "render.h"
#include "renderContextMenu.h"
#include "renderDebugWindow.h"
#include "renderSettingsWindow.h"
#include "elements/text.h"
#include "../debug/debug.h"

void RenderMainWindow(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 12, 12, 24, 255);
	SDL_RenderClear(renderer);

	Text testText = CreateText();
	testText.text = "HELLO";
	DrawText(&testText, renderer);
	
	debugValues[1].value = intToChar(c_mouse.x);

	SDL_RenderPresent(renderer);
}

void RenderWindows(SDL_Renderer* renderer) {
	if (debugMode) {
		RenderDebugWindow();
	}
	if (contextMenuOpen) {
		RenderContextMenu();
	}
	if (c_settingsWindow.isOpen) {
		RenderSettingsWindow();
	}
	RenderMainWindow(renderer);
}

