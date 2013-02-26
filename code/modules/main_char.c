#include "main_char.h"

<<<<<<< HEAD

=======
>>>>>>> ed43c118bcb8e589e23b61b7f1efba6fb799e650
//Get Functions

coordinate get_cPosition(const character* char1)
{
    return get_oPosition(&(char1->disposition));
}

coordinate get_cSpeed(const character* char1)
{
    return get_oSpeed(&(char1->disposition));
}

coordinate get_cHitbox(const character* char1)
{
    return get_oHitbox(&(char1->disposition));
}

int get_cHP(const character* char1)
{
    return char1->hp;
}

int get_cAlive(const character* char1)
{
    return char1->alive;
}

