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
weapon * init_weapon(); //creer un weapon
void free_weapon(weapon * weap);
#endif // WEAPON_H_INCLUDED
