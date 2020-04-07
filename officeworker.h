#ifndef OFFICEWORKER_H
#define OFFICEWORKER_H

#include "abovegroundworker.h"

class OfficeWorker: public AboveGroundWorker
{
public:
    OfficeWorker();
    void work();
};

#endif // OFFICEWORKER_H
