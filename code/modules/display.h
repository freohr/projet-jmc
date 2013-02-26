#ifndef _DISPLAY_
#define _DISPLAY_

#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include"struct.h"

struct sScreen
{
	coordinate definiton; /* taille de l'écran */
	plan plans[];
	int nb_plans;
}
typedef struct sScreen screen

struct sPlan
{
	SDL_Surface sprite;
	int nb_images;
	int max_images;
}
typedef struct sPlan plan

#endif
