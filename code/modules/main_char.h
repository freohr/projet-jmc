#ifndef _main_char_h_
#define _main_char_h_

#include<stdio.h>
#include<stdlib.h>
#include "object.h"
#include "weapon.h"
#include "struct.h"

struct sCharacter
{
    object disposition;
    int hp;
    int alive; // etat mort ou vif si en vie = 1 si mort = 0
    // weapon* gear; //A d�commenter une fois le module weapons.c �crit
    // int grenades
    state pose;

};
typedef struct sCharacter character;

// Initialisation and Destruction
character * init_mainChar();
void free_mainChar(character* char1);

//Get Functions (r�cupere les informations)

coordinate get_cPosition(const character* char1);
coordinate get_cSpeed(const character* char1);
coordinate get_cHitbox(const character* char1);
object* get_cObject(const character* char1); //pour la fonction de mouvement (pour avoir une seule fonction, et �viter les cast sur des (void*)

int get_cHP(const character* char1);
int get_calive (const character * cha ); // etat mort ou vif si en vie = 1 si mort = 0
weapon get_cgear (const character * cha); // renvoie tableau d'arme actuel
int get_cgrenades (const character * cha); // recupere le nombre de grenade
int get_cstate (const character * cha); // recupere l'int du state


//Set Functions (modifier les parametres du character

void set_cPosition(character* char1, int x, int y); // la position du perso
void set_cSpeed(character* char1, int x, int y); // la rapidite
void set_cHitbox(character* char1, int x, int y); // la hitbox , en fonction de getposition

void set_chp (character * cha,int hp); // modifie les points de vie du personnage
void set_clife (character * cha,int life); // modifier l'etat mort ou vivant
void set_cgear (character * cha,weapon gear); // modifier le tableau d'arme
void set_cgrenades (character * cha,int nb_grenades); //modifier le nombre de grenade
void set_cstate (character * cha,state state1); // modifier l'�tat du personnage

// other
void cmove (character * cha,int speed,int angle); // d�place le personnage; appelle getposition get speed setposition
void cjump (character * cha,int speed,int angle); // A FAIRE ET UTILISE LA SDL
void ccrouch (character * cha,int direction); // A FAIRE ET UTILISE LA SDL
void ccover (character * cha,int direction); // A FAIRE ET UTILISE LA SDL
void cclimb (character * cha,int direction);  /* ici la direction sera haut o� bas */

void cshoot (character * cha,int direction,int angle); // A FAIRE ET UTILISE LA SDL
void cgrenade (character * cha,int direction,int angle); // A FAIRE ET UTILISE LA SDL
//void cmelee (character * cha,int direction);

void cdeath (character * cha, coordinate new_position); // A FAIRE v�rifie la mort et recharge le niveau sur le checkpoint rencontr� en dernier

#endif
