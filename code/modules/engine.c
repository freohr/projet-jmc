#include "engine.h"

int collision(const object* obj1, const object* obj2)
//renvoie un code dictant le type de collision , a améliorer plus tard pour gérer s'il y a plusieurs collision en même temps!
{
    coordinate* size1;
    coordinate* position1;
    coordinate* size2;
    coordinate* position2;

    size1 = get_oHitbox(obj1);
    position1 = get_oPosition(obj1);
    size2 = get_oHitbox(obj2);
    position1 = get_oHitbox(obj2);

    if(position1->x + size1->x >= position2->x)
        return 1;
    else if(position1->y + size1->y >= position2->y)
        return 2;
    else if(position2->x + size2->x >= position1->x)
        return 3;
    else if(position2->y + size2->y >= position1->y)
        return 4;
    else
        return 0;
}

