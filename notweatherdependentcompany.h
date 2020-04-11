#ifndef NOTWEATHERDEPENDENTCOMPANY_H
#define NOTWEATHERDEPENDENTCOMPANY_H

#include <iostream>

class NotWeatherDependentCompany
{
private:
    double moneyPayingAmount;
    std::string name;
    double needs;
public:
    NotWeatherDependentCompany();
    void setNeeds(double n);
    double getNeeds();
    double getMoneyPayingAmount();

};

#endif // NOTWEATHERDEPENDENTCOMPANY_H
