#include "SaveHeader.h"

void InitializeSaveMenu(SaveMenu *Menu)
{
	Menu->Savebg = IMG_Load("Background.jpeg");
	Menu->Savebgpos.x = 0;
	Menu->Savebgpos.y = 0;
	Menu->Savebgpos.w = Menu->Savebg->w;
	Menu->Savebgpos.h = Menu->Savebg->h;
	Menu->Save[0] = IMG_Load("nhover.png");
	Menu->Save[1] = IMG_Load("hover.png");
	Menu->SavePos.x = 100;
	Menu->SavePos.y = 500;
	Menu->SavePos.w = Menu->Save[0]->w;
	Menu->SavePos.h = Menu->Save[0]->h;
	Menu->No[0] = IMG_Load("nhover.png");
	Menu->No[1] = IMG_Load("hover.png");
    Menu->NoPos.x = 400;
    Menu->NoPos.y = 500;
    Menu->NoPos.w = Menu->Save[0]->w;
    Menu->NoPos.h = Menu->Save[0]->h;
    Menu->Font = TTF_OpenFont("arial.ttf", 24);
    Menu->SaveTextPos.x = 180;
    Menu->SaveTextPos.y = 530;
    Menu->NoTextPos.x = 480;
    Menu->NoTextPos.y = 530;
    Menu->QuestionTextPos.x = 180;
    Menu->QuestionTextPos.y = 180;
	Menu->NoFlag = 0;
    Menu->Color.b = 0;
	Menu->Color.r = 0;
	Menu->Color.g = 0;
    Menu->ColorQ.b = 50;
	Menu->ColorQ.r = 255;
	Menu->ColorQ.g = 55;
    Menu->NoText = TTF_RenderText_Solid(Menu->Font, "No", Menu->Color);
    Menu->SaveText = TTF_RenderText_Solid(Menu->Font, "Yes", Menu->Color);
    Menu->QuestionText = TTF_RenderText_Solid(Menu->Font, "Would you like to save your game?", Menu->ColorQ);
    Menu->SaveFlag = 0;

};
void InitializeLoadMenu(SaveMenu *Menu)
{
	Menu->Savebg = IMG_Load("Background.jpeg");
	Menu->Savebgpos.x = 0;
	Menu->Savebgpos.y = 0;
	Menu->Savebgpos.w = Menu->Savebg->w;
	Menu->Savebgpos.h = Menu->Savebg->h;
	Menu->Save[0] = IMG_Load("nhover.png");
	Menu->Save[1] = IMG_Load("hover.png");
	Menu->SavePos.x = 100;
	Menu->SavePos.y = 500;
	Menu->SavePos.w = Menu->Save[0]->w;
	Menu->SavePos.h = Menu->Save[0]->h;
	Menu->No[0] = IMG_Load("nhover.png");
	Menu->No[1] = IMG_Load("hover.png");
    Menu->NoPos.x = 400;
    Menu->NoPos.y = 500;
    Menu->NoPos.w = Menu->Save[0]->w;
    Menu->NoPos.h = Menu->Save[0]->h;
    Menu->Font = TTF_OpenFont("arial.ttf", 24);
    Menu->SaveTextPos.x = 180;
    Menu->SaveTextPos.y = 530;
    Menu->NoTextPos.x = 480;
    Menu->NoTextPos.y = 530;
    Menu->QuestionTextPos.x = 180;
    Menu->QuestionTextPos.y = 180;
	Menu->NoFlag = 0;
    Menu->Color.b = 0;
	Menu->Color.r = 0;
	Menu->Color.g = 0;
    Menu->ColorQ.b = 50;
	Menu->ColorQ.r = 255;
	Menu->ColorQ.g = 55;
    Menu->NoText = TTF_RenderText_Solid(Menu->Font, "No", Menu->Color);
    Menu->SaveText = TTF_RenderText_Solid(Menu->Font, "Yes", Menu->Color);
    Menu->QuestionText = TTF_RenderText_Solid(Menu->Font, "Would you like to Load your game?", Menu->ColorQ);
    Menu->SaveFlag = 0;

};
void DisplaySaveMenu(SaveMenu Menu, SDL_Surface *screen)
{
	SDL_BlitSurface(Menu.Savebg, NULL, screen, &Menu.Savebgpos);
	SDL_BlitSurface(Menu.Save[Menu.SaveFlag],NULL, screen, &Menu.SavePos);
	SDL_BlitSurface(Menu.No[Menu.NoFlag], NULL, screen, &Menu.NoPos);
	SDL_BlitSurface(Menu.NoText, NULL, screen, &Menu.NoTextPos);
	SDL_BlitSurface(Menu.SaveText, NULL, screen, &Menu.SaveTextPos);
	SDL_BlitSurface(Menu.QuestionText, NULL,screen, &Menu.QuestionTextPos);


}
