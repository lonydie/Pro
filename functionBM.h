#ifndef FUNCTIONBM_H
#define FUNCTIONBM_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

// Structure for Menu1 (First Menu)
typedef struct {
    SDL_Surface *background;
    SDL_Rect posBackground;
    SDL_Surface *button[2]; // Normal and hover buttons
    SDL_Rect posButton;
    int buttonFlag; // 0 = normal, 1 = hover
 // Hover sound
} Menu1;

// Structure for Menu2 (Second Menu)
typedef struct {
    SDL_Surface *background;
    SDL_Rect posBackground;
    Mix_Music *music; // Background music
    SDL_Surface *button1[2]; // Back button
    SDL_Rect posButton1;
    int button1Flag; // 0 = normal, 1 = hover
    SDL_Surface *button2[2]; // Do-nothing button
    SDL_Rect posButton2;
    int button2Flag; // 0 = normal, 1 = hover
 // Hover sound
} Menu2;

// Function prototypes
void initMenu1(Menu1 *m);
void displayMenu1(Menu1 m, SDL_Surface *screen);
void initMenu2(Menu2 *m);
void displayMenu2(Menu2 m, SDL_Surface *screen);

#endif
