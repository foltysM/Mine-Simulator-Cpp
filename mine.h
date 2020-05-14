#ifndef MINE_H
#define MINE_H

#include <vector>
#include <iostream>
#include "miner.h"
#include "QMessageBox"

class Game;

class Mine
{
private:
    std::string coalType;
    double productivity;
    std::vector <Miner*> miners;
public:
    /**
     * @brief Konstruktor klasy Mine
     */
    Mine();
    virtual void runSpecial(Game *g) = 0;
    /**
     * @brief Metoda zwiększająca staż każdego górnika o 1
     */
    void upSeniority();
    /**
     * @brief Metoda zwracająca ilość wykopanego węgla
     * @return Ilość wykopanego węgla
     */
    double coalMined();
    /**
     * @brief Metoda zwracająca koszty zatrudnienia górników
     * @return Ilość pieniędzy do zapłacenia za pensje górników
     */
    double getMinerCosts();
    /**
     * @brief Metoda zwracająca wskaźnik do listy górników pracujących w kopalni
     * @return Wskaźnik do listy górników pracujących w kopalni
     */
    std::vector <Miner*>* getMiners();
    /**
     * @brief Metoda ustawiająca wskaźnik na listę górników
     * @param m Wskaźnik na listę górników
     */
    void setMiners(std::vector <Miner*>* m);
    /**
     * @brief Metoda zwracająca wskaźnik na jednego górnika z listy
     * @param i Numer górnika na liście
     * @return Wskaźnik na obiekt górnika
     */
    Miner* getOneMiner(int i);
    /**
     * @brief Metoda dodająca górnika do listy
     * @param m Wskaźnik na obiekt dodawanego górnika
     */
    void addMinerToList(Miner* m);
    /**
     * @brief Metoda usuwająca górnika z listy
     * @param i Numer górnika na liście
     */
    void eraseMiner(int i);
};

#endif // MINE_H
