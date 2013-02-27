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
    set_dScreen (disp, height, width, format, mode); /* initialise l'écran */
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
    set_sPosition (sp, 0, 0);
    return sp;
}

display* initialize_display_module()
{
    display *disp;
    initialize_SDL();
    disp = initialize_display(640, 480, 32, "SDL_HWSURFACE | SDL_DOUBLEBUF", "prototype");
    SDL_FillRect(get_dScreen(disp), NULL, SDL_MapRGB(disp->screen->format, 0, 0, 0)); /* initialise l'écran en noir */
    return disp;
}

void free_SDL()
{
    SDL_Quit();
}

void free_display(display *disp)
{
    set_dDefiniton (disp, 0, 0);
    SDL_FreeSurface(get_dScreen(disp));
    free_sprite(get_dCharacter(disp));
    free_sprite(get_dPlatform(disp));
    free(disp);
}

void free_sprite(sprite *sp)
{
    SDL_FreeSurface(get_sImage(sp));
    set_sPosition (sp, 0, 0);
    free(sp);
}

void free_display_module(display *disp)
{
    free_display(disp);
    free_SDL();
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

void set_dDefiniton (display *disp, int height, int width)
{
    disp->definition->y=height;
    disp->definition->x=width;
}

void set_dScreen (display *disp, int height, int width, int format, char *mode)
{
    disp->screen = SDL_SetVideoMode(height, width, format, mode);
}

void set_dCharacter (display *disp, char *path, int height, int width)
{
    if (path == NULL)
        set_sImage(get_dCharacter(disp), path);
    set_sPosition(get_dCharacter(disp), height, width);
}

void set_dPlatform (display *disp, char *path, int height, int width)
{
    if (path == NULL)
        set_sImage(get_dPlatform(disp), path);
    set_sPosition(get_dPlatform(disp), height, width);
}

void set_sImage (sprite *sp, char *path)
{
    if (path == NULL)
        sp->image = SDL_LoadBMP(path);
}

void set_sPosition (sprite *sp, int height, int witdh)
{
    sp->position->y = height;
    sp->position->x = witdh;
}

int convert_position_obj (int height_screen, int obj_position, int screen_position, int height_obj)
{
    return height_screen - (obj_position - screen_position) - height_obj;
}

void change_position_character (display *disp, int height, int width)
{
    set_sPosition(get_dCharacter(disp), height, width);
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
