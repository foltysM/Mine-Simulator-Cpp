#ifndef MINE_H
#define MINE_H

#include <iostream>
#include "miner.h"
#include <vector>

class Mine
{
private:
    std::string coalType;
    double productivity;
public:
    std::vector <Miner> miners;
    Mine();
    void addMiner(Miner m);
    bool Failure();
    void moveMiner(Miner m);
    void removeMiner(Miner m);
    virtual double setProductivity(double p) = 0;
    void updateProductivity();
    void hireMiner(Miner m);
    void upSeniority();
};

#endif // MINE_H
