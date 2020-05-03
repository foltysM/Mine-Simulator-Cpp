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
}

void AboveGroundWorkerItem::setReduction(double r)
{
    if(r<=1)
        reduction = r;
    else
    {
         QMessageBox msg;
         msg.setText("Error encountered, reduction not set!");
    }
}
