#ifndef MINE_H
#define MINE_H

#include <iostream>

class Mine
{
private:
    std::string coalType;
    Miner miners;
    double productivity;
public:
    Mine();
    void addMiner(Miner m);
    bool Failure();
    Miner generateMiner();  //TODO czy na pewno tutaj
    void moveMiner(Miner m);
    void removeMiner(Miner m);
    virtual double setProductivity(double p) = 0;
    void updateProductivity();
};

#endif // MINE_H
