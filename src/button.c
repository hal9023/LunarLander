#include "button.h"

void createButton(BUTTON* button, int screenX, int screenY, int btnState) {

    // Note To Self: for EACH button, make sure to initialize frames and texture
    
    float frameHeight = (float)button->sprite.height/button->frames;
    button->source = (Rectangle){ 0.0f, 0.0f, (float)button->sprite.width, frameHeight };
    button->bounds = (Rectangle){ screenX - button->sprite.width/ 2.0f, screenY };
    button->source.y = btnState*frameHeight;
    DrawTextureRec(button->sprite, button->source, (Vector2){ button->bounds.x, button->bounds.y }, WHITE);
}
