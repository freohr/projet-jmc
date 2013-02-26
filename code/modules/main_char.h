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
    int alive;
    // weapon* gear; //A décommenter une fois le module weapons.c écrit
    // int grenades
    enum state {crouch=1, hit=2, jump=3, normal=4};
};
typedef struct sCharacter character;

// Initialisation and Destruction
void init_mainChar(character* char1);
void free_mainChar(character* char1);

//Get Functions
object get_cdisposition (character * cha);
        // necessite
        coordinate get_cPosition(const character* char1);
        coordinate get_cSpeed(const character* char1);
        coordinate get_cHitbox(const character* char1);
        int get_cHP(const character* char1);
int get_chp (character * cha);
int get_clife (character * cha );
weapon get_cgear (character * cha);
int get_cgrenades (character * cha);
int get_cstate (character * cha);


//Set Functions
void set_cdisposition (character * cha, object disposition);
void set_chp (character * cha,int hp);
void set_clife (character * cha,int life);
void set_cgear (character * cha,weapon gear);
void set_cgrenades (character * cha,int nb_grenades);
void set_cstate (character * cha,int state);

// other
void cmove (character * cha,int speed,int angle);
void cjump (character * cha,int speed,int angle);
void ccrouch (character * cha,int direction);
void ccover (character * cha,int direction);
void cclimb (character * cha,int direction);  /* ici la direction sera haut où bas */

void cshoot (character * cha,int direction,int angle);
void cgrenade (character * cha,int direction,int angle);
void cmelee (character * cha,int direction);

void cdeath (character * cha, coordinate new_position);

#endif
