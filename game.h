#ifndef GAME_H
#define GAME_H

#include <vector>
#include "miner.h"
#include "storage.h"
#include "seasondependent.h"
#include "notseasondependentcompany.h"
#include "blackcoalmine.h"
#include "browncoalmine.h"
#include "mixedcoalmine.h"
#include "officeworker.h"
#include "accountant.h"

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
    SeasonDependent heatingPlant;
    SeasonDependent powerStation;
    NotSeasonDependentCompany coalStorageSite;
    NotSeasonDependentCompany ironworks;
    int miners_overall;
    int officeWorkersAmount;
    double lastMonthRevenues;
    int accountantsAmount;
public:
    std::vector <Miner> vectorMiners;
    std::vector <Accountant> vectorAccountants;
    std::vector <OfficeWorker> vectorOfficeWorkers;
    Game();
    void setMonths(int m);
    int getMonths();
    MinerHat generateHat();
    MinerSuit generateSuit();
    MinerLamp generateLamp();
    std::string getSeason();
    void setSeason();
    NotSeasonDependentCompany getIronWorks();
    NotSeasonDependentCompany getCoalStorageSite();
    SeasonDependent getPowerStation();
    SeasonDependent getHeatingPlant();
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
    void subMoney(double m);
    Storage getStorage();
    BlackCoalMine blackCoalMine;
    BrownCoalMine brownCoalMine;
    MixedCoalMine mixedCoalMine;
    void refreshOfficeWorkersAmount();
    void refreshAccountantsAmount();
    int randomStrike();
    double moneyForChildren();
    int getOfficeWorkersAmount();
    void setLastMonthRevenues(double r);
    double itemsReduction();
    double getAccStorageReduction();

};

#endif // GAME_H
