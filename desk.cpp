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

void Desk::useItem() {

}
