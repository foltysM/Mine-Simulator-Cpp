#include "seasondependent.h"

SeasonDependent::SeasonDependent():NotSeasonDependentCompany()
{

}

void SeasonDependent::setSeason(std::string s)
{
    season = s;
}

double SeasonDependent::getNeedsBlack()
{
    if(season == "Spring")
        needs_black = rand()%10+20;
    if(season == "Summer")
        needs_black = rand()%10+15;
    if(season == "Autumn")
        needs_black = rand()%10+20;
    if(season == "Winter")
        needs_black = rand()%10+25;
    return needs_black;
}

double SeasonDependent::getNeedsBrown()
{
    if(season == "Spring")
        needs_brown = rand()%10+20;
    if(season == "Summer")
        needs_brown = rand()%10+15;
    if(season == "Autumn")
        needs_brown = rand()%10+20;
    if(season == "Winter")
        needs_brown = rand()%10+25;
    return needs_brown;
}
void SeasonDependent::setNeedsBlack(double n)
{
    needs_black = n;
}

