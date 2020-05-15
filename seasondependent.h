#ifndef SEASONDEPENDENT_H
#define SEASONDEPENDENT_H

#include <iostream>
#include <QMessageBox>
#include "notseasondependentcompany.h"

class SeasonDependent :public NotSeasonDependentCompany
{
private:
    std::string season;
public:
    /**
     * @brief Konstruktor klasy SeasonDependent
     */
    SeasonDependent();
    /**
     * @brief Metoda ustawiająca zapotrzebowanie firmy na węgiel kamienny
     * @param n Ilość zapotrzebowania
     */
    void setNeedsBlack(double n);
    /**
     * @brief Metoda zwracająca zapotrzebowanie firmy na węgiel kamienny
     * @return Ilość zapotrzebowania
     */
    double getNeedsBlack();
    /**
     * @brief Metoda zwracająca zapotrzebowanie firmy na węgiel brunatny
     * @return Ilość zapotrzebowania
     */
    double getNeedsBrown();
    /**
     * @brief Metoda ustawiająca porę roku
     * @param s Nazwa pory roku
     */
    void setSeason(std::string s);
};

#endif // WEATHERDEPENDENT_H
