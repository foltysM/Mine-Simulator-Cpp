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
    bool Failure();
    void moveMiner(Miner m);
    void removeMiner(Miner m);
    void updateProductivity();
    void upSeniority();
    double coalMined();
    double getMinerCosts();
};

#endif // MINE_H
