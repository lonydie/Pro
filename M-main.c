#include "M-main.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

void initmain(mainmenu *m, int fullscreen){
m->back[0]=IMG_Load("BackGrounds/MainMenu.png");
m->back[1]=IMG_Load("BackGrounds/MainMenu70.png");
m->posback.x=0;
m->posback.y=0;
m->backflag = fullscreen;
m->play[0]=IMG_Load("Buttons/MainMenuButton.jpeg");
m->play[1]=IMG_Load("Buttons/HoverOverMainMenuButton.jpeg");
m->posplay.x= m->back[fullscreen]->w / 19.2;
m->posplay.y=m->back[fullscreen]->h / 5;
m->playflag=0;
m->option[0]=IMG_Load("Buttons/MainMenuButton.jpeg");
m->option[1]=IMG_Load("Buttons/HoverOverMainMenuButton.jpeg");
m->posoption.x=m->back[fullscreen]->w / 19.2;
m->posoption.y=m->posplay.y + 100;
m->optionflag=0;
m->high[0]=IMG_Load("Buttons/MainMenuButton.jpeg");
m->high[1]=IMG_Load("Buttons/HoverOverMainMenuButton.jpeg");
m->poshigh.x=m->back[fullscreen]->w / 19.2;
m->poshigh.y=m->posoption.y + 100;
m->highflag=0;
m->history[0]=IMG_Load("Buttons/MainMenuButton.jpeg");
m->history[1]=IMG_Load("Buttons/HoverOverMainMenuButton.jpeg");
m->poshistory.x= m->back[fullscreen]->w / 19.2;
m->poshistory.y=m->poshigh.y + 100;
m->historyflag=0;
m->exit[0]=IMG_Load("Buttons/MainMenuButton.jpeg");
m->exit[1]=IMG_Load("Buttons/HoverOverMainMenuButton.jpeg");
m->posexit.x=m ->back[fullscreen]->w / 19.2;
m->posexit.y=m->poshistory.y + 150;
m->exitflag=0;
m->font=TTF_OpenFont("Fonts/VT323-Regular.ttf",24);
m->textColor.r = 0;
m->textColor.g = 0;
m->textColor.b = 255;
m->postxt1.x = m->posplay.x + 50;
m->postxt1.y = m->posplay.y + 20;
m->postxt2.x = m->posoption.x + 50;
m->postxt2.y = m->posoption.y + 20;
m->postxt3.x = m->poshigh.x + 50;
m->postxt3.y = m->poshigh.y + 20;
m->postxt4.x = m->poshistory.x + 50;
m->postxt4.y = m->poshistory.y + 20;
m->postxt5.x = m->posexit.x + 50;
m->postxt5.y = m->posexit.y + 20;
m->textplay=TTF_RenderText_Blended(m->font,"play",m->textColor);
m->textoption=TTF_RenderText_Blended(m->font,"option",m->textColor);
m->texthigh=TTF_RenderText_Blended(m->font,"high score",m->textColor);
m->texthistory=TTF_RenderText_Blended(m->font,"history",m->textColor);
m->textexit=TTF_RenderText_Blended(m->font,"exit",m->textColor);
}



void displaymain(mainmenu m, SDL_Surface *screen){
SDL_BlitSurface(m.back[m.backflag], NULL,screen, &m.posback);
SDL_BlitSurface(m.play[m.playflag],NULL,screen,&m.posplay);
SDL_BlitSurface(m.option[m.optionflag], NULL,screen, &m.posoption);
SDL_BlitSurface(m.high[m.highflag], NULL,screen, &m.poshigh);
SDL_BlitSurface(m.history[m.historyflag], NULL,screen, &m.poshistory);
SDL_BlitSurface(m.exit[m.exitflag], NULL,screen, &m.posexit);
SDL_BlitSurface(m.textplay,NULL,screen,&m.postxt1);
SDL_BlitSurface(m.textoption,NULL,screen,&m.postxt2);
SDL_BlitSurface(m.texthigh,NULL,screen,&m.postxt3);
SDL_BlitSurface(m.texthistory,NULL,screen,&m.postxt4);
SDL_BlitSurface(m.textexit,NULL,screen,&m.postxt5);
}
// Global variables
/*SDL_Surface *screen;
SDL_Surface *background;
SDL_Surface *textSurface;
TTF_Font *font;
SDL_Color textColor = {255, 255, 255}; // White color
SDL_Color shadowColor = {0, 100, 0};  // Dark green color for shadow
Mix_Music *backgroundMusic;
Mix_Chunk *hoverSound = NULL;

Button buttons[5] = {
    {{125, 300, 200, 50}, "Play"},
    {{125, 400, 200, 50}, "Options"},
    {{125, 500, 200, 50}, "Score"},
    {{125, 600, 200, 50}, "History"},
    {{125, 700, 200, 50}, "Exit"}
};

// Initialize SDL and related subsystems

// Load assets for the main menu (images, fonts, music)
int initializeSAFI() {

    background = IMG_Load("menu_bg.png");
    if (background == NULL) {
        fprintf(stderr, "Failed to load background image: %s\n", IMG_GetError());
        return 0;
    }

    backgroundMusic = Mix_LoadMUS("menu_bg_music.mp3");
    if (backgroundMusic == NULL) {
        fprintf(stderr, "Failed to load background music: %s\n", Mix_GetError());
        return 0;
    }

    font = TTF_OpenFont("VT323-Regular.ttf", 40);
    if (font == NULL) {
        fprintf(stderr, "Failed to load font: %s\n", TTF_GetError());
        return 0;
    }

    hoverSound = Mix_LoadWAV("paper_hover_sfx.wav");
    if (hoverSound == NULL) {
        fprintf(stderr, "Failed to load hover sound effect: %s\n", Mix_GetError());
        return 0;
    }

    // Play background music in a loop
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2); // 50% volume
    Mix_PlayMusic(backgroundMusic, -1);

    return 1;
}

// Render text with a shadow effect
void renderTextWithShadow(const char *text, int x, int y) {
    // Render shadow text (dark green)
    textSurface = TTF_RenderText_Solid(font, text, shadowColor);
    if (textSurface == NULL) {
        fprintf(stderr, "Failed to render shadow text: %s\n", TTF_GetError());
        return;
    }
    SDL_Rect shadowRect = {x + 2, y + 2, textSurface->w, textSurface->h};
    SDL_BlitSurface(textSurface, NULL, screen, &shadowRect);
    SDL_FreeSurface(textSurface);

    // Render main text (white)
    textSurface = TTF_RenderText_Solid(font, text, textColor);
    if (textSurface == NULL) {
        fprintf(stderr, "Failed to render main text: %s\n", TTF_GetError());
        return;
    }
    SDL_Rect textRect = {x, y, textSurface->w, textSurface->h};
    SDL_BlitSurface(textSurface, NULL, screen, &textRect);
    SDL_FreeSurface(textSurface);
}

// Render all buttons
void renderButtons() {
    for (int i = 0; i < 5; i++) {
        SDL_FillRect(screen, &buttons[i].rect, SDL_MapRGB(screen->format, 0, 0, 0)); // Draw button background
        renderTextWithShadow(buttons[i].label, buttons[i].rect.x, buttons[i].rect.y); // Draw button label with shadow
    }
}

// Handle button click events
void handleButtonClick(int x, int y) {
    for (int i = 0; i < 5; i++) {
        if (x >= buttons[i].rect.x && x <= buttons[i].rect.x + buttons[i].rect.w &&
            y >= buttons[i].rect.y && y <= buttons[i].rect.y + buttons[i].rect.h) {
            printf("Button clicked: %s\n", buttons[i].label);
            if (strcmp(buttons[i].label, "Exit") == 0) {
                SDL_Event quitEvent;
                quitEvent.type = SDL_QUIT;
                SDL_PushEvent(&quitEvent);
            }
        }
    }
}*/

// Check for button hover and play sound effect
//IM GONNA KILL MYSELF AUUUGH, THIS IS A CRY FOR HELP
/*void checkButtonHover(int x, int y) {
    // Track the last hovered button to avoid playing the sound repeatedly
    static int lastHoveredButton = -1;

    for (int i = 0; i < 5; i++) {
        if (x >= buttons[i].rect.x && x <= buttons[i].rect.x + buttons[i].rect.w &&
            y >= buttons[i].rect.y && y <= buttons[i].rect.y + buttons[i].rect.h) {
            // If the mouse is over a new button, play the sound
            if (lastHoveredButton != i) {

printf("Hovering over button: %s\n", buttons[i].label);

                Mix_PlayChannel(-1, hoverSound, 0); // Play the sound effect
                lastHoveredButton = i; // Update the last hovered button
            }
            return; // Exit the function after finding the hovered button
        }
    }

    // If the mouse is not over any button, reset the last hovered button
    lastHoveredButton = -1;
}
*/
// Clean up resources
/*void cleanup() {
    SDL_FreeSurface(background);
    TTF_CloseFont(font);
    TTF_Quit();
    Mix_FreeMusic(backgroundMusic);
    if (hoverSound != NULL) {
        Mix_FreeChunk(hoverSound);
        hoverSound = NULL;
    }
    Mix_CloseAudio();
    SDL_Quit();
}*/
