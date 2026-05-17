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
