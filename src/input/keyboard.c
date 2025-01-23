#include "keyboard.h"
#include "../timing/timer.h"
#include "../rendering/components/layoutHandler.h"

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <X11/Xlib.h>
#include <X11/XKBlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <pthread.h>
#elif __APPLE__
#include <Carbon/Carbon.h>
#endif

void HandleKeyboardInput(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		SDL_Keycode key = event.key.keysym.sym;

		SDL_Window* focusedWindow = SDL_GetKeyboardFocus();

		switch (event.key.keysym.sym) {
			case SDLK_a:
				StartTimer();
				break;

			case SDLK_s:
				ResetTimer();
				break;

			case SDLK_d:
				StopTimer();
				break;

			case SDLK_o:
				LoadLayout("./layouts/test.ppl", &currentPPLLayout);
				break;

			default:
				break;
		}
	}
}

void SendSDLKeyEvent(SDL_Keycode key) {
	SDL_Event event;
	event.type = SDL_KEYDOWN;
	event.key.keysym.sym = key;
	event.key.state = SDL_PRESSED;
	SDL_PushEvent(&event);
}

#ifdef _WIN32
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
		KBDLLHOOKSTRUCT* kbStruct = (KBDLLHOOKSTRUCT*)lParam;
		SDL_Keycode key = (SDL_Keycode)kbStruct->vkCode;
		SendSDLKeyEvent(key);
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void RegisterGlobalHotkey() {
	SetWindowsHookEx(WM_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), 0);
}

void ListenForGlobalHotkey() {
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

#elif __linux__
Display* display;

void* GlobalHotkeyThread(void* arg) {
	display = XOpenDisplay(NULL);
	if (!display) {
		printf("Failed to open X display\n");
		return NULL;
	}

	Window root = DefaultRootWindow(display);
	Window window = XCreateSimpleWindow(display, root, 100, 100, 800, 600, 1, BlackPixel(display, 0), WhitePixel(display, 0));

	XGrabKeyboard(display, window, True, GrabModeAsync, GrabModeAsync, CurrentTime);

	XSelectInput(display, window, KeyPressMask | KeyReleaseMask);  // Select events

	XMapWindow(display, window);
	XEvent ev;

	printf("Global hotkey listener initialized...\n");

	while (1) {
		XNextEvent(display, &ev);
		printf("NO WAY\n");
		if (ev.type == KeyPress) {
			KeySym keysym = XLookupKeysym(&ev.xkey, 0);
			printf("Gloabl key pressed: %ld\n", keysym);

			SDL_Event sdlEvent;
			sdlEvent.type = SDL_KEYDOWN;
			sdlEvent.key.keysym.sym = keysym;
			SDL_PushEvent(&sdlEvent);
		}
	}

	XCloseDisplay(display);
	return NULL;
}

void RegisterGlobalHotkey() {
	pthread_t threadID;
	if (pthread_create(&threadID, NULL, GlobalHotkeyThread, NULL) != 0) {
		fprintf(stderr, "Failed to create global hotkey thread\n");
	}
	pthread_detach(threadID);
}

void ListenForGlobalHotkey() {
	if (!display) {
		printf("Display not initialized\n");
		return;
	}

	XEvent event;
	while (1) {
		XNextEvent(display, &event);
		if (event.type == KeyPress) {
			XKeyEvent* keyEvent = (XKeyEvent*)&event;
			KeySym keysym = XLookupKeysym(keyEvent, 0);
			SDL_Keycode key = (SDL_Keycode)keysym;
			SendSDLKeyEvent(key);
		}
	}
}

#elif __APPLE__
void HotKeyHandler(EventHandlerCallRef nextHandler, EventRef event, void* userData) {
	EventHotKeyID hotKeyID;
	GetEventParameter(event, kEventParamDirectObject, typeEventHotKeyID, NULL, sizeof(hotKeyID), NULL, &hotKeyID);

	SDL_Keycode key = (SDL_Keycode)(hotKeyID.id);
	SendSDLKeyEvent(key);
}

void RegisterGlobalHotkey() {
	for (int key = 0; key < 128; ++key) {
		EventHotKeyRef hotKeyRef;
		EventHotKeyID hotKeyID;
		hotKeyID.signature = 'HotK';
		hotKeyID.id = key;

		RegisterEventHotKey(
			key,
			0,
			hotKeyID,
			GetApplicationEventTarget(),
			0,
			&hotKeyRef
		);
	}
}

void ListenForGlobalHotkey() {
	RunApplicationEventLoop();
}

#endif

