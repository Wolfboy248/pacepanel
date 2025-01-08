#include "settingsWindow.h"
#include "window.h"

void OpenSettings() {
	if (!SDL_settingsWindow) {
		c_settingsWindow.isOpen = 1;
		SDL_settingsWindow = CreateSettingsWindow(SDL_settingsWindow);
		
		if (SDL_settingsWindow) {
			SDL_RaiseWindow(SDL_settingsWindow);
		}
	}
}

