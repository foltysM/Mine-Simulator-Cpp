#include "weatherdependent.h"

WeatherDependent::WeatherDependent()
{

}

void WeatherDependent::setSeason(std::string s)
{
    season = s;
}

double WeatherDependent::getNeedsBlack()
{
    return needs_black; //TODO dostep gdy private:?
}

double WeatherDependent::getNeedsBrown()
{
    return needs_brown;
}
void WeatherDependent::setNeedsBlack(double n)
{
    needs_black = n;
}

