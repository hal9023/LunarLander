#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "raylib.h"
#include "raymath.h"
#include "resource_dir.h"

typedef struct Lander {
    Vector2 position; 
    Vector2 velocity;
    float rotation; 
    float throttle; 
    int fuel; 
    Texture sprite; 
} Lander; 

// Declare Public Functions
void initGameplay(void);
void updateGameplay(void);
void drawGameplay(void);
void unloadGameplay(void);

#endif