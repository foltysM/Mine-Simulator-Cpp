#ifndef MINERLAMP_H
#define MINERLAMP_H

#include <QMessageBox>
#include "mineritem.h"

class MinerLamp: public MinerItem
{
private:
    double additionalProductivity;
public:
    MinerLamp();
    void setAdditionalProductivity(double p);
    double getAdditionalProductivity();
};

#endif // MINERLAMP_H
