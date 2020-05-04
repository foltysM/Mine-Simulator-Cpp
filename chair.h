#ifndef CHAIR_H
#define CHAIR_H

#include "abovegroundworkeritem.h"


class Chair: public AboveGroundWorkerItem
{
public:
    Chair();
    double useItem();
    void special(Game *g);
};

#endif // CHAIR_H
