#ifndef MIXEDCOALMINE_H
#define MIXEDCOALMINE_H

#include "mine.h"

class MixedCoalMine: public Mine
{
public:
    /**
     * @brief Konstruktor klasy MixedCoalMine
     */
    MixedCoalMine();
    /**
     * @brief Metoda losująca special - możliwe dodanie po 5 jednostek każdego węgla do magazynu
     * @param g Wskaźnik na obiekt gry
     */
    void runSpecial(Game *g);
};

#endif // MIXEDCOALMINE_H
