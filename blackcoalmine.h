#ifndef BLACKCOALMINE_H
#define BLACKCOALMINE_H

#include "mine.h"

class BlackCoalMine: public Mine
{
public:
    BlackCoalMine();
    double setProductivity(double p);
};

#endif // BLACKCOALMINE_H
