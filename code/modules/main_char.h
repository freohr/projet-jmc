#ifndef _main_char_h_
#define _main_char_h_

#include<stdio.h>
#include<stdlib.h>
#include "object.h"
#include "weapon.h"
#include "struct.h"

enum eState {
    crouch=1,
    hit=2,
    jump=3,
    normal=4
};
typedef enum eState state;

struct sCharacter
{
    object disposition;
    int hp;
    int alive;
    // weapon* gear; //A décommenter une fois le module weapons.c écrit
    // int grenades
    state etat;

};
typedef struct sCharacter character;

// Initialisation and Destruction
void init_mainChar(character* char1);
void free_mainChar(character* char1);

//Get Functions (récupere les informations
coordinate get_cPosition(const character* char1);
coordinate get_cSpeed(const character* char1);
coordinate get_cHitbox(const character* char1);
int get_cHP(const character* char1);
//
int get_calive (const character * cha ); // etat mort ou vif si en vie = 1 si mort = 0
weapon get_cgear (const character * cha); // renvoie tableau d'arme actuel
int get_cgrenades (const character * cha); // recupere le nombre de grenade
int get_cstate (const character * cha); // recupere l'int du state


//Set Functions (modifier les parametres du character

void set_cPosition(const character* char1); // la position du perso
void set_cSpeed(const character* char1); // la rapidite
void set_cHitbox(const character* char1); // la hitbox , en fonction de getposition

void set_chp (character * cha,int hp); // modifie les points de vie du personnage
void set_clife (character * cha,int life); // modifier l'etat mort ou vivant
void set_cgear (character * cha,weapon gear); // modifier le tableau d'arme
void set_cgrenades (character * cha,int nb_grenades); //modifier le nombre de grenade
void set_cstate (character * cha,int state); // modifier l'état du personnage

// other
void cmove (character * cha,int speed,int angle); // déplace le personnage; appelle getposition get speed setposition
void cjump (character * cha,int speed,int angle); // A FAIRE ET UTILISE LA SDL
void ccrouch (character * cha,int direction); // A FAIRE ET UTILISE LA SDL
void ccover (character * cha,int direction); // A FAIRE ET UTILISE LA SDL
void cclimb (character * cha,int direction);  /* ici la direction sera haut où bas */

void cshoot (character * cha,int direction,int angle); // A FAIRE ET UTILISE LA SDL
void cgrenade (character * cha,int direction,int angle); // A FAIRE ET UTILISE LA SDL
//void cmelee (character * cha,int direction);

void cdeath (character * cha, coordinate new_position); // A FAIRE vérifie la mort et recharge le niveau sur le checkpoint rencontré en dernier

#endif
