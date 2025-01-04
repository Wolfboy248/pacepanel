#ifndef COMMON_FUNCTIONS_H
#define COMMON_FUNCTIONS_H

#include "common.h"

char* format(const char* format, ...);
void SetWindowPosition(int x, int y, I_Window* window);
void SetWindowDimensions(int w, int h, I_Window* window);

void A_Quit();

#endif

