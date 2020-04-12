#include "storage.h"
// TODO storage
Storage::Storage()
{
    blackCoalAmount = 0;
    brownCoalAmount = 0;
}

double Storage::getBlackCoalAmount()
{
    return blackCoalAmount;
}

double Storage::getBrownCoalAmount()
{
    return brownCoalAmount;
}

double Storage::getPrice()
{
    price = rand()%5+5;
    return price;
}

void Storage::SetBlackCoalAmount(double bla)
{
    blackCoalAmount = bla;
}

void Storage::SetBrownCoalAmount(double bra)
{
    brownCoalAmount = bra;
}
