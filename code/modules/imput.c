#include "imput.h"
/* vide pour l'instant, a supprimer peut être */

void input_cMove(character* char1)
{
    coordinate speed;
    SDL_Event input;

    speed = get_cSpeed(char1);

    while(SDL_PollEvent(&input))
    {
        switch(input.type)
        {
            case SDL_KEYDOWN:
                switch(input.key.keysym.sim)
                {
                    case SDLK_LEFT:
                        if(get_cstate(char1) == jump)
                            set_cSpeed(char1, speed.x-1, speed.y);
                        else
                            set_cSpeed(char1, -1, speed.y);

                    case SDLK_RIGHT:
                        if(get_cstate(char1) == jump)
                            set_cSpeed(char1, speed.x+1, speed.y);
                        else
                            set_cSpeed(char1, 1, speed.y);

                    default:
                       set_cSpeed(char1, 0, speed.y);
                }

        }
    }
}

void input_cAction(character* char1)
{
    SDL_Event input;

    while(SDL_PollEvent(&input))
    {
        switch(input.type)
        {
            case SDL_KEYDOWN:
                switch(input.key.keysym.sim)
                {
                    case SDLK_SPACE:
                        set_cstate(char1, jump);
                }
        }
    }
}
