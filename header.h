#ifndef HEADER_H
#define HEADER_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>

typedef struct {
    SDL_Surface *bg;
    SDL_Rect bgPos;
    SDL_Surface *buttons[2][2]; // [0] normal, [1] hover
    SDL_Rect buttonPos[2];
    SDL_Surface *text[2];
    SDL_Rect textPos[2];
    TTF_Font *font;
    SDL_Color textColor;
    int hoverIndex;
} MainMenu;

typedef struct {
    SDL_Surface *bg;
    SDL_Rect bgPos;
    SDL_Surface *buttons[6][2]; // [0] normal, [1] hover
    SDL_Rect buttonPos[6];
    SDL_Surface *numbers[6];
    SDL_Surface *message;
    TTF_Font *font;
    SDL_Color textColor;
    int hoverIndex;
} Numpad;

// Global resources
extern Mix_Chunk *hoverSound;
extern Mix_Chunk *wowSound;
extern Mix_Music *backgroundMusic;

void InitializeMainMenu(MainMenu *menu);
int RunMainMenu(MainMenu *menu, SDL_Surface *screen);
void InitializeNumpad(Numpad *numpad);
void RunNumpad(Numpad *numpad, SDL_Surface *screen);
SDL_Surface* LoadImage(const char *filename);
void FreeMainMenu(MainMenu *menu);
void FreeNumpad(Numpad *numpad);

#endif
