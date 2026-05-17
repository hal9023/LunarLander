#include "gameplay.h"
#include <stdio.h>

#define GRAVITY_ACCEL 0.075f
#define THRUST_FACTOR 2.0f
#define TROTTLE_RATE 5
#define ROTATION_RATE 1.0f

static LANDER player = { 0 };


void initGameplay(void) {
    SetWindowSize(800, 600);

    player.position = (Vector2){ (GetScreenWidth() / 2), (GetScreenHeight() / 2) };
    player.velocity = (Vector2){ 0, 0};
    player.fuel = 100;
    player.throttle = 0;
    player.rotation = 0.0f;

    // Load Lander texture
    player.sprite = LoadTexture("lander.png");
}

void updateGameplay(void) {
    // Player Input
    if (IsKeyDown(KEY_A)) {
        player.rotation -= ROTATION_RATE;
        printf("Rotating Left\n");
    }   
    if (IsKeyDown(KEY_D)) {
        player.rotation += ROTATION_RATE;
        printf("Rotating Right\n");
    }   
    if (player.rotation > 359) player.rotation = 0;
    if (player.rotation < 0) player.rotation = 359;
    if (IsKeyDown(KEY_W)) {
        player.throttle += TROTTLE_RATE;
    }
    if (!IsKeyDown(KEY_W)) { player.throttle -= TROTTLE_RATE;}


    Vector2 currentThrust = { 0, 0};

    if (player.throttle > 0.0f) {
        Vector2 dir = {
            sinf(player.rotation * DEG2RAD),
            -cosf(player.rotation * DEG2RAD)
        };
        float thrustMagnitude = GRAVITY_ACCEL * THRUST_FACTOR * (player.throttle / 100.0f);
        currentThrust = Vector2Scale(dir, thrustMagnitude);
    }

    Vector2 gravity = { 0, GRAVITY_ACCEL };

    player.velocity = Vector2Add(player.velocity, currentThrust);
    player.velocity = Vector2Add(player.velocity, gravity);

    player.position = Vector2Add(player.position, player.velocity);
    
    // Boundary Checking Statements

    float minX = player.sprite.width / 2.0f;
    float maxX = GetScreenWidth() - (player.sprite.width / 2.0f);
    float minY = player.sprite.height / 2.0f;
    float maxY = GetScreenHeight() - (player.sprite.height / 2.0f);

    // Horizontal Boundaries
    if (player.position.x > maxX) {
        player.position.x = maxX;
        player.velocity.x = 0;
    } else if (player.position.x < minX) {
        player.position.x = minX;
        player.velocity.x = 0;
    }
    // Vertical Boundaries 
    if (player.position.y > maxY) {
        player.position.y = maxY;
        player.velocity.y = 0;
    } else if (player.position.y < minY) {
        player.position.y = minY;
        player.velocity.y = 0;
    }
    // Throttle Boundaries
    if (player.throttle < 0) {
        player.throttle = 0;
    }
    if (player.throttle >= 100) {
        player.throttle = 100;
    }
    if (IsWindowResized) SetWindowSize(800, 600);
    // Debug Prints
    printf("X Velocity: %f\n", player.velocity.x);
    printf("Y Velocity: %f\n", player.velocity.y);
    printf("Throttle: %f\n", player.throttle);
    printf("X Position: %f\n", player.position.x);
    printf("Y Position: %f\n", player.position.y);
}
void drawGameplay(void) {
    ClearBackground(BLACK);

    Rectangle source = { 0.0f, 0.0f, (float)player.sprite.width, (float)player.sprite.height };
    Rectangle dest = { player.position.x, player.position.y, (float)player.sprite.width, (float)player.sprite.height };
    Vector2 origin = { (float)player.sprite.width / 2, (float)player.sprite.height / 2 };

    DrawTexturePro(player.sprite, source, dest, origin, player.rotation, WHITE);

    // Later to implement UI for this "scene"
}
void unloadGameplay(void) { // Add an input handler for "Escape" Key to tirgger this function. Probably want something about returning to menu
    UnloadTexture(player.sprite);

    player.fuel = 100;
    player.throttle = 0;
    player.position = (Vector2){ 0, 0};
    player.velocity = (Vector2){ 0, 0};
    player.rotation = 0.0f;

    CloseWindow();
}