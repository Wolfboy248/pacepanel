#include "../component.h"

void InitComponent(ComponentContext* context, SDL_Renderer* renderer) {
	context->renderer = renderer;
	context->numElements = 1;
	context->elements = malloc(sizeof(GraphicElement) * context->numElements);

	Text titleText = CreateText();
	titleText.w = c_window.w;
	titleText.textAlignH = CENTER;
	context->elements[0].text = titleText;
}

void RenderComponent(ComponentContext* context) {
	for (int i = 0; i < context->numElements; i++) {
		GraphicElement* element = &context->elements[i];

		element->w = c_window.w;
		element->text.w = element->w;
	}

	context->elements[0].text.text = pp_currentGame.title;

	DrawText(&context->elements[0].text, context->renderer);
	printf("%d\n", context->elements[0].text.w);
}

void CleanupComponent(ComponentContext* context) {
	free(context->elements);
}

