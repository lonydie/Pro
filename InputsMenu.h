#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
    SDL_Surface *background1;
    SDL_Rect posback1;
    Mix_Music *musicback1;
    SDL_Surface *sp[2];
    SDL_Rect possp;
    int spflag;
    Mix_Chunk *sound;
    SDL_Surface *mp[2];
    SDL_Rect posmp;
    int mpflag;
    SDL_Surface *re[2];
    SDL_Rect posre;
    int reflag;
    TTF_Font *font;
    SDL_Color textColor;
    SDL_Surface *textsp;
    SDL_Rect postxt1;
    SDL_Surface *textmp;
    SDL_Rect postxt2;
    SDL_Surface *textre;
    SDL_Rect postxt3;
}undermenu1;

typedef struct
{
    SDL_Surface *background2;
    SDL_Rect posback2;
    Mix_Music *musicback2;
    SDL_Surface *av1[2];
    SDL_Rect posav1;
    int av1flag;
    Mix_Chunk *sound;
    SDL_Surface *av2[2];
    SDL_Rect posav2;
    int av2flag;
    SDL_Surface *val[2];
    SDL_Rect posval;
    int valflag;
    SDL_Surface *re1[2];
    SDL_Rect posre1;
    int re1flag;
    SDL_Surface *av3[2];
    SDL_Rect posav3;
    int av3flag;
    SDL_Surface *av4[2];
    SDL_Rect posav4;
    int av4flag;
    SDL_Surface *textav3;
    SDL_Rect postxt8;
    SDL_Surface *textav4;
    SDL_Rect postxt9;
    TTF_Font *font;
    SDL_Color textColor;
    SDL_Surface *textin1;
    SDL_Rect postxt4;
    SDL_Surface *textin2;
    SDL_Rect postxt5;
    SDL_Surface *textval;
    SDL_Rect postxt6;
    SDL_Surface *textre2;
    SDL_Rect postxt7;
}undermenu2;

void initializeundermenu1(undermenu1 *um);
void displayundermenu1(undermenu1 um,SDL_Surface *screen);
void initializeundermenu2(undermenu2 *um);
void displayundermenu2(undermenu2 um,SDL_Surface *screen);
