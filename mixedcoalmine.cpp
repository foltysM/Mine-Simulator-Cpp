#include "mixedcoalmine.h"
#include "game.h"

MixedCoalMine::MixedCoalMine()
{

}

void MixedCoalMine::runSpecial(Game *g)
{
    int r = rand()%20;
    switch(r)
    {
    case 1:
        g->subMoney(500);
        g->getStorage()->setBlackCoalAmount(g->getStorage()->getBlackCoalAmount()+5);
        g->getStorage()->setBrownCoalAmount(g->getStorage()->getBrownCoalAmount()+5);
        break;
    default:
        g->subMoney(500);
        break;
    }
}
