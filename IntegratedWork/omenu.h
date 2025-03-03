
typedef struct {
SDL_Surface *bg1;
SDL_Rect bg1pos;
SDL_Surface *decrease[2];
SDL_Rect decreasepos;
SDL_Surface *increase[2];
SDL_Rect increasepos;
SDL_Surface *normal[2];
SDL_Rect normalpos;
SDL_Surface *fullscreen[2];
SDL_Rect fullscreenpos;
SDL_Surface *quit[2];
SDL_Rect quitpos;
int increaseflag;
int decreaseflag;
int normalflag;
int fullscreenflag;
int quitflag;
SDL_Color tColor;
TTF_Font *font;
SDL_Rect text1pos;
SDL_Rect text2pos;
SDL_Surface *text1;
SDL_Surface *text2;
Mix_Music *backgroundMusic; 
}omain1;
void Inisialise_omain1(omain1 *Opm);
void displayomain1(omain1 Om,SDL_Surface *screen);
