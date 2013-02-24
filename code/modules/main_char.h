#include<stdio.h>
#include<stdlib.h>

#include "object.h"

struct sCharacter
{
    object disposition;
    int hp;
    int alive;
    // weapon* gear; //A décommenter une fois le module weapons.c écrit
    // int grenades
    enum state { normal, jump, crouch, hit};
};
typedef struct sCharacter character;

// Initialisation and Destruction
void init_mainChar(character* char1);
void free_mainChar(character* char1);

//Get Functions

