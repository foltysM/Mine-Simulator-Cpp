#ifndef BLACKCOALMINE_H
#define BLACKCOALMINE_H

#include "mine.h"

class BlackCoalMine: public Mine
{
public:
    BlackCoalMine();
    void runSpecial(Game *g);
};

#endif // BLACKCOALMINE_H
