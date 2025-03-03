#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "SaveHeader.h"
#include "InputsMenu.h"
#include "omenu.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    SDL_Surface *screen;
    Mix_Chunk *SoundEffect = Mix_LoadWAV("Sound.wav");
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE);
    SaveMenu savemenu, loadmenu;
    undermenu1 multsingmenu;
    undermenu2 inputmenu;
    omain1 Opm;
    int currentVolume = MIX_MAX_VOLUME / 2;
    Inisialise_omain1(&Opm);
    InitializeSaveMenu(&savemenu);
    InitializeLoadMenu(&loadmenu);
    initializeundermenu1(&multsingmenu);
    initializeundermenu2(&inputmenu);


    int quit = 0;
    SDL_Event Event;
    int menu = 2; // 2 and 3 for iheb, 4 and 4 for wassim

    while (!quit)
    {
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_QUIT)
                quit = 1;
            else if (Event.type == SDL_MOUSEMOTION||Event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (menu == 2)
                { // options (salma)
                  if (Event.motion.x >= 454 && Event.motion.x <= 714 && Event.motion.y >= 284 && Event.motion.y <= 334) {
                        if (Opm.decreaseflag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                        Opm.decreaseflag = 1;

                    }
                    else Opm.decreaseflag = 0;

                    if (Event.motion.x >= 770 && Event.motion.x <= 1030 && Event.motion.y >= 284 && Event.motion.y <= 334) {
                        if (Opm.increaseflag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                        Opm.increaseflag = 1;

                    }
                    else Opm.increaseflag = 0;

                    if (Event.motion.x >= 454 && Event.motion.x <= 714 && Event.motion.y >= 438 && Event.motion.y <= 488) {
                        if (Opm.normalflag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                        Opm.normalflag = 1;
                    }
                    else Opm.normalflag = 0;

                    if (Event.motion.x >= 770 && Event.motion.x <= 1030 && Event.motion.y >= 438 && Event.motion.y <= 488) {
                        if (Opm.fullscreenflag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                            Opm.fullscreenflag = 1;
                    }
                    else Opm.fullscreenflag = 0;

                    if (Event.motion.x >= 230 && Event.motion.x <= 420 && Event.motion.y >= 562 && Event.motion.y <= 620) {
                        if (Opm.quitflag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                        Opm.quitflag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN) menu = 3;

                    }
                    else Opm.quitflag = 0;

                    if (Event.button.x >= 454 && Event.button.x <= 714 && Event.button.y >= 284 && Event.button.y <= 334) {
                        currentVolume -= 10;
                        if (currentVolume < 0) currentVolume = 0;
                        	Mix_VolumeMusic(currentVolume);
                    }
                    else if (Event.button.x >= 770 && Event.button.x <= 1030 && Event.button.y >= 284 && Event.button.y <= 334) {
                        currentVolume += 10;
                        if (currentVolume > MIX_MAX_VOLUME) currentVolume = MIX_MAX_VOLUME;
                        	Mix_VolumeMusic(currentVolume);
                    }
                    else if (Event.button.x >= 454 && Event.button.x <= 714 && Event.button.y >= 438 && Event.button.y <= 488) {
                           screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                    }
                    else if (Event.button.x >= 770 && Event.button.x <= 1030 && Event.button.y >= 438 && Event.button.y <= 488) {
                           screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                    }


                }
                if (menu == 3)
                { // multiplay / singleplayer menu (iheb)
                    if(Event.motion.x > 50 && Event.motion.x < 50 + savemenu.SavePos.w &&
                        Event.motion.y > 400 && Event.motion.y < 500 + savemenu.SavePos.h)
                    {
                        if (multsingmenu.spflag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                        multsingmenu.spflag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN) menu = 3;
                    }
                    else multsingmenu.spflag = 0;
                    if (Event.motion.x > 464 && Event.motion.x < 464 + savemenu.SavePos.w &&
                        Event.motion.y > 400 && Event.motion.y < 400 + savemenu.SavePos.h)
                    {
                        if (multsingmenu.mpflag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                        multsingmenu.mpflag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN) menu = 3;
                    }
                    else multsingmenu.mpflag = 0;
                    if (Event.motion.x > 255 && Event.motion.x < 255 + savemenu.SavePos.w&&
                        Event.motion.y > 550 && Event.motion.y < 550 + savemenu.SavePos.h)
                    {
                        if (multsingmenu.reflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                        multsingmenu.reflag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN) menu = 1;
                    }
                    multsingmenu.reflag = 0;
                }
                if (menu == 4)
                { // input bs menu (iheb)
                    if(Event.motion.x > 50 && Event.motion.x < 50 + savemenu.SavePos.w &&
                        Event.motion.y > 300 && Event.motion.y <300 + savemenu.SavePos.h)
                    {
                        if (inputmenu.av1flag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                        inputmenu.av1flag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN);
                    }
                    else inputmenu.av1flag = 0;

                    if (Event.motion.x > 50 && Event.motion.x < 50 + savemenu.SavePos.w &&
                        Event.motion.y > 100 && Event.motion.y < 100 + savemenu.SavePos.h)
                    {
                        if (inputmenu.av3flag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                        inputmenu.av3flag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN);
                    }
                    else inputmenu.av3flag = 0;

                    if (Event.motion.x > 470 && Event.motion.x < 470 + savemenu.SavePos.w&&
                        Event.motion.y > 300 && Event.motion.y < 300 + savemenu.SavePos.h)
                    {
                        if (inputmenu.av2flag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                        inputmenu.av2flag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN);
                    }
                    else inputmenu.av2flag = 0;
                    if (Event.motion.x > 470 && Event.motion.y < 470 + savemenu.SavePos.w &&
                        Event.motion.y > 100 && Event.motion.y < 100 + savemenu.SavePos.h)
                    {
                        if (inputmenu.av4flag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                        inputmenu.av4flag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN) menu = 4;
                    }
                    else inputmenu.av4flag = 0;


                    if (Event.motion.x > 260 && Event.motion.y < 260 + savemenu.SavePos.w &&
                        Event.motion.y > 400 && Event.motion.y < 400 + savemenu.SavePos.h)
                    {
                        if (inputmenu.valflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                        inputmenu.valflag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN) menu = 4;
                    }
                    else inputmenu.valflag = 0;

                }
                if (menu == 5)
                { // Save menu
                    if (Event.motion.x > 100 && Event.motion.x < 100 + savemenu.SavePos.w &&
                        Event.motion.y > 500 && Event.motion.y < 500 + savemenu.SavePos.h)
                    {
                        if (savemenu.SaveFlag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                        savemenu.SaveFlag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN) menu = 3;
                    }
                    else
                        savemenu.SaveFlag = 0;

                    if (Event.motion.x > 400 && Event.motion.x < 400 + savemenu.SavePos.w &&
                        Event.motion.y > 500 && Event.motion.y < 500 + savemenu.SavePos.h)
                    {
                        if (savemenu.NoFlag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                        savemenu.NoFlag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN) menu = 4;
                    }
                    else
                        savemenu.NoFlag = 0;
                }
                else if (menu == 5)
                { // Load menu
                    if (Event.motion.x > 100 && Event.motion.x < 100 + loadmenu.SavePos.w &&
                        Event.motion.y > 500 && Event.motion.y < 500 + loadmenu.SavePos.h)
                    {
                        if (loadmenu.SaveFlag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                        loadmenu.SaveFlag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN) menu = 2;
                    }
                    else
                        loadmenu.SaveFlag = 0;

                    if (Event.motion.x > 400 && Event.motion.x < 400 + loadmenu.SavePos.w &&
                        Event.motion.y > 500 && Event.motion.y < 500 + loadmenu.SavePos.h)
                    {
                        if (loadmenu.NoFlag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                        loadmenu.NoFlag = 1;
                        if (Event.type == SDL_MOUSEBUTTONDOWN) menu = 2;
                    }
                    else
                        loadmenu.NoFlag = 0;
                }
                //else if
            }
        }
        if (menu == 2)
            displayomain1(Opm,screen);
        else if (menu == 3)
            displayundermenu1(multsingmenu, screen);
        else if (menu == 4)
            displayundermenu2(inputmenu, screen);
        else if (menu == 5)
            DisplaySaveMenu(savemenu, screen);
        else if (menu == 6)
            DisplaySaveMenu(loadmenu, screen);

        SDL_Flip(screen);
    }

    return 0;
}
