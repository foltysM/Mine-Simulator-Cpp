#ifndef WEATHERDEPENDENT_H
#define WEATHERDEPENDENT_H

#include <iostream>
#include "notweatherdependentcompany.h"

class WeatherDependent:public NotWeatherDependentCompany
{
private:
    std::string season;
public:
    WeatherDependent();
    double setNeeds(double n);
    void setSeason(std::string s);
};

#endif // WEATHERDEPENDENT_H
