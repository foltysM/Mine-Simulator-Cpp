#ifndef COMPUTER_H
#define COMPUTER_H

#include "abovegroundworkeritem.h"


class Computer:public AboveGroundWorkerItem
{
public:
    Computer();
    double useItem();
    void special(Game *g);
};

#endif // COMPUTER_H
