#include "SdlFont.h"
//Initialisation gestion de la fenêtre et de la font

void loadTextures(game *myGame,SDL_Texture **TabTexture)
{
    SDL_Surface *Temp;
    Temp=IMG_Load("D:/Lucas/PROJET CODE/Algo-C/TP_Casse-Brique/assets/ball.png");
    TabTexture[0] = SDL_CreateTextureFromSurface(myGame->g_pRenderer,Temp);
    SDL_FreeSurface(Temp);
    Temp=IMG_Load("D:/Lucas/PROJET CODE/Algo-C/TP_Casse-Brique/assets/paddle.png");
    TabTexture[1] = SDL_CreateTextureFromSurface(myGame->g_pRenderer,Temp);
    SDL_FreeSurface(Temp);
    Temp=IMG_Load("D:/Lucas/PROJET CODE/Algo-C/TP_Casse-Brique/assets/bricks.png");
    TabTexture[2] = SDL_CreateTextureFromSurface(myGame->g_pRenderer,Temp);
    SDL_FreeSurface(Temp);
}//-----------------------------------------------------------------------------

//BUT : init window, paddle, ball
int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame,coordonnees *dep, balle *bal1)
{
    //initialize SDL
    dep->x=SCREEN_WIDTH/2-(64);
    dep->y=SCREEN_HEIGHT-32;
    dep->w=128;
    dep->h=32;
    bal1->x=SCREEN_WIDTH/2-16;
    bal1->y=SCREEN_HEIGHT-64;
    bal1->r=16;
    bal1->d=1;
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
        //if succeeded create our window
        myGame->g_pWindow=SDL_CreateWindow(title,xpos,ypos,height,width,flags);
        //if succeeded create window, create our render
        if(myGame->g_pWindow!=NULL)
        {
            myGame->g_pRenderer=SDL_CreateRenderer(myGame->g_pWindow,-1,SDL_RENDERER_ACCELERATED);
        }
    }
    else
    {
        return 0;
    }
    return 1;
}//-----------------------------------------------------------------------------

void destroy(game *myGame,SDL_Texture **TabTexture)
{
    //Destroy texture
    if(myGame->g_ptexture!=NULL)
            SDL_DestroyTexture(myGame->g_ptexture);
    if(TabTexture[0]!=NULL)
            SDL_DestroyTexture(TabTexture[0]);
    if(TabTexture[1]!=NULL)
            SDL_DestroyTexture(TabTexture[1]);
    if(TabTexture[2]!=NULL)
            SDL_DestroyTexture(TabTexture[2]);


    //Destroy render
    if(myGame->g_pRenderer!=NULL)
        SDL_DestroyRenderer(myGame->g_pRenderer);


    //Destroy window
    if(myGame->g_pWindow!=NULL)
        SDL_DestroyWindow(myGame->g_pWindow);
}//-----------------------------------------------------------------------------
