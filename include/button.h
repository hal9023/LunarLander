#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"
#include "resource_dir.h"

typedef enum BUTTON_STATE {
	NORMAL = 0, // Becomes 0
	SELECTED, // Becomes 1
	PRESSED // Becomes 2
} BUTTON_STATE;

typedef struct BUTTON {
	Vector2 buttonPos;
	BUTTON_STATE buttonState;
	bool buttonAction;
	Texture2D sprite;
    int frames; // Number of different states the sprite has
    Rectangle source;
    Rectangle bounds;
} BUTTON;

void createButton(BUTTON* button, int screenX, int screenY, int btnState);

#endif 