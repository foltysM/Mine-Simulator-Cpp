#include "mineritem.h"

MinerItem::MinerItem()
{

}

std::string MinerItem::getName()
{
    return name;
}

int MinerItem::getPrice()
{
    return price;
}

void MinerItem::setName(std::string n)
{
    name = n;
}
