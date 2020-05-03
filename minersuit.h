#ifndef MINERSUIT_H
#define MINERSUIT_H

#include <QMessageBox>
#include "mineritem.h"

class MinerSuit: public MinerItem
{
private:
    double additionalProductivity;
    double salaryReduction;
public:
    MinerSuit();
    void setAdditionalProductivity(double p);
    void setSalaryReduction(double r);
    double getSalaryReduction();
    double getAdditionalProductivity();
};

#endif // MINERSUIT_H
