#include "briques.h"
//D:\SDL2-2.0.5 chemin vers sdl
//D:\SDL2-2.0.5\SDL2_ttf-devel-2.0.14-mingw\SDL2_ttf-2.0.14 chemin vers sdl ttf
int main(int argc, char *argv[])
{

     game myGame;
     gameState state;
     SDL_Texture *MesTextures[10];

     coordonnees dep;
     EtatRaquette boo1;
     EtatPause Pboo=Pause;

     balle bal1;

     brique TabBriq[NOMBRE_LIGNE*NOMBRE_BRIQ];
     int niveau=0;

     int choix=0;
     int scoreJ1=0;


     state.g_bRunning=1;

    //Pour les 60 fps
    unsigned int frameLimit = SDL_GetTicks() + 16;

    //Create texture for drawing in texture or load picture
    myGame.g_ptexture=SDL_CreateTexture(myGame.g_pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,SCREEN_WIDTH,SCREEN_HEIGHT);
    printf("Bienvenue dans mon casse brique !\n");
    printf("D�placer la raquette � gauche avec q.\n");
    printf("D�placer la raquette � droite avec d.\n");
    printf("Appuyer sur espace pour l'engagement et/ou mettre le jeu en pause .\n");
    printf("Appuyer sur echap pour quitter la partie. \n");
    while(state.g_bRunning)
    {
        if(choix==0)
        {
            printf("1: Jouer !\n");
            scanf("%i",&choix);
        }
        switch (choix)
        {
            case 1:
                init("Chapter 1 setting up SDL",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&myGame,&dep,&bal1);
                loadTextures(&myGame,MesTextures);
                initBriques(TabBriq,niveau);
                while(state.g_bRunning)
                {
                    SDL_RenderClear(myGame.g_pRenderer);
                    handleEvents(&state,&boo1,&Pboo);
                    renderRaquette1(&myGame,&dep,MesTextures);
                    renderBalle(&myGame,&bal1,MesTextures);
                    renderBriques(&myGame,TabBriq,MesTextures);
                    if (Pboo==Jeu){
                        MouvementRaquette(&dep,&boo1);
                        jeu(&myGame,&bal1,&dep,&scoreJ1,&Pboo,TabBriq);
                    }
                    SDL_RenderPresent(myGame.g_pRenderer);
                }

                 break;

        }

         destroy(&myGame,MesTextures);

         TTF_Quit();
         SDL_Quit();
    }

    return 0;
}//-----------------------------------------------------------------------------
















