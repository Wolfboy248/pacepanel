#include "renderContextMenu.h"
#include "elements/button.h"

typedef struct {
	const char* text;
	enum CMDs cmd;
} ContextMenuButtonE;

ContextMenuButtonE buttons[] = {
	{"Quit", CMD_Quit},
};

void RenderContextMenu() {
	SDL_SetRenderDrawColor(c_contextMenuWindow.renderer, 12, 12, 24, 255);

	SDL_RenderClear(c_contextMenuWindow.renderer);
	
	// stuff
	Text contextMenuButtonText = {
		.fontSize = 12,
		.fontPath = "fonts/JetBrainsMonoNerdFont-Medium.ttf",
	};

	int buttonsLength = sizeof(buttons) / sizeof(buttons[0]);
	
	SetWindowDimensions(contextMenuButton.w, buttonsLength * contextMenuButton.h, &c_contextMenuWindow);

	for (int i = 0; i < buttonsLength; i++) {
		Button newContextButton = contextMenuButton;
		newContextButton.y = i * newContextButton.h;
		newContextButton.text = contextMenuButtonText;
		newContextButton.text.text = buttons[i].text;
		newContextButton.cmd = buttons[i].cmd;
		DrawButton(newContextButton, c_contextMenuWindow, c_contextMenuWindow.renderer);
	}

	if (contextMenuOpen && c_mouse.LMBClick) {
		contextMenuOpen = 0;
		SDL_DestroyWindow(SDL_contextMenuWindow);
		SDL_contextMenuWindow = NULL;
		return;
	}

	// Button quitButton = contextMenuButton;
	// quitButton.text = contextMenuButtonText;
	// quitButton.text.text = "Quit";
	// DrawButton(quitButton, c_contextMenuWindow, c_contextMenuWindow.renderer);

	SDL_RenderPresent(c_contextMenuWindow.renderer);
}

