#include "layoutHandler.h"

#define MAX_TAG_LENGTH 128
#define MAX_CONTENT_LENGTH 1024

typedef struct {
	char tag[MAX_TAG_LENGTH];
	char content[MAX_CONTENT_LENGTH];
} XmlElement;

void skipWhitespaces(FILE* file) {
	int ch;
	while ((ch = fgetc(file)) != EOF && (ch == ' ' || ch == '\n' || ch == '\t')) {

	}
	if (ch != EOF) {
		ungetc(ch, file);
	}
}

int parseTag(FILE* file, char* tag) {
	int i = 0;
	int ch;

	skipWhitespaces(file);

	if ((ch = fgetc(file)) != '<') {
		return 0;
	}

	while ((ch = fgetc(file)) != EOF && ch != '>' && ch != ' ' && i < MAX_TAG_LENGTH - 1) {
		tag[i++] = ch;
	}
	tag[i] = '\0';

	return (ch == '>' || ch == ' ');
}

int parseContent(FILE* file, char* content) {
	int i = 0;
	int ch;

	skipWhitespaces(file);

	while ((ch = fgetc(file)) != EOF && ch != '<' && i < MAX_CONTENT_LENGTH - 1) {
		content[i++] = ch;
	}
	content[i] = '\0';

	return (ch == '<');
}

void LoadLayout(const char* filePath, PPLayout* layout) {
	printf("Loading %s\n", filePath);
	FILE* file = fopen(filePath, "r");
	if (!file) {
		printf("Error: Unable to open PPL file %s\n", filePath);
		return;
	}

	XmlElement element;

	while (1) {
		if (!parseTag(file, element.tag)) {
			break;
		}

		if (parseContent(file, element.content)) {
			printf("Tag: <%s>\n", element.tag);
			printf("Content: %s\n", element.content);
		} else {
			printf("Tag: <%s>\n", element.tag);
			printf("No content\n");
		}

		char closeTag[MAX_TAG_LENGTH];

		if (parseTag(file, closeTag) && strcmp(element.tag, closeTag) != 0) {
			printf("Error: mismatched closing tag <%s> vs. <%s>\n", closeTag, element.tag);
		}
	}

	fclose(file);
}

