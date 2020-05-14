#ifndef BROWNCOALMINE_H
#define BROWNCOALMINE_H

#include "mine.h"

class BrownCoalMine: public Mine
{
public:
    /**
     * @brief Konstruktor klasy BrownCoalMine
     */
    BrownCoalMine();
    /**
     * @brief Metoda powodująca ponowne wylosowanie możliwych do kupienia przedmiotów górnika
     * @param g Wskaźnik na obiekt gry
     */
    void runSpecial(Game *g);
};

#endif // BROWNCOALMINE_H
