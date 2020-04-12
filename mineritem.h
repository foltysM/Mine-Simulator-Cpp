#ifndef MINERITEM_H
#define MINERITEM_H

#include <iostream>

class MinerItem
{
protected:
    std::string name;
    int price;
public:
    MinerItem();
    void listItems();
    std::string getName();
    int getPrice();
    void setName(std::string n);
};

#endif // MINERITEM_H
