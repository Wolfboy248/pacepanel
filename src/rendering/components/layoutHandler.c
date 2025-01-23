#include "layoutHandler.h"

void InitLayout() {
	LoadLayout("./layouts/default.ppl", &currentPPLLayout);

	printf("Loaded winSize: %d, %d\n", currentPPLLayout.settings.windowWidth, currentPPLLayout.settings.windowHeight);
}

void LoadLayout(const char* filePath, PPLayout* layout) {
	UnloadComponents();
	printf("Loading %s\n", filePath);
	FILE* file = fopen(filePath, "r");
	if (!file) {
		printf("Error: Unable to open PPL file %s\n", filePath);
		return;
	}
	
	mxml_node_t* tree = mxmlLoadFile(NULL, file, MXML_OPAQUE_CALLBACK);
    fclose(file);

    if (!tree) {
        printf("Error: Failed to parse XML\n");
        return;
    }

    // Get the root node
    mxml_node_t* root = mxmlFindElement(tree, tree, "layout", NULL, NULL, MXML_DESCEND);
    if (!root) {
        printf("Error: Root element not found\n");
        mxmlDelete(tree);
        return;
    }

    // Process <settings>
    mxml_node_t* settings = mxmlFindElement(root, root, "settings", NULL, NULL, MXML_DESCEND);
    if (settings) {
        mxml_node_t* child;
        for (child = mxmlFindElement(settings, settings, NULL, NULL, NULL, MXML_DESCEND);
             child != NULL;
             child = mxmlFindElement(child, settings, NULL, NULL, NULL, MXML_NO_DESCEND)) {
			if (strcmp(mxmlGetElement(child), "windowWidth") == 0) {
				layout->settings.windowWidth = charToInt(mxmlGetOpaque(child));
			} else if (strcmp(mxmlGetElement(child), "windowHeight") == 0) {
				layout->settings.windowHeight = charToInt(mxmlGetOpaque(child));
			}
            printf("Setting: %s = %s\n", mxmlGetElement(child), mxmlGetOpaque(child));
        }
    }

    // Process <components>
	layout->numComponents = 0;
    mxml_node_t* components = mxmlFindElement(root, root, "components", NULL, NULL, MXML_DESCEND);
    if (components) {
        mxml_node_t* component;
        for (component = mxmlFindElement(components, components, "component", NULL, NULL, MXML_DESCEND);
             component != NULL;
             component = mxmlFindElement(component, components, "component", NULL, NULL, MXML_NO_DESCEND)) {
            mxml_node_t* type = mxmlFindElement(component, component, "type", NULL, NULL, MXML_DESCEND);
            if (type) {
				layout->components[layout->numComponents].type = mxmlGetOpaque(type);
                printf("Component Type: %s\n", mxmlGetOpaque(type));
            }
			layout->numComponents++;
        }
    }

	c_window.h = 0;

	if (isInit) {
		LoadComponents(layout);
	}
}

