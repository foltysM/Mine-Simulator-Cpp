#include "computer.h"

Computer::Computer()
{
    int w = rand()%2;
    switch(w)
    {
    case 0:
        reduction = 0.95;
        break;
    case 1:
    default:
        reduction = 0.96;
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
