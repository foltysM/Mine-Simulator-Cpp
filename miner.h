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
    bool striking;
public:
    static int miners;
    Miner();
    ~Miner();
    int getKids();
    std::string getName();
    double getProductivity();
    double getSalaryAmount();
    int getSeniority();
    void promotion();
    void setSeniority(int s);
    bool strike();
    int getMiners();
    bool getUnion();
    int getStrikeOpportunity();
    MinerHat getHat();
    MinerSuit getSuit();
    MinerLamp getLamp();
    void setHat(MinerHat h);
    void setSuit(MinerSuit s);
    void setLamp(MinerLamp l);
};
#endif // MINER_H
