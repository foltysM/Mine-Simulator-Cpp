#ifndef DESK_H
#define DESK_H

#include "abovegroundworkeritem.h"


class Desk:public AboveGroundWorkerItem
{
public:
    Desk();
    double useItem();
    void special(Game *g);
};

#endif // DESK_H
