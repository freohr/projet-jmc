#include "imput.h"
/* vide pour l'instant, a supprimer peut �tre */

void input_cMove(character* char1)
{
    if(/*input indiquant mouvement � gauche*/)
    {
        coordinate speed;
        speed = get_cSpeed(char1);
        set_cSpeed(char1, -10, speed.y);
    }
    else if(/*input indiquant mouvement � droite*/)
    {
        coordinate speed;
        speed = get_cSpeed(char1);
        set_cSpeed(char1, 10, speed.y);
    }
    else //pas d'input indiquant un mouvement lat�ral
    {
        coordinate speed;
        speed = get_cSpeed(char1);
        set_cSpeed(char1, 0, speed.y)
    }
}
