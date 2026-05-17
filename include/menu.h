#pragma once

#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "resource_dir.h"
#include "shared.h"
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