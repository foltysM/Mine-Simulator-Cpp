#ifndef BROWNCOALMINE_H
#define BROWNCOALMINE_H

#include "mine.h"

class BrownCoalMine: public Mine
{
public:
    BrownCoalMine();
    double setProductivity(double p);
};

#endif // BROWNCOALMINE_H
