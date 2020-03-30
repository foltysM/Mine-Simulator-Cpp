#ifndef MINER_H
#define MINER_H

#include <iostream>

class Miner
{
private:
    MinerHat hat;
    int kids;
    MinerLamp lamp;
    static int miners;
    double monthSalary;
    std::string name;
    double productivity;
    int seniority;
    int strikeOpportunity;
    MinerSuit suit;
    bool tradeUnion;
public:
    Miner();
    ~Miner();
    int getKids();
    std::string getName();
    double getProductivity();
    double getSalaryAmount();
    double getSeniority();
    void promotion();
    void setSeniority(double s);
    bool strike;

};

#endif // MINER_H
