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
    int continuer = 1; /* la variable coninuer sera égale à 0 si on veux quitter le programme */
    display *disp;

    SDL_Event event;
    int repeat;
  /*  Uint8 *keystate;*/

    disp = initialize_display_module();
    initialize_SDL();
    repeat = SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, 3);

    //Init du main_char
    character* main_char;
    main_char = init_mainChar();

    coordinate* speed;
    state cState;
    int* jumpSpeed;

    //Init Plateforme
    plateform* floor;
    floor = init_plateform();

    set_pHitbox(floor, 640, 200);
    set_pPosition(floor, 0, 640-200);

    set_dCharacter_sprite(disp, "sprite/main_character.bmp");
    set_dPlatform_sprite(disp, "sprite/floor.bmp");

    set_dPlatform_position(disp, get_pPosition(floor));

    SDL_BlitSurface(disp->platform->image, NULL, disp->screen, disp->platform->position);


    speed = get_cSpeed(main_char);
    cState = get_cState(main_char);

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

                     case SDLK_LEFT:
                        if(cState == jump)
                            set_cSpeed(main_char, speed->x-1, speed->y);
                        else
                            set_cSpeed(main_char, -1, speed->y);
                        break;

                    case SDLK_RIGHT:
                        if(cState == jump)
                            set_cSpeed(main_char, speed->x+1, speed->y);
                        else
                            set_cSpeed(main_char, 1, speed->y);
                        break;

                    case SDLK_SPACE:
                        if(cState != jump)
                        {
                            set_cState(main_char, jump);
                            *jumpSpeed = 10;
                        }
                        break;
                }
        }

        if(get_cState(main_char) == jump)
            cJump(main_char, jumpSpeed);

        move_char(main_char);

        set_dCharacter_position(disp, get_cPosition(main_char));

        display_all(disp);
    }

    free_display_module(disp);
    free_SDL();

    free_mainChar(main_char);
    free_plateform(floor);

    return 0;
}
