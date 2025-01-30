#include "settings.h"

#include "../rendering/components/layoutHandler.h"

#define MAX_LINE_LENGTH 256

void s_lastLayout(char value[MAX_LINE_LENGTH]) {
	char noQuoteVal[MAX_LINE_LENGTH];
	int j = 0;

	for (size_t i = 0; i < MAX_LINE_LENGTH; i++) {
		if (value[i] == '"') {
			;
		} else {
			noQuoteVal[j] = value[i];
			j++;
		}
	}

	noQuoteVal[j] = '\0';

	LoadLayout(noQuoteVal, &currentPPLLayout);
}

void LoadGlobalSettings() {
	FILE* settingsFilePtr;
	settingsFilePtr = fopen("./settings.cfg", "r");

	char line[MAX_LINE_LENGTH];
	char key[MAX_LINE_LENGTH];
	char value[MAX_LINE_LENGTH];

	if (settingsFilePtr) {
		while (fgets(line, sizeof(line), settingsFilePtr)) {
			int testinggg = sscanf(line, "%[^=] = %s", key, value);

			printf("%s, %s\n", key, value);
			if (line[0] == '#') continue;

			if (testinggg == 2) {
				char* trimmed_key = key;
				while (*trimmed_key == ' ') trimmed_key++;

				if (strcmp(trimmed_key, "lastLayout") == 0) s_lastLayout(value);
			}
		}
	} else {
		settingsFilePtr = fopen(format("%s/settings.cfg", workingDir), "w");
		printf("No settings file detected, creating default...\n");

		fprintf(settingsFilePtr, "lastLayout '%s/layouts/default.ppl'\n", workingDir);
	}

	fclose(settingsFilePtr);
}

void SaveGlobalSettings() {

}

