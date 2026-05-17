#pragma once

#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "resource_dir.h"
#include "shared.h"
#include <stdlib.h>
#include "button.h"

typedef struct MENU {
    SCENE selected;
} MENU;
 
typedef enum SELECTED_BUTTON {
    PLAY_BUTTON = 0,
    SETTINGS_BUTTON,
    QUIT_BUTTON
} SELECTED_BUTTON;

// Deeclare Public Functions
void initMenu(void);
void updateMenu(void);
void drawMenu(void);
void unloadMenu(void);

#endif