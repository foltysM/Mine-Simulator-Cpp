#ifndef ABOVEGROUNDWORKERITEM_H
#define ABOVEGROUNDWORKERITEM_H

#include <stdlib.h>
#include <QMessageBox>
// TODO include game


class AboveGroundWorkerItem
{
private:
    double reduction;
public:
    AboveGroundWorkerItem();
    void listItems();
    virtual double useItem() = 0;
    //virtual bool special(Game g) = 0;
    double getReduction();
    void setReductionOne();
    void setReduction(double r);
};

#endif // ABOVEGROUNDWORKERITEM_H
