#include "struct.h"
#include "object.h"

struct sPlateform
{
    object disposition;
};
typedef struct sPlateform plateform;

//Init and Destruction

plateform* init_plateform();
void free_plateform(plateform* pf);

//Get functions

int get_pID(const plateform * pf);
coordinate get_pPosition(const plateform *pf);
coordinate get_pSpeed(const plateform *pf);
coordinate get_pHitbox(const plateform *pf);

//Set functions

void set_pID(plateform *pf, int id);
void set_pPosition(plateform *pf, int x, int y);
void set_pSpeed(plateform *pf, int x, int y);
void set_pHitbox(plateform *pf, int x, int y);

//Creation
void create_plateform(plateform *pf, int id, int xpos, int ypos, int xhit, int yhit);

