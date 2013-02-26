#include "display.h"

void initialize_SDL()
{
    SDL_Init(SDL_INIT_VIDEO);
}

display* initialize_display(int height, int width, int format, char *mode, char *window_name)
{
    display *disp;
    disp = malloc(sizeof(display));
    set_dDefiniton (disp, height, width); /* initialisation de la taille */
    set_dScreen (disp, height, width, format, mode); /* initialise l'�cran */
    SDL_WM_SetCaption(window_name, NULL); /* met le nom donn� en param�tre � la fen�tre */
    disp->character = initialize_sprite();
    disp->platform = initialize_sprite();
    return disp;
}

sprite* initialize_sprite()
{
    sprite *sp;
    sp = malloc(sizeof(sprite));
    sp->image = NULL;
    set_sPosition (sp, 0, 0);
    return sp;
}

void initialize_display_module()
{
    display *disp;
    initialize_SDL();
    disp = initialize_display(640, 480, 32, "SDL_HWSURFACE | SDL_DOUBLEBUF", "prototype");
    SDL_FillRect(disp->screen, NULL, SDL_MapRGB(disp->screen->format, 0, 0, 0)); /* initialise l'�cran en noir */
}

void free_SDL()
{
    SDL_Quit();
}

void free_display(display *disp)
{
    set_dDefiniton (disp, 0, 0);
    SDL_FreeSurface(disp->screen);
    free_sprite(disp->character);
    free_sprite(disp->platform);
    free(disp);
}

void free_sprite(sprite *sp)
{
    SDL_FreeSurface(sp->image);
    set_sPosition (sp, 0, 0);
    free(sp);
}

void free_display_module(display *disp)
{
    free_display(disp);
    free_SDL();
}

/* get */

SDL_Rect get_dDefinition (const display *disp)
{
    return disp->definition;
}

SDL_Surface* get_dScreen (const display *disp)
{
    return disp->screen;
}

sprite* get_dCharacter (const display *disp)
{
    return disp->character;
}

sprite* get_dPlatform (const display *disp)
{
    return disp->platform;
}

SDL_Surface* get_sImage (const sprite *sp)
{
    return sp->image;
}

SDL_Rect get_sPosition (const sprite *sp)
{
    return sp->position;
}

/* set */

void set_dDefiniton (display *disp, int height, int width)
{
    disp->definition.y=height;
    disp->definition.x=width;
}

void set_dScreen (display *disp, int height, int width, int format, char *mode)
{
    disp->screen = SDL_SetVideoMode(height, width, format, mode);
}

void set_dCharacter (display *disp, char *path, int height, int width)
{
    if (path == NULL)
        set_sImage(disp->character, path);
    set_sPosition(disp->character, height, width);
}

void set_dPlatform (display *disp, char *path, int height, int width)
{
    if (path == NULL)
        set_sImage(disp->platform, path);
    set_sPosition(disp->character, height, width);
}

void set_sImage (sprite *sp, char *path)
{
    if (path == NULL)
        sp->image = SDL_LoadBMP(path);
}

void set_sPosition (sprite *sp, int height, int witdh)
{
    sp->position.y = height;
    sp->position.x = witdh;
}

int convert_position_obj (int height_screen, int obj_position, int screen_position, int height_obj)
{
    return height_screen - (obj_position - screen_position) - height_obj;
}
