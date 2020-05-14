#ifndef STORAGE_H
#define STORAGE_H


#include <QMessageBox>

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
    void setBlackCoalAmount(double bla);
    void setBrownCoalAmount(double bra);
};

#endif // STORAGE_H
