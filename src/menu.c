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
#define BUTTON_X (WINDOW_X / 2)

void initMenu(void) { // Add Title text
    InitWindow(WINDOW_X, WINDOW_Y, "Main Menu");
    playButton.sprite = LoadTexture("playbutton.png");
    settingsButton.sprite = LoadTexture("settingsbutton.png");
    quitButton.sprite = LoadTexture("quitwbutton.png");

    playButton.frames = 3;
    settingsButton.frames = 3;
    quitButton.frames = 3;
}
void updateMenu(void) {
    // Menu Navigation Handler

    printf("Play Button State: %d\n", playButton.buttonState);
    printf("Selected Button: %d\n", selectedButton);

    playButton.buttonAction = false;
    settingsButton.buttonAction = false;
    quitButton.buttonAction= false;

    // Button Navigation

    if (IsKeyPressed(KEY_W)) selectedButton --;
    if (IsKeyPressed(KEY_S)) selectedButton ++;

    // Button Highlighting Handler

    if (selectedButton == PLAY_BUTTON) {
        playButton.buttonState = 1;
    } else playButton.buttonState = 0;

    if (selectedButton == SETTINGS_BUTTON) {
        settingsButton.buttonState = 1;
    } else settingsButton.buttonState = 0;

    if (selectedButton == QUIT_BUTTON) {
        quitButton.buttonState = 1;
    } else quitButton.buttonState = 0;

    if ((int)selectedButton < PLAY_BUTTON) selectedButton = QUIT_BUTTON;
    if ((int)selectedButton > QUIT_BUTTON) selectedButton = PLAY_BUTTON;

    // Button Press Handler

    if (IsKeyPressed(KEY_ENTER)) {
        switch (selectedButton) {
            case PLAY_BUTTON:
                playButton.buttonAction = true;
                scene = GAMEPLAY_SCENE;
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
    float frameHeight = (float)playButton.sprite.height / playButton.frames;
    int buttonHeight = (int)frameHeight;
    const char *titleText = "Lunar Lander";

    DrawText(titleText, BUTTON_X - MeasureText(titleText, 20) / 2, 20, 20, RED);
    createButton(&playButton, BUTTON_X, BUTTON_Y, playButton.buttonState);
    createButton(&settingsButton, BUTTON_X, BUTTON_Y + (buttonHeight + BUTTON_SPACING), settingsButton.buttonState);
    createButton(&quitButton, BUTTON_X, BUTTON_Y + 2*(buttonHeight + BUTTON_SPACING), quitButton.buttonState);
}
void unloadMenu(void) {
    UnloadTexture(playButton.sprite);
    UnloadTexture(settingsButton.sprite);
    UnloadTexture(quitButton.sprite);
}
