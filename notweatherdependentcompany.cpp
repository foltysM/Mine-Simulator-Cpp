#include "notweatherdependentcompany.h"

NotWeatherDependentCompany::NotWeatherDependentCompany()
{

}

double NotWeatherDependentCompany::getNeedsBlack()
{
    needs_black = rand()%10+20;
    return needs_black;
}

double NotWeatherDependentCompany::getMoneyPayingAmount()
{
    moneyPayingAmount = rand()%100+400; //TODO do zrobienia przy ustalaniu finansow
    return moneyPayingAmount;
}

double NotWeatherDependentCompany::getNeedsBrown()
{
    needs_brown = rand()%10+20;

    return needs_brown;
}

void NotWeatherDependentCompany::randNeedsAndCash()
{
    //TODO zeby dzialalo

}
