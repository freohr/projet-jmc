#ifndef _IMPUT_
#define _IMPUT_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "main_char.h"

/* vide pour l'instant, a supprimer peut �tre */

void input_cMove(character* char1);
/*  pr�cond : char1 initialis�
    postcond : le champ char->speed.x sera modifi� en fonction de l'input
    NB : LE PERSONNAGE N'AURA PAS BOUGE, c'est le module "engine" qui va s'occuper de modifier les positions
*/

void input_cAction(character* char1);
/*  pr�cond : char1 initialis�
    postcond : l'�tat actuel du peros est chang� (jump, crouch,..) ou le perso vient de tirer
*/

#endif /* _IMPUT_ */
