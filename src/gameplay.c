#include "gameplay.h"

#define thrustPower 0.015f
#define throttleRate 3
#define rotationRate 0.7f

static Lander player = { 0 };


void initGameplay(void) {
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
        player.rotation -= rotationRate;
    }   
    if (IsKeyDown(KEY_D)) {
        player.rotation += rotationRate;
    }   
    if (player.rotation > 359) player.rotation = 0;
    if (player.rotation < 0) player.rotation = 359;
    if (IsKeyDown(KEY_W)) {
        player.throttle += throttleRate;
    }
    if (!IsKeyDown(KEY_W)) { player.throttle -= throttleRate;}


    Vector2 currentThrust = { 0, 0};

    if (player.throttle > 0.0f) {
        Vector2 dir = {
            sinf(player.rotation * DEG2RAD),
            -cosf(player.rotation * DEG2RAD)
        };
        currentThrust= Vector2Scale(dir, thrustPower * player.throttle); // This could be a problem child idk

    }

    Vector2 gravity = { 0, 0.01f};

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
}
void drawGameplay(void) {
    ClearBackground(BLACK);

    Rectangle source = { 0.0f, 0.0f, (float)player.sprite.width, (float)player.sprite.height };
    Rectangle dest = { player.position.x, player.position.y, (float)player.sprite.width, (float)player.sprite.height };
    Vector2 origin = { (float)player.sprite.width / 2, (float)player.sprite.height / 2 };

    DrawTexturePro(player.sprite, source, dest, origin, player.rotation, WHITE);

    // Later to implement UI for this "scene"
}
void unloadGameplay(void) {
    UnloadTexture(player.sprite);

    player.fuel = 100;
    player.throttle = 0;
    player.position = (Vector2){ 0, 0};
    player.velocity = (Vector2){ 0, 0};
    player.rotation = 0.0f;
}