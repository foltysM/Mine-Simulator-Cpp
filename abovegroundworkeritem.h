#ifndef ABOVEGROUNDWORKERITEM_H
#define ABOVEGROUNDWORKERITEM_H

#include <stdlib.h>
#include <QMessageBox>


class Game;

class AboveGroundWorkerItem
{
private:
    double reduction;
public:
    /**
     * @brief Konstruktor klasy AbovegroundWorkerItem
     */
    AboveGroundWorkerItem();
    virtual double useItem() = 0;
    virtual void special(Game *g) = 0;
    /**
     * @brief Metoda zwrająca wartość redukcji przedmiotu
     * @return Wartość redukcji przedmiotu
     */
    double getReduction();
    /**
     * @brief Metoda ustawiająca redukcję przedmiotu na 1
     */
    void setReductionOne();
    /**
     * @brief Metoda ustawiająca redukcję przedmiotu
     * @param r Wartość ustawianej redukcji
     */
    void setReduction(double r);
};

#endif // ABOVEGROUNDWORKERITEM_H
