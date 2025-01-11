#ifndef COMPONENT_H
#define COMPONENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../common/common.h"
#include "../common/common_functions.h"
#include "../rendering/elements/text.h"
#include "../rendering/elements/rect.h"
#include "../timing/timer.h"
	
	typedef struct {
		int w, h;
		Text text;
	} GraphicElement;

	typedef struct {
		GraphicElement* elements;
		int numElements;
		SDL_Renderer* renderer;
		int h, paddingV, paddingH;
	} ComponentContext;

	void InitComponent(ComponentContext* context, SDL_Renderer* renderer);

	void RenderComponent(ComponentContext* context);

	void CleanupComponent(ComponentContext* context);

	int GetComponentHeight(ComponentContext* context);

#ifdef __cplusplus
}
#endif

#endif

