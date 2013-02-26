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
	SDL_Rect definition; /* taille de l'écran */
	SDL_Surface *screen;
	sprite *character;
	sprite *platform;
};
typedef struct sDisplay display;

/* fonctions d'initialisation  et de libérations */

void initialize_SDL();
display* initialize_display(int height, int width, int format, char *mode, char *window_name);
/* précondition :   - weight et width contiennent la taille de l'écran
                    - format contient le format de codage des pixel (mettre a 32)
                    - mode est le mode d'affichage de l'écran
                    - window_name est le nom a donner a la fenêtre
   postcondition : display initialisé et screen contient une image noire de la taille de l'écran*/

sprite* initialize_sprite();
/* postcondition : display initialisé et screen contient une image noire de la taille de l'écran*/
void initialize_display_module();

void free_SDL();
void free_display(display *disp);
void free_sprite(sprite *sp);
void free_display_module(display *disp);

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
/* précondition :   - weight et width contiennent la taille de l'écran
                    - format contient le format de codage des pixel (mettre a 32)
                    - mode est le mode d'affichage de l'écran

*/
void set_dCharacter (display *disp, char *path, int height, int width);
/* précondition :   - disp initialisé
                    - path contient le chemin relatif de l'image
                    - si path est NULL, l'image ne sera pas changée
                    - weight et width contiennent la position de l'image */
void set_dPlatform (display *disp, char *path, int height, int width);
/* précondition :   - disp initialisé
                    - path contient le chemin relatif de l'image
                    - si path est NULL, l'image ne sera pas changée
                    - weight et width contiennent la position de l'image */
void set_sImage (sprite *sp, char *path);
/* précondition :   - sp initialisé
                    - path contient le chemin relatif de l'image
                    - si path est NULL, l'image ne sera pas changée*/

void set_sPosition (sprite *sp, int height, int witdh);
/* précondition :   - disp initialisé
                    - weight et width contiennent la position de l'image */

int convert_position_obj (int height_screen, int obj_position, int screen_position, int height_obj);
/* la SDL considére que le point (0,0) est en haut à gauche de l'écran
tandis que notre moteur considére que le point (0,0) est en bas à droite
du niveau, cette fonction convertis une hauteur envoyée par le moteur
en une hauteur utilisable pour la SDL */



#endif
