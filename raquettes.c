#include "raquettes.h"

void handleEvents(gameState *state,EtatRaquette *boo1,EtatPause *Pboo)
{
    SDL_Event event;

    if(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
        case SDL_QUIT:
              state->g_bRunning=0;break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_q: *boo1=VerslaGauche ;
                    break;
                case SDLK_d: *boo1=VerslaDroite;
                    break;
                case SDLK_SPACE: *Pboo=*Pboo*-1;
                    break;
                case SDLK_ESCAPE: state->g_bRunning=0;
                    break;
            }
        break;

        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
                case SDLK_q: *boo1=Immobile ;
                    break;
                case SDLK_d: *boo1=Immobile;
                    break;
            }
            break;

        default:break;
        }
    }
}//-----------------------------------------------------------------------------

void MouvementRaquette(coordonnees *dep,EtatRaquette *boo1)
{
    if ((*boo1==VerslaDroite) && (dep->x<SCREEN_WIDTH-dep->w))
    {
        dep->x++;
    } else if (*boo1==VerslaGauche && dep->x>0){
        dep->x--;
    }
}//-----------------------------------------------------------------------------

//But : Construction raquette
void renderRaquette1(game *myGame,coordonnees *dep,SDL_Texture **TabTexture)
{
    SDL_Rect rectangleSource;
    SDL_Rect rectangleDest;

    myGame->g_ptexture = TabTexture[1]; // Préparation du sprite

    if(myGame->g_ptexture)
    {
        rectangleSource.x=0;//debut x
        rectangleSource.y=0;//debut y
        rectangleSource.w=SCREEN_WIDTH; //Largeur
        rectangleSource.h=SCREEN_HEIGHT; //Hauteur
        SDL_QueryTexture(myGame->g_ptexture,NULL,NULL,NULL,NULL);

        //Définition du rectangle dest pour dessiner Bitmap
        rectangleDest.x=dep->x;//debut x
        rectangleDest.y=dep->y;//debut y
        rectangleDest.w=dep->w; //Largeur
        rectangleDest.h=dep->h; //Hauteur

        SDL_RenderCopy(myGame->g_pRenderer,myGame->g_ptexture,&rectangleSource,&rectangleDest);
    }
    else
    {
            fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
    }
}//-----------------------------------------------------------------------------
