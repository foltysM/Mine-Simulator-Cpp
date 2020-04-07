#ifndef MIXEDCOALMINE_H
#define MIXEDCOALMINE_H

#include "mine.h"

class MixedCoalMine: public Mine
{
public:
    MixedCoalMine();
    double setProductivity(double p);
};

#endif // MIXEDCOALMINE_H
