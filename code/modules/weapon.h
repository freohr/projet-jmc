#ifndef WEAPON_H_
#define WEAPON_H_


struct sWeapon
{
    int ID;
    int damage;
    int hit_number;
};
typedef struct sWeapon weapon;

//fonction pour initialiser et libérer
void init_weapon(weapon * weap);
void free_weapon(weapon * weap);
#endif // WEAPON_H_INCLUDED
