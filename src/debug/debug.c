#include "debug.h"

DebugValue debugValues[] = {
	{"Debug", ""},
	{"Value1", ""}
};

int debugValuesLen = 2;

void AddDebugValue(const char* name, char* value) {
	debugValues[debugValuesLen].name = strdup(name);
	debugValues[debugValuesLen].value = strdup(value);
	debugValuesLen++;
}

