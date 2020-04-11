#include "notweatherdependentcompany.h"

NotWeatherDependentCompany::NotWeatherDependentCompany()
{

}
double NotWeatherDependentCompany::getNeeds()
{
    needs = rand()%10+20;
    return needs;
}
double NotWeatherDependentCompany::getMoneyPayingAmount()
{
    moneyPayingAmount = rand()%100+400; //TODO do zrobienia przy ustalaniu finansow
    return moneyPayingAmount;
}
