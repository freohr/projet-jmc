#include "plateform.h"

//Init and Destruction

plateform* init_plateform()
{
    plateform* pf;
    pf=malloc(sizeof(plateform));
    pf->disposition.ID=0;
    pf->disposition.hitbox.x=0;
    pf->disposition.hitbox.y=0;
    pf->disposition.speed.x=0;
    pf->disposition.speed.y=0;
    pf->disposition.position.x=0;
    pf->disposition.position.y=0;
    return pf;
}

void free_plateform(plateform* pf)
{
    pf->disposition.ID=0;
    pf->disposition.hitbox.x=0;
    pf->disposition.hitbox.y=0;
    pf->disposition.speed.x=0;
    pf->disposition.speed.y=0;
    pf->disposition.position.x=0;
    pf->disposition.position.y=0;
    free(pf);
}

//Get functions

int get_pID(const plateform * pf)
{
    return get_oID(&(pf->disposition));
}

coordinate* get_pPosition(const plateform *pf)
{
    return get_oPosition(&(pf->disposition));
}

coordinate*  get_pSpeed(const plateform *pf)
{
    return get_oSpeed(&(pf->disposition));
}

coordinate*  get_pHitbox(const plateform *pf)
{
    return get_oHitbox(&(pf->disposition));
}

//Set functions

void set_pID(plateform *pf, int id)
{
    set_oID(&(pf->disposition), id);
}

void set_pPosition(plateform *pf, int x, int y)
{
    set_oPosition(&(pf->disposition), x, y);
}

void set_pSpeed(plateform *pf, int x, int y)
{
    set_oSpeed(&(pf->disposition), x, y);
}

void set_pHitbox(plateform *pf, int x, int y)
{
    set_oHitbox(&(pf->disposition), x, y);
}

//Creation
void create_plateform(plateform *pf, int id, int xpos, int ypos, int xhit, int yhit)
{
    set_oID(&(pf->disposition), id);
    set_oPosition(&(pf->disposition), xpos, ypos);
    set_oSpeed(&(pf->disposition), 0, 0);
    set_oHitbox(&(pf->disposition), xhit, yhit);
}


