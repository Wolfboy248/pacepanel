#include "text.h"

int InitText() {
	if (TTF_Init() == -1) {
		printf("SDL_ttf could not init! Error: %s\n", TTF_GetError());
		return -1;
	}
	return 0;
}

Font* LoadFont(const char* fontPath, int fontSize) {
	Font* text = (Font*)malloc(sizeof(Font));
	if (!text) {
		printf("Failed to allocate mem for Text struct!\n");
		return NULL;
	}

	text->font = TTF_OpenFont(fontPath, fontSize);
	if (!text->font) {
		printf("Failed to load font! Error: %s\n", TTF_GetError());
		free(text);
		return NULL;
	}
	text->size = fontSize;
	return text;
}

Text CreateText() {
	Text defaultText = {
		.x = 0,
		.y = 0,
		.color = (SDL_Color){255, 255, 255, 255},
		.fontPath = "fonts/JetBrainsMonoNerdFont-Medium.ttf",
		.fontSize = 18,
		.text = "Text"
	};

	return defaultText;
}

void DrawText(Text textStruct, SDL_Renderer* renderer) {
	Font* textObj = LoadFont(textStruct.fontPath, textStruct.fontSize);
	if (!textObj) {
		return;
	}

	SDL_Surface* textSurface = TTF_RenderText_Blended(textObj->font, textStruct.text, textStruct.color);
	if (!textSurface) {
		printf("Unable to create text surface! Error: %s\n", TTF_GetError());
		TTF_CloseFont(textObj->font);
		free(textObj);
		return;
	}

	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if (!textTexture) {
		printf("Unable to create texture from surface! Error: %s\n", TTF_GetError());
	}

	SDL_Rect dstRect = { textStruct.x, textStruct.y, textSurface->w, textSurface->h };
	SDL_RenderCopy(renderer, textTexture, NULL, &dstRect);

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
	TTF_CloseFont(textObj->font);
	free(textObj);
}

void FreeText() {
	TTF_Quit();
}

