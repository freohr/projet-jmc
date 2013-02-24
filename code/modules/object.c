// Initialisation and Destruction
void init_object(object* obj1)
{
    obj1->ID = 0;
    obj1->position.x = 1;
    obj1->position.y = 1;
    obj1->speed.x = 0;
    obj1->speed.y = 0;
    obj1->hitbox.x = 1;
    obj1->hitbox.y = 1;
}

void free_object(object* obj1)
{
    obj1->ID = 0;
    obj1->position.x = 0;
    obj1->position.y = 0;
    obj1->speed.x = 0;
    obj1->speed.y = 0;
    obj1->hitbox.x = 0;
    obj1->hitbox.y = 0;

    free(obj1);
}

// Get Functions

int get_oID(object obj1)
{
    return obj1->ID;
}

coordinate get_oPosition(object obj1)
{
    return obj1->position;
}

coordinate get_oSpeed(object obj1)
{
    return obj1->speed;
}

coordinate get_oHitbox(object obj1)
{
    return obj1->hitbox;
}

//Set Funcions

void set_oID(object* obj1, int id)
{
    obj1->ID = id;
}

void set_oPosition(object* obj1, int x, int y)
{
    obj1->position.x = x;
    obj1->position.y = y;
}

void set_oSpeed(object* obj1, int x, int y)
{
    obj1->speed.x = x;
    obj1->speed.y = y;
}

void set_oHitbox(object* obj1, int x, int y)
{
    obj1->hitbox.x = x;
    obj1->hitbox.y = y;
}
