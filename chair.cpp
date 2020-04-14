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
void Chair::useItem() {

}


