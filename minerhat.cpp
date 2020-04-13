#include "minerhat.h"

MinerHat::MinerHat()
{
    int w = rand()%5;
    switch(w)
    {
    case 0:
        name = "Knight's hat";
        salaryReduction = 0.93;
        price = 1000; // TODO przy ustalaniu finansow
        break;
    case 1:
        name = "Peasant's hat";
        salaryReduction = 0.99;
        price = 1000;
        break;
    case 2:
        name = "Mongolian helmet";
        salaryReduction = 0.97;
        price = 1000;
        break;
    case 3:
        name = "Common miner hat";
        salaryReduction = 0.97;
        price = 1000;
        break;
    case 4:
        name = "Awesome hat";
        salaryReduction = 0.9;
        price = 1000;
        break;
    }
}

void MinerHat::setSalaryReduction(double r)
{
    salaryReduction = r;
}

double MinerHat::getSalaryReduction()
{
    return salaryReduction;
}
