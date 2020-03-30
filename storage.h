#ifndef STORAGE_H
#define STORAGE_H


class Storage
{
private:
    double CoalAmount;
    double price;
public:
    Storage();
    double getCoalAmount();
    double getPrice();
    void SetCoalAmount(double a);
};

#endif // STORAGE_H
