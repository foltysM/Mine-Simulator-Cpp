#include "minersuit.h"

MinerSuit::MinerSuit()
{
    int w = rand()%5;
    switch(w)
    {
    case 0:
        name = "Pretty good lamp";
        additionalProductivity = 1.03;
        price = 1000;
        salaryReduction = 0.99;
        break;
    case 1:
        name = "Old miner's suit";
        additionalProductivity = 1.005;
        salaryReduction = 0.98;
        price = 1000;
        break;
    case 2:
        name = "Suit from future";
        additionalProductivity = 1.015;
        salaryReduction = 0.97;
        price = 1000;
        break;
    case 3:
        name = "Common miner suit";
        additionalProductivity = 1.015;
        salaryReduction = 0.96;
        price = 1000;
        break;
    case 4:
        name = "Miner's armor";
        additionalProductivity = 1.05;
        salaryReduction = 0.95;
        price = 1000;
        break;
    }
}


void MinerSuit::setAdditionalProductivity(double p)
{
    if(p>=1)
        additionalProductivity = p;
    else
    {
        QMessageBox msg;
        msg.setText("Error encountered, productivity not set!");
    }
}

void MinerSuit::setSalaryReduction(double r)
{
    if(r<=1)
        salaryReduction = r;
    else
    {
        QMessageBox msg;
        msg.setText("Error encountered, reduction not set!");
    }
}

double MinerSuit::getSalaryReduction()
{
    return salaryReduction;
}

double MinerSuit::getAdditionalProductivity()
{
    return additionalProductivity;
}
