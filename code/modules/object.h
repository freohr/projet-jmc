#IFNDEF _OBJECT_
#DEFINE _OBJECT_

#include<sdtio.h>
#include<stdlib.h>

struct sCoordinate
{
    int x;
    int y;
};
typedef struct sCoordinate coordinate;

struct sObject
{
    int ID;
    coordinate position;
    coordinate speed;
    coordinate hitbox;
};
typedef struct sObject object;

//Initialising Objects

void init_object(object* obj1);

void free_object(object* obj1);

// Get Functions
// TODO : rajouter sprite et direction

int get_oID(object obj1);
coordinate get_oPosition(object obj1);
coordinate get_oSpeed(object obj1);
coordinate get_oHitbox(object obj1);

// Set Functions
// TODO : rajouter sprite et direction

void set_oID(object* obj1, int id);
void set_oPosition(object* obj1, int x, int y);
void set_oSpeed(object* obj1, int x, int y);
void set_oHitbox(object* obj1, int x, int y);

#ENDIF
