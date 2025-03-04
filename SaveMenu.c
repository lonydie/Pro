#include "SaveHeader.h"

void InitializeSaveMenu(SaveMenu *Menu)
{
	Menu->Savebg = IMG_Load("BackGrounds/SubMenu.png");
	Menu->Savebgpos.x = 0;
	Menu->Savebgpos.y = 0;
	Menu->Savebgpos.w = Menu->Savebg->w;
	Menu->Savebgpos.h = Menu->Savebg->h;
	Menu->Save[0] = IMG_Load("Buttons/Button.png");
	Menu->Save[1] = IMG_Load("Buttons/HoveredOverButton.png");
	Menu->SavePos.x = 700;
	Menu->SavePos.y = 500;
	Menu->No[0] = IMG_Load("Buttons/Button.png");
	Menu->No[1] = IMG_Load("Buttons/HoveredOverButton.png");
    Menu->NoPos.x = 1000;
    Menu->NoPos.y = 500;
    Menu->Font = TTF_OpenFont("Fonts/VT323-Regular.ttf", 24);
    Menu->Font2 = TTF_OpenFont("Fonts/VT323-Regular.ttf", 40);
    Menu->SaveTextPos.x = Menu->SavePos.x + 50;
    Menu->SaveTextPos.y = Menu->SavePos.y + 20;
    Menu->NoTextPos.x = Menu->NoPos.x + 50;
    Menu->NoTextPos.y = Menu->NoPos.y + 20;
    Menu->QuestionTextPos.x = 700;
    Menu->QuestionTextPos.y = 300;
	Menu->NoFlag = 0;
    Menu->Color.b = 0;
	Menu->Color.r = 0;
	Menu->Color.g = 0;
    Menu->ColorQ.b = 50;
	Menu->ColorQ.r = 255;
	Menu->ColorQ.g = 55;
    Menu->NoText = TTF_RenderText_Solid(Menu->Font, "No", Menu->Color);
    Menu->SaveText = TTF_RenderText_Solid(Menu->Font, "Yes", Menu->Color);
    Menu->QuestionText = TTF_RenderText_Solid(Menu->Font2, "Would you like to save your game?", Menu->ColorQ);
    Menu->SaveFlag = 0;

};
void InitializeLoadMenu(SaveMenu *Menu)
{
	Menu->Savebg = IMG_Load("BackGrounds/SubMenu.png");
	Menu->Savebgpos.x = 0;
	Menu->Savebgpos.y = 0;
	Menu->Savebgpos.w = Menu->Savebg->w;
	Menu->Savebgpos.h = Menu->Savebg->h;
	Menu->Save[0] = IMG_Load("Buttons/Button.png");
	Menu->Save[1] = IMG_Load("Buttons/HoveredOverButton.png");
	Menu->SavePos.x = 700;
	Menu->SavePos.y = 500;
	Menu->No[0] = IMG_Load("Buttons/Button.png");
	Menu->No[1] = IMG_Load("Buttons/HoveredOverButton.png");
    Menu->NoPos.x = 1000;
    Menu->NoPos.y = 500;
    Menu->Font = TTF_OpenFont("Fonts/VT323-Regular.ttf", 24);
    Menu->Font2 = TTF_OpenFont("Fonts/VT323-Regular.ttf", 40);
    Menu->SaveTextPos.x = Menu->SavePos.x + 50;
    Menu->SaveTextPos.y = Menu->SavePos.y + 20;
    Menu->NoTextPos.x = Menu->NoPos.x + 50;
    Menu->NoTextPos.y = Menu->NoPos.y + 20;
    Menu->QuestionTextPos.x = 700;
    Menu->QuestionTextPos.y = 300;
	Menu->NoFlag = 0;
    Menu->Color.b = 0;
	Menu->Color.r = 0;
	Menu->Color.g = 0;
    Menu->ColorQ.b = 50;
	Menu->ColorQ.r = 255;
	Menu->ColorQ.g = 55;
    Menu->NoText = TTF_RenderText_Solid(Menu->Font, "No", Menu->Color);
    Menu->SaveText = TTF_RenderText_Solid(Menu->Font, "Yes", Menu->Color);
    Menu->QuestionText = TTF_RenderText_Solid(Menu->Font2, "Would you like to Load your game?", Menu->ColorQ);
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
