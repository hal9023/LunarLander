#include <stdio.h>
#include <math.h>
#include "raylib.h"
#include "resource_dir.h"
#include "gameplay.h"
#include "menu.h"
#include "shared.h"

#undef SETTINGS

bool running = false;
SCENE scene = MENU_SCENE;

void clearTerminal(void) {
	printf("\e[1;1H\e[2J");
	fflush(stdout);
}

void selectScene(bool status, SCENE sceneL) {
	switch (sceneL) {
		case MENU_SCENE:
			if (!status) {
				initMenu();
			}
			updateMenu();
			drawMenu();
			break;
		case LEVEL_SELECTOR:
			// Include "Running" check here for init function
			break;
		case SETTINGS:
			// Include "Running" check here for init function
			break; 
		case GAMEPLAY_SCENE:
			if(!status) {
				initGameplay();
			}
			updateGameplay();
			drawGameplay();
			break;
		case ENDING_SCENE:
			// Include "Running" check here for init function
			break;
	}
}

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SearchAndSetResourceDir("resources");
	SetTargetFPS(60);
	
	// game loop
	selectScene(running, scene);

	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		running = true;

		clearTerminal();

		printf("--- Lunar Lander Debug ---\n");
		printf("Current Screen %d\n", scene); // If I want I might make this parse the enum to a "string" for pretty printing

		BeginDrawing();
			selectScene(running, scene);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
