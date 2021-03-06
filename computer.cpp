#include "computer.h"
#include "game.h"

Computer::Computer():AboveGroundWorkerItem()
{
    int w = rand()%2;
    switch(w)
    {
    case 0:
        AboveGroundWorkerItem::setReduction(0.95);
        break;
    case 1:
    default:
        AboveGroundWorkerItem::setReduction(0.96);
        break;
    }
}

double Computer::useItem()
{
    int random = rand()%12;
    double r = 0;
    switch(random)
    {
    case 1:
        r = 0.5;
        break;
    default:
        r = 1;
        break;
    }
    return r;
}

void Computer::special(Game *g)
{
    int s = rand()%100;
    switch(s)
    {
    case 1:
        if(getReduction()!=1)
            g->setComputerSpecial(true);
        break;
    default:
        g->setComputerSpecial(false);
        break;
    }
}


