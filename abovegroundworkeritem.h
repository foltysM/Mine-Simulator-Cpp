#ifndef ABOVEGROUNDWORKERITEM_H
#define ABOVEGROUNDWORKERITEM_H

#include <stdlib.h>

class AboveGroundWorkerItem
{
private:
    double reduction;
public:
    AboveGroundWorkerItem();
    void listItems();
    virtual double useItem() = 0;
    double getReduction();
    void setReductionOne();
};

#endif // ABOVEGROUNDWORKERITEM_H
