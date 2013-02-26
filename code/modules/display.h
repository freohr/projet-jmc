#ifndef _DISPLAY_
#define _DISPLAY_

#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include"struct.h"

struct sSprite
{
    SDL_Surface *image;
    SDL_Rect position;
};
typedef struct sSprite sprite;

struct sDisplay
{
	SDL_Rect definition; /* taille de l'�cran */
	SDL_Surface *screen;
	sprite *character;
	sprite *platform;
};
typedef struct sDisplay display;

void initialize_SDL();
display* initialize_display();
sprite* initialize_sprite();

void free_SDL();
void free_display();
void free_sprite();

/* get */
SDL_Rect get_dDefinition (const display *disp);
SDL_Surface* get_dScreen (const display *disp);
sprite* get_dCharacter (const display *disp);
sprite* get_dPlatform (const display *disp);
SDL_Surface* get_sImage (const sprite *sp);
SDL_Rect get_sPosition (const sprite *sp);

/* set */
void set_dDefiniton (display *disp, int height, int width);
void set_dScreen (display *disp, int height, int width, int format, char *mode);
void set_dCharacter (display *disp, char *path, int height, int width);
/* pr�condition :   - disp initialis�
                    - path contient le chemin relatif de l'image
                    - weight et width contiennent la position de l'image */
void set_dPlatform (display *disp, char *path, int height, int width);
/* pr�condition :   - disp initialis�
                    - path contient le chemin relatif de l'image
                    - weight et width contiennent la position de l'image */
void set_sImage (sprite *sp, char *path);
/* pr�condition :   - sp initialis�
                    - path contient le chemin relatif de l'image */

void set_sPosition (sprite *sp, int height, int witdh);
/* pr�condition :   - disp initialis�
                    - weight et width contiennent la position de l'image */


int convert_position_obj (int height_screen, int obj_position, int screen_position, int height_obj);
/* la SDL consid�re que le point (0,0) est en haut � gauche de l'�cran
tandis que notre moteur consid�re que le point (0,0) est en bas � droite
du niveau, cette fonction convertis une hauteur envoy�e par le moteur
en une hauteur utilisable pour la SDL */

#endif
