#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include "abovegroundworker.h"

class Accountant:public AboveGroundWorker
{
private:
    static int accountants;
public:
    Accountant();
    ~Accountant();
    void work();
};

#endif // ACCOUNTANT_H
