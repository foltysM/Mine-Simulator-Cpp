#ifndef BLACKCOALMINE_H
#define BLACKCOALMINE_H

#include "mine.h"

class BlackCoalMine: public Mine
{
public:
    /**
     * @brief Konstruktor klasy BlackCoalMine
     */
    BlackCoalMine();
    /**
     * @brief Metoda losująca możliwość dodania graczowi $2000
     * @param g Wskaźnik na obiekt gry
     */
    void runSpecial(Game *g);
};

#endif // BLACKCOALMINE_H
