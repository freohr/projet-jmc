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

ennemy* init_ennemy() // LE MEC N'A PAS D'ARME
{
    ennemy* enn;
    enn=malloc(sizeof(ennemy));
    enn->disposition = init_object();

    enn->hp=100;
    enn->alive=1; // l'ennemi est par défaut en vie
    enn->nb_grenades=0;
    enn->etat=normal;
    enn->actuelle=wait;
    // creation de l'arme de l'ennemi :
    weapon * weap1;
    weap1=init_weapon();
    enn->weap=weap1;

    return enn;
}

void free_ennemy(ennemy * enm)
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


// Gets
// Les fonctions en Get 
coordinate* get_ePosition(const ennemy* enm)
{
    return get_oPosition(enm->disposition);
}

coordinate* get_eSpeed(const ennemy* enm)
{
    return get_oSpeed(enm->disposition);
}

coordinate* get_eHitbox(const ennemy* enm)
{
    return get_oHitbox(enm->disposition);
}

object* get_eObject(ennemy* enm)
{
    return enm->disposition;
}

int get_eHP(ennemy* enm) //retourne le nombre d'hp du mob
{
    return enm->hp;
}

weapon * get_eGear(ennemy* enm) //retourne un pointeur sur l'arme enemie
{
    return enm->weap;
}

int get_eGrenades(ennemy* enm) // retourne le nombre de grenade de l'enemie
{
    return enm->nb_grenades;
}

int get_eState(ennemy* enm) //retourne l'état de l'enemie
{
    return enm->etat;
}

int get_eAction(ennemy* enm) //retourne l'action actuelle de l'ennemie
{
    return enm->actuelle;
}


// Sets
void set_eHP(ennemy* enm, int hp)
{
    enm->hp=hp;
}

void set_eLife(ennemy* enm, int life)
{
    enm->alive=life;
}
/*
void set_egear (ennemy * enm,weapon gear);
void set_egrenades (ennemy * enm,int nb_grenades);
void set_estate (ennemy * enm,int state);
void set_eaction (ennemy * enm,int state); */
