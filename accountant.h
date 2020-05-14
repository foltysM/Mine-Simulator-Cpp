#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include "abovegroundworker.h"


class Accountant:public AboveGroundWorker
{
public:
    Accountant();
    /**
     * @brief Metoda powodująca "pracę" księgowego czyli redukcję opłat
     * @return Wartość redukcji
     */
    double work();
};

#endif // ACCOUNTANT_H
