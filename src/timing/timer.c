#include "timer.h"

void FormatValues(T_Timer* timer) {
	timer->elapsed.s = timer->elapsed.total / 1000 % 60;
	timer->elapsed.ms = timer->elapsed.total % 1000;
	timer->elapsed.m = timer->elapsed.total / 1000 / 60 % 60;
	timer->elapsed.h = timer->elapsed.total / 1000 / 60 / 60;

	const char* formattedValue;
	const char* formattedMSValue;

	timer->settings.decimalPresicion = 2;
	switch (timer->settings.decimalPresicion) {
		case 0:
			formattedMSValue = "";
			break;
		case 1:
			formattedMSValue = format(".%d", timer->elapsed.ms / 100);
			break;
		case 2:
			formattedMSValue = format(".%02d", timer->elapsed.ms / 10);
			break;
		case 3:
			formattedMSValue = format(".%03d", timer->elapsed.ms);
			break;
		default:
			formattedMSValue = "";
			break;
	}

	if (timer->elapsed.h != 0) {
		formattedValue = format("%d:%02d:%02d%s", timer->elapsed.h, timer->elapsed.m, timer->elapsed.s, formattedMSValue);
	} else if (timer->elapsed.m != 0) {
		formattedValue = format("%d:%02d%s", timer->elapsed.m, timer->elapsed.s, formattedMSValue);
	} else {
		formattedValue = format("%d%s", timer->elapsed.s, formattedMSValue);
	}

	timer->formattedString = formattedValue;
}

void InitTimer() {
	FormatValues(&t_realTime);
}

void StartTimer() {
	t_realTime.startTime = 0;
	// t_realTime.startTime = 3595999;
	t_realTime.timeStarted = SDL_GetTicks();
	t_realTime.running = 1;
}

void ResetTimer() {
	t_realTime.elapsed.total = 0;
	FormatValues(&t_realTime);
	t_realTime.running = 0;
}

void StopTimer() {
	t_realTime.running = 0;
}

void HandleTimer() {
	if (t_realTime.running) {
		t_realTime.elapsed.total = SDL_GetTicks() - t_realTime.timeStarted + t_realTime.startTime;
		FormatValues(&t_realTime);
	}
}

