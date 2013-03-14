#include<stdio.h>
#include<stdlib.h>

#include <SDL/SDL.h>
#include "modules/display.h"
#include "modules/engine.h"
#include "modules/plateform.h"

int main(int argc, char *argv[])
{
    // test Display
    int continuer = 1; /* la variable coninuer sera égale à 0 si on veux quitter le programme */
    display *disp;
    SDL_Event event;
    initialize_SDL();
    disp = initialize_display_module();

    set_dCharacter_sprite(disp, "sprite/main_character.bmp");
    set_dCharacter_position(disp, 60, (640-200-80));
    set_dPlatform_sprite(disp, "sprite/floor.bmp");
    set_dPlatform_position(disp, 0, (640-200));
    display_all(disp);
    SDL_Flip(disp->screen);

    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        /*
        case SDL_MOUSEBUTTONDOWN:
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                set_dCharacter_position(disp, event.button.x, event.button.y);
                break;
            }
            break;
        }
        display_all(disp);
        */
        }
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
