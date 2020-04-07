#ifndef MINERSUIT_H
#define MINERSUIT_H

#include "mineritem.h"

class MinerSuit: public MinerItem
{
private:
    double additionalProductivity;
    double salaryReduction;
public:
    MinerSuit();
};

#endif // MINERSUIT_H
