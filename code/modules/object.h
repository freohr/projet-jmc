#ifndef _OBJECT_
#define _OBJECT_

#include<stdio.h>
#include<stdlib.h>

#include "struct.h"

enum eType
{
    main_character = 1,
    ennemi = 2,
    plateforme = 3,
    bullet = 4,
};
typedef enum eType typeID;

struct sObject
{
    int ID;
    typeID type;
    coordinate position;
    coordinate speed;
    coordinate hitbox;
};
typedef struct sObject object;

//Initialising Objects

object* init_object();

void free_object(object* obj1);

// Get Functions
// TODO : rajouter sprite et direction

int get_oID(const object* obj1);
int get_oType(object* obj1);
coordinate* get_oPosition(object* obj1);
coordinate* get_oSpeed(object* obj1);
coordinate* get_oHitbox(object* obj1);

// Set Functions
// TODO : rajouter sprite et direction

void set_oID(object* obj1, int id);
void set_oType(object* obj1, int typeID);
void set_oPosition(object* obj1, int x, int y);
void set_oSpeed(object* obj1, int x, int y);
void set_oHitbox(object* obj1, int x, int y);

#endif
