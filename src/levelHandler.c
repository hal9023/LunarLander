#include "level_handler.h"

float lineThickness = 3.0f;
float collider = 10.0f;

void drawLevel(TERRAIN_LINE terrain[], LANDING_ZONE lz, int terrainSize) {
    // get number of entries within erray
    int arraySize = terrainSize;

    for (int i = 0; i <= arraySize; i++) {
        DrawLineEx(terrain[i].start, terrain[i].end, 3.0f, WHITE);
    }
}

bool collisionDetector(TERRAIN_LINE terrain[], LANDING_ZONE lz, Vector2 landerPos, int terrainSize) {
    int arraySize = terrainSize;

    for (int i = 0; i <= arraySize; i++) {
        if (CheckCollisionCircleLine(landerPos, collider, terrain[i].start, terrain[i].end)) {
            return true; 
        }
    }
    return false; 
}