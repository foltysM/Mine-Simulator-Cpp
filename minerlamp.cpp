#include "minerlamp.h"

MinerLamp::MinerLamp()
{
    int w = rand()%5;
    switch(w)
    {
    case 0:
        name = "Pretty good lamp";
        additionalProductivity = 1.07;
        price = 1000;
        break;
    case 1:
        name = "Grandpa's Lamp";
        additionalProductivity = 1.01;
        price = 1000;
        break;
    case 2:
        name = "Laser Lamp";
        additionalProductivity = 1.03;
        price = 1000;
        break;
    case 3:
        name = "Common miner lamp";
        additionalProductivity = 1.03;
        price = 1000;
        break;
    case 4:
        name = "Lamp bright as sun";
        additionalProductivity = 1.1;
        price = 1000;
        break;
    }
}

void MinerLamp::setAdditionalProductivity(double p)
{
    additionalProductivity = p;
}

double MinerLamp::getAdditionalProductivity()
{
    return additionalProductivity;
}
