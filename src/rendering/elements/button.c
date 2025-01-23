#include "button.h"
#include "../../window/settingsWindow.h"

int IsButtonHover(I_Window desiredWindow, Button button) {
	int isHover;
	if (c_mouse.absX > desiredWindow.x + button.x && c_mouse.absX < desiredWindow.x + button.w + button.x && 
		c_mouse.absY > desiredWindow.y + button.y && c_mouse.absY < desiredWindow.y + button.h + button.y &&
		c_mouse.absX < desiredWindow.x + desiredWindow.w && c_mouse.absX > desiredWindow.x && 
		c_mouse.absY < desiredWindow.y + desiredWindow.h && c_mouse.absY > desiredWindow.y) {
		isHover = 1;
	} else {
		isHover = 0;
	}

	return isHover;
}

int IsButtonClick(I_Window desiredWindow, Button button) {
	if (IsButtonHover(desiredWindow, button) && c_mouse.LMBClick) {
		return 1;
	} else {
		return 0;
	}
}

void DrawButton(Button button, I_Window desiredWindow, SDL_Renderer* renderer) {
	button.text.x = button.x;
	button.text.y = button.y;
	if (IsButtonClick(desiredWindow, button)) {
		switch (button.cmd) {
			case CMD_Quit:
				A_Quit();
				break;
			case CMD_OpenSettings:
				OpenSettings();
				break;
			default:
				printf("Invalid command\n");
				break;
		}
	}

	// alignment stuff
	button.text.w = button.w;
	button.text.h = button.h;
	button.bg.x = button.x;
	button.bg.y = button.y;
	button.bg.w = button.w;
	button.bg.h = button.h;
	button.bg.color = button.bgColor;

	if (IsButtonHover(desiredWindow, button)) {
		button.bg.color = button.bgColorH;
		DrawRect(button.bg, renderer);
		button.text.color = button.textColorH;
		DrawText(&button.text, renderer);
	} else {
		button.bg.color = button.bgColor;
		DrawRect(button.bg, renderer);
		button.text.color = button.textColor;
		DrawText(&button.text, renderer);
	}
}

