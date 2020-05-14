#include "mine.h"

Mine::Mine()
{

}

void Mine::upSeniority()
{
    for(int i = 0;i<(int)miners.size();i++)
    {
        int s = miners[i]->getSeniority();
        miners[i]->setSeniority(s+1);
    }
}

double Mine::coalMined()
{
    double amount = 0;
    for(int i = 0; i<(int)miners.size();i++)
    {
       amount = amount + miners[i]->getProductivity() + (miners[i]->getSeniority()/10);
    }
    return amount;
}

double Mine::getMinerCosts()
{
    double sum;
    for(int i = 0;i<(int)miners.size();i++)
    {
        if(miners[i]->getStriking()==false)
            sum = sum + (miners[i]->getSalaryAmount()*miners[i]->getHat()->getSalaryReduction()*miners[i]->getSuit()->getSalaryReduction());
    }
    return sum;
}

std::vector <Miner*>* Mine::getMiners()
{
    return &miners;
}

void Mine::setMiners(std::vector <Miner*>* m)
{
    miners = *m;
}

Miner* Mine::getOneMiner(int i)
{
    if(i>=0)
        return miners[i];
    else
    {
        QMessageBox msg;
        msg.setText("Error encountered, miner cannot be get!");
    }
    return nullptr;
}

void Mine::addMinerToList(Miner* m)
{
    miners.push_back(m);
}

void Mine::eraseMiner(int i)
{
    if(i>=0)
        miners.erase(miners.begin()+i);
    else
    {
        QMessageBox msg;
        msg.setText("Error encountered, miner not erased!");
    }
}

