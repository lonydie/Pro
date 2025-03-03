#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>



typedef struct
{
    SDL_Surface *Savebg;
	SDL_Rect Savebgpos;
	SDL_Surface* Save[2];
	SDL_Rect SavePos;
	SDL_Surface* No[2];
	SDL_Rect NoPos;
	SDL_Surface *SaveText;
	SDL_Rect SaveTextPos;
	SDL_Surface *NoText;
	SDL_Rect NoTextPos;
	SDL_Surface* QuestionText;
	SDL_Rect QuestionTextPos;
	SDL_Color Color;
	SDL_Color ColorQ;
    TTF_Font *Font;
	int SaveFlag, NoFlag;

} SaveMenu;



void InitializeSaveMenu(SaveMenu *Menu);
void InitializeLoadMenu(SaveMenu *Menu);
void DisplaySaveMenu(SaveMenu Menu, SDL_Surface *screen);
