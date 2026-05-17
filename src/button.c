#include "button.h"

void createButton(BUTTON* button, int screenX, int screenY, int btnState) {
    float frameHeight = (float)button->sprite.height/button->frames;
    button->source = (Rectangle){ 0.0f, 0.0f, (float)button->sprite.width, frameHeight };

    button->bounds = (Rectangle){ screenX/2.0f - button->sprite.width/2.0f, screenY/2.0f - (float)button->sprite.height/button->frames };
    /*
        Button bounds just make it so that the button is clickable
        For my interface, the buttons don't need to be clickable
        So unless I change my mind this will probabl be removed
    */
    button->source.y = btnState*frameHeight;

    DrawTextureRec(button->sprite, button->source, (Vector2){ button->bounds.x, button->bounds.y }, WHITE);

}