#include "menu.h"

SELECTED_BUTTON selectedButton = PLAY_BUTTON;

static BUTTON playButton = { .buttonAction = false, .buttonState = NORMAL };
static BUTTON settingsButton = { .buttonAction = false, .buttonState = NORMAL };
static BUTTON quitButton = { .buttonAction = false, .buttonState = NORMAL };

#define BUTTON_SPACING 25 // pixels between buttons
#define BUTTON_PADDING 20 // pixels between the edge of the frame and button
#define BUTTON_Y 100 // how far down the button should be 
#define WINDOW_X 300
#define WINDOW_Y 400

void initMenu(void) { // Add Title text
    InitWindow(WINDOW_X, WINDOW_Y, "Main Menu");
    playButton.sprite = LoadTexture("button.png");
    playButton.frames = 3;
}
void updateMenu(void) {
    // Menu Navigation Handler

    playButton.buttonAction = false;
    settingsButton.buttonAction = false;
    quitButton.buttonAction= false;

    // Button Navigation

    if (IsKeyPressed(KEY_UP || KEY_W)) {
        selectedButton --;
    }
    if (IsKeyPressed(KEY_DOWN || KEY_W)) {
        selectedButton ++;
    }

    // Button Highlighting Handler

    if (selectedButton == PLAY_BUTTON) {
        playButton.buttonState = 1;
    } else playButton.buttonState = 0;

    if (selectedButton == SETTINGS_BUTTON) {
        settingsButton.buttonState = 1;
    } else playButton.buttonState = 0;

    if (selectedButton == QUIT_BUTTON) {
        quitButton.buttonState = 1;
    } else quitButton.buttonState = 0;

    // Button Press Handler

    if (IsKeyPressed(KEY_ENTER)) {
        switch (selectedButton) {
            case PLAY_BUTTON:
                playButton.buttonAction = true;
                scene = LEVEL_SELECTOR;
                break;
            case SETTINGS_BUTTON:
                settingsButton.buttonAction = true;
                scene = SETTINGS;
                break;
            case QUIT_BUTTON: // Could add dialog handler
                quitButton.buttonAction = false;
                exit(0);
                break;
        }
    }
}
void drawMenu(void) {
    DrawText("Text", WINDOW_X/2, WINDOW_Y-20, 20, RED);
    createButton(&playButton, WINDOW_X, WINDOW_Y, playButton.buttonState);
}
void unloadMenu(void) {

}
