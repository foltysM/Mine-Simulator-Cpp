#ifndef MINERLAMP_H
#define MINERLAMP_H

#include "mineritem.h"

class MinerLamp: public MinerItem
{
private:
    double additionalProductivity();
public:
    MinerLamp();
};

#endif // MINERLAMP_H
