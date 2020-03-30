#ifndef ABOVEGROUNDWORKERITEM_H
#define ABOVEGROUNDWORKERITEM_H


class AboveGroundWorkerItem
{
private:
    double reduction;
public:
    AboveGroundWorkerItem();
    void listItems();
    virtual void useItem() = 0;
};

#endif // ABOVEGROUNDWORKERITEM_H
