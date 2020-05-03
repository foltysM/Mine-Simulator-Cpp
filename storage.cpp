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
    if(bla>=0)
        blackCoalAmount = bla;
    else
    {
        QMessageBox msg;
        msg.setText("Error encountered, amount not set!");
    }
}

void Storage::setBrownCoalAmount(double bra)
{
    if(bra>=0)
        brownCoalAmount = bra;
    else
    {
        QMessageBox msg;
        msg.setText("Error encountered, amount not set!");
    }
}
