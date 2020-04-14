#ifndef NOTSEASONDEPENDENTCOMPANY_H
#define NOTSEASONDEPENDENTCOMPANY_H

#include <iostream>

class NotSeasonDependentCompany
{
private:
    double moneyPayingAmount;
    std::string name;

public:
    NotSeasonDependentCompany();
    double needs_brown;
    double needs_black;
    void setNeeds(double n);
    double getNeedsBlack();
    double getNeedsBrown();
    double getMoneyPayingAmount();
};

#endif // NOTWEATHERDEPENDENTCOMPANY_H
