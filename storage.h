#ifndef STORAGE_H
#define STORAGE_H


#include <QMessageBox>

class Storage
{
private:
    double blackCoalAmount;
    double brownCoalAmount;
    double price;
public:
    /**
     * @brief Konstruktor klasy Storage
     */
    Storage();
    /**
     * @brief Metoda zwracająca ilość węgla kamiennego w magazynie
     * @return Ilość węgla kamiennego w magazynie
     */
    double getBlackCoalAmount();
    /**
     * @brief Metoda zwracająca ilość węgla brunatnego w magazynie
     * @return Ilość węgla brunatny w magazynie
     */
    double getBrownCoalAmount();
    /**
     * @brief Metoda zwracająca cenę za przechowanie jednostki węgla
     * @return Cenę za przechowanie jednostki węgla
     */
    double getPrice();
    /**
     * @brief Metoda ustawiająca ilość węgla kamiennego w magazynie
     * @param bla Ilość węgla kamiennego
     */
    void setBlackCoalAmount(double bla);
    /**
     * @brief Metoda ustawiająca ilość węgla brunatnego w magazynie
     * @param bra Ilość węgla brunatnego
     */
    void setBrownCoalAmount(double bra);
};

#endif // STORAGE_H
