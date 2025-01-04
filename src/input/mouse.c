#include "mouse.h"
#include "../window/window.h"

Uint32 childWindowTimer = 0;
int dragging = 0;
int dragOffsetX = 0;
int dragOffsetY = 0;

int contextMenuReady = 0;

void MouseChecks() {
	// printf("Mouse state: x: %d, y: %d, LMBDown: %d, RMBDown, %d, LMBClick: %d, RMBClick: %d\n", c_mouse.x, c_mouse.y, c_mouse.LMBDown, c_mouse.RMBDown, c_mouse.LMBClick, c_mouse.RMBClick);
	
	// update mouse
	Uint32 mouseState = SDL_GetGlobalMouseState(&c_mouse.absX, &c_mouse.absY);
	// printf("X: %d, Y: %d\n", c_mouse.absX, c_mouse.absY);

	if (c_mouse.LMBClick) {
		dragOffsetX = c_mouse.x;
		dragOffsetY = c_mouse.y;
		c_mouse.LMBClick = 0;
	}

	if (c_mouse.RMBClick) {
		c_mouse.RMBClick = 0;
	}

	if (c_mouse.LMBDown) {
		dragging = 1;
	} else if (!c_mouse.LMBDown) {
		dragging = 0;
	}
}

void HandleMouseInput(SDL_Event event) {
	// update mouse x and y
	if (event.type == SDL_MOUSEMOTION) {
		c_mouse.x = event.motion.x;
		c_mouse.y = event.motion.y;

		if (dragging) {
			// printf("MouseX Abs: %d, DragOffsetX: %d, RelativeMov: %d\n", c_mouse.x + c_window.x, dragOffsetX, c_mouse.x - dragOffsetX + c_window.x);
			// SDL_SetWindowPosition(SDL_mainWindow, c_mouse.x - dragOffsetX + c_window.x, c_mouse.y - dragOffsetY + c_window.y);
			SetWindowPosition(c_mouse.x - dragOffsetX + c_window.x, c_mouse.y - dragOffsetY + c_window.y, &c_window);
		} else {
			// printf("MouseX Abs: %d\n", c_mouse.x + c_window.x);
		}
	}

	// context menu state focus 
//	if (event.type == SDL_WINDOWEVENT) {
//		if (event.window.event == SDL_WINDOWEVENT_FOCUS_LOST && contextMenuOpen) {
//			if (contextMenuReady) {
//				contextMenuOpen = 0;
//				contextMenuReady = 0;
//				SDL_DestroyWindow(SDL_contextMenuWindow);
//				SDL_contextMenuWindow = NULL;
//			}		
//		}
//	}

	if (event.type != SDL_MOUSEMOTION) {
		dragging = 0;
	}

	if (event.type == SDL_MOUSEBUTTONUP) {
		if (event.button.button == SDL_BUTTON_RIGHT) {
			c_mouse.RMBDown = 0;
		} else if (event.button.button == SDL_BUTTON_LEFT) {
			c_mouse.LMBDown = 0;
		}
	}

	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (event.button.button == SDL_BUTTON_RIGHT) {
			if (!c_mouse.RMBDown) {
				c_mouse.RMBClick = 1;
			} else {
				c_mouse.RMBClick = 0;
			}
			c_mouse.RMBDown = 1;

			// Context menu
			if (!SDL_contextMenuWindow) {
				SDL_contextMenuWindow = CreateContextMenu(SDL_mainWindow);

				if (SDL_contextMenuWindow) {
					SDL_RaiseWindow(SDL_contextMenuWindow);
					contextMenuReady = 1;
				}

				contextMenuOpen = 1;

				return;
			}
		} else if (event.button.button == SDL_BUTTON_LEFT) {
			if (!c_mouse.LMBDown) {
				c_mouse.LMBClick = 1;
			} else {
				c_mouse.LMBClick = 1;
			}

			c_mouse.LMBDown = 1;
		}
	}
}

