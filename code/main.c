#include<stdio.h>
#include<stdlib.h>

#include "modules/display.h"
#include "modules/engine.h"
#include "modules/plateform.h"

int main(int argc, char *argv[])
{
    // test Display
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
