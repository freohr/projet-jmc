#include "weapon.h"
/*
struct sWeapon
{
    int ID;
    int damage;
    int hit_number;
};
*/
// initialisation et libération
void init_weapon(weapon * weap)
{
    weap->ID=0;
    weap->damage=0;
    weap->hit_number=0;
}

void free_weapon(weapon * weap)
{
    weap->ID=0;
    weap->damage=0;
    weap->hit_number=0;
    free(weap);
}
