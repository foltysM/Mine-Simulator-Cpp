#ifndef WEATHERDEPENDENT_H
#define WEATHERDEPENDENT_H

#include <iostream>
#include "notweatherdependentcompany.h"

class WeatherDependent :public NotWeatherDependentCompany
{
private:
    std::string season;
public:
    WeatherDependent();
    void setNeedsBlack(double n);
    double getNeedsBlack();
    double getNeedsBrown();
    void setSeason(std::string s);
    //TODO needs zalezne od pory roku faktycznie
};

#endif // WEATHERDEPENDENT_H
