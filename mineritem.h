#ifndef MINERITEM_H
#define MINERITEM_H

#include <iostream>

class MinerItem
{
private:
    std::string name;
    int price;
public:
    MinerItem();
    void listItems();
};

#endif // MINERITEM_H
