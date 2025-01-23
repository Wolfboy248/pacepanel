#ifndef LAYOUTHANDLER_H
#define LAYOUTHANDLER_H

#include "../../common/common.h"
#include "../../common/common_functions.h"

#include "componentHandler.h"

#include <mxml.h>

void InitLayout();
void LoadLayout(const char* filePath, PPLayout* layout);

#endif

