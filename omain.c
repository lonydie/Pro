#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "omenu.h"
void Inisialise_omain1(omain1 *Opm, int fullscreen)
{
	Opm->bg1[0]=IMG_Load("BackGrounds/SubMenu.png");
	Opm->bg1[1]=IMG_Load("BackGrounds/SubMenu70.png");
	Opm->bg1pos.x=0;
	Opm->bg1pos.y=0;
	Opm->bgflag = fullscreen;
	Opm->decrease[0]=IMG_Load("Buttons/Button.png");
	Opm->decrease[1]=IMG_Load("Buttons/HoveredOverButton.png");
	Opm->decreasepos.x=Opm->bg1[fullscreen]->w / 3.2;
	Opm->decreasepos.y=Opm->bg1[fullscreen]->h / 3;
	Opm->decreaseflag=0;
	Opm->increase[0]=IMG_Load("Buttons/Button.png");
	Opm->increase[1]=IMG_Load("Buttons/HoveredOverButton.png");
	Opm->increasepos.x=Opm->bg1[fullscreen]->w / 1.92;
	Opm->increasepos.y=Opm->bg1[fullscreen]->h / 3;
	Opm->increaseflag=0;
	Opm->normal[0]=IMG_Load("Buttons/Button.png");
	Opm->normal[1]=IMG_Load("Buttons/HoveredOverButton.png");
	Opm->normalpos.x=Opm->bg1[fullscreen]->w / 3.2;
	Opm->normalpos.y=Opm->bg1[fullscreen]->h / 2.16;
	Opm->normalflag=0;
	Opm->fullscreen[0]=IMG_Load("Buttons/Button.png");
	Opm->fullscreen[1]=IMG_Load("Buttons/HoveredOverButton.png");
	Opm->fullscreenpos.x=Opm->bg1[fullscreen]->w / 1.92;
	Opm->fullscreenpos.y=Opm->bg1[fullscreen]->h / 2.16;
	Opm->fullscreenflag=0;
	Opm->quit[0]=IMG_Load("Buttons/Button.png");
	Opm->quit[1]=IMG_Load("Buttons/HoveredOverButton.png");
	Opm->quitpos.x=Opm->bg1[fullscreen]->w / 4;
	Opm->quitpos.y=Opm->bg1[fullscreen]->h / 1.6;
    Opm->quitflag=0;
	Opm->font=TTF_OpenFont("Fonts/VT323-Regular.ttf", 50);
	Opm->font2=TTF_OpenFont("Fonts/VT323-Regular.ttf", 30);
	Opm->tColor.r=0;
	Opm->tColor.g=0;
	Opm->tColor.b=128;
	Opm->text1pos.x= Opm->decreasepos.x - 160;
	Opm->text1pos.y= Opm->decreasepos.y + 15;
	Opm->text2pos.x= Opm->normalpos.x -160;
	Opm->text2pos.y= Opm->normalpos.y + 15;
	Opm->DecreaseTextPos.x = Opm->decreasepos.x + 50;
	Opm->DecreaseTextPos.y = Opm->decreasepos.y + 20;
	Opm->IncreaseTextPos.x = Opm->increasepos.x + 50;
	Opm->IncreaseTextPos.y = Opm->increasepos.y + 20;

	Opm->FullscreenTextPos.x = Opm->fullscreenpos.x + 50;
	Opm->FullscreenTextPos.y = Opm->fullscreenpos.y + 20;
	Opm->NormalTextPos.x = Opm->normalpos.x + 50;
	Opm->NormalTextPos.y = Opm->normalpos.y + 20;

	Opm->QuitTextPos.x = Opm->quitpos.x + 50;
	Opm->QuitTextPos.y = Opm->quitpos.y + 20;




	Opm->text1=TTF_RenderText_Blended(Opm->font, " Volume ",Opm->tColor);
	Opm->text2=TTF_RenderText_Blended(Opm->font, " Screen ",Opm->tColor);
	Opm->DecreastText = TTF_RenderText_Blended(Opm->font2, " Decrease ",Opm->tColor);
	Opm->IncreaseText = TTF_RenderText_Blended(Opm->font2, " Increase ",Opm->tColor);
	Opm->FullscreenText = TTF_RenderText_Blended(Opm->font2, " Fullscreen ",Opm->tColor);
    Opm->NormalText = TTF_RenderText_Solid(Opm->font2, " Normal ",Opm->tColor);
    Opm->QuitText = TTF_RenderText_Blended(Opm->font2, " Return ",Opm->tColor);
	}
	void displayomain1(omain1 Opm,SDL_Surface *screen)
	{
		SDL_BlitSurface(Opm.bg1[Opm.bgflag],NULL,screen,&Opm.bg1pos);
        SDL_BlitSurface(Opm.decrease[Opm.decreaseflag],NULL,screen,&Opm.decreasepos);
		SDL_BlitSurface(Opm.increase[Opm.increaseflag],NULL,screen,&Opm.increasepos);
		SDL_BlitSurface(Opm.normal[Opm.normalflag],NULL,screen,&Opm.normalpos);
		SDL_BlitSurface(Opm.fullscreen[Opm.fullscreenflag],NULL,screen,&Opm.fullscreenpos);
		SDL_BlitSurface(Opm.quit[Opm.quitflag],NULL,screen,&Opm.quitpos);
		SDL_BlitSurface (Opm.text1, NULL, screen, &Opm.text1pos);
		SDL_BlitSurface (Opm.text2, NULL, screen, &Opm.text2pos);
		SDL_BlitSurface(Opm.DecreastText, NULL, screen, &Opm.DecreaseTextPos);
		SDL_BlitSurface(Opm.IncreaseText, NULL, screen, &Opm.IncreaseTextPos);
		SDL_BlitSurface(Opm.FullscreenText, NULL, screen, &Opm.FullscreenTextPos);

		SDL_BlitSurface(Opm.QuitText, NULL, screen, &Opm.QuitTextPos);
		SDL_BlitSurface(Opm.NormalText, NULL, screen, &Opm.NormalTextPos);
	}
