#ifndef MINERSUIT_H
#define MINERSUIT_H

#include <QMessageBox>
#include "mineritem.h"

class MinerSuit: public MinerItem
{
private:
    double additionalProductivity;
    double salaryReduction;
public:
    /**
     * @brief Konstruktor klasy MinerSuit
     */
    MinerSuit();
    /**
     * @brief Metoda ustawiająca wartość dodatkowej produktywności
     * @param p Wartość dodatkowej produktywności
     */
    void setAdditionalProductivity(double p);
    /**
     * @brief Metoda ustawiająca wartość redukcji wynagrodzenia
     * @param r Wartość o jaką redukuje się wynagrodzenie
     */
    void setSalaryReduction(double r);
    /**
     * @brief Metoda zwracająca wartość redukcji wynagrodzenia
     * @return Wartość o jaką redukuje się wynagrodzenie
     */
    double getSalaryReduction();
    /**
     * @brief Metoda zwracająca wartość dodatkowej produktywności
     * @return Wartość dodatkowej produktywności
     */
    double getAdditionalProductivity();
};

#endif // MINERSUIT_H
