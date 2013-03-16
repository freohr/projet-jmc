#ifndef _main_char_h_
#define _main_char_h_

#include<stdio.h>
#include<stdlib.h>
#include "object.h"
#include "weapon.h"
#include "struct.h"

struct sCharacter
{
    object* disposition;
    int hp;
    int alive; // etat mort ou vif si en vie = 1 si mort = 0
    // weapon* gear; //A décommenter une fois le module weapons.c écrit
    // int grenades
    state pose;

};
typedef struct sCharacter character;

// Initialisation and Destruction
character* init_mainChar();
void free_mainChar(character* char1);

//Get Functions (récupere les informations)

coordinate* get_cPosition(character* char1);
coordinate* get_cSpeed(character* char1);
coordinate* get_cHitbox(character* char1);
object* get_cObject(character* char1); //pour la fonction de mouvement (pour avoir une seule fonction, et éviter les cast sur des (void*)

int get_cHP(const character* char1);
int get_cAlive (const character* cha ); // etat mort ou vif si en vie = 1 si mort = 0
weapon get_cGear (const character* cha); // renvoie tableau d'arme actuel
int get_cGrenades (const character* cha); // recupere le nombre de grenade
int get_cState (const character* cha); // recupere l'int du state


//Set Functions (modifier les parametres du character

void set_cPosition(character* char1, int x, int y); // la position du perso
void set_cSpeed(character* char1, int x, int y); // la rapidite
void set_cHitbox(character* char1, int x, int y); // la hitbox , en fonction de getposition

void set_cHP(character * cha,int hp); // modifie les points de vie du personnage
void set_cLife(character * cha,int life); // modifier l'etat mort ou vivant
void set_cGear(character * cha,weapon gear); // modifier le tableau d'arme
void set_cGrenades(character * cha,int nb_grenades); //modifier le nombre de grenade
void set_cState(character * cha,state state1); // modifier l'état du personnage

// other
void move_char(character* cha); // done

void cJump(character* char1); //done

void ccrouch(character * cha); // A FAIRE ET UTILISE LA SDL
void ccover(character * cha); // A FAIRE ET UTILISE LA SDL
void cclimb(character * cha);  /* ici la direction sera haut où bas */

void cshoot(character * cha,int direction,int angle); // A FAIRE ET UTILISE LA SDL
void cgrenade(character * cha,int direction,int angle); // A FAIRE ET UTILISE LA SDL
//void cmelee (character * cha,int direction);

void cdeath(character * cha, coordinate new_position); // A FAIRE vérifie la mort et recharge le niveau sur le checkpoint rencontré en dernier

#endif
