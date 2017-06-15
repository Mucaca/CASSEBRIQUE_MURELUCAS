//Création des types initialisation sdl et gestion de la font
#ifndef SDLFONT_H_INCLUDED
#define SDLFONT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 585
#define NOMBRE_BRIQ 20
#define NOMBRE_LIGNE 5

typedef struct game{


     SDL_Window *g_pWindow;
     SDL_Renderer *g_pRenderer;
     SDL_Texture *g_ptexture;
     SDL_Surface *g_psurface;


}game;
//-----------------------------------------------------------------------------

typedef struct gameState{

    int g_bRunning;


}gameState;
//-----------------------------------------------------------------------------

typedef struct coordonnees{

    double x;
    double y;
    double w;
    double h;
}coordonnees;
//-----------------------------------------------------------------------------

typedef enum {

    VerslaGauche=-1,
    Immobile=0,
    VerslaDroite=1
}EtatRaquette;
//-----------------------------------------------------------------------------

typedef enum {
    Pause=-1,
    Jeu=1,
}EtatPause;
//-----------------------------------------------------------------------------

typedef struct balle{
    double x;
    double y;
    double r;
    int d;
}balle;
//-----------------------------------------------------------------------------

typedef struct brique{
    double Sx;
    double Sy;
    double Destx;
    double Desty;
    double w;
    double h;
    int visible;
}brique;
//-----------------------------------------------------------------------------

void loadTextures(game *myGame,SDL_Texture **TabTexture);
int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame,coordonnees *dep, balle *bal1);
void delay(unsigned int frameLimit);
void destroy(game *myGame,SDL_Texture **TabTexture);

#endif // SDLFONT_H_INCLUDED
