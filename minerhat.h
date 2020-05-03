#ifndef MINERHAT_H
#define MINERHAT_H

#include <QMessageBox>
#include "mineritem.h"

class MinerHat: public MinerItem
{
private:
    double salaryReduction;
public:
    MinerHat();
    void setSalaryReduction(double r);
    double getSalaryReduction();
};

#endif // MINERHAT_H
