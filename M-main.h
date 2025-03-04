#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
	SDL_Surface *back[2];
	SDL_Rect posback;
    int backflag;
	SDL_Surface *play[2];
	SDL_Rect posplay;
	int playflag;
	SDL_Surface *option[2];
	SDL_Rect posoption;
	int optionflag;
	SDL_Surface *high[2];
	SDL_Rect poshigh;
	int highflag;
	SDL_Surface *history[2];
	SDL_Rect poshistory;
	int historyflag;
	SDL_Surface *exit[2];
	SDL_Rect posexit;
	int exitflag;
	TTF_Font *font;
	SDL_Color textColor;
	SDL_Surface *textplay;
	SDL_Rect postxt1;
	SDL_Surface *textoption;
	SDL_Rect postxt2;
	SDL_Surface *texthigh;
	SDL_Rect postxt3;
	SDL_Surface *texthistory;
	SDL_Rect postxt4;
	SDL_Surface *textexit;
	SDL_Rect postxt5;
}mainmenu;

void initmain(mainmenu *m, int fullscreen);
void displaymain(mainmenu m, SDL_Surface *screen);
