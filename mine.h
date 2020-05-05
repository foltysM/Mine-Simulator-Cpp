#ifndef MINE_H
#define MINE_H

#include <vector>
#include <iostream>
#include "miner.h"
#include "QMessageBox"

class Game;

class Mine
{
private:
    std::string coalType;
    double productivity;
    std::vector <Miner*> miners;
public:    
    Mine();
    ~Mine();
    virtual void runSpecial(Game *g) = 0;
    bool Failure();
    void moveMiner(Miner m);
    void removeMiner(Miner m);
    void updateProductivity();
    void upSeniority();
    double coalMined();
    double getMinerCosts();
    std::vector <Miner*>* getMiners();
    void setMiners(std::vector <Miner*>* m);
    Miner* getOneMiner(int i);
    void addMinerToList(Miner* m);
    void eraseMiner(int i);
};

#endif // MINE_H
