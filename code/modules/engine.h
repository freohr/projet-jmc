#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "object.h"



// Gravity

//void how_do_i_gravity();

int test_collision(object* obj1, object* obj2);
/**
    pr�cond : obj1 et obj2 initialis�/

    postcond : valeurs de retour
    0 : pas de collision
    1 : collision entre obj1 � gauche et obj2 � droite
    2 : collision entre obj1 � droite et obj2 � gauche
    3 : collision entre obj1 en bas et obj2 en haut
    4 : collision entre obj1 en haut et obj2 en bas
    NB : s'il y a plus d'une collision entre 2 objets (ex, 2 objets plac�s en diagonale), seule la premi�re collision suivant cette liste sera retourn�e en r�sultat.
**/

void collision(object* obj1, object* obj2);

//Movement

#endif // _ENGINE_H_
