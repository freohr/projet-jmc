#ifndef _ENNEMY_H_
#define _ENNEMY_H_

#include <stdlib.h>
#include <stdio.h>

#include "object.h"
#include "weapon.h"
#include "struct.h"

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


// Fonctions

void init_ennemy (ennemy * enm);
void free_ennemy (ennemy * enm);

// Les fonctions en Get 
object get_edisposition (ennemy * enm);
int get_ehp (ennemy * enm);
weapon get_egear (ennemy * enm);
int get_egrenades (ennemy * enm);
int get_estate (ennemy * enm);
int get_eaction (ennemy * enm);

// Les fonctions en Set 
void set_edisposition (ennemy * enm,object disposition);
void set_ehp (ennemy * enm,int hp);
void set_elife (ennemy * enm,int life);
void set_egear (ennemy * enm,weapon gear);
void set_egrenades (ennemy * enm,int nb_grenades);
void set_estate (ennemy * enm,int state);
void set_eaction (ennemy * enm,int state);


// other
void emove (ennemy * enm,int speed,int angle);
void ejump (ennemy * enm,int speed,int angle);
void ecrouch (ennemy * enm, int direction);
void ecover (ennemy * enm, int direction);
void eclimb (ennemy * enm, int direction);  /* ici la direction sera haut où bas */

void eshoot (ennemy * enm,int direction,int angle);
void egrenade (ennemy * enm,int direction,int angle);
void emelee (ennemy * enm,int direction);

void edeath (ennemy * enm);


#endif // ENNEMY_H_INCLUDED
