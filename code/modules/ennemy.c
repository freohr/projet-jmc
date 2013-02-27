#include "ennemy.h"


/*
enum eAction
{
    distance=1,
    melee=2,
    movement=3,
    wait=4
};
typedef enum eAction action;

struct sEnnemy
{
	int ID;
	object disposition;
	int hp;
	//gear : table of weapon (voir weapon) voir ligne suivante improvisation
    weapon weap;
	int nb_grenades;
	state etat;
	action actuelle;

};
typedef struct sEnnemy ennemy;

struct sWeapon
{
    int ID;
    int damage;
    int hit_number;
};
typedef struct sWeapon weapon;
*/


ennemy * init_ennemy () // LE MEC N'A PAS D'ARME
{
   ennemy * enn;
   enn=malloc(sizeof(ennemy));
   enn->ID=0;
   enn->hp=100;
   enn->nb_grenades=0;
   enn->etat=normal;
   enn->actuelle=wait;
   // creation de l'arme de l'enemie :
    weapon * weap1;
   weap1=init_weapon();
   enn->weap=weap1;

    return enn;
}

void free_ennemy (ennemy * enm)
{
   enm->ID=0;
   enm->hp=100;
   enm->nb_grenades=0;
   enm->etat=normal;
   enm->actuelle=wait;
   // liberation de l'arme de l'enemie :
   free_weapon(enm->weap);
   free(enm);
}
