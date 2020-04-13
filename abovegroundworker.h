#ifndef ABOVEGROUNDWORKER_H
#define ABOVEGROUNDWORKER_H

#include <iostream>
#include "chair.h"
#include "computer.h"
#include "desk.h"

class AboveGroundWorker
{
protected:
    std::string name;
    Chair chair;
    Computer computer;
    Desk desk;
    double salary;
public:
    AboveGroundWorker();
    virtual void work() = 0;
    void setDesk(Desk d);
    void setComputer(Computer c);
    void setChair(Chair c);
    Chair getChair();
    Computer getComputer();
    Desk getDesk();
};

#endif // ABOVEGROUNDWORKER_H
