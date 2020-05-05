#include "browncoalmine.h"
#include "game.h"

BrownCoalMine::BrownCoalMine()
{

}

void BrownCoalMine::runSpecial(Game *g)
{
    g->subMoney(500);
    g->deleteHat();
    g->setHat(g->generateHat());
    g->deleteLamp();
    g->setLamp(g->generateLamp());
    g->deleteSuit();
    g->setSuit(g->generateSuit());
}



