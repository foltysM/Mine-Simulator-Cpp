#ifndef MIXEDCOALMINE_H
#define MIXEDCOALMINE_H

#include "mine.h"

class MixedCoalMine: public Mine
{
public:
    MixedCoalMine();
    void runSpecial(Game *g);
};

#endif // MIXEDCOALMINE_H
