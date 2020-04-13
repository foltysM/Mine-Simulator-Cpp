#include "abovegroundworker.h"

AboveGroundWorker::AboveGroundWorker()
{

}

void AboveGroundWorker::setDesk(Desk d)
{
    desk = d;
}

void AboveGroundWorker::setComputer(Computer c)
{
    computer = c;
}

void AboveGroundWorker::setChair(Chair c)
{
    chair = c;
}

Chair AboveGroundWorker::getChair()
{
    return chair;
}

Computer AboveGroundWorker::getComputer()
{
    return computer;
}

Desk AboveGroundWorker::getDesk()
{
    return desk;
}
