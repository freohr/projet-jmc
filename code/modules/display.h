#ifndef _DISPLAY_
#define _DISPLAY_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

struct sSprite
{
    SDL_Surface *image;
    SDL_Rect *position; /* position contient la taille et la position de l'image */
};
typedef struct sSprite sprite;

struct sDisplay
{
	SDL_Rect *definition; /* taille de l'écran */
	SDL_Surface *screen;
	sprite *character;
	sprite *platform;
};
typedef struct sDisplay display;

/* fonctions d'initialisation  et de libérations */

void initialize_SDL();
display* initialize_display(int width, int height, int format, Uint32 flags, const char *window_name);
/* précondition :   - weight et width contiennent la taille de l'écran
                    - format contient le format de codage des pixel (mettre a 32)
                    - flags est le mode d'affichage de l'écran
                    - window_name est le nom a donner a la fenêtre
   postcondition : display initialisé et screen contient une image noire de la taille de l'écran*/

sprite* initialize_sprite();
/* postcondition : display initialisé et screen contient une image noire de la taille de l'écran*/
display* initialize_display_module();
SDL_Rect* initialize_SDL_Rect(int widht, int height, int x, int y);
/* les varaibles SDL_Rect que nous utilisons sont des pointeurs, il nous faut donc une voariable
pour initaliser le pointeur */

void free_SDL();
void free_display(display *disp);
void free_sprite(sprite *sp);
void free_display_module(display *disp);
void free_SDL_Rect(SDL_Rect *rect);

/* get */
SDL_Rect* get_dDefinition (const display *disp);
SDL_Surface* get_dScreen (const display *disp);
sprite* get_dCharacter (const display *disp);
sprite* get_dPlatform (const display *disp);
SDL_Surface* get_sImage (const sprite *sp);
SDL_Rect* get_sPosition (const sprite *sp);

/* set */
void set_dDefiniton (display *disp, int width, int height);
void set_dScreen (display *disp, int width, int height, int format, Uint32 flags);
/* précondition :   - weight et width contiennent la taille de l'écran
                    - format contient le format de codage des pixel (mettre a 32)
                    - flags est le mode d'affichage de l'écran
*/

void set_dCharacter_sprite (display *disp, char *path);
/* précondition :   - disp initialisé
                    - path contient le chemin relatif de l'image
   postcondition : la taille du sprite est contenue dans SDL_Surface */

void set_dCharacter_position (display *disp, int x, int y);
/* précondition :   -disp initialisé
                    - x et y contiennent la position du personnage */

void set_dPlatform_sprite (display *disp, char *path);
/* précondition :   - disp initialisé
                    - path contient le chemin relatif de l'image */

void set_dPlatform_position (display *disp, int x, int y);
/* précondition :   - disp initialisé
                    - x et y contiennent la position de la plateforme
   postcondition : la taille du sprite est contenue dans SDL_Surface */

void set_sImage (sprite *sp, char *path);
/* précondition :   - sp initialisé
                    - path contient le chemin relatif de l'image*/

void set_sPosition (sprite *sp, int x, int y);
/* précondition :   - disp initialisé
                    - x et y contiennent la position de l'image
   postcondition : la taille du sprite est contenue dans SDL_Surface */

int convert_position_obj (int height_screen, int obj_position, int screen_position, int height_obj);
/* la SDL considére que le point (0,0) est en haut à gauche de l'écran
tandis que notre moteur considére que le point (0,0) est en bas à droite
du niveau, cette fonction convertis une hauteur envoyée par le moteur
en une hauteur utilisable pour la SDL */

void display_all(const display *disp);

#endif
