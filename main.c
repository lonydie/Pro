#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "SaveHeader.h"
#include "InputsMenu.h"
#include "omenu.h"
#include "M-main.h"
#include "functionBM.h"
#include "header.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    SDL_Surface *screen;
    Mix_Chunk *SoundEffect = Mix_LoadWAV("Sounds and music/hov.wav");
    screen = SDL_SetVideoMode(1344, 756, 32, SDL_HWSURFACE);
    SaveMenu savemenu, loadmenu;
    undermenu1 multsingmenu;
    undermenu2 inputmenu;
    omain1 Opm;
    mainmenu main;
    Menu1 Usermenu;
    Menu2 Highmenu;
    /*MainMenu ayoub;
    Numpad ayuib;*/
    int currentVolume = MIX_MAX_VOLUME;


    initmain(&main, 1);
    Inisialise_omain1(&Opm, 1);
    InitializeSaveMenu(&savemenu);
    InitializeLoadMenu(&loadmenu);
    initializeundermenu1(&multsingmenu, 1);
    initializeundermenu2(&inputmenu, 1);
    initMenu1(&Usermenu);
    initMenu2(&Highmenu);

    /*InitializeMainMenu(&ayoub);
    InitializeNumpad(&ayuib);*/
    Mix_Music *sound;
	sound = Mix_LoadMUS("Sounds and music/BackGroundMusic.mp3");
    Mix_PlayMusic(sound, -1);
    int quit = 0;
    SDL_Event Event;
    int menu = 1;

    while (!quit)
    {
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_QUIT)
                quit = 1;
            else if (Event.type == SDL_MOUSEMOTION)
            {

                switch (menu)
                {
                case 1:
                        //// Button 1: Play button
                        if (Event.motion.x > main.posplay.x && Event.motion.x < main.posplay.x +  main.play[0]->w&&
                            Event.motion.y > main.posplay.y && Event.motion.y < main.posplay.y + main.play[0]->h)
                        {
                            if (main.playflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            main.playflag = 1;
                        }
                        else main.playflag = 0;


                        // Button 2: Option button
                        if (Event.motion.x > main.posoption.x && Event.motion.x < main.posoption.x + main.play[0]->w&&
                            Event.motion.y > main.posoption.y && Event.motion.y < main.posoption.y + main.play[0]->h)
                        {
                            if (main.optionflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            main.optionflag = 1;
                        }
                        else main.optionflag = 0;


                        // Button 3: Highscores button
                        if (Event.motion.x > main.poshigh.x && Event.motion.x < main.poshigh.x + main.play[0]->w &&
                            Event.motion.y > main.poshigh.y && Event.motion.y < main.poshigh.y + main.play[0]->h)
                        {
                            if (main.highflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            main.highflag = 1;
                        }
                        else main.highflag = 0;


                        // Button 4: History button
                        if (Event.motion.x > main.poshistory.x && Event.motion.x < main.poshistory.x + main.play[0]->w &&
                            Event.motion.y > main.poshistory.y && Event.motion.y < main.poshistory.y + main.play[0]->h)
                        {
                            if (main.historyflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            main.historyflag = 1;
                        }
                        else main.historyflag = 0;


                        // Button 5: Exit button
                        if (Event.motion.x > main.posexit.x && Event.motion.x < main.posexit.x + main.play[0]->w &&
                            Event.motion.y > main.posexit.y && Event.motion.y < main.posexit.y + main.play[0]->h)
                        {
                            if (main.exitflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            main.exitflag = 1;
                        }
                        else main.exitflag = 0;
                        break;


               case 2:
                        //options menu
                        if (Event.motion.x > Opm.decreasepos.x && Event.motion.x < Opm.decreasepos.x + Opm.decrease[0]->w &&
                            Event.motion.y > Opm.decreasepos.y && Event.motion.y < Opm.decreasepos.y + Opm.decrease[0]->h)
                        {
                            if (Opm.decreaseflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            Opm.decreaseflag = 1;
                        }
                        else Opm.decreaseflag = 0;

                        if (Event.motion.x > Opm.increasepos.x && Event.motion.x < Opm.increasepos.x + Opm.increase[0]->w &&
                            Event.motion.y > Opm.increasepos.y && Event.motion.y < Opm.increasepos.y + Opm.increase[0]->h)
                        {
                            if (Opm.increaseflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            Opm.increaseflag = 1;
                        }
                        else Opm.increaseflag = 0;

                        if (Event.motion.x > Opm.normalpos.x && Event.motion.x < Opm.normalpos.x + Opm.normal[0]->w &&
                            Event.motion.y > Opm.normalpos.y && Event.motion.y < Opm.normalpos.y + Opm.normal[0]->h)
                        {
                            if (Opm.normalflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            Opm.normalflag = 1;
                        }
                        else Opm.normalflag = 0;

                        if (Event.motion.x > Opm.fullscreenpos.x && Event.motion.x < Opm.fullscreenpos.x + Opm.fullscreen[0]->w &&
                            Event.motion.y > Opm.fullscreenpos.y && Event.motion.y < Opm.fullscreenpos.y + Opm.fullscreen[0]->h)
                        {
                            if (Opm.fullscreenflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            Opm.fullscreenflag = 1;
                        }
                        else Opm.fullscreenflag = 0;

                        if (Event.motion.x > Opm.quitpos.x && Event.motion.x < Opm.quitpos.x + Opm.quit[0]->w &&
                            Event.motion.y > Opm.quitpos.y && Event.motion.y < Opm.quitpos.y + Opm.quit[0]->h)
                        {
                            if (Opm.increaseflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            Opm.quitflag = 1;
                        }
                        else Opm.quitflag = 0;
                        break;


                case 3:
                        // multiplayer / singleplayer menu (iheb)
                        if(Event.motion.x > multsingmenu.possp.x && Event.motion.x < multsingmenu.possp.x + multsingmenu.sp[0]->w &&
                            Event.motion.y > multsingmenu.possp.y && Event.motion.y < multsingmenu.possp.y + multsingmenu.sp[0]->h)
                        {
                            if (multsingmenu.spflag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                            multsingmenu.spflag = 1;
                        }
                        else multsingmenu.spflag = 0;

                        if (Event.motion.x > multsingmenu.posmp.x && Event.motion.x < multsingmenu.posmp.x + multsingmenu.mp[0]->w &&
                            Event.motion.y > multsingmenu.posmp.y && Event.motion.y < multsingmenu.posmp.y + multsingmenu.mp[0]->h)
                        {
                            if (multsingmenu.mpflag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                            multsingmenu.mpflag = 1;

                        }
                        else multsingmenu.mpflag = 0;

                        if (Event.motion.x > multsingmenu.posre.x && Event.motion.x < multsingmenu.posre.x + multsingmenu.re[0]->w&&
                            Event.motion.y > multsingmenu.posre.y && Event.motion.y < multsingmenu.posre.y + multsingmenu.re[0]->h)
                        {
                            if (multsingmenu.reflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            multsingmenu.reflag = 1;

                        }
                        else multsingmenu.reflag = 0;
                        break;


                case 4:
                        // input bs menu (iheb)
                        if(Event.motion.x > inputmenu.posav1.x && Event.motion.x < inputmenu.posav1.x + inputmenu.av1[0]->w &&
                            Event.motion.y > inputmenu.posav1.y && Event.motion.y <inputmenu.posav1.y + inputmenu.av1[0]->h)
                        {
                            if (inputmenu.av1flag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                            inputmenu.av1flag = 1;

                        }
                        else inputmenu.av1flag = 0;

                        if (Event.motion.x > inputmenu.posav3.x && Event.motion.x < inputmenu.posav3.x + inputmenu.av3[0]->w &&
                            Event.motion.y > inputmenu.posav3.y && Event.motion.y < inputmenu.posav3.y + inputmenu.av3[0]->h)
                        {
                            if (inputmenu.av3flag == 0 ) Mix_PlayChannel(-1, SoundEffect, 0);
                            inputmenu.av3flag = 1;

                        }
                        else inputmenu.av3flag = 0;

                        if (Event.motion.x > inputmenu.posav2.x && Event.motion.x < inputmenu.posav2.x + inputmenu.av2[0]->w &&
                            Event.motion.y > inputmenu.posav2.y && Event.motion.y < inputmenu.posav2.y + inputmenu.av2[0]->h)
                        {
                            if (inputmenu.av2flag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            inputmenu.av2flag = 1;

                        }
                        else inputmenu.av2flag = 0;

                        if (Event.motion.x > inputmenu.posav4.x && Event.motion.x < inputmenu.posav4.x + inputmenu.av4[0]->w &&
                            Event.motion.y > inputmenu.posav4.y && Event.motion.y < inputmenu.posav4.y + inputmenu.av4 [0]->h)
                        {
                            if (inputmenu.av4flag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            inputmenu.av4flag = 1;

                        }
                        else inputmenu.av4flag = 0;


                        if (Event.motion.x > inputmenu.posval.x && Event.motion.x < inputmenu.posval.x + inputmenu.val[0]->w &&
                            Event.motion.y > inputmenu.posval.y && Event.motion.y < inputmenu.posval.y + inputmenu.val[0]->h)
                        {
                            if (inputmenu.valflag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            inputmenu.valflag = 1;

                        }
                        else inputmenu.valflag = 0;

                        if (Event.motion.x > inputmenu.posre1.x && Event.motion.x < inputmenu.posre1.x + inputmenu.re1[0]->w &&
                            Event.motion.y > inputmenu.posre1.y && Event.motion.y < inputmenu.posre1.y + inputmenu.re1[0]->h)
                        {
                            if (inputmenu.re1flag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            inputmenu.re1flag = 1;

                        }
                        else inputmenu.re1flag = 0;
                        break;


                case 5:
                        // Save menu (wassim)
                        if (Event.motion.x > savemenu.SavePos.x && Event.motion.x < savemenu.SavePos.x + savemenu.Save[0]->w &&
                            Event.motion.y > savemenu.SavePos.y && Event.motion.y < savemenu.SavePos.y + savemenu.Save[0]->h)
                        {
                            if (savemenu.SaveFlag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            savemenu.SaveFlag = 1;
                        }
                        else savemenu.SaveFlag = 0;

                        if (Event.motion.x > savemenu.NoPos.x && Event.motion.x < savemenu.NoPos.x + savemenu.No[0]->w &&
                            Event.motion.y > savemenu.NoPos.y && Event.motion.y < savemenu.NoPos.y + savemenu.No[0]->h)
                        {
                            if (savemenu.NoFlag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            savemenu.NoFlag = 1;

                        }
                        else savemenu.NoFlag = 0;
                        break;

                case 6:
                        // Load menu (wassim)
                        if (Event.motion.x > loadmenu.SavePos.x && Event.motion.x < loadmenu.SavePos.x + loadmenu.Save[0]->w &&
                            Event.motion.y > loadmenu.SavePos.y && Event.motion.y < loadmenu.SavePos.y + loadmenu.Save[0]->h)
                        {
                            if (loadmenu.SaveFlag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            loadmenu.SaveFlag = 1;

                        }
                        else loadmenu.SaveFlag = 0;

                        if (Event.motion.x > savemenu.NoPos.x && Event.motion.x < savemenu.NoPos.x + savemenu.No[0]->w &&
                            Event.motion.y > savemenu.NoPos.y && Event.motion.y < savemenu.NoPos.y + savemenu.No[0]->h)
                        {
                            if (loadmenu.NoFlag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            loadmenu.NoFlag = 1;
                            if (Event.type == SDL_MOUSEBUTTONDOWN) menu = 6;
                        }
                        else loadmenu.NoFlag = 0;
                        break;

                case 7:
                        //username menu (mounib)
                        if (Event.motion.x > 100 && Event.motion.x < 100 + 281 &&
                            Event.motion.y > 400 && Event.motion.y < 400 + 218)
                        {
                            if (Usermenu.buttonFlag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            Usermenu.buttonFlag = 1;
                        }
                        else Usermenu.buttonFlag = 0;


                case 8:
                        //actual high menu
                        if (Event.motion.x > 100 && Event.motion.x < 100 + 222 &&
                        Event.motion.y > 300 && Event.motion.y < 300 + 82)
                        {
                            if (Highmenu.button1Flag == 0) Mix_PlayChannel(-1, SoundEffect, 0);
                            Highmenu.button1Flag = 1;
                        }
                        else Highmenu.button1Flag = 0;

                        if (Event.motion.x > 300 && Event.motion.x < 300 + 222 &&
                            Event.motion.y > 300 && Event.motion.y < 300 + 82)
                        {
                            if (Highmenu.button2Flag == 0) Mix_PlayChannel(-1 , SoundEffect, 0);
                            Highmenu.button2Flag = 1;
                        }
                        else Highmenu.button2Flag = 0;
            }


            /*if (menu == 9)
            {
                RunMainMenu(&ayoub, screen);
            }*/
        }










           //////////////////////////////////////////////////////////////////////////////////

            if (Event.type == SDL_MOUSEBUTTONDOWN && Event.button.button == SDL_BUTTON_LEFT)
            {
                switch(menu)
                {
                    case 1:
                        if (main.playflag) menu = 3, main.playflag = 0;
                        if (main.optionflag) menu = 2, main.optionflag = 0;
                        if (main.historyflag) menu = 1, main.historyflag = 0;
                        //if (main.highflag) menu = 7, main.highflag = 0;
                        if (main.exitflag) quit = 1, main.exitflag =0;
                        break;
                    case 2:
                        if (Opm.increaseflag) currentVolume += 10, Mix_VolumeMusic(currentVolume);
                        if(Opm.decreaseflag) currentVolume -=10, Mix_VolumeMusic(currentVolume);
                        if (Opm.fullscreenflag)
                        {
                            screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
                            initmain(&main, 0);
                            Inisialise_omain1(&Opm, 0);
                            initializeundermenu1(&multsingmenu, 0);
                            initializeundermenu2(&inputmenu, 0);
                        }


                        if (Opm.normalflag)
                        {
                            screen = SDL_SetVideoMode(1250, 720, 32, SDL_HWSURFACE );
                            initmain(&main, 1);
                            Inisialise_omain1(&Opm, 1);
                            initializeundermenu1(&multsingmenu, 1);
                            initializeundermenu2(&inputmenu, 1);
                        }

                        if (Opm.quitflag) menu = 1, Opm.quitflag = 0;
                        break;
                    case 3:
                        if (multsingmenu.reflag) menu  = 1, multsingmenu.reflag = 0;
                        if (multsingmenu.mpflag) menu = 4, multsingmenu.mpflag = 0;
                        if (multsingmenu.spflag) menu = 4, multsingmenu.spflag = 0;
                        break;
                    case 4:
                        if (inputmenu.re1flag) menu = 3, inputmenu.re1flag = 0;
                        break;

                }
            }
        }


       switch(menu)
       {
            case 1:
                displaymain(main, screen);
                break;
            case 2:
                displayomain1(Opm,screen);
                break;
            case 3:
                displayundermenu1(multsingmenu, screen);
                break;
            case 4:
                displayundermenu2(inputmenu, screen);
                break;
            case 5:
                DisplaySaveMenu(savemenu, screen);
                break;
            case 6:
                DisplaySaveMenu(loadmenu, screen);
                break;
            case 7:
                displayMenu1(Usermenu, screen);
                break;
            case 8:
                displayMenu2(Highmenu, screen);
                break;
        }

        SDL_Flip(screen);

    }

    return 0;
}
