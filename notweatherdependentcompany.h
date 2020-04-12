#ifndef NOTWEATHERDEPENDENTCOMPANY_H
#define NOTWEATHERDEPENDENTCOMPANY_H

#include <iostream>

class NotWeatherDependentCompany
{
private:
    double moneyPayingAmount;
    std::string name;

public:
    NotWeatherDependentCompany();
    double needs_brown;
    double needs_black; // TODO zeby dzialao private
    void setNeeds(double n);
    double getNeedsBlack();
    double getNeedsBrown();
    double getMoneyPayingAmount();
    void randNeedsAndCash();

};

#endif // NOTWEATHERDEPENDENTCOMPANY_H
