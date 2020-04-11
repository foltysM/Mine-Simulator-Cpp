#include "mine.h"

Mine::Mine()
{

}
void Mine::addMiner(Miner m)
{

}

void Mine::hireMiner(Miner m)
{
//    switch(w)
//    {
//    case 0:
//        qDebug() <<"Przenosimy do kopalni black";

//        break;
//    case 1:
//        qDebug() <<"Przenosimy do kopalni brown";

//        break;
//    case 2:
//        qDebug() <<"Przenosimy do kopalni mixed";

//        break;
//    }


}

void Mine::upSeniority()
{
    for(int i = 0;i<(int)miners.size();i++)
    {
        // TODO cos tu nie dziala
        //double s = miners[i].getSeniority();
       // miners[i].setSeniority(s+1);
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

