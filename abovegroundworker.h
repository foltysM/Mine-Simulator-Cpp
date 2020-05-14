#ifndef ABOVEGROUNDWORKER_H
#define ABOVEGROUNDWORKER_H

#include <iostream>
#include "chair.h"
#include "computer.h"
#include "desk.h"

class AboveGroundWorker
{
private:
    std::string name;
    Chair *chair;
    Computer *computer;
    Desk *desk;
    double salary;
public:
    /**
     * @brief Konstruktor klasy AboveGroundWorker
     */
    AboveGroundWorker();
    /**
     * @brief Metoda ustawiająca wskaźnik na obiekt klasy Desk
     * @param d Wskaźnik na obiekt
     */
    void setDesk(Desk *d);
    /**
     * @brief Metoda ustawiająca wskaźnik na obiekt klasy Computer
     * @param c Wskaźnik na obiekt
     */
    void setComputer(Computer *c);
    /**
     * @brief Metoda ustawiająca wskaźnik na obiekt klasy Chair
     * @param c Wskaźnik na obiekt
     */
    void setChair(Chair *c);
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt klasy Chair
     * @return Wskaźnik na obiekt klasy Chair
     */
    Chair* getChair();
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt klasy Computer
     * @return Wskaźnik na obiekt klasy Computer
     */
    Computer* getComputer();
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt klasy Desk
     * @return Wskaźnik na obiekt klasy Desk
     */
    Desk* getDesk();
};

#endif // ABOVEGROUNDWORKER_H
