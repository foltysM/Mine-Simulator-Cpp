#include "minersuit.h"

MinerSuit::MinerSuit()
{
    int w = rand()%5;
    switch(w)
    {
    case 0:
        name = "Pretty good lamp"; // TODO brak dostepu
        additionalProductivity = 1.03;
        price = 1000; // TODO przy ustalaniu finansow
        salaryReduction = 0.01;
        break;
    case 1:
        name = "Grandpa's Lamp";
        additionalProductivity = 1.005;
        salaryReduction = 0.02;
        price = 1000;
        break;
    case 2:
        name = "Laser Lamp";
        additionalProductivity = 1.015;
        salaryReduction = 0.03;
        price = 1000;
        break;
    case 3:
        name = "Common miner lamp";
        additionalProductivity = 1.015;
        salaryReduction = 0.04;
        price = 1000;
        break;
    case 4:
        name = "Lamp bright as sun";
        additionalProductivity = 1.05;
        salaryReduction = 0.05;
        price = 1000;
        break;
    }
} // TODO nazwy


void MinerSuit::setAdditionalProductivity(double p)
{
    additionalProductivity = p;
}

void MinerSuit::setSalaryReduction(double r)
{
    salaryReduction = r;
}

double MinerSuit::getSalaryReduction()
{
    return salaryReduction;
}

double MinerSuit::getAdditionalProductivity()
{
    return additionalProductivity;
}
