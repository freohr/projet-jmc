#include<stdio.h>
#include<stdlib.h>

#include "modules/display.h"

int main(int argc, char *argv[])
{
    int i;
    display *disp;
    disp = initialize_display_module();
    set_dCharacter(disp, "sprite/main_character.bnp", (640-200-80), 0);
    set_dPlatform(disp, "sprite/main_character.bnp", (640-200), 0);
    display_all(disp);
    for(i=0; i<480; i++)
    {
        set_dCharacter(disp, "sprite/main_character.bnp", (640-200-80), 0);
        display_all(disp);
    }
    free_display_module(disp);
    return 0;
}
