#include "engine.h"

int test_collision(object* obj1, object* obj2)
{
    coordinate* size1;
    coordinate* position1;
    coordinate* size2;
    coordinate* position2;

    size1 = get_oHitbox(obj1);
    position1 = get_oPosition(obj1);
    size2 = get_oHitbox(obj2);
    position1 = get_oHitbox(obj2);

    if(position1->x + size1->x >= position2->x && (position1->y + size1->y >= position2->y && position1->y + size1->y <= position2->y + size2->y))
        return 1;
    else if(position2->x + size2->x >= position1->x  && (position2->y + size2->y >= position1->y && position2->y + size2->y <= position1->y + size1->y))
        return 2;
    else if(position1->y + size1->y >= position2->y && position1->y <= position2->y + size2->y)
        return 3;
    else if(position2->y + size2->y >= position1->y && position2->y <= position1->y + size1->y)
        return 4;
    else
        return 0;
}


void collision(object* obj1, object* obj2)
{
    IDtype type_obj1;
    IDtype type_obj2;
    int coll;

    type_obj1 = get_oType(obj1);
    type_obj2 = get_oType(obj2);

    coll = test_collision(obj1, obj2);

    if(coll)
    {
        switch(type_obj1)
        {
            case main_character:
                switch(type_obj2)
                {
                    case plateforme:
                        switch(coll)
                        {
                            case 1:
                                set_oPosition(obj1, get_oPosition(obj2)->x-get_oHitbox(obj1)->x, get_oPosition(obj1)->y);
                                set_oSpeed(obj1, 0, get_oSpeed(obj1)->y);
                                break;

                            case 2:
                                set_oPosition(obj1, get_oPosition(obj2)->x+get_oHitbox(obj2)->x, get_oPosition(obj1)->y);
                                set_oSpeed(obj1, 0, get_oSpeed(obj1)->y);
                                break;

                            case 3:
                                set_oPosition(obj1, get_oPosition(obj1)->x, get_oPosition(obj2)->y + get_oHitbox(obj2)->y + 1);
                                set_oSpeed(obj1, get_oSpeed(obj1)->x, -(get_oSpeed(obj1)->y));
                                break;

                            case 4:
                                set_oPosition(obj1, get_oPosition(obj1)->x, get_oPosition(obj2)->y - get_oHitbox(obj1)->y - 1);
                                set_oSpeed(obj1, get_oSpeed(obj1)->x, 0);
                                break;
                        }
                }
                break;

            case plateforme:
                switch(type_obj2)
                {
                    case main_character:
                        switch(coll)
                        {
                            case 1:
                                set_oPosition(obj2, get_oPosition(obj1)->x+get_oHitbox(obj1)->x, get_oPosition(obj2)->y);
                                set_oSpeed(obj2, 0, get_oSpeed(obj2)->y);
                                break;

                            case 2:
                                set_oPosition(obj2, get_oPosition(obj1)->x-get_oHitbox(obj2)->x, get_oPosition(obj2)->y);
                                set_oSpeed(obj2, 0, get_oSpeed(obj2)->y);
                                break;

                            case 3:
                                set_oPosition(obj2, get_oPosition(obj2)->x, get_oPosition(obj1)->y - get_oHitbox(obj2)->y - 1);
                                set_oSpeed(obj2, get_oSpeed(obj2)->x, 0);
                                break;

                            case 4:
                                set_oPosition(obj2, get_oPosition(obj2)->x, get_oPosition(obj1)->y + get_oHitbox(obj1)->y + 1);
                                set_oSpeed(obj2, get_oSpeed(obj2)->x, -(get_oSpeed(obj2)->y));
                                break;


                        }
                }
                break;
        }
    }
}

