#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "InputsMenu.h"

void initializeundermenu1(undermenu1 *um) {
    um->background1 = IMG_Load("rsmback.jpg");
    um->posback1.x = 0;
    um->posback1.y = 0;
    um->musicback1 = Mix_LoadMUS("back1s.mp3");

    um->sp[0] = IMG_Load("nhover.png");
    um->sp[1] = IMG_Load("hover.png");
    um->possp.x = 50;
    um->possp.y = 400;
    um->spflag = 0;

    um->mp[0] = IMG_Load("nhover.png");
    um->mp[1] = IMG_Load("hover.png");
    um->posmp.x = 464;
    um->posmp.y = 400;
    um->mpflag = 0;

    um->re[0] = IMG_Load("nhover.png");
    um->re[1] = IMG_Load("hover.png");
    um->posre.x = 255;
    um->posre.y = 550;
    um->reflag = 0;

    um->postxt1.x = 80;
    um->postxt1.y = 430;
    um->postxt2.x = 495;
    um->postxt2.y = 430;
    um->postxt3.x = 320;
    um->postxt3.y = 570;

    um->sound = Mix_LoadWAV("hh2.wav");
    um->font = TTF_OpenFont("arial.ttf", 24);
    um->textColor.r = 0;
    um->textColor.g = 0;
    um->textColor.b = 0;

    um->textsp = TTF_RenderText_Blended(um->font, "singleplayer", um->textColor);
    um->textmp = TTF_RenderText_Blended(um->font, "multiplayer", um->textColor);
    um->textre = TTF_RenderText_Blended(um->font, "return", um->textColor);
}

void displayundermenu1(undermenu1 um, SDL_Surface *screen) {
    SDL_BlitSurface(um.background1, NULL, screen, &um.posback1);
    SDL_BlitSurface(um.sp[um.spflag], NULL, screen, &um.possp);
    SDL_BlitSurface(um.mp[um.mpflag], NULL, screen, &um.posmp);
    SDL_BlitSurface(um.re[um.reflag], NULL, screen, &um.posre);
    SDL_BlitSurface(um.textsp, NULL, screen, &um.postxt1);
    SDL_BlitSurface(um.textmp, NULL, screen, &um.postxt2);
    SDL_BlitSurface(um.textre, NULL, screen, &um.postxt3);
}

void initializeundermenu2(undermenu2 *um) {
    um->background2 = IMG_Load("back2.jpg");
    um->posback2.x = 0;
    um->posback2.y = 0;
    um->musicback2 = Mix_LoadMUS("back2s.mp3");

    um->av1[0] = IMG_Load("nhover.png");
    um->av1[1] = IMG_Load("hover.png");
    um->posav1.x = 50;
    um->posav1.y = 300;
    um->av1flag = 0;

    um->av3[0] = IMG_Load("nhover.png");
    um->av3[1] = IMG_Load("hover.png");
    um->posav3.x = 50;
    um->posav3.y = 100;
    um->av3flag = 0;

    um->av4[0] = IMG_Load("nhover.png");
    um->av4[1] = IMG_Load("hover.png");
    um->posav4.x = 470;
    um->posav4.y = 100;
    um->av4flag = 0;

    um->av2[0] = IMG_Load("nhover.png");
    um->av2[1] = IMG_Load("hover.png");
    um->posav2.x = 470;
    um->posav2.y = 300;
    um->av2flag = 0;

    um->val[0] = IMG_Load("nhover.png");
    um->val[1] = IMG_Load("hover.png");
    um->posval.x = 260;
    um->posval.y = 400;
    um->valflag = 0;

    um->re1[0] = IMG_Load("nhover.png");
    um->re1[1] = IMG_Load("hover.png");
    um->posre1.x = 500;
    um->posre1.y = 500;
    um->re1flag = 0;

    um->sound = Mix_LoadWAV("hh2.wav");

    um->postxt4.x = 125;
    um->postxt4.y = 330;
    um->postxt8.x = 125;
    um->postxt8.y = 130;
    um->postxt9.x = 540;
    um->postxt9.y = 130;
    um->postxt5.x = 540;
    um->postxt5.y = 330;
    um->postxt6.x = 325;
    um->postxt6.y = 430;
    um->postxt7.x = 565;
    um->postxt7.y = 530;

    um->font = TTF_OpenFont("arial.ttf", 24);
    um->textColor.r = 0;
    um->textColor.g = 0;
    um->textColor.b = 0;

    um->textav3 = TTF_RenderText_Blended(um->font, "avatar1", um->textColor);
    um->textav4 = TTF_RenderText_Blended(um->font, "avatar2", um->textColor);
    um->textin1 = TTF_RenderText_Blended(um->font, "input1", um->textColor);
    um->textin2 = TTF_RenderText_Blended(um->font, "input2", um->textColor);
    um->textval = TTF_RenderText_Blended(um->font, "validate", um->textColor);
    um->textre2 = TTF_RenderText_Blended(um->font, "return", um->textColor);
}

void displayundermenu2(undermenu2 um, SDL_Surface *screen) {
    SDL_BlitSurface(um.background2, NULL, screen, &um.posback2);
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
