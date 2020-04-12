#include <iostream>
#include "miner.h"

int Miner::miners = 0;

Miner::Miner()
{
    miners++; //TODO liczenie górników
    int val;
    hat.setName("No hat");
    hat.setSalaryReduction(1);
    lamp.setName("No lamp");
    lamp.setAdditionalProductivity(1);
    suit.setName("No suit");
    suit.setSalaryReduction(1);
    suit.setAdditionalProductivity(1);
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

int Miner::getSeniority()
{
    return seniority;
}

void Miner::setSeniority(int s)
{
    seniority = s;
}

MinerHat Miner::getHat()
{
    return hat;
}

MinerSuit Miner::getSuit()
{
    return suit;
}

MinerLamp Miner::getLamp()
{
    return lamp;
}

void Miner::setHat(MinerHat h)
{
    hat = h;
}

void Miner::setSuit(MinerSuit s)
{
    suit = s;
}

void Miner::setLamp(MinerLamp l)
{
    lamp = l;
}


