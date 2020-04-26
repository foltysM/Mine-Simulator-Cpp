#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include "abovegroundworker.h"


class Accountant:public AboveGroundWorker
{
public:
    Accountant();
    ~Accountant();
    double work();
};

#endif // ACCOUNTANT_H
