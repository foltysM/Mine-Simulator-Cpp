#include "mine.h"

Mine::Mine()
{

}

void Mine::upSeniority()
{
    for(int i = 0;i<(int)miners.size();i++)
    {
        int s = miners[i].getSeniority();
        miners[i].setSeniority(s+1);
    }
}

double Mine::coalMined()
{
    double amount = 0;
    for(int i = 0; i<(int)miners.size();i++)
    {
       amount = amount + miners[i].getProductivity();
    }
    return amount;
}

double Mine::getMinerCosts()
{
    double sum;
    for(int i = 0;i<(int)miners.size();i++)
    {
        sum = sum + (miners[i].getSalaryAmount()*miners[i].getHat().getSalaryReduction()*miners[i].getSuit().getSalaryReduction());
    }
    return sum;
}

