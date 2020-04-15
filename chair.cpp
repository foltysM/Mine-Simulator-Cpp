#include "chair.h"

Chair::Chair()
{
    int w = rand()%2;
    switch(w)
    {
    case 0:
        reduction = 0.99;
        break;
    case 1:
    default:
        reduction = 0.98;
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
