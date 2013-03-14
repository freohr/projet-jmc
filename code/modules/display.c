#include "display.h"

// Inits and Frees

display* initialize_display(int width, int height, int format, Uint32 flags, const char *window_name)
{
    display *disp;
    disp = malloc(sizeof(display));
    disp->definition = initialize_SDL_Rect(width, height,0,0); /*initialisation de la taille de l'écran */
    set_dScreen (disp, width, height, format, flags); /* initialise l'écran */
    SDL_WM_SetCaption(window_name, NULL); /* met le nom donné en paramètre à la fenètre */
    disp->character = initialize_sprite(); /* initialisation de character */
    disp->platform = initialize_sprite(); /*initialisation de plateforme */
    return disp;
}

sprite* initialize_sprite()
{
    sprite *sp;
    sp = malloc(sizeof(sprite));
    sp->image = NULL;
    sp->position = initialize_SDL_Rect(0, 0, 0, 0);
    return sp;
}

display* initialize_display_module()
{
    display *disp;
    disp = initialize_display(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF, "prototype");
    SDL_FillRect(get_dScreen(disp), NULL, SDL_MapRGB(disp->screen->format, 0, 0, 0)); /* initialise l'écran en noir */
    return disp;
}

SDL_Rect* initialize_SDL_Rect(int width, int height, int x, int y)
{
    SDL_Rect *rect;
    rect = malloc(sizeof(SDL_Rect));
	rect->h = height;
	rect->w = width;
	rect->x = x;
	rect->y = y;
	return rect;
}


void free_display(display *disp)
{
    free_SDL_Rect(get_dDefinition(disp));
    SDL_FreeSurface(get_dScreen(disp));
    free_sprite(get_dCharacter(disp));
    free_sprite(get_dPlatform(disp));
    free(disp);
}

void free_sprite(sprite *sp)
{
    SDL_FreeSurface(get_sImage(sp));
    free_SDL_Rect(get_sPosition(sp));
    free(sp);
}

void free_display_module(display *disp)
{
    free_display(disp);
    free_SDL();
}

void free_SDL_Rect(SDL_Rect *rect)
{
    rect->h = 0;
    rect->w = 0;
    rect->x = 0;
    rect->y = 0;
    free(rect);
}

/* get */

SDL_Rect* get_dDefinition (const display *disp)
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

SDL_Rect* get_sPosition (const sprite *sp)
{
    return sp->position;
}


/* set */

void set_dDefiniton (display *disp, int width, int height)
{
    disp->definition->h=height;
    disp->definition->w=width;
}

void set_dScreen (display *disp, int width, int height, int format, Uint32 flags)
{
    disp->screen = SDL_SetVideoMode(width, height, format, flags);
}

void set_dCharacter_sprite (display *disp, char *path)
{
    set_sImage(get_dCharacter(disp), path);
}

void set_dCharacter_position (display *disp, coordinate* position)
{
    set_sPosition(get_dCharacter(disp), position->x, position->y);
}

void set_dPlatform_sprite (display *disp, char *path)
{
    set_sImage(get_dPlatform(disp), path);
}

void set_dPlatform_position (display *disp, coordinate* position)
{
    set_sPosition(get_dPlatform(disp), position->x, position->y);
}

void set_sImage (sprite *sp, char *path)
{
    sp->image = SDL_LoadBMP(path);
}

void set_sSize (sprite *sp, int width, int height)
{
    sp->position->h = height;
    sp->position->w = width;
}

void set_sPosition (sprite *sp, int x, int y)
{
    sp->position->x = x;
    sp->position->y = y;
}


// Various
int convert_position_obj (int height_screen, int obj_position, int screen_position, int height_obj)
{
    return height_screen - (obj_position - screen_position) - height_obj;
}

void change_position_character (display *disp, int width, int height)
{
    set_sPosition(get_dCharacter(disp), width, height);
}

void display_all(const display *disp)
{
        SDL_FillRect(get_dScreen(disp), NULL, SDL_MapRGB(disp->screen->format, 0, 0, 0));  /* on réinitialise le fond d'écran */
        SDL_BlitSurface(get_sImage(get_dPlatform(disp)), NULL, get_dScreen(disp), get_sPosition(get_dPlatform(disp)));
            /* on place le plateforme */
        SDL_BlitSurface(get_sImage(get_dCharacter(disp)), NULL, get_dScreen(disp),get_sPosition(get_dCharacter(disp)));
            /* on place le personnage */

        SDL_Flip(get_dScreen(disp)); //on met a jour l'écran
}
