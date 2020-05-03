#ifndef COMPUTER_H
#define COMPUTER_H

#include "abovegroundworkeritem.h"
//#include "game.h"

class Computer:public AboveGroundWorkerItem
{
private:
    //double reduction;
public:
    Computer();
    double useItem();
    //bool special(Game *g);
};

#endif // COMPUTER_H
