#ifndef COMMONTIMER_H
#define COMMONTIMER_H

#include "common.h"

typedef struct {
	Uint32 total;
	Uint32 h, m, s, ms;
} ElapsedTime;

typedef struct {
	Uint32 timeStarted;
	Uint32 startTime;
	ElapsedTime elapsed;
	const char* formattedString;
	int running;

	struct {
		int decimalPresicion;
	} settings;
} T_Timer;

extern T_Timer t_realTime;
extern T_Timer t_gameTime;

#endif

