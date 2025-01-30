#include "layoutHandler.h"

void InitLayout() {
	// LoadLayout("./layouts/default.ppl", &currentPPLLayout);

	// printf("Loaded winSize: %d, %d\n", currentPPLLayout.settings.windowWidth, currentPPLLayout.settings.windowHeight);
}

void LoadLayout(const char* filePath, PPLayout* layout) {
	UnloadComponents();
	printf("Loading %s\n", filePath);
	FILE* file = fopen(filePath, "r");
	if (!file) {
		printf("Error: Unable to open PPL file %s\n", filePath);
		return;
	}

	layout->filePath = filePath;

	
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

	c_window.w = layout->settings.windowWidth;
	c_window.h = 0;


	if (isInit) {
		LoadComponents(layout);
	}
}

int calculate_depth(mxml_node_t *node) {
    int depth = 0;
    while ((node = mxmlGetParent(node)) != NULL) {
        depth++;
    }
    return depth;
}

// Custom callback for pretty-printing with newlines and indentation
const char *custom_write_cb(mxml_node_t *node, int where) {
    static char indent[128];
    int depth;

	const char* element;

	element = mxmlGetElement(node);

	switch (where) {
    // case MXML_WS_BEFORE_OPEN:
        // depth = calculate_depth(node); // Calculate the depth of the node
        // snprintf(indent, sizeof(indent), "\n%*s", depth * 2, ""); // 2 spaces per level
        // return indent;
    case MXML_WS_BEFORE_CLOSE:
        depth = calculate_depth(node) - 1; // One level up for closing tag
        snprintf(indent, sizeof(indent), "\n%*s", depth * 2, "");
        return indent;
    case MXML_WS_AFTER_CLOSE:
        if (mxmlGetParent(node)) { // Only add a newline after closing if not the root
            return "\n";
        }
        break;
	case MXML_WS_AFTER_OPEN:
		depth = calculate_depth(node);
		snprintf(indent, sizeof(indent), "\n%*s", depth * 2, "");
		return indent;
    default:
        break;
    }

    return NULL; // Default: no extra whitespace
}

#define SETTING_INFO(struct_type, member) {#member, offsetof(struct_type, member)}

void SaveSettingsHandler(mxml_node_t* settingsNode, PPLayout* layout) {
	size_t settingsNum = sizeof(PPLayoutSettings) / sizeof(int);
	printf("%lu\n", settingsNum);

	typedef struct {
		const char* name;
		int val;
	} NamedSetting;

	int* ptr = &layout->settings.windowWidth;

	NamedSetting namedSettings[] = {
		SETTING_INFO(PPLayoutSettings, windowWidth),
		SETTING_INFO(PPLayoutSettings, windowHeight),
	};

	for (size_t i = 0; i < settingsNum; i++) {
		int settingVal = ptr[i];
		mxml_node_t* setting;
		printf("Setting %s: %d\n", namedSettings[i].name, ptr[i]);

		setting = mxmlNewElement(settingsNode, namedSettings[i].name);
		mxmlNewText(setting, 0, format("%d", settingVal));
	}
}

void SaveComponentsHandler(mxml_node_t* componentsNode, PPLayout* layout) {
	printf("Saving Components\n");
	size_t componentsNum = sizeof(PPLComponent[64]) / sizeof(const char*);
	printf("%lu\n", componentsNum);

	mxml_node_t* componentNode;
	mxml_node_t* typeNode;

	for (size_t i = 0; i < componentsNum; i++) {
		if (layout->components[i].type == NULL) {
			printf("Invalid component: %zu\n", i);
		} else {
			printf("Component type: %s, %zu\n", layout->components[i].type, i);
			
			componentNode = mxmlNewElement(componentsNode, "component");
			typeNode = mxmlNewElement(componentNode, "type");
			mxmlNewText(typeNode, 0, layout->components[i].type);
		}
	}
}

void SaveLayout(const char* filePath, PPLayout* layout) {
	FILE* fp;
	mxml_node_t* xml;
	mxml_node_t* layoutNode;
	mxml_node_t* settingsNode;
	mxml_node_t* componentsNode;
	
	xml = mxmlNewXML("1.0");
	layoutNode = mxmlNewElement(xml, "layout");
	settingsNode = mxmlNewElement(layoutNode, "settings");
	componentsNode = mxmlNewElement(layoutNode, "components");

	SaveSettingsHandler(settingsNode, layout);
	SaveComponentsHandler(componentsNode, layout);

	fp = fopen(filePath, "w");
	mxmlSaveFile(xml, fp, 0);

	fclose(fp);
}

