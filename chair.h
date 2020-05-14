#ifndef CHAIR_H
#define CHAIR_H

#include "abovegroundworkeritem.h"


class Chair: public AboveGroundWorkerItem
{
public:
    /**
     * @brief Konstruktor klasy Chair
     */
    Chair();
    /**
     * @brief Metoda losująca możliwość połowicznej redukcji wypłaty dla górników w danym miesiącu
     * @return Wartość redukcji
     */
    double useItem();
    /**
     * @brief Metoda losująca czy special dla obiektu klasy Chair powinien się wykonać czy nie
     * @param g Wskaźnik na obiekt gry
     */
    void special(Game *g);
};

#endif // CHAIR_H
