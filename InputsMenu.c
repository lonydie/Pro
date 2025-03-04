#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "InputsMenu.h"

void initializeundermenu1(undermenu1 *um, int fullscreen) {
    um->background1[0] = IMG_Load("BackGrounds/SubMenu.png");
    um->background1[1] = IMG_Load("BackGrounds/SubMenu70.png");
    um->backflag = fullscreen;

    um->posback1.x = 0;
    um->posback1.y = 0;
    um->sp[0] = IMG_Load("Buttons/Button.png");
    um->sp[1] = IMG_Load("Buttons/HoveredOverButton.png");
    um->possp.x = um->background1[fullscreen]->w / 1.92;
    um->possp.y = um->background1[fullscreen]->h / 2.7;
    um->spflag = 0;


    um->mp[0] = IMG_Load("Buttons/Button.png");
    um->mp[1] = IMG_Load("Buttons/HoveredOverButton.png");
    um->posmp.x = um->background1[fullscreen]->w / 3.2;
    um->posmp.y = um->background1[fullscreen]->h / 2.7;
    um->mpflag = 0;


    um->re[0] = IMG_Load("Buttons/Button.png");
    um->re[1] = IMG_Load("Buttons/HoveredOverButton.png");
    um->posre.x = um->background1[fullscreen]->w / 4;
    um->posre.y = um->background1[fullscreen]->h / 1.6;
    um->reflag = 0;


    um->postxt1.x = um->possp.x + 50;
    um->postxt1.y = um->possp.y + 20;
    um->postxt2.x = um->posmp.x + 50;
    um->postxt2.y = um->posmp.y + 20;
    um->postxt3.x = um->posre.x + 50;
    um->postxt3.y = um->posre.y + 20;


    um->font = TTF_OpenFont("Fonts/VT323-Regular.ttf", 30);
    um->textColor.r = 0;
    um->textColor.g = 0;
    um->textColor.b = 0;

    um->textsp = TTF_RenderText_Blended(um->font, "singleplayer", um->textColor);
    um->textmp = TTF_RenderText_Blended(um->font, "multiplayer", um->textColor);
    um->textre = TTF_RenderText_Blended(um->font, "return", um->textColor);
}

void displayundermenu1(undermenu1 um, SDL_Surface *screen) {
    SDL_BlitSurface(um.background1[um.backflag], NULL, screen, &um.posback1);
    SDL_BlitSurface(um.sp[um.spflag], NULL, screen, &um.possp);
    SDL_BlitSurface(um.mp[um.mpflag], NULL, screen, &um.posmp);
    SDL_BlitSurface(um.re[um.reflag], NULL, screen, &um.posre);
    SDL_BlitSurface(um.textsp, NULL, screen, &um.postxt1);
    SDL_BlitSurface(um.textmp, NULL, screen, &um.postxt2);
    SDL_BlitSurface(um.textre, NULL, screen, &um.postxt3);
}

void initializeundermenu2(undermenu2 *um, int fullscreen) {
    um->background2[0] = IMG_Load("BackGrounds/SubMenu.png");
    um->background2[1] = IMG_Load("BackGrounds/SubMenu70.png");
    um->posback2.x = 0;
    um->posback2.y = 0;
    um->backflag = fullscreen;


    um->av1[0] = IMG_Load("Buttons/Button.png");
    um->av1[1] = IMG_Load("Buttons/HoveredOverButton.png");
    um->posav1.x = um->background2[fullscreen]->w / 1.8;
    um->posav1.y = um->background2[fullscreen]->h / 2;
    um->av1flag = 0;
  ;

    um->av3[0] = IMG_Load("Buttons/Button.png");
    um->av3[1] = IMG_Load("Buttons/HoveredOverButton.png");
    um->posav3.x = um->background2[fullscreen]->w / 3.2;
    um->posav3.y = um->background2[fullscreen]->h / 2.8;
    um->av3flag = 0;


    um->av4[0] = IMG_Load("Buttons/Button.png");
    um->av4[1] = IMG_Load("Buttons/HoveredOverButton.png");
    um->posav4.x = um->background2[fullscreen]->w / 1.8;
    um->posav4.y = um->background2[fullscreen]->h / 2.8;
    um->av4flag = 0;


    um->av2[0] = IMG_Load("Buttons/Button.png");
    um->av2[1] = IMG_Load("Buttons/HoveredOverButton.png");
    um->posav2.x = um->background2[fullscreen]->w / 3.2;
    um->posav2.y = um->background2[fullscreen]->h / 2;
    um->av2flag = 0;


    um->val[0] = IMG_Load("Buttons/Button.png");
    um->val[1] = IMG_Load("Buttons/HoveredOverButton.png");
    um->posval.x = um->background2[fullscreen]->w / 1.7;
    um->posval.y = um->background2[fullscreen]->h / 1.6;
    um->valflag = 0;

    um->re1[0] = IMG_Load("Buttons/Button.png");
    um->re1[1] = IMG_Load("Buttons/HoveredOverButton.png");
    um->posre1.x = um->background2[fullscreen]->w / 4;
    um->posre1.y = um->background2[fullscreen]->h / 1.6;
    um->re1flag = 0;




    um->postxt4.x = um->posav2.x + 50;
    um->postxt4.y = um->posav2.y + 20;
    um->postxt8.x = um->posav3.x + 50;
    um->postxt8.y = um->posav3.y + 20;
    um->postxt9.x = um->posav4.x + 50;
    um->postxt9.y = um->posav4.y + 20;
    um->postxt5.x = um->posav1.x + 50;
    um->postxt5.y = um->posav1.y + 20;
    um->postxt6.x = um->posval.x + 50;
    um->postxt6.y = um->posval.y + 20;
    um->postxt7.x = um->posre1.x + 50;
    um->postxt7.y = um->posre1.y + 20;

    um->font = TTF_OpenFont("Fonts/VT323-Regular.ttf", 30);
    um->textColor.r = 0;
    um->textColor.g = 0;
    um->textColor.b = 0;

    um->textav3 = TTF_RenderText_Blended(um->font, "avatar 1", um->textColor);
    um->textav4 = TTF_RenderText_Blended(um->font, "avatar2", um->textColor);
    um->textin1 = TTF_RenderText_Blended(um->font, "input1", um->textColor);
    um->textin2 = TTF_RenderText_Blended(um->font, "input2", um->textColor);
    um->textval = TTF_RenderText_Blended(um->font, "validate", um->textColor);
    um->textre2 = TTF_RenderText_Blended(um->font, "return", um->textColor);
}

void displayundermenu2(undermenu2 um, SDL_Surface *screen) {
    SDL_BlitSurface(um.background2[um.backflag], NULL, screen, &um.posback2);
    SDL_BlitSurface(um.av1[um.av1flag], NULL, screen, &um.posav1);
    SDL_BlitSurface(um.av2[um.av2flag], NULL, screen, &um.posav2);
    SDL_BlitSurface(um.re1[um.re1flag], NULL, screen, &um.posre1);
    SDL_BlitSurface(um.val[um.valflag], NULL, screen, &um.posval);
    SDL_BlitSurface(um.av3[um.av3flag], NULL, screen, &um.posav3);
    SDL_BlitSurface(um.av4[um.av4flag], NULL, screen, &um.posav4);
    SDL_BlitSurface(um.textav3, NULL, screen, &um.postxt8);
    SDL_BlitSurface(um.textav4, NULL, screen, &um.postxt9);
    SDL_BlitSurface(um.textin1, NULL, screen, &um.postxt4);
    SDL_BlitSurface(um.textin2, NULL, screen, &um.postxt5);
    SDL_BlitSurface(um.textval, NULL, screen, &um.postxt6);
    SDL_BlitSurface(um.textre2, NULL, screen, &um.postxt7);
}
