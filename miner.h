#ifndef MINER_H
#define MINER_H

#include <QMessageBox>
#include <iostream>
#include "minerlamp.h"
#include "minerhat.h"
#include "minersuit.h"

class Miner
{
private:
    int kids;
    MinerHat *hat;
    MinerLamp *lamp;
    MinerSuit *suit;
    double monthSalary;
    std::string name;
    double productivity;
    int seniority;
    int strikeOpportunity;    
    bool tradeUnion;
    bool striking;
public:
    Miner();
    int getKids();
    std::string getName();
    double getProductivity();
    double getSalaryAmount();
    int getSeniority();
    void promotion();
    void setSeniority(int s);
    bool getStriking();
    void setStriking(bool s);
    int getMiners();
    bool getUnion();
    int getStrikeOpportunity();
    MinerHat* getHat();
    MinerSuit* getSuit();
    MinerLamp* getLamp();
    void setHat(MinerHat *h);
    void setSuit(MinerSuit *s);
    void setLamp(MinerLamp *l);
};
#endif // MINER_H
