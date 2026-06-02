#pragma once

typedef enum SCENE {
	MENU_SCENE = 0, 
	LEVEL_SELECTOR, 
	SETTINGS,
	GAMEPLAY_SCENE, 
	ENDING_SCENE 
} SCENE;

extern SCENE scene; 
extern bool running;

typedef struct TERRAIN_LINE {
    Vector2 start; 
    Vector2 end;
} TERRAIN_LINE;
typedef struct LANDING_ZONE {
    Vector2 start; 
    Vector2 end;
} LANDING_ZONE;