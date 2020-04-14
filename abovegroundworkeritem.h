#ifndef ABOVEGROUNDWORKERITEM_H
#define ABOVEGROUNDWORKERITEM_H

#include <stdlib.h>

class AboveGroundWorkerItem
{
protected:
    double reduction;
public:
    AboveGroundWorkerItem();
    void listItems();
    virtual void useItem() = 0;
    double getReduction();
    void setReductionOne();
};

#endif // ABOVEGROUNDWORKERITEM_H
