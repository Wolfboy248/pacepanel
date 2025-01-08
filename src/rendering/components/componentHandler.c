#include "componentHandler.h"
#ifdef __linux__
#include <dlfcn.h>
#elif _WIN32
#include <windows.h>
#endif

typedef void (*InitFunc)(ComponentContext* context, SDL_Renderer* renderer);
typedef void (*RenderFunc)(ComponentContext* context);
typedef void (*CleanupFunc)(ComponentContext* context);

typedef struct {
	RenderFunc render;
	CleanupFunc cleanup;
	ComponentContext context;
	void* handle;
} LoadedComponent;

#define MAX_COMPONENTS 10

LoadedComponent components[MAX_COMPONENTS];
int numComponents = 0;

void LoadComponent(const char* componentPath) {
	printf("Loading component: %s\n", componentPath);
	if (numComponents >= MAX_COMPONENTS) {
		fprintf(stderr, "Cannot load more components, limit reached\n");
		return;
	}

	void* handle = dlopen(componentPath, RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "Failed to load component! %s\n", dlerror());
		return;
	}

	InitFunc init = (InitFunc)dlsym(handle, "InitComponent");
	RenderFunc render = (RenderFunc)dlsym(handle, "RenderComponent");
	CleanupFunc cleanup = (CleanupFunc)dlsym(handle, "CleanupComponent");

	if (!init || !render || !cleanup) {
		fprintf(stderr, "Failed to load required functions %s\n", dlerror());
		dlclose(handle);
		return;
	}

	ComponentContext context = {0};
	init(&context, c_window.renderer);

	components[numComponents].render = render;
	components[numComponents].cleanup = cleanup;
	components[numComponents].context = context;
	components[numComponents].handle = handle;

	numComponents++;
}

void UnloadComponents() {
	for (int i = 0; i < numComponents; i++) {
		components[i].cleanup(&components[i].context);

		dlclose(components[i].handle);
	}

	numComponents = 0;
}

void RenderComponents() {
	for (int i = 0; i < numComponents; i++) {
		components[i].render(&components[i].context);
	}
}

