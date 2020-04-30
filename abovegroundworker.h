#ifndef ABOVEGROUNDWORKER_H
#define ABOVEGROUNDWORKER_H

#include <iostream>
#include "chair.h"
#include "computer.h"
#include "desk.h"

class AboveGroundWorker
{
private:
    std::string name;
    Chair *chair;
    Computer *computer;
    Desk *desk;
    double salary;
public:
    AboveGroundWorker();
    void setDesk(Desk *d);
    void setComputer(Computer *c);
    void setChair(Chair *c);
    Chair* getChair();
    Computer* getComputer();
    Desk* getDesk();
};

#endif // ABOVEGROUNDWORKER_H
