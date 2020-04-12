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

MinerHat Game::generateHat()
{   MinerHat hat;
    return hat;
}

MinerSuit Game::generateSuit()
{
    MinerSuit suit;
    return suit;
}

MinerLamp Game::generateLamp()
{
    MinerLamp lamp;
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
        powerStation.setSeason(season);
        heatingPlant.setSeason(season);
    }
    if(months==3||months==4||months==5||months==15||months==16||months==17||months==27||months==28||months==29||months==39||months==40||months==41||months==51||months==52||months==53||months==63||months==64||months==65||months==75||months==76||months==77||months==87||months==88||months==89||months==99||months==100||months==101)
    {
        season = "Summer";
        powerStation.setSeason(season);
        heatingPlant.setSeason(season);
    }
    if(months==6||months==7||months==8||months==18||months==19||months==20||months==30||months==31||months==32||months==42||months==43||months==44||months==54||months==55||months==56||months==66||months==67||months==68||months==78||months==79||months==80||months==90||months==91||months==92||months==102||months==103||months==104)
    {
        season = "Autumn";
        powerStation.setSeason(season);
        heatingPlant.setSeason(season);
    }
    if(months==9||months==10||months==11||months==21||months==22||months==23||months==33||months==34||months==35||months==45||months==46||months==47||months==57||months==58||months==59||months==69||months==70||months==71||months==81||months==82||months==83||months==93||months==94||months==95||months==105||months==106||months==107)
    {
        season = "Winter";
        powerStation.setSeason(season);
        heatingPlant.setSeason(season);
    }
}

NotWeatherDependentCompany Game::getIronWorks()
{
    return ironworks;
}
NotWeatherDependentCompany Game::getCoalStorageSite()
{
    return coalStorageSite;
}

WeatherDependent Game::getPowerStation()
{
    return powerStation;
}

WeatherDependent Game::getHeatingPlant()
{
    return heatingPlant;
}

void Game::generateMinerList() {
    int list_size = minerList.size();
    int iter = 10-list_size;

    for(int i = 0; i<iter; i++)
    {
        Miner gornik;
        minerList.push_back(gornik);
    }
}

std::vector<Miner> Game::getMinersList(){
    return minerList;
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

MinerHat Game::getHat()
{
    return hat;
}

MinerSuit Game::getSuit()
{
    return suit;
}

MinerLamp Game::getLamp()
{
    return lamp;
}

void Game::setHat(MinerHat h)
{
    hat = h;
}

void Game::setSuit(MinerSuit s)
{
    suit = s;
}

void Game::setLamp(MinerLamp l)
{
    lamp = l;
}
