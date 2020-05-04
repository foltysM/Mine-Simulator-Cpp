#include "desk.h"
#include "game.h"

Desk::Desk():AboveGroundWorkerItem()
{
    int w = rand()%2;
    switch(w)
    {
    case 0:
        AboveGroundWorkerItem::setReduction(0.97);
        break;
    case 1:
    default:
        AboveGroundWorkerItem::setReduction(0.9);
        break;
    }
}

double Desk::useItem()
{
    int random = rand()%30;
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

void Desk::special(Game *g)
{
    int s = rand()%100;
    switch(s)
    {
    case 1:
        if(getReduction()!=1)
            g->addMoney(10000);
        break;
    default:
        break;
    }

}

