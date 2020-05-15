#ifndef NOTSEASONDEPENDENTCOMPANY_H
#define NOTSEASONDEPENDENTCOMPANY_H

#include <iostream>

class NotSeasonDependentCompany
{
private:
    double moneyPayingAmount;
    std::string name;

public:
    /**
     * @brief Konstruktor klasy NotSeasonDependentCompany
     */
    NotSeasonDependentCompany();

    double needs_brown;
    double needs_black;
    /**
     * @brief Metoda zwracająca zapotrzebowanie firmy na węgiel kamienny
     * @return Ilość jednostek zapotrzebowania
     */
    double getNeedsBlack();
    /**
     * @brief Metoda zwracająca zapotrzebowanie firmy na węgiel brunatny
     * @return Ilość jednostek zapotrzebowania
     */
    double getNeedsBrown();
    /**
     * @brief Metoda zwracająca ilość płaconych pieniędzy
     * @return Ilość płaconych pieniędzy
     */
    double getMoneyPayingAmount();
};

#endif // NOTWEATHERDEPENDENTCOMPANY_H
