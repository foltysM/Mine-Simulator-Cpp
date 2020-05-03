#ifndef DESK_H
#define DESK_H

#include "abovegroundworkeritem.h"
//#include "game.h"

class Desk:public AboveGroundWorkerItem
{
private:
    //double reduction;
public:
    Desk();
    double useItem();
   // bool special(Game *g);
};

#endif // DESK_H
