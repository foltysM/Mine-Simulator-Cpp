#include <QDebug>
#include "game.h"

Game::Game()
{
    months = 0;
}

void Game::setMonths(int m)
{
    months = m;
}

int Game::getMonths()
{
    return months;
}

MinerHat* Game::generateHat()
{
    MinerHat* hat = new MinerHat;
    return hat;
}

MinerSuit* Game::generateSuit()
{
    MinerSuit *suit = new MinerSuit;
    return suit;
}

MinerLamp* Game::generateLamp()
{
    MinerLamp *lamp = new MinerLamp;
    return lamp;
}

std::string Game::getSeason()
{
    return season;
}

void Game::setSeason()
{
    if(months==0||months==1||months==2||months==12||months==13||months==14||months==24||months==25||months==26||months==36||months==37||months==38||months==48||months==49||months==50||months==60||months==61||months==62||months==72||months==73||months==74||months==84||months==85||months==86||months==96||months==97||months==98)
    {
        season = "Spring";
        powerStation->setSeason(season);
        heatingPlant->setSeason(season);
    }
    if(months==3||months==4||months==5||months==15||months==16||months==17||months==27||months==28||months==29||months==39||months==40||months==41||months==51||months==52||months==53||months==63||months==64||months==65||months==75||months==76||months==77||months==87||months==88||months==89||months==99||months==100||months==101)
    {
        season = "Summer";
        powerStation->setSeason(season);
        heatingPlant->setSeason(season);
    }
    if(months==6||months==7||months==8||months==18||months==19||months==20||months==30||months==31||months==32||months==42||months==43||months==44||months==54||months==55||months==56||months==66||months==67||months==68||months==78||months==79||months==80||months==90||months==91||months==92||months==102||months==103||months==104)
    {
        season = "Autumn";
        powerStation->setSeason(season);
        heatingPlant->setSeason(season);
    }
    if(months==9||months==10||months==11||months==21||months==22||months==23||months==33||months==34||months==35||months==45||months==46||months==47||months==57||months==58||months==59||months==69||months==70||months==71||months==81||months==82||months==83||months==93||months==94||months==95||months==105||months==106||months==107)
    {
        season = "Winter";
        powerStation->setSeason(season);
        heatingPlant->setSeason(season);
    }
}

NotSeasonDependentCompany* Game::getIronWorks()
{
    return ironworks;
}
NotSeasonDependentCompany* Game::getCoalStorageSite()
{
    return coalStorageSite;
}

SeasonDependent* Game::getPowerStation()
{
    return powerStation;
}

SeasonDependent* Game::getHeatingPlant()
{
    return heatingPlant;
}

void Game::generateMinerList()
{
    int list_size = minerList.size();
    int iter = 10-list_size;

    for(int i = 0; i<iter; i++)
    {
        Miner* gornik = new Miner;
        minerList.push_back(gornik);
    }
}

std::vector<Miner*> Game::getMinersList()
{
    return minerList;
}

Miner* Game::getOneMinerFromList(int i)
{
    return minerList[i];
}

void Game::eraseMiner(int w)
{
    minerList.erase(minerList.begin()+w);
    generateMinerList();
}

void Game::setMoney(double m)
{
     money = m;
}

double Game::getMoney()
{
    return money;
}

MinerHat* Game::getHat()
{
    return hat;
}

MinerSuit* Game::getSuit()
{
    return suit;
}

MinerLamp* Game::getLamp()
{
    return lamp;
}

void Game::setHat(MinerHat *h)
{
    hat = h;
}

void Game::setSuit(MinerSuit *s)
{
    suit = s;
}

void Game::setLamp(MinerLamp *l)
{
    lamp = l;
}

void Game::subMoney(double m)
{
    money = money - m;
}

Storage* Game::getStorage()
{
    return &storage;
}

void Game::refreshOfficeWorkersAmount()
{
    int minersSum = blackCoalMine->getMiners()->size()+brownCoalMine->getMiners()->size()+mixedCoalMine->getMiners()->size();
    officeWorkersAmount = minersSum/5;
    if(officeWorkersAmount<(int)vectorOfficeWorkers.size())
    {
        while(officeWorkersAmount<(int)vectorOfficeWorkers.size())
        {
            vectorOfficeWorkers.erase(vectorOfficeWorkers.begin()+((int)vectorOfficeWorkers.size())-1);
        }
    }
    if(officeWorkersAmount>(int)vectorOfficeWorkers.size())
    {
        while(officeWorkersAmount>(int)vectorOfficeWorkers.size())
        {
            OfficeWorker* o = new OfficeWorker;
            vectorOfficeWorkers.push_back(o);
        }
    }
}

void Game::refreshAccountantsAmount()
{
    // for every $10k hires one accountant
    accountantsAmount = lastMonthRevenues / 10000;
    while(accountantsAmount<(int)vectorAccountants.size())
    {
        vectorAccountants.erase(vectorAccountants.begin()+((int)vectorAccountants.size())-1);
    }
    while(accountantsAmount>(int)vectorAccountants.size())
    {
        Accountant* a = new Accountant;
        vectorAccountants.push_back(a);
    }
}

int Game::randomStrike()
{
    int sum = 0;
    for(int i = 0;i<(int)blackCoalMine->getMiners()->size();i++)
    {
        // strike probability
        int sop = blackCoalMine->getOneMiner(i)->getStrikeOpportunity();
        int r = rand()%100;
        switch(r/sop)
        {
        case 1:
            blackCoalMine->getOneMiner(i)->setStriking(true);
            sum++;
            break;
        default:
            blackCoalMine->getOneMiner(i)->setStriking(false);
            break;
        }
    }
    for(int i = 0;i<(int)brownCoalMine->getMiners()->size();i++)
    {
        // strike probability
        int sop = brownCoalMine->getOneMiner(i)->getStrikeOpportunity();
        int r = rand()%100;
        switch(r/sop)
        {
        case 1:
            brownCoalMine->getOneMiner(i)->setStriking(true);
            sum++;
            break;
        default:
            brownCoalMine->getOneMiner(i)->setStriking(false);
            break;
        }
    }
    for(int i = 0;i<(int)mixedCoalMine->getMiners()->size();i++)
    {
        // strike probability
        int sop = mixedCoalMine->getOneMiner(i)->getStrikeOpportunity();
        int r = rand()%100;
        switch(r/sop)
        {
        case 1:
            mixedCoalMine->getOneMiner(i)->setStriking(true);
            sum++;
            break;
        default:
            mixedCoalMine->getOneMiner(i)->setStriking(false);
            break;
        }
    }
    return sum;
}

double Game::moneyForChildren()
{
    double r = 0;
    if(season=="Autumn")
    {
        for(int i = 0;i<(int)blackCoalMine->getMiners()->size();i++)
        {
            //$20 for every child every autumn month
            r = r + 20*blackCoalMine->getOneMiner(i)->getKids();
        }
        for(int i = 0;i<(int)brownCoalMine->getMiners()->size();i++)
        {
            //$20 for every child every autumn month
            r = r + 20*brownCoalMine->getOneMiner(i)->getKids();
        }
        for(int i = 0;i<(int)mixedCoalMine->getMiners()->size();i++)
        {
            //$20 for every child every autumn month
            r = r + 20*mixedCoalMine->getOneMiner(i)->getKids();
        }
    }
    return r;
}

int Game::getOfficeWorkersAmount()
{
    return officeWorkersAmount;
}

void Game::setLastMonthRevenues(double r)
{
    lastMonthRevenues = r;
}

double Game::getLastMonthRevenues()
{
    return lastMonthRevenues;
}


double Game::itemsReduction()
{
    double r = 1;
    for(int i = 0;i<(int)vectorAccountants.size();i++)
    {
        r = r * vectorAccountants[i]->getDesk()->getReduction() * vectorAccountants[i]->getChair()->getReduction() * vectorAccountants[i]->getComputer()->getReduction();
        r = r * vectorAccountants[i]->getChair()->useItem();
        r = r * vectorAccountants[i]->getDesk()->useItem();
        r = r * vectorAccountants[i]->getComputer()->useItem();
    }
    for(int i =0;i<(int)vectorOfficeWorkers.size();i++)
    {
        r = r * vectorOfficeWorkers[i]->getDesk()->getReduction() * vectorOfficeWorkers[i]->getChair()->getReduction() * vectorOfficeWorkers[i]->getComputer()->getReduction();
        r = r * vectorOfficeWorkers[i]->getChair()->useItem();
        r = r * vectorOfficeWorkers[i]->getDesk()->useItem();
        r = r * vectorOfficeWorkers[i]->getComputer()->useItem();
    }
    return r;
}

double Game::getAccStorageReduction()
{
    double reduction = 1;
    for(int i = 0 ;i<(int)vectorAccountants.size();i++)
    {
        reduction = reduction * vectorAccountants[i]->work();
    }
    return reduction;
}

void Game::createAcc()
{
    if(lastMonthRevenues>=0)
    {
        int accSum = 0;
        accSum = lastMonthRevenues/10000;
        while(accSum<(int)vectorAccountants.size())
        {
            vectorAccountants.erase(vectorAccountants.begin()+((int)vectorAccountants.size())-1);
        }
        while(accSum>(int)vectorAccountants.size())
        {
            Accountant* a = new Accountant;
            vectorAccountants.push_back(a);
        }
    }else{
        while(vectorAccountants.size()>0)
        {
            vectorAccountants.erase(vectorAccountants.begin()+((int)vectorAccountants.size())-1);
        }
    }
}

std::vector <Accountant*> Game::getAccountantsVector()
{
    return vectorAccountants;
}

std::vector <OfficeWorker*> Game::getOfficeWorkersVector()
{
    return vectorOfficeWorkers;
}

OfficeWorker* Game::getOneOfficeWorker(int i)
{
    return vectorOfficeWorkers[i];
}

Accountant* Game::getOneAccountant(int i)
{
    return vectorAccountants[i];
}

BlackCoalMine* Game::getBlackCoalMine()
{
    return blackCoalMine;
}

BrownCoalMine* Game::getBrownCoalMine()
{
    return brownCoalMine;
}

MixedCoalMine* Game::getMixedCoalMine()
{
    return mixedCoalMine;
}

void Game::deleteMinersList()
{
    for (int i = (int)minerList.size();i>0;i--)
    {
        delete minerList[i];
    }
}

void Game::deleteMines()
{
    for (int i = (int)blackCoalMine->getMiners()->size();i>0;i--)
    {
        delete blackCoalMine->getOneMiner(i);
    }

    for (int i = (int)brownCoalMine->getMiners()->size();i>0;i--)
    {
        delete brownCoalMine->getOneMiner(i);
    }

    for (int i = (int)mixedCoalMine->getMiners()->size();i>0;i--)
    {
        delete blackCoalMine->getOneMiner(i);
    }

}

void Game::initMinerItems()
{
    hat = new MinerHat;
    suit = new MinerSuit;
    lamp = new MinerLamp;
}

void Game::initMines()
{
    blackCoalMine = new BlackCoalMine;
    brownCoalMine = new BrownCoalMine;
    mixedCoalMine = new MixedCoalMine;
}


