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

//Set Functions
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

void set_cPosition(character* char1, int x, int y)
{
    set_oPosition(&(char1->disposition), x, y);
} // la position du perso

void set_cSpeed(character* char1, int x, int y) // la rapidite
{
    set_oSpeed(&(char1->disposition), x, y);
}

void set_cHitbox(character* char1, int x, int y) // la hitbox , en fonction de getposition
{
    set_oHitbox(&(char1->disposition), x, y);
}

//Various Functions
character* init_mainChar()//  initialisation et libération
{
    character * char1;
    char1=malloc(sizeof(character));
    set_oPosition(&(char1->disposition), 0, 0); // initialise la position du personnage a x=0, y=0
    set_oSpeed(&(char1->disposition), 0, 0); // initialise la rapidité du personnage a x=0, y=0 (vitesse nulle)
    set_oHitbox(&(char1->disposition), 20, 40); // itinialise la hit box
    set_chp(char1,100);
    set_clife(char1,1); // modifier l'etat mort ou vivant 0 mort, 1 vivant
    set_cstate(char1,normal);
    return char1;
}

void free_mainChar(character * char1) // libere le main_char !
{
    set_chp(char1,100);
    set_clife(char1,1); // modifier l'etat mort ou vivant 0 mort, 1 vivant
    set_cstate(char1,normal);
    free_object(&(char1->disposition));
    free(char1);
}

/*void move_char(character* char1, int direction)
{
    set_cPosition()
}*/
