#include "renderDebugWindow.h"
#include "../debug/debug.h"
#include "elements/text.h"

void RenderDebugWindow() {
	SDL_SetRenderDrawColor(c_debugWindow.renderer, 12, 12, 24, 255);
	SDL_RenderClear(c_debugWindow.renderer);

	Text debugText = CreateText();
	int spacing = 2;
	for (int i = 0; i < debugValuesLen; i++) {		
		debugText.text = format("%s: %s", debugValues[i].name, debugValues[i].value);
		debugText.y = i * debugText.h + spacing;
		DrawText(&debugText, c_debugWindow.renderer);
	}

	SetWindowDimensions(c_debugWindow.w, debugValuesLen * (debugText.h + spacing), &c_debugWindow);

	SDL_RenderPresent(c_debugWindow.renderer);
}

