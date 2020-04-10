#ifndef MINER_H
#define MINER_H

#include <iostream>
#include "minerlamp.h"
#include "minerhat.h"
#include "minersuit.h"

class Miner
{
private:
    MinerHat hat;
    int kids;
    MinerLamp lamp;
    double monthSalary;
    std::string name;
    double productivity;
    int seniority;
    int strikeOpportunity;
    MinerSuit suit;
    bool tradeUnion;
public:
    static int miners;
    Miner();
    ~Miner();
    int getKids();
    std::string getName();
    double getProductivity();
    double getSalaryAmount();
    double getSeniority();
    void promotion();
    void setSeniority(double s);
    bool strike();
    int getMiners();
    bool getUnion();
    int getStrikeOpportunity();
};

#endif // MINER_H
