#include "renderSettingsWindow.h"
#include "elements/text.h"
#include "elements/rect.h"
#include "elements/button.h"
#include "../common/common_colours.h"

void RenderSettingsWindow() {
	SDL_SetRenderDrawColor(c_settingsWindow.renderer, 12, 12, 24, 255);
	SDL_RenderClear(c_settingsWindow.renderer);

	int footerHeight = 50;

	// title
	Text titleText = CreateHeader1();
	Rect sep1 = {
		.x = 10,
		.y = titleText.y + GetTextHeight(&titleText) + 10,
		.w = c_settingsWindow.w - 20,
		.h = 3,
		.color = c_grey,
		.fill = 1,
	};

	// footer
	int footerPadding = 5;
	Rect footerBG = {
		.x = 0,
		.y = c_settingsWindow.h - footerHeight,
		.w = c_settingsWindow.w,
		.h = footerHeight,
		.color = c_darkBG,
		.fill = 1
	};
	int closeSettingsBtnPadding = 3;
	Text closeSettingsBtnText = CreateText();
	closeSettingsBtnText.text = "Close";
	Button closeSettingsBtn = {
		.x = c_settingsWindow.w - GetTextWidth(&closeSettingsBtnText) - closeSettingsBtnPadding - footerPadding,
		.y = footerBG.y + footerPadding,
		.w = GetTextWidth(&closeSettingsBtnText) + (closeSettingsBtnPadding * 2),
		.h = GetTextHeight(&closeSettingsBtnText) + (closeSettingsBtnPadding * 2),
		.text = closeSettingsBtnText,
		.bgColor = c_grey,
		.bgColorH = c_white,
		.textColor = c_black,
		.textColorH = c_black,
		.cmd = CMD_CloseSettings,
	};

	// Draw calls
	DrawText(&titleText, c_settingsWindow.renderer);
	DrawRect(sep1, c_settingsWindow.renderer);

	// footer
	DrawRect(footerBG, c_settingsWindow.renderer);
	DrawButton(closeSettingsBtn, c_settingsWindow, c_settingsWindow.renderer);

	SDL_RenderPresent(c_settingsWindow.renderer);
}

