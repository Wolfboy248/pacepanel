#include "../component.h"

void InitComponent(ComponentContext* context, SDL_Renderer* renderer) {
	context->renderer = renderer;
	context->numElements = 1;
	context->elements = malloc(sizeof(GraphicElement) * context->numElements);

	Text testText = CreateText();
	testText.text = t_realTime.formattedString;
	testText.textAlignH = RIGHT;
	testText.paddingR = 5;
	testText.w = c_window.w;
	testText.y = c_window.h;
	context->elements[0].text = testText;
	context->elements[0].text.fontSize = 32;

	context->h = GetComponentHeight(context);
	SetWindowDimensions(c_window.w, c_window.h + context->h, &c_window);
}

void RenderComponent(ComponentContext* context) {
	for (int i = 0; i < context->numElements; i++) {
		GraphicElement* element = &context->elements[i];

		// update values
		element->w = c_window.w;
		element->text.w = element->w;
	}

	context->elements[0].text.text = t_realTime.formattedString;
	
										 // please god this is cursed
	DrawText(&context->elements[0].text, SDL_GetRenderer(SDL_GetWindowFromID(1)));
}

void CleanupComponent(ComponentContext* context) {
	free(context->elements);
}

