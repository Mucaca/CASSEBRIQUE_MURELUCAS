#include "balle.h"
//Gestion de la balle
//BUT : construction de la balle
//ENTREE : la fenêtre myGame et la balle
//SORTIE : Balle construite ( cercle)
void renderBalle(game *myGame,balle *bal1,SDL_Texture **TabTexture)
{
    SDL_Rect rectangleSource;
    SDL_Rect rectangleDest;
    myGame->g_ptexture = TabTexture[0];

    if(myGame->g_ptexture)
    {
        rectangleSource.x=0;//debut x
        rectangleSource.y=0;//debut y
        rectangleSource.w=SCREEN_WIDTH; //Largeur
        rectangleSource.h=SCREEN_HEIGHT; //Hauteur
        SDL_QueryTexture(myGame->g_ptexture,NULL,NULL,NULL,NULL);

        //Définition du rectangle dest pour dessiner Bitmap
        rectangleDest.x=bal1->x;//debut x
        rectangleDest.y=bal1->y;//debut y
        rectangleDest.w=bal1->r*2; //Largeur
        rectangleDest.h=bal1->r*2; //Hauteur

        SDL_RenderCopy(myGame->g_pRenderer,myGame->g_ptexture,&rectangleSource,&rectangleDest);
    }
    else
    {
            fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
    }
}//-----------------------------------------------------------------------------

//BUT : Calcul position balle + collision, gestion du score
void jeu(game *myGame, balle *bal1,coordonnees *dep,int *scoreJ1,EtatPause *Pboo,brique *TabBriq)
{
    int i;
    //HAUT gauche
    if (bal1->d==1)
    {
        bal1->x=bal1->x-1;
        bal1->y=bal1->y-1;
    }
    //HAUT droite
    if (bal1->d==2)
    {
        bal1->x=bal1->x+1;
        bal1->y=bal1->y-1;
    }
    //BAS droit
    if (bal1->d==3)
    {
        bal1->x=bal1->x+1;
        bal1->y=bal1->y+1;
    }
    //BAS gauche
    if (bal1->d==4)
    {
        bal1->x=bal1->x-1;
        bal1->y=bal1->y+1;
    }
    //Rebond ecran haut
    if (bal1->y<=bal1->r)
    {
        if (bal1->d==1)
        {
            bal1->d=4;
        }
        else if (bal1->d==2)
        {
            bal1->d=3;
        }
    }
    //Rebond ecran gauche
    if (bal1->x<=bal1->r)
    {
        if (bal1->d==1)
        {
            bal1->d=2;
        }
        else if (bal1->d==4)
        {
            bal1->d=3;
        }
    }
    //Rebond ecran droit
    if (bal1->x>=SCREEN_WIDTH-bal1->r){
        if (bal1->d==2){
            bal1->d=1;
        } else if (bal1->d==3){
            bal1->d=4;
        }
    }

    //Rebond Raquette
    if ((bal1->y>=SCREEN_HEIGHT-(dep->h+bal1->r))&&(bal1->x>=dep->x)&&(bal1->x<=dep->x+dep->w))
    {
        if (bal1->d==4)
        {
            bal1->d=1;
        }
        else if (bal1->d==3)
        {
            bal1->d=2;
        }
    }
    //Rebond Briques
    for (i=0; i<NOMBRE_LIGNE*NOMBRE_BRIQ; i++)
    {
        if (TabBriq[i].visible==1)
        {
            if ((TabBriq[i].Destx <= bal1->x+2*(bal1->d))&&(TabBriq[i].Destx+TabBriq[i].w>=bal1->x)&&(TabBriq[i].Desty<=bal1->y+2*(bal1->d))&&(TabBriq[i].Desty+TabBriq[i].h>=bal1->y))
            {
                if (bal1->d==1)
                {
                    bal1->d=4;
                }
                //HAUT droite
                if (bal1->d==2)
                {
                    bal1->d=3;
                }
                //BAS droit
                if (bal1->d==3)
                {
                    bal1->d=2;
                }
                //BAS gauche
                if (bal1->d==4)
                {
                    bal1->d=1;
                }
                TabBriq[i].visible=0;
            }
        }
    }
}//-----------------------------------------------------------------------------
