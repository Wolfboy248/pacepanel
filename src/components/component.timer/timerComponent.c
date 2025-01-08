#include "../component.h"

void InitComponent(ComponentContext* context, SDL_Renderer* renderer) {
	context->renderer = renderer;
	context->numElements = 1;
	context->elements = malloc(sizeof(GraphicElement) * context->numElements);

	Text testText = CreateText();
	testText.text = t_realTime.formattedString;
	context->elements[0].text = testText;
}

void RenderComponent(ComponentContext* context) {
	for (int i = 0; i < context->numElements; i++) {
		GraphicElement* element = &context->elements[i];

		// update values
		context->elements[0].text.text = t_realTime.formattedString;
		
		// please god this is cursed
		DrawText(&element->text, SDL_GetRenderer(SDL_GetWindowFromID(1)));
	}
}

void CleanupComponent(ComponentContext* context) {
	free(context->elements);
	printf("Cleaned up elements\n");
}

