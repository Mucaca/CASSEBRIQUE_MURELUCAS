//Cr�ation des raquettes et gestion des �v�nements li�es aux raquettes
#ifndef RAQUETTES_H_INCLUDED
#define RAQUETTES_H_INCLUDED
#include "SdlFont.h"


void handleEvents(gameState *state,EtatRaquette *boo1,EtatPause *Pboo);
void MouvementRaquette(coordonnees *dep,EtatRaquette *boo1);
void renderRaquette1(game *myGame,coordonnees *dep,SDL_Texture **TabTexture);


#endif // RAQUETTES_H_INCLUDED
