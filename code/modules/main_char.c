#include "main_char.h"
#include<math.h>

//Get Functions

coordinate* get_cPosition(character* char1)
{
    return get_oPosition(char1->disposition);
}

coordinate* get_cSpeed(character* char1)
{
    return get_oSpeed(char1->disposition);
}

coordinate* get_cHitbox(character* char1)
{
    return get_oHitbox(char1->disposition);
}

object* get_cObject(character* char1)
{
    return char1->disposition;
}

int get_cHP(const character* char1)
{
    return char1->hp;
}

int get_cAlive(const character* char1)
{
    return char1->alive;
}

int get_cState(const character* char1)
{
    return char1->pose;
}

//Set Functions
void set_cHP(character* cha,int hp) // modifie les points de vie du personnage
{
    cha->hp=hp;
}
void set_cLife(character* cha,int life) // modifier l'etat mort ou vivant 0 mort, 1 vivant
{
    cha->alive=life;
}
// void set_cgear (character * cha,weapon gear); // modifier le tableau d'arme A FAIRE PLUS TARD !!!!!!!!!!!!
// void set_cgrenades (character * cha,int nb_grenades); //modifier le nombre de grenade

void set_cState(character* cha, state state1) // modifier l'état du personnage
{
    cha->pose=state1;
}

void set_cPosition(character* char1, int x, int y)
{
    set_oPosition(char1->disposition, x, y);
} // la position du perso

void set_cSpeed(character* char1, int x, int y) // la rapidite
{
    set_oSpeed(char1->disposition, x, y);
}

void set_cHitbox(character* char1, int x, int y) // la hitbox , en fonction de getposition
{
    set_oHitbox(char1->disposition, x, y);
}

//Various Functions
character* init_mainChar()//  initialisation et libération
{
    character* char1;

    char1=malloc(sizeof(character));
    char1->disposition = init_object();

    set_oPosition(char1->disposition, 60, (640-200-80)); // initialise la position du personnage a x=0, y=0
    set_oSpeed(char1->disposition, 0, 1); // initialise la vitesse du personnage a x=0, y=0 (vitesse nulle)
    set_oHitbox(char1->disposition, 60, 80); // itinialise la hit box

    set_cHP(char1,100);
    set_cLife(char1,1); // modifier l'etat mort ou vivant 0 mort, 1 vivant
    set_cState(char1,normal);

    return char1;
}

void free_mainChar(character * char1) // libere le main_char !
{
    set_cHP(char1,100);
    set_cLife(char1,1); // modifier l'etat mort ou vivant 0 mort, 1 vivant
    set_cState(char1,normal);

    free_object(char1->disposition);
    free(char1);
}

void move_char(character* char1)
{
    coordinate* movement;
    coordinate* speed;

    movement = get_cPosition(char1);
    speed = get_cSpeed(char1);

    set_cPosition(char1, movement->x+speed->x, movement->y+speed->y);
    if(get_cState(char1) != jump)
        set_cSpeed(char1, 0, speed->y);
}

void cJump(character* char1)
{
    coordinate* speed;
    speed = get_cSpeed(char1);

    set_cSpeed(char1, speed->x, (speed->y +1));

    if(get_cSpeed(char1)->y >= 10)
    {
       set_cState(char1, normal);
       set_cSpeed(char1, speed->x, 0);
    }
}
