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

