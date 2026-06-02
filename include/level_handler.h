#pragma once

#include "raylib.h"
#include "resource_dir.h"
#include "shared.h"

typedef enum SELECTED_LEVEL {
    EASY = 0,
    MEDIUM,
    HARD,
    EXPERT,
    MISC1,
    MISC2,
    MISC3
} SELECTED_LEVEL;

void drawLevel();
bool collisionDetector();