#include "weapon.h"

void init_weapon(weapon * weap) // initialisation weapon attention le malloc sera a faire !!
{
    weap->ID=0;
    weap->damage=0;
    weap->hit_number=0;
}

void free_weapon(weapon * weap) // libération weapon
{
    weap->ID=0;
    weap->damage=0;
    weap->hit_number=0;
    free(weap);
}
