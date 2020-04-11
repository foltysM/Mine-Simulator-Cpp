#include "minerhat.h"

MinerHat::MinerHat():MinerItem()
{
    int w = rand()%5;
    switch(w)
    {
    case 0:
        name = "Knight's hat";
        salaryReduction = 0.07;
        price = 1000; // TODO przy ustalaniu finansow
        break;
    case 1:
        name = "Peasant's hat";
        salaryReduction = 0.01;
        price = 1000;
        break;
    case 2:
        name = "Mongolian helmet";
        salaryReduction = 0.03;
        price = 1000;
        break;
    case 3:
        name = "Common miner hat";
        salaryReduction = 0.03;
        price = 1000;
        break;
    case 4:
        name = "Awesome hat";
        salaryReduction = 0.1;
        price = 1000;
        break;
    }
}
