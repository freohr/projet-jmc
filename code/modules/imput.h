#ifndef _IMPUT_
#define _IMPUT_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

/* vide pour l'instant, a supprimer peut �tre */

void input_cMove(character* char1);
/*  pr�cond : char1 initialis�
    postcond : le champ char->speed.x sera modifi� en fonction de l'input
    NB : LE PERSONNAGE N'AURA PAS BOUGE, c'est le module "engine" qui va s'occuper de modifier les positions
*/

#endif /* _IMPUT_ */
