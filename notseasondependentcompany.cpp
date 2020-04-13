#include "notseasondependentcompany.h"

NotSeasonDependentCompany::NotSeasonDependentCompany()
{

}

double NotSeasonDependentCompany::getNeedsBlack()
{
    needs_black = rand()%10+20;
    return needs_black;
}

double NotSeasonDependentCompany::getMoneyPayingAmount()
{
    moneyPayingAmount = rand()%100+400;
    return moneyPayingAmount;
}

double NotSeasonDependentCompany::getNeedsBrown()
{
    needs_brown = rand()%10+20;
    return needs_brown;
}


