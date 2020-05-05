#include "blackcoalmine.h"
#include "game.h"

BlackCoalMine::BlackCoalMine()
{

}

void BlackCoalMine::runSpecial(Game *g)
{
    int r = rand()%10;
    switch(r)
    {
    case 1:
        g->subMoney(500);
        g->addMoney(2000);
        break;
    default:
        g->subMoney(500);
        break;
    }
}

