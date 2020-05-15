#ifndef MINERITEM_H
#define MINERITEM_H

#include <iostream>

class MinerItem
{
protected:
    std::string name;
    int price;
public:
    /**
     * @brief Konstruktor klasy MinerItem
     */
    MinerItem();
    /**
     * @brief Metoda zwracająca nazwę przedmiotu
     * @return Nazwę przedmiotu
     */
    std::string getName();
    /**
     * @brief Metoda zwracająca cenę przedmiotu
     * @return Cenę przedmiotu
     */
    int getPrice();
    /**
     * @brief Metoda ustawiająca nazwę przedmiotu
     * @param n Nazwa przedmiotu
     */
    void setName(std::string n);
};

#endif // MINERITEM_H
