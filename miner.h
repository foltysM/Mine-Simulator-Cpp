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
     * @brief getName
     * @return
     */
    std::string getName();
    /**
     * @brief getProductivity
     * @return
     */
    double getProductivity();
    /**
     * @brief getSalaryAmount
     * @return
     */
    double getSalaryAmount();
    /**
     * @brief getSeniority
     * @return
     */
    int getSeniority();
    /**
     * @brief promotion
     */
    void promotion();
    /**
     * @brief setSeniority
     * @param s
     */
    void setSeniority(int s);
    /**
     * @brief getStriking
     * @return
     */
    bool getStriking();
    /**
     * @brief setStriking
     * @param s
     */
    void setStriking(bool s);
    /**
     * @brief getMiners
     * @return
     */
    int getMiners();
    /**
     * @brief getUnion
     * @return
     */
    bool getUnion();
    /**
     * @brief getStrikeOpportunity
     * @return
     */
    int getStrikeOpportunity();
    /**
     * @brief getHat
     * @return
     */
    MinerHat* getHat();
    /**
     * @brief getSuit
     * @return
     */
    MinerSuit* getSuit();
    /**
     * @brief getLamp
     * @return
     */
    MinerLamp* getLamp();
    /**
     * @brief setHat
     * @param h
     */
    void setHat(MinerHat *h);
    /**
     * @brief setSuit
     * @param s
     */
    void setSuit(MinerSuit *s);
    /**
     * @brief setLamp
     * @param l
     */
    void setLamp(MinerLamp *l);
};
#endif // MINER_H
