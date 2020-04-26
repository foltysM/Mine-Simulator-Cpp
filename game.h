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
    std::vector <Miner*> minerList;
    int months;
    std::string season;
    MinerHat hat;
    MinerSuit suit;
    MinerLamp lamp;
    double money;   
    SeasonDependent heatingPlant;
    SeasonDependent powerStation;
    NotSeasonDependentCompany coalStorageSite;
    NotSeasonDependentCompany ironworks;
    int miners_overall;
    int officeWorkersAmount;
    double lastMonthRevenues;
    int accountantsAmount;
    std::vector <Accountant*> vectorAccountants;
    std::vector <OfficeWorker*> vectorOfficeWorkers;
    Storage storage;
    BlackCoalMine blackCoalMine;
    BrownCoalMine brownCoalMine;
    MixedCoalMine mixedCoalMine;
public:   
    Game();
    double getLastMonthRevenues();
    void setMonths(int m);
    int getMonths();
    MinerHat* generateHat();
    MinerSuit* generateSuit();
    MinerLamp* generateLamp();
    std::string getSeason();
    void setSeason();
    NotSeasonDependentCompany* getIronWorks();
    NotSeasonDependentCompany* getCoalStorageSite();
    SeasonDependent* getPowerStation();
    SeasonDependent* getHeatingPlant();
    void eraseMiner(int w);
    void generateMinerList();
    std::vector<Miner*> getMinersList();
    void setMoney(double m);
    double getMoney();
    MinerHat* getHat();
    MinerSuit* getSuit();
    MinerLamp* getLamp();
    void setHat(MinerHat *h);
    void setSuit(MinerSuit *s);
    void setLamp(MinerLamp *l);
    void subMoney(double m);
    Storage* getStorage();
    void refreshOfficeWorkersAmount();
    void refreshAccountantsAmount();
    int randomStrike();
    double moneyForChildren();
    int getOfficeWorkersAmount();
    void setLastMonthRevenues(double r);
    double itemsReduction();
    double getAccStorageReduction();
    void createAcc();
    std::vector <Accountant*> getAccountantsVector();
    std::vector <OfficeWorker*> getOfficeWorkersVector();
    OfficeWorker* getOneOfficeWorker(int i);
    Accountant* getOneAccountant(int i);
    BlackCoalMine* getBlackCoalMine();
    BrownCoalMine* getBrownCoalMine();
    MixedCoalMine* getMixedCoalMine();
    void deleteMinersList();
    void deleteMines();
};

#endif // GAME_H
