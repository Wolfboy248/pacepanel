#ifndef DEBUG_H
#define DEBUG_H

#include "../common/common.h"

typedef struct {
	const char* name;
	const char* value;
} DebugValue;

extern DebugValue debugValues[];
extern int debugValuesLen;

void AddDebugValue(const char* name, char* value);

#endif

