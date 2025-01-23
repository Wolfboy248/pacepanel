#include "render.h"
#include "renderContextMenu.h"
#include "renderDebugWindow.h"
#include "renderSettingsWindow.h"
#include "elements/text.h"
#include "components/componentHandler.h"
#include "components/layoutHandler.h"

void InitRendering() {	
	LoadComponents(&currentPPLLayout);
}

void RenderMainWindow(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 12, 12, 24, 255);
	SDL_RenderClear(renderer);

	Text timerText = CreateText();
	Text debugTimer = CreateText();
	debugTimer.y = 20;
	debugTimer.text = format("%d", t_realTime.elapsed.total);
	timerText.text = t_realTime.formattedString;
	// DrawText(&timerText, renderer);
	// DrawText(&debugTimer, renderer);

	RenderComponents();
	
	// debugValues[1].value = intToChar(c_mouse.x);

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

