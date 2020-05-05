#ifndef BROWNCOALMINE_H
#define BROWNCOALMINE_H

#include "mine.h"

class BrownCoalMine: public Mine
{
public:
    BrownCoalMine();
    void runSpecial(Game *g);
};

#endif // BROWNCOALMINE_H
