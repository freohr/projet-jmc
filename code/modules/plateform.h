#include "struct.h"
#include "object.h"

struct sPlateform
{
    object disposition;
};
typedef struct sPlateform plateform;

//Init and Destruction

void init_plateform(plateform* pf);
void free_plateform(plateform* pf);

//Get functions

int get_pID(const plateform * pf);
int get_pPosition(const plateform *pf);
int get_pSpeed(const plateform *pf);
int get_pHitbox(const plateform *pf);

//Set functions

void set_pID(plateform *pf, int id);
void set_pPosition(plateform *pf, int x, int y);
void set_pSpeed(plateform *pf, int x, int y);
void set_pHitbox(plateform *pf, int x, int y);

//Creation
void create_plateform(plateform *pf, int id, int xpos, int ypos, int xspeed, int yspeed, int xhit, int yhit);

