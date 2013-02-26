#include "main_char.h"

//Get Functions

coordinate get_cPosition(const character* char1)
{
    return get_oPosition(&(char1->disposition));
}

coordinate get_cSpeed(const character* char1)
{
    return get_oSpeed(&(char1->disposition));
}

coordinate get_cHitbox(const character* char1)
{
    return get_oHitbox(&(char1->disposition));
}

int get_cHP(const character* char1)
{
    return char1->hp;
}

int get_cAlive(const character* char1)
{
    return char1->alive;
}

void set_chp (character * cha,int hp) // modifie les points de vie du personnage
{
    cha->hp=hp;
}
void set_clife (character * cha,int life) // modifier l'etat mort ou vivant 0 mort, 1 vivant
{
    cha->alive=life;
}
// void set_cgear (character * cha,weapon gear); // modifier le tableau d'arme A FAIRE PLUS TARD !!!!!!!!!!!!
// void set_cgrenades (character * cha,int nb_grenades); //modifier le nombre de grenade

void set_cstate (character * cha,state state1) // modifier l'état du personnage
{
    cha->pose=state1;
}

/*struct sCharacter
{
    object disposition;
    int hp;
    int alive;
    // weapon* gear; //A décommenter une fois le module weapons.c écrit
    // int grenades
    state pose;

struct sObject
{
    int ID;
    coordinate position;
    coordinate speed;
    coordinate hitbox;
};
typedef struct sObject object;

};
typedef struct sCharacter character;

void set_oPosition(object* obj1, int x, int y);
void set_oSpeed(object* obj1, int x, int y);
void set_oHitbox(object* obj1, int x, int y);
*/
//  initialisation et libération

void init_mainChar(character* char1)
{
    set_oPosition(&(char1->disposition), 0, 0); // initialise la position du personnage a x=0, y=0
    set_oSpeed(&(char1->disposition), 0, 0); // initialise la rapidité du personnage a x=0, y=0 (vitesse nulle)
    set_oHitbox(&(char1->disposition), 20, 40); // itinialise la hit box
    set_chp (&cha,100);
    set_clife (&cha,1); // modifier l'etat mort ou vivant 0 mort, 1 vivant
    set_cstate (&cha,normal);
}

//void free_mainChar(character* char1)

