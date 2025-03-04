#include "header.h"

Mix_Chunk *hoverSound = NULL;
Mix_Chunk *wowSound = NULL;
Mix_Music *backgroundMusic = NULL;

void InitializeMainMenu(MainMenu *menu) {
    menu->bg = LoadImage("back.jpg");
    menu->bgPos.x = 0;
    menu->bgPos.y = 0;

    menu->font = TTF_OpenFont("VT.ttf", 48);
    menu->textColor.r = 25;
    menu->textColor.g = 50;
    menu->textColor.b = 50;

    // Button positions
    int positions[2][2] = {{120, 210}, {320, 210}};
    for(int i=0; i<2; i++) {
        menu->buttons[i][0] = LoadImage("unpress.png");
        menu->buttons[i][1] = LoadImage("press.png");
        menu->buttonPos[i].x = positions[i][0];
        menu->buttonPos[i].y = positions[i][1];
    }

    // Button texts
    const char *labels[2] = {"Puzzle", "Back"};
    for(int i=0; i<2; i++) {
        menu->text[i] = TTF_RenderText_Solid(menu->font, labels[i], menu->textColor);
        menu->textPos[i].x = positions[i][0] + (menu->buttons[i][0]->w - menu->text[i]->w)/2;
        menu->textPos[i].y = positions[i][1] + (menu->buttons[i][0]->h - menu->text[i]->h)/2;
    }

    menu->hoverIndex = -1;
}

void InitializeNumpad(Numpad *numpad) {
    numpad->bg = LoadImage("numpad.jpg");
    numpad->bgPos.x = 0;
    numpad->bgPos.y = 0;

    numpad->font = TTF_OpenFont("VT.ttf", 48);
    numpad->textColor.r = 255;
    numpad->textColor.g = 255;
    numpad->textColor.b = 255;

    int positions[6][2] = {
        {85,190}, {235,190}, {390,190},
        {85,350}, {235,350}, {390,350}
    };

    for(int i=0; i<6; i++) {
        numpad->buttons[i][0] = LoadImage("unpress.png");
        numpad->buttons[i][1] = LoadImage("press.png");
        numpad->buttonPos[i].x = positions[i][0];
        numpad->buttonPos[i].y = positions[i][1];

        char numStr[2] = {'1'+i, '\0'};
        numpad->numbers[i] = TTF_RenderText_Solid(numpad->font, numStr, numpad->textColor);
    }

    numpad->message = NULL;
    numpad->hoverIndex = -1;
}
