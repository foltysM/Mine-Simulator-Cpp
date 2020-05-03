#ifndef SEASONDEPENDENT_H
#define SEASONDEPENDENT_H

#include <iostream>
#include <QMessageBox>
#include "notseasondependentcompany.h"

class SeasonDependent :public NotSeasonDependentCompany
{
private:
    std::string season;
public:
    SeasonDependent();
    void setNeedsBlack(double n);
    double getNeedsBlack();
    double getNeedsBrown();
    void setSeason(std::string s);
};

#endif // WEATHERDEPENDENT_H
