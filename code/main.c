#include<stdio.h>
#include<stdlib.h>

#include <SDL/SDL.h>
#include "modules/display.h"
#include "modules/engine.h"
#include "modules/plateform.h"
#include "modules/main_char.h"
#include "modules/input.h"

int main(int argc, char *argv[])
{

    // Init Display/SDM
    int continuer = 1; /* la variable coninuer sera �gale � 0 si on veux quitter le programme */
    display *disp;

    SDL_Event event;
    SDL_Event input;
    int repeat;

    disp = initialize_display_module();
    initialize_SDL();
    repeat = SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);

    //Init du main_char
    character* main_char;
    main_char = init_mainChar();

    coordinate* speed;
    state cState;

    //Init Plateforme
    plateform* floor;
    floor = init_plateform();

    set_pHitbox(floor, 640, 200);
    set_pPosition(floor, 0, 640-200);

    set_dCharacter_sprite(disp, "sprite/main_character.bmp");
    set_dPlatform_sprite(disp, "sprite/floor.bmp");

    set_dPlatform_position(disp, get_pPosition(floor));

    SDL_BlitSurface(disp->platform->image, NULL, disp->screen, disp->platform->position);



    while(continuer)
    {

        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                }
            /*
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    set_dCharacter_position(disp, event.button.x, event.button.y);
                    break;
            }
            display_all(disp);
            */
        }

        speed = get_cSpeed(main_char);
        cState = get_cState(main_char);

        while(SDL_PollEvent(&input))
        {
            switch(input.type)
            {
                case SDL_KEYDOWN:
                    switch(input.key.keysym.sym)
                    {
                        case SDLK_LEFT:
                            if(cState == jump)
                                set_cSpeed(main_char, speed->x-1, speed->y);
                            else
                                set_cSpeed(main_char, -1, speed->y);

                        case SDLK_RIGHT:
                            if(cState == jump)
                                set_cSpeed(main_char, speed->x+1, speed->y);
                            else
                                set_cSpeed(main_char, 1, speed->y);

                        default:
                           set_cSpeed(main_char, 0, speed->y);
                    }

            }
        }

    /*  input_cMove(main_char); */
        move_char(main_char);

        set_dCharacter_position(disp, get_cPosition(main_char));

        SDL_BlitSurface(disp->character->image, NULL, disp->screen, disp->character->position);
        SDL_Flip(disp->screen);
        //display_all(disp);
    }

    free_display_module(disp);
    free_SDL();

    free_mainChar(main_char);
    free_plateform(floor);

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
