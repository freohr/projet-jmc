#include<stdio.h>
#include<stdlib.h>

#include <SDL/SDL.h>
#include "modules/display.h"

int main(int argc, char *argv[])
{
    int continuer = 1; /* la variable coninuer sera égale à 0 si on veux quitter le programme */
    display *disp;
    SDL_Event event;
    initialize_SDL();
    disp = initialize_display_module();

    set_dCharacter(disp, "sprite/main_character.bnp", 60, 80, 60, 80);
    set_dPlatform(disp, "sprite/main_character.bnp", 640, 200, (640-200), 0);

    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                set_dCharacter(disp, NULL, 60, 80, event.button.x, event.button.y);
                break;
            }
            break;
        }
        display_all(disp);
    }
    free_display_module(disp);
    free_SDL();

    return 0;
}
