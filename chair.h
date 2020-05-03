#ifndef CHAIR_H
#define CHAIR_H

#include "abovegroundworkeritem.h"
//#include "game.h"

class Chair: public AboveGroundWorkerItem
{
private:
    //double reduction;
public:
    Chair();
    double useItem();
   // bool special(Game g);
};

#endif // CHAIR_H
