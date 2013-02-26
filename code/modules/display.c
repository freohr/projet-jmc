#include "display.h"

void initialize_SDL()
{
    SDL_Init(SDL_INIT_VIDEO);
}


void free_SDL()
{
    SDL_Quit();
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
    set_sImage(disp->character, path);
}

void set_dPlatform (display *disp, char *path, int height, int width)
{
    set_sImage(disp->platform, path);
}

void set_sImage (sprite *sp, char *path)
{
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
