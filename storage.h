#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>

class Storage
{
private:
    double blackCoalAmount;
    double brownCoalAmount;
    double price;
public:
    Storage();
    double getBlackCoalAmount();
    double getBrownCoalAmount();
    double getPrice();
    void SetBlackCoalAmount(double bla);
    void SetBrownCoalAmount(double bra);
};

#endif // STORAGE_H
