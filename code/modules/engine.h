#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "object.h"



// Gravity

//void how_do_i_gravity();

int collision(const object* obj1, const object* obj2);
/*  postcond : valeurs de retour
    0 : pas de collision
    1 : collision entre obj1 � gauche et obj2 � droite
    2 : collision entre obj1 en bas et obj2 en haut
    3 : collision entre obj1 � droite et obj2 � gauche
    4 : collision entre obj1 en haut et obj2 en bas
    NB : s'il y a plus d'une collision entre 2 objets (ex, 2 objets plac�s en diagonale), seule la premi�re collision suivant cette liste sera retourn�e en r�sultat.
*/

//Movement

void move_object(object* obj1, int direction);
/*  pr�cond : obj1 est initialis�, et le pointeur est r�cuper� avec un get.
    postcond : le champ object.speed est modifi�
*/

#endif // _ENGINE_H_

int saut (character * char1, object * obj);
