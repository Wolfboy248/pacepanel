#include "renderSettingsWindow.h"

void RenderSettingsWindow() {
	SDL_SetRenderDrawColor(c_settingsWindow.renderer, 12, 12, 24, 255);
	SDL_RenderClear(c_settingsWindow.renderer);

	SDL_RenderPresent(c_settingsWindow.renderer);
}

