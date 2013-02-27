#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "object.h"



// Gravity

void how_do_i_gravity();

int collision(const object* obj1, const object* obj2);
/* postcond : valeurs de retour
    0 : pas de collision
    1 : collision entre obj1 à gauche et obj2 à droite
    2 : collision entre obj1 en bas et obj2 en haut
    3 : collision entre obj1 à droite et obj2 à gauche
    4 : collision entre obj1 en haut et obj2 en bas
*/

#endif // _ENGINE_H_
