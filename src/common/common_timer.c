#include "common_timer.h"

T_Timer t_realTime = {
	.running = 0,
	.startTime = 0,
};

T_Timer t_gameTime = {
	.running = 0,
	.startTime = 0,
};

