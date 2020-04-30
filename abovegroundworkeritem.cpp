#include "abovegroundworkeritem.h"

AboveGroundWorkerItem::AboveGroundWorkerItem()
{

}

double AboveGroundWorkerItem::getReduction()
{
    return reduction;
}

void AboveGroundWorkerItem::setReductionOne()
{
    reduction = 1;
    //TODO PROBLEM, NIESTWORZONY OBIEKT
}

void AboveGroundWorkerItem::setReduction(double r)
{
    reduction = r;
}
