#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "omenu.h"
void Inisialise_omain1(omain1 *Opm)
{
	Opm->bg1=IMG_Load("back_opt.png");
	Opm->bg1pos.x=0;
	Opm->bg1pos.y=0;
	Opm->bg1pos.w=1280;
	Opm->bg1pos.h=720;
	Opm->decrease[0]=IMG_Load("decrease_bottom.png");
	Opm->decrease[1]=IMG_Load("decrease_bottom2.png");
	Opm->decreasepos.x=454;
	Opm->decreasepos.y=284;
	Opm->decreasepos.w=260;
	Opm->decreasepos.h=50;
	Opm->decreaseflag=0;
	Opm->increase[0]=IMG_Load("increase_bottom.png");
	Opm->increase[1]=IMG_Load("increase_bottom2.png");
	Opm->increasepos.x=770;
	Opm->increasepos.y=284;
	Opm->increasepos.w=260;
	Opm->increasepos.h=50;
	Opm->increaseflag=0;
	Opm->normal[0]=IMG_Load("normal_bottom.png");
	Opm->normal[1]=IMG_Load("normal_bottom2.png");
	Opm->normalpos.x=454;
	Opm->normalpos.y=438;
	Opm->normalpos.w=260;
	Opm->normalpos.h=50;
	Opm->normalflag=0;
	Opm->fullscreen[0]=IMG_Load("fullscreen_bottom.png");
	Opm->fullscreen[1]=IMG_Load("fullscreen_bottom2.png");
	Opm->fullscreenpos.x=770;
	Opm->fullscreenpos.y=438;
	Opm->fullscreenpos.w=260;
	Opm->fullscreenpos.h=50;
	Opm->fullscreenflag=0;
	Opm->quit[0]=IMG_Load("quit_bottom.png");
	Opm->quit[1]=IMG_Load("quit_bottom2.png");
	Opm->quitpos.x=230;
	Opm->quitpos.y=562;
	Opm->quitpos.w=180;
	Opm->quitpos.h=55;
	Opm->quitflag=0;
	Opm->font=TTF_OpenFont("VT323-Regular.ttf", 35);
	Opm->tColor.r=0;
	Opm->tColor.g=0;
	Opm->tColor.b=128;
	Opm->text1pos.x=258;
	Opm->text1pos.y=302;
	Opm->text2pos.x=258;
	Opm->text2pos.y=455;
	Opm->text1=TTF_RenderText_Blended(Opm->font, " volume ",Opm->tColor);
	Opm->text2=TTF_RenderText_Blended(Opm->font, " screen ",Opm->tColor);
	Opm->backgroundMusic = Mix_LoadMUS("back1s.mp3");
	}
	void displayomain1(omain1 Opm,SDL_Surface *screen)
	{
		SDL_BlitSurface(Opm.bg1,NULL,screen,&Opm.bg1pos);
		SDL_BlitSurface (Opm.text1, NULL, screen, &Opm.text1pos);
		SDL_BlitSurface (Opm.text2, NULL, screen, &Opm.text2pos);
		SDL_BlitSurface(Opm.decrease[Opm.decreaseflag],NULL,screen,&Opm.decreasepos);
		SDL_BlitSurface(Opm.increase[Opm.increaseflag],NULL,screen,&Opm.increasepos);
		SDL_BlitSurface(Opm.normal[Opm.normalflag],NULL,screen,&Opm.normalpos);
		SDL_BlitSurface(Opm.fullscreen[Opm.fullscreenflag],NULL,screen,&Opm.fullscreenpos);
		SDL_BlitSurface(Opm.quit[Opm.quitflag],NULL,screen,&Opm.quitpos);
	}
