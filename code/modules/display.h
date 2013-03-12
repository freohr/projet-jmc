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
	SDL_Rect *definition; /* taille de l'�cran */
	SDL_Surface *screen;
	sprite *character;
	sprite *platform;
};
typedef struct sDisplay display;

/* fonctions d'initialisation  et de lib�rations */

void initialize_SDL();
display* initialize_display(int width, int height, int format, Uint32 flags, const char *window_name);
/* pr�condition :   - weight et width contiennent la taille de l'�cran
                    - format contient le format de codage des pixel (mettre a 32)
                    - flags est le mode d'affichage de l'�cran
                    - window_name est le nom a donner a la fen�tre
   postcondition : display initialis� et screen contient une image noire de la taille de l'�cran*/

sprite* initialize_sprite();
/* postcondition : display initialis� et screen contient une image noire de la taille de l'�cran*/
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
/* pr�condition :   - weight et width contiennent la taille de l'�cran
                    - format contient le format de codage des pixel (mettre a 32)
                    - flags est le mode d'affichage de l'�cran
*/

void set_dCharacter_sprite (display *disp, char *path);
/* pr�condition :   - disp initialis�
                    - path contient le chemin relatif de l'image
   postcondition : la taille du sprite est contenue dans SDL_Surface */

void set_dCharacter_position (display *disp, int x, int y);
/* pr�condition :   -disp initialis�
                    - x et y contiennent la position du personnage */

void set_dPlatform_sprite (display *disp, char *path);
/* pr�condition :   - disp initialis�
                    - path contient le chemin relatif de l'image */

void set_dPlatform_position (display *disp, int x, int y);
/* pr�condition :   - disp initialis�
                    - x et y contiennent la position de la plateforme
   postcondition : la taille du sprite est contenue dans SDL_Surface */

void set_sImage (sprite *sp, char *path);
/* pr�condition :   - sp initialis�
                    - path contient le chemin relatif de l'image*/

void set_sPosition (sprite *sp, int x, int y);
/* pr�condition :   - disp initialis�
                    - x et y contiennent la position de l'image
   postcondition : la taille du sprite est contenue dans SDL_Surface */

int convert_position_obj (int height_screen, int obj_position, int screen_position, int height_obj);
/* la SDL consid�re que le point (0,0) est en haut � gauche de l'�cran
tandis que notre moteur consid�re que le point (0,0) est en bas � droite
du niveau, cette fonction convertis une hauteur envoy�e par le moteur
en une hauteur utilisable pour la SDL */

void display_all(const display *disp);

#endif
