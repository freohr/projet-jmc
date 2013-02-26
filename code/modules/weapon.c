#include "weapon.h"
#include <stdlib.h>
#include <stdio.h>

weapon * init_weapon() // initialisation weapon attention le malloc sera a faire !!
{
    weapon * weap;
    weap=malloc(sizeof(weapon));
    weap->ID=0;
    weap->damage=0;
    weap->hit_number=0;
    return weap;
}

void free_weapon(weapon * weap) // libération weapon
{
    weap->ID=0;
    weap->damage=0;
    weap->hit_number=0;
    free(weap);
}

