#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H


class Accountant
{
private:
    static int accountants;
public:
    Accountant();
    ~Accountant();
    void work();
};

#endif // ACCOUNTANT_H
