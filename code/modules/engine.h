#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "object.h"



// Gravity

//void how_do_i_gravity();

int test_collision(object* obj1, object* obj2);
/**
    précond : obj1 et obj2 initialisé/

    postcond : valeurs de retour
    0 : pas de collision
    1 : collision entre obj1 à gauche et obj2 à droite
    2 : collision entre obj1 à droite et obj2 à gauche
    3 : collision entre obj1 en bas et obj2 en haut
    4 : collision entre obj1 en haut et obj2 en bas
    NB : s'il y a plus d'une collision entre 2 objets (ex, 2 objets placés en diagonale), seule la première collision suivant cette liste sera retournée en résultat.
**/

void collision(object* obj1, object* obj2);

//Movement

#endif // _ENGINE_H_
