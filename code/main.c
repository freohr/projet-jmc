#include<stdio.h>
#include<stdlib.h>

#include <SDL/SDL.h>
#include "modules/display.h"
#include "modules/engine.h"
#include "modules/plateform.h"

int main(int argc, char *argv[])
{

    int continuer = 1; /* la variable coninuer sera égale à 0 si on veux quitter le programme */

    // test Display
    int i;

    display *disp;
    SDL_Event event;
    initialize_SDL();
    disp = initialize_display_module();

    set_dCharacter(disp, "sprite/main_character.bmp", 60, 80, 60, 80);
    set_dPlatform(disp, "sprite/floor.bmp", 640, 200, (640-200), 0);

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
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                    case SDLK_LEFT:
                        set_dCharacter(disp, NULL, 60, 80, 120, 80);
                        break;
                }
                break;
        }
        display_all(disp);
    }
    free_display_module(disp);

    free_SDL();



    //test collision
    /*plateform* p1;
    plateform* p2;
    int coll;

    p1 = init_plateform();
    p2 = init_plateform();

    create_plateform(p1, 1, 20, 20, 0, 0, 5, 30);
    create_plateform(p2, 2, 30, 30, 0, 0, 10, 10);
    coll = collision(p1, p2);*/

    return 0;
}
