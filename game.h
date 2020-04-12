#ifndef GAME_H
#define GAME_H

#include <vector>
#include "miner.h"
#include "storage.h"
#include "weatherdependent.h"
#include "notweatherdependentcompany.h"

class Game
{
private:
    std::vector <Miner> minerList;
    int months;
    std::string season;
    MinerHat hat;
    MinerSuit suit;
    MinerLamp lamp;
    double money;
    Storage storage;
    WeatherDependent heatingPlant;
    WeatherDependent powerStation;
    NotWeatherDependentCompany coalStorageSite;
    NotWeatherDependentCompany ironworks;
public:
    std::vector <Miner> vectorMiners;
    Game();
    void setMonths(int m);
    int getMonths();
    MinerHat generateHat();
    MinerSuit generateSuit();
    MinerLamp generateLamp();
    std::string getSeason();
    void setSeason();
    NotWeatherDependentCompany getIronWorks();
    NotWeatherDependentCompany getCoalStorageSite();
    WeatherDependent getPowerStation();
    WeatherDependent getHeatingPlant();
    void eraseMiner(int w);
    void generateMinerList();
    std::vector<Miner> getMinersList();
    void setMoney(double m);
    double getMoney();
    MinerHat getHat();
    MinerSuit getSuit();
    MinerLamp getLamp();
    void setHat(MinerHat h);
    void setSuit(MinerSuit s);
    void setLamp(MinerLamp l);
};

#endif // GAME_H
