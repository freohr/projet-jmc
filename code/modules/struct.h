#ifndef _STRUCT_H_
#define _STRUCT_H_

#include<stdlib.h>
#include<stdio.h>

struct sCoordinate
{
    int x;
    int y;
};
typedef struct sCoordinate coordinate;

enum eState
{
    crouch=1,
    hit=2,
    jump=3,
    normal=4
};
typedef enum eState state;



#endif
