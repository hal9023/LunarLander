#include <stdio.h>
#include <math.h>
#include "raylib.h"
#include "resource_dir.h"
#include "gameplay.h"

typedef enum GameScreen {
	MENU = 0, // Becomes 0
	LEVEL_SELECTOR, // Becomes 1
	GAMEPLAY, // Becomes 2
	ENDING // Becomes 3
} GameScreen;

GameScreen currentScreen = MENU;

#define thrust 0.015f // Changes how quickly the lander accelerates
#define throttleRate 3 // Changes how quickly the throttle changes
#define rotationRate 0.7f // changes how quickly the lander rotates

int calculateVelocity (float theta, float throttle, float* verticalVelocity, float* horizontalVelocity) {
	// degrees to radians
	float radians = (theta - 90.0f) * (PI / 180.0f);

	float totalThrust = ((throttle / 100.0f) * thrust);
	//printf("Total Thrust: %f\n", totalThrust);

	float xComponent = cos(radians) * totalThrust;
	float yComponent = sin(radians) * totalThrust;
	
	//printf("X Component: %f\n Y Component: %f\n", xComponent, yComponent);

	*verticalVelocity += (yComponent);

	printf("Vertical Velocity: %f\n", *verticalVelocity);
	printf("Horizontal Velocity: %f\n", *horizontalVelocity);

	*horizontalVelocity += (xComponent);
}

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(800, 600, "Lunar Lander");
	SearchAndSetResourceDir("resources");
	Texture lander = LoadTexture("lander.png");
	
	float x;
	float y;

	float rotation = 0.0f;
	
	float throttle = 0;

	float verticalVelocity = 0.0;
	float horizontalVelocity = 0.0;

	float gravity = 0.01f; 

	// define starting position
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;

	// Velocity will depend on the angle of the thrust applied
	// Pretty simple vectory math but accounting for gravity could prove to be aannoying

	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		// Make sure rotation doesn't exceed 360
		if (rotation>359) rotation = 0;
		if (rotation<0) rotation = 359;

		if (IsKeyDown(KEY_A)) {
			rotation -= rotationRate;
			printf("Rotation: %f\n", rotation);
		}
		if (IsKeyDown(KEY_D)) {
			rotation += rotationRate;
			printf("Rotation: %f\n", rotation);
		}
		// Smoothly incresae throttle when w is pressed down
		if (IsKeyDown(KEY_W)) {
			throttle += throttleRate;
			if (throttle > 100) throttle = 100; 
			printf("Throttle: %d\n", throttle);
		}
		if (!IsKeyDown(KEY_W)) {
			throttle -= throttleRate;
			if (throttle < 0) throttle = 0;
			printf("Throttle: %d\n", throttle);
		}

		calculateVelocity(rotation, throttle, &verticalVelocity, &horizontalVelocity);

		x += horizontalVelocity;
		y += verticalVelocity;

		// drawing
		BeginDrawing();

		DrawTexturePro(lander, (Rectangle){0, 0, lander.width, lander.height}, (Rectangle){x, y, lander.width, lander.height}, (Vector2){lander.width / 2, lander.height / 2}, rotation, WHITE);
		
		if (x >= GetScreenWidth()) {
			x = (GetScreenWidth() - (lander.width/2));
			horizontalVelocity = 0;
		}

		if (x <= 0) {
			x = (0 + (lander.width/2));
			horizontalVelocity = 0;
		}

		if (y >= GetScreenHeight()) {
			y = (GetScreenHeight() - (lander.height/2));
			verticalVelocity = 0;
		}
		
		if (y <= 0) {
			y = (0 + (lander.height/2)); 
			gravity = 0;
			verticalVelocity = 0;
		}
		else {
			gravity = 0.01f;
		}



		verticalVelocity += gravity;

		// Implement Map Drawing Later
		ClearBackground(BLACK);

		EndDrawing();
	}
	UnloadTexture(lander);

	CloseWindow();
	return 0;
}
