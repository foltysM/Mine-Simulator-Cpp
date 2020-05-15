#ifndef MINER_H
#define MINER_H

#include <QMessageBox>
#include <iostream>
#include "minerlamp.h"
#include "minerhat.h"
#include "minersuit.h"

class Miner
{
private:
    int kids;
    MinerHat *hat;
    MinerLamp *lamp;
    MinerSuit *suit;
    double monthSalary;
    std::string name;
    double productivity;
    int seniority;
    int strikeOpportunity;    
    bool tradeUnion;
    bool striking;
public:
    /**
     * @brief Konstruktor klasy Miner
     */
    Miner();
    /**
     * @brief Metoda zwracająca liczbę dzieci górnika
     * @return Liczbę dzieci górnika
     */
    int getKids();
    /**
     * @brief Metoda zwracająca imię górnika
     * @return Imię górnika
     */
    std::string getName();
    /**
     * @brief Metoda zwracająca produktywność górnika
     * @return Produktywność górnika
     */
    double getProductivity();
    /**
     * @brief Metoda zwracająca wielkość wypłaty
     * @return Wielkość wypłaty górnika
     */
    double getSalaryAmount();
    /**
     * @brief Metoda zwracająca staż górnika
     * @return Staż górnika
     */
    int getSeniority();
    /**
     * @brief Metoda ustawiająca staż górnika
     * @param s Staż górnika
     */
    void setSeniority(int s);
    /**
     * @brief Metoda zwracająca czy dany górnik strajkuje w danym miesiącu czy nie
     * @return True, jeżeli strajkuje
     */
    bool getStriking();
    /**
     * @brief Metoda ustawiająca pole striking, określające czy górnik strajkuje
     * @param s True, jeżeli górnik będzie strajkować; false jeżeli nie
     */
    void setStriking(bool s);
    /**
     * @brief Metoda zwraca czy dany górnik jest w związku zawodowym czy nie
     * @return True, jeżeli górnik należy do związku zawodowego
     */
    bool getUnion();
    /**
     * @brief Metoda zwracająca skłonność do strajków górnika
     * @return Wartość oznaczającą skłonność do strajków
     */
    int getStrikeOpportunity();
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt klasy MinerHat górnika
     * @return Wskaźnik na obiekt klasy MinerHat
     */
    MinerHat* getHat();
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt klasy MinerSuit górnika
     * @return Wskaźnik na obiekt klasy MinerSuit
     */
    MinerSuit* getSuit();
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt klasy MinerLamp górnika
     * @return Wskaźnik na obiekt klasy MinerLamp
     */
    MinerLamp* getLamp();
    /**
     * @brief Metoda ustawiająca wskaźnik na obiekt klasy MinerHat górnika
     * @param h Wskaźnik na obiekt klasy MinerHat
     */
    void setHat(MinerHat *h);
    /**
     * @brief Metoda ustawiająca wskaźnik na obiekt klasy MinerSuit górnika
     * @param Wskaźnik na obiekt klasy MinerSuit
     */
    void setSuit(MinerSuit *s);
    /**
     * @brief Metoda ustawiająca wskaźnik na obiekt klasy MinerLamp górnika
     * @param Wskaźnik na obiekt klasy MinerLamp
     */
    void setLamp(MinerLamp *l);
};
#endif // MINER_H
