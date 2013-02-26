#ifndef _OBJECT_
#define _OBJECT_

#include<stdio.h>
#include<stdlib.h>

#include "struct.h"

struct sObject
{
    int ID;
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
coordinate get_oPosition(const object* obj1);
coordinate get_oSpeed(const object* obj1);
coordinate get_oHitbox(const object* obj1);

// Set Functions
// TODO : rajouter sprite et direction

void set_oID(object* obj1, int id);
void set_oPosition(object* obj1, int x, int y);
void set_oSpeed(object* obj1, int x, int y);
void set_oHitbox(object* obj1, int x, int y);

#endif
