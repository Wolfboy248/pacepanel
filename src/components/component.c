#include "component.h"

int GetComponentHeight(ComponentContext* context) {
	for (int i = 0; i < context->numElements; i++) {
		GraphicElement* element = &context->elements[i];

		return GetTextHeight(&element->text);
	}

	return 24;
}

