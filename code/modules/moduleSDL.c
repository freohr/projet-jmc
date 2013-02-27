#include "moduleSDL.h"

void initialize_SDL()
{
    SDL_Init(SDL_INIT_VIDEO);
}

void free_SDL()
{
    SDL_Quit();
}
