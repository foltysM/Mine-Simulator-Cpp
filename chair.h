#ifndef CHAIR_H
#define CHAIR_H


#include "abovegroundworkeritem.h"

class Chair: public AboveGroundWorkerItem
{
private:
    //double reduction;
public:
    Chair();
    double useItem();
};

#endif // CHAIR_H
