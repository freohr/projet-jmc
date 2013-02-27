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
	int alive;
	//gear : table of weapon (voir weapon) voir ligne suivante improvisation
    weapon * weap;
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
   enn->alive=1; // l'ennemie est par defaut en vie
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


// FONCTION GET ENEMIE
int get_ehp (ennemy * enm) //retourne le nombre d'hp du mob
{
    return enm->hp;
}
weapon * get_egear (ennemy * enm) //retourne un pointeur sur l'arme enemie
{
    return enm->weap;
}
int get_egrenades (ennemy * enm) // retourne le nombre de grenade de l'enemie
{
    return enm->nb_grenades;
}
int get_estate (ennemy * enm) //retourne l'état de l'enemie
{
    return enm->etat;
}
int get_eaction (ennemy * enm) //retourne l'action actuelle de l'ennemie
{
    return enm->actuelle;
}


// LES FONCTIONS SET ENEMIE
void set_ehp (ennemy * enm,int hp)
{
    enm->hp=hp;
}
void set_elife (ennemy * enm,int life)
{
    enm->alive=life;
}
/*
void set_egear (ennemy * enm,weapon gear);
void set_egrenades (ennemy * enm,int nb_grenades);
void set_estate (ennemy * enm,int state);
void set_eaction (ennemy * enm,int state); */
