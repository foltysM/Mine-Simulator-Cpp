#include "desk.h"

Desk::Desk()
{
    int w = rand()%2;
    switch(w)
    {
    case 0:
        reduction = 0.97;
        break;
    case 1:
    default:
        reduction = 0.98;
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
