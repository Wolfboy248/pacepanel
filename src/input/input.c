#include "input.h"

SDL_Thread* hotKeyThread;

void InitInput() {
#ifdef _WIN32
	printf("Initalizing input for windows\n");
	RegisterGlobalHotkey();
#elif __linux__
	printf("Initalizing input for linux\n");
	RegisterGlobalHotkey();
#elif __APPLE__
	printf("Initalizing input for mac\n");
	RegisterGlobalHotkey();
#endif
	
	//hotKeyThread = SDL_CreateThread(
	//	(int (*)(void*))ListenForGlobalHotkey,
	//	"HotkeyListener",
	//	NULL
	//);
}

void CleanupInput() {
	// SDL_WaitThread(hotKeyThread, NULL);
}

void InputPerFrameChecks() {
	MouseChecks();
}

void HandleInput(SDL_Event event) {
	if (event.type == SDL_QUIT) {
		running = 0;
	}

	if (event.type == SDL_WINDOWEVENT) {
		// focus
		if (event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) {
			SDL_focusedWindow = SDL_GetWindowFromID(event.window.windowID);
			if (SDL_focusedWindow) {
				const char* winTitle = SDL_GetWindowTitle(SDL_focusedWindow);
				const char* prevWinTitle;

				if (SDL_prevFocusedWindow) {
					prevWinTitle = SDL_GetWindowTitle(SDL_prevFocusedWindow);
					int winID = SDL_GetWindowID(SDL_focusedWindow);
					int prevWinID = SDL_GetWindowID(SDL_prevFocusedWindow);
					SDL_Log("Window selected: %s (%d) | Previous window: %s (%d)", winTitle, winID, prevWinTitle, prevWinID);

					if (prevWinID == SDL_GetWindowID(c_contextMenuWindow.window)) {
						contextMenuOpen = 0;
						SDL_DestroyWindow(c_contextMenuWindow.window);
						SDL_DestroyRenderer(c_contextMenuWindow.renderer);
						SDL_contextMenuWindow = NULL;
					}
				} else {
					SDL_Log("Window selected: %s", winTitle);
				}

				SDL_prevFocusedWindow = SDL_focusedWindow;
			} else {
				SDL_Log("No window found");
			}
		}

		// closing of windows
		if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
			SDL_Window* windowToClose = SDL_GetWindowFromID(event.window.windowID);
			if (windowToClose) {
				const char* winTitle = SDL_GetWindowTitle(windowToClose);

				printf("Closing window %s\n", winTitle);

				for (int i = 0; i < numWindows; i++) {
					if (windowToClose == c_windows[i]->window) {
						CloseWindow(c_windows[i]);
					}
				}
			}
		}
	}

	HandleMouseInput(event);
	HandleKeyboardInput(event);
};

