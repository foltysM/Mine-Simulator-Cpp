#ifndef ABOVEGROUNDWORKER_H
#define ABOVEGROUNDWORKER_H

#include <iostream>

class AboveGroundWorker
{
private:
    std::string name;
    double salary;
public:
    AboveGroundWorker();
    virtual void work() = 0;
};

#endif // ABOVEGROUNDWORKER_H
