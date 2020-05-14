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
    MinerHat *hat;
    MinerSuit *suit;
    MinerLamp *lamp;
    double money;   
    SeasonDependent *heatingPlant;
    SeasonDependent *powerStation;
    NotSeasonDependentCompany *coalStorageSite;
    NotSeasonDependentCompany *ironworks;
    int miners_overall;
    int officeWorkersAmount;
    double lastMonthRevenues;
    int accountantsAmount;
    std::vector <Accountant*> vectorAccountants;
    std::vector <OfficeWorker*> vectorOfficeWorkers;
    Storage storage;
    BlackCoalMine *blackCoalMine;
    BrownCoalMine *brownCoalMine;
    MixedCoalMine *mixedCoalMine;
    bool computerSpecial = false;
    bool chairSpecial = false;

public:   
    Game();
    /**
     * @brief Metoda ustawiająca wartość computerSpecial, która określa czy special powinien się wykonać czy nie
     * @param s Ustawiana wartość
     */
    void setComputerSpecial(bool s);
    /**
     * @brief Metoda ustawiająca wartość chairSpecial, która określa czy special powinien się wykonać czy nie
     * @param s Ustawiana wartość
     */
    void setChairSpecial(bool s);
    /**
     * @brief Metoda pobierająca wartość computerSpecial
     * @return Wartość computerSpecial
     */
    bool getComputerSpecial();
    /**
     * @brief getChairSpecial
     * @return
     */
    bool getChairSpecial();
    /**
     * @brief initMinerItems
     */
    void initMinerItems();
    /**
     * @brief getOneMinerFromList
     * @param i
     * @return
     */
    Miner* getOneMinerFromList(int i);
    /**
     * @brief initMines
     */
    void initMines();
    /**
     * @brief getLastMonthRevenues
     * @return
     */
    double getLastMonthRevenues();
    /**
     * @brief setMonths
     * @param m
     */
    void setMonths(int m);
    /**
     * @brief getMonths
     * @return
     */
    int getMonths();
    /**
     * @brief generateHat
     * @return
     */
    MinerHat* generateHat();
    /**
     * @brief generateSuit
     * @return
     */
    MinerSuit* generateSuit();
    /**
     * @brief generateLamp
     * @return
     */
    MinerLamp* generateLamp();
    /**
     * @brief getSeason
     * @return
     */
    std::string getSeason();
    /**
     * @brief setSeason
     */
    void setSeason();
    /**
     * @brief getIronWorks
     * @return
     */
    NotSeasonDependentCompany* getIronWorks();
    /**
     * @brief getCoalStorageSite
     * @return
     */
    NotSeasonDependentCompany* getCoalStorageSite();
    /**
     * @brief getPowerStation
     * @return
     */
    SeasonDependent* getPowerStation();
    /**
     * @brief getHeatingPlant
     * @return
     */
    SeasonDependent* getHeatingPlant();
    /**
     * @brief eraseMiner
     * @param w
     */
    void eraseMiner(int w);
    /**
     * @brief generateMinerList
     */
    void generateMinerList();
    /**
     * @brief getMinersList
     * @return
     */
    std::vector<Miner*> getMinersList();
    /**
     * @brief setMoney
     * @param m
     */
    void setMoney(double m);
    /**
     * @brief getMoney
     * @return
     */
    double getMoney();
    /**
     * @brief getHat
     * @return
     */
    MinerHat* getHat();
    /**
     * @brief getSuit
     * @return
     */
    MinerSuit* getSuit();
    /**
     * @brief getLamp
     * @return
     */
    MinerLamp* getLamp();
    /**
     * @brief setHat
     * @param h
     */
    void setHat(MinerHat *h);
    /**
     * @brief setSuit
     * @param s
     */
    void setSuit(MinerSuit *s);
    /**
     * @brief setLamp
     * @param l
     */
    void setLamp(MinerLamp *l);
    /**
     * @brief subMoney
     * @param m
     */
    void subMoney(double m);
    /**
     * @brief getStorage
     * @return
     */
    Storage* getStorage();
    /**
     * @brief refreshOfficeWorkersAmount
     */
    void refreshOfficeWorkersAmount();
    /**
     * @brief refreshAccountantsAmount
     */
    void refreshAccountantsAmount();
    /**
     * @brief randomStrike
     * @return
     */
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
    void addMoney(double m);
    void deleteHat();
    void deleteSuit();
    void deleteLamp();
};

#endif // GAME_H
