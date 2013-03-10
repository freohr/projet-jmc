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
	int alive;
	//gear : table of weapon (voir weapon) voir ligne suivante improvisation
    weapon* weap;
	int nb_grenades;
	state etat;
	action actuelle;

};
typedef struct sEnnemy ennemy;


// Fonctions

ennemy * init_ennemy (); // DONE
void free_ennemy (ennemy * enm); // DONE

// Les fonctions en Get 
coordinate get_ePosition(const ennemy* enm);
coordinate get_eSpeed(const ennemy* enm);
coordinate get_eHitbox(const ennemy* enm);

int get_eHP (ennemy* enm); // DONE
weapon* get_eGear (ennemy* enm); //DONE
int get_eGrenades (ennemy* enm); // DONE
int get_eState (ennemy* enm); //DONE
int get_eAction (ennemy* enm); //DONE

object* get_eObject(const ennemy* enm);

// Les fonctions en Set 
void set_eDisposition (ennemy* enm, object disposition);
void set_eHP (ennemy* enm, int hp);
void set_eLife (ennemy* enm, int life);
void set_eGear (ennemy* enm, weapon gear);
void set_eGrenades (ennemy* enm, int nb_grenades);
void set_eState (ennemy* enm, int state);
void set_eAction (ennemy* enm, int state);


// other
void emove (ennemy* enm, int speed, int angle);
void ejump (ennemy* enm, int speed, int angle);
void ecrouch (ennemy* enm, int direction);
void ecover (ennemy* enm, int direction);
void eclimb (ennemy* enm, int direction);  /* ici la direction sera haut où bas */

void eshoot (ennemy* enm, int direction, int angle);
void egrenade (ennemy* enm, int direction, int angle);
void emelee (ennemy* enm, int direction);

void edeath (ennemy* enm);


#endif // ENNEMY_H_INCLUDED
