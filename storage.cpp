#include "storage.h"

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

void Storage::setBlackCoalAmount(double bla)
{
    blackCoalAmount = bla;
}

void Storage::setBrownCoalAmount(double bra)
{
    brownCoalAmount = bra;
}
