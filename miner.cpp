#include <iostream>
#include "miner.h"

int Miner::miners = 0;

Miner::Miner()
{
    miners++; //TODO liczenie górników
    int val;
    /*hat = 0;

    lamp = 0;
    suit = NULL;
    TODO NULL
    */
    kids = rand()%4+1;
    //salary from 2k to 3k
    monthSalary = rand()%1000+2000;
    productivity = ((double)(rand()%5+10))/10;
    seniority = 0;
    //striking = false;
    //value from 1 to 10
    strikeOpportunity = rand()%10+1;

    val = rand()%2;
    if(val==1)
        tradeUnion=true;
    else
        tradeUnion=false;

    val = rand()%5;
    switch (val) {
    case 0:
        name = "Kamil";
        break;
    case 1:
        name = "Konrad";
        break;
    case 2:
        name = "Mirosław";
        break;
    case 3:
        name = "Roman";
        break;
    case 4:
        name = "Maciej";
        break;
    default:
        name = "Anna";
        break;
    }



}

std::string Miner::getName() {
    return name;
}
Miner::~Miner() {
    miners--;
}
int Miner::getMiners() {
    return miners;
}
bool Miner::getUnion()
{
    return tradeUnion;
}
double Miner::getProductivity()
{
    return productivity;
}
double Miner::getSalaryAmount()
{
    return monthSalary;
}
int Miner::getKids()
{
    return kids;
}
int Miner::getStrikeOpportunity()
{
    return strikeOpportunity;
}

