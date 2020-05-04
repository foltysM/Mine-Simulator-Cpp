#include "chair.h"
#include "game.h"

Chair::Chair():AboveGroundWorkerItem()
{
    int w = rand()%2;
    switch(w)
    {
    case 0:
        AboveGroundWorkerItem::setReduction(0.99);
        break;
    case 1:
    default:
        AboveGroundWorkerItem::setReduction(0.98);
        break;
    }
}

double Chair::useItem() {
    int random = rand()%45;
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

void Chair::special(Game *g)
{
    int s = rand()%100;
    switch(s)
    {
    case 1:
        if(getReduction()!=1)
            g->setChairSpecial(true);
        break;
    default:
        g->setChairSpecial(false);
        break;
    }
}


