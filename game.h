#ifndef GAME_H
#define GAME_H

#include "miner.h"
#include "storage.h"
#include "weatherdependent.h"
#include "notweatherdependentcompany.h"

class Game
{
private:
    int months;
    std::string season;
    MinerHat hat;
    MinerSuit suit;
    MinerLamp lamp;
    Storage storage;
    WeatherDependent heatingPlant;
    WeatherDependent powerStation;
    NotWeatherDependentCompany coalStorageSite;
    NotWeatherDependentCompany ironworks;
public:
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
};

#endif // GAME_H
