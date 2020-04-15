#ifndef CHAIR_H
#define CHAIR_H


#include "abovegroundworkeritem.h"

class Chair: public AboveGroundWorkerItem
{
public:
    Chair();
    double useItem();
};

#endif // CHAIR_H
