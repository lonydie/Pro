#include "functionBM.h"

// Initialize Menu1
void initMenu1(Menu1 *m) {
    m->background = IMG_Load("BackGrounds/SubMenu.png"); // Load background image
    m->posBackground.x = 0;                  // Set background position (top-left corner)
    m->posBackground.y = 0;
    m->button[0] = IMG_Load("Buttons/Button.png");   // Load normal button image
    m->button[1] = IMG_Load("Buttons/HoveredOverButton.png");    // Load hover button image
    m->posButton.x = 100;                    // Set button position
    m->posButton.y = 400;
    m->posButton.h = 87;
    m->posButton.w = 218;
    m->buttonFlag = 0;                       // Start with normal button
}

// Display Menu1
void displayMenu1(Menu1 m, SDL_Surface *screen) {
    SDL_BlitSurface(m.background, NULL, screen, &m.posBackground); // Draw background
    SDL_BlitSurface(m.button[m.buttonFlag], NULL, screen, &m.posButton); // Draw button
}

// Initialize Menu2
void initMenu2(Menu2 *m) {
    m->background = IMG_Load("BackGrounds/SubMenu");  // Load background image
    m->posBackground.x = 0;                   // Set background position
    m->posBackground.y = 0;

    m->button1[0] = IMG_Load("Buttons/Button.png");    // Load normal back button
    m->button1[1] = IMG_Load("Buttons/HoveredOverButton.png");      // Load hover back button
    m->posButton1.x = 100;                    // Set back button position
    m->posButton1.y = 300;
    m->button1Flag = 0;                       // Start with normal button
    m->button2[0] = IMG_Load("Buttons/Button.png");   // Load normal do-nothing button
    m->button2[1] = IMG_Load("Buttons/HoveredOverButton.png");    // Load hover do-nothing button
    m->posButton2.x = 300;                    // Set do-nothing button position
    m->posButton2.y = 300;
    m->button2Flag = 0;                       // Start with normal button
       // Load hover sound
}

// Display Menu2
void displayMenu2(Menu2 m, SDL_Surface *screen) {
    SDL_BlitSurface(m.background, NULL, screen, &m.posBackground); // Draw				 background
    SDL_BlitSurface(m.button1[m.button1Flag], NULL, screen, &m.posButton1); // Draw back button
    SDL_BlitSurface(m.button2[m.button2Flag], NULL, screen, &m.posButton2); // Draw do-nothing button
}
