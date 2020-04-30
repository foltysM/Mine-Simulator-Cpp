#ifndef COMPUTER_H
#define COMPUTER_H

#include "abovegroundworkeritem.h"

class Computer:public AboveGroundWorkerItem
{
private:
    //double reduction;
public:
    Computer();
    double useItem();
};

#endif // COMPUTER_H
