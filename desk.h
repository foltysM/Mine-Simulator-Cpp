#ifndef DESK_H
#define DESK_H

#include "abovegroundworkeritem.h"

class Desk:public AboveGroundWorkerItem
{
private:
    //double reduction;
public:
    Desk();
    double useItem();
};

#endif // DESK_H
