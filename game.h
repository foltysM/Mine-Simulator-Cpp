#ifndef GAME_H
#define GAME_H

#include <vector>
#include "miner.h"
#include "storage.h"
#include "seasondependent.h"
#include "notseasondependentcompany.h"
#include "blackcoalmine.h"
#include "browncoalmine.h"
#include "mixedcoalmine.h"
#include "officeworker.h"
#include "accountant.h"

class Game
{
private:
    std::vector <Miner*> minerList;
    int months;
    std::string season;
    MinerHat *hat;
    MinerSuit *suit;
    MinerLamp *lamp;
    double money;   
    SeasonDependent *heatingPlant;
    SeasonDependent *powerStation;
    NotSeasonDependentCompany *coalStorageSite;
    NotSeasonDependentCompany *ironworks;
    int miners_overall;
    int officeWorkersAmount;
    double lastMonthRevenues;
    int accountantsAmount;
    std::vector <Accountant*> vectorAccountants;
    std::vector <OfficeWorker*> vectorOfficeWorkers;
    Storage storage;
    BlackCoalMine *blackCoalMine;
    BrownCoalMine *brownCoalMine;
    MixedCoalMine *mixedCoalMine;
    bool computerSpecial = false;
    bool chairSpecial = false;

public:   
    Game();
    /**
     * @brief Metoda ustawiająca wartość computerSpecial, która określa czy special powinien się wykonać czy nie
     * @param s Ustawiana wartość
     */
    void setComputerSpecial(bool s);
    /**
     * @brief Metoda ustawiająca wartość chairSpecial, która określa czy special powinien się wykonać czy nie
     * @param s Ustawiana wartość
     */
    void setChairSpecial(bool s);
    /**
     * @brief Metoda pobierająca wartość computerSpecial
     * @return Wartość computerSpecial
     */
    bool getComputerSpecial();
    /**
     * @brief Metoda pobierająca wartość chairSpecial
     * @return Wartość chairSpecial
     */
    bool getChairSpecial();
    /**
     * @brief Metoda tworząca nowe obiekty podklas MinerItem, które będą potem możliwe do kupienia
     */
    void initMinerItems();
    /**
     * @brief Metoda zwracająca jednego górnika z listy górników
     * @param i Numer górnika na liście górników
     * @return Obiekt górnika o wybranym numerze
     */
    Miner* getOneMinerFromList(int i);
    /**
     * @brief Metoda inicjująca obiekty trzech kopalń wykorzystywanych w grze
     */
    void initMines();
    /**
     * @brief Metoda zwracająca przychody z zeszłego miesiąca
     * @return Wartość przychodów w zeszłym miesiącu
     */
    double getLastMonthRevenues();
    /**
     * @brief Metoda ustawiająca wartość miesiąca
     * @param m Numer miesiąca gry
     */
    void setMonths(int m);
    /**
     * @brief Metoda zwracająca numer miesiąca gry
     * @return Numer miesiąca gry
     */
    int getMonths();
    /**
     * @brief Metoda tworząca nowy obiekt klasy MinerHat
     * @return Wskaźnik na stworzony obiekt
     */
    MinerHat* generateHat();
    /**
     * @brief Metoda tworząca nowy obiekt klasy MinerSuit
     * @return Wskaźnik na stworzony obiekt
     */
    MinerSuit* generateSuit();
    /**
     * @brief Metoda tworząca nowy obiekt klasy MinerLamp
     * @return Wskaźnik na stworzony obiekt
     */
    MinerLamp* generateLamp();
    /**
     * @brief Metoda zwracająca porę roku
     * @return Nazwę pory roku
     */
    std::string getSeason();
    /**
     * @brief Metoda ustawiająca nazwę pory roku na podstawie miesiąca gry
     */
    void setSeason();
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt huty
     * @return Wskaźnik na obiekt huty
     */
    NotSeasonDependentCompany* getIronWorks();
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt składowiska węgla
     * @return Wskaźnik na obiekt składowiska
     */
    NotSeasonDependentCompany* getCoalStorageSite();
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt elektrowni
     * @return Wskaźnik na obiekt elektrowni
     */
    SeasonDependent* getPowerStation();
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt ciepłowni
     * @return Wskaźnik na obiekt ciepłowni
     */
    SeasonDependent* getHeatingPlant();
    /**
     * @brief Metoda usuwająca obiekt górnika z listy górników
     * @param w Numer górnika na liście
     */
    void eraseMiner(int w);
    /**
     * @brief Metoda generująca listę górników
     */
    void generateMinerList();
    /**
     * @brief Metoda zwracająca listę górników
     * @return Wskaźnik na listę górników
     */
    std::vector<Miner*> getMinersList();
    /**
     * @brief Metoda ustawiająca ilość pieniędzy gracza
     * @param m Ilość pieniędzy
     */
    void setMoney(double m);
    /**
     * @brief Metoda zwracająca ilość pieniędzy gracza
     * @return Ilość pieniędzy
     */
    double getMoney();
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt klasy MinerHat możliwy do kupienia
     * @return Wskaźnik na obiekt klasy MinerHat
     */
    MinerHat* getHat();
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt klasy MinerSuit możliwy do kupienia
     * @return Wskaźnik na obiekt klasy MinerSuit
     */
    MinerSuit* getSuit();
    /**
     * @brief Metoda zwracająca wskaźnik na obiekt klasy MinerLamp możliwy do kupienia
     * @return Wskaźnik na obiekt klasy MinerLamp
     */
    MinerLamp* getLamp();
    /**
     * @brief Metoda ustawiająca wskaźnik na obiekt klasy MinerHat mozliwy do kupienia
     * @param h Wskaźnik na obiekt klasy MinerHat
     */
    void setHat(MinerHat *h);
    /**
     * @brief Metoda ustawiająca wskaźnik na obiekt klasy MinerSuit możliwy do kupienia
     * @param s Wskaźnik na obiekt klasy MinerSuit
     */
    void setSuit(MinerSuit *s);
    /**
     * @brief Metoda ustawiająca wskaźnik na obiekt klasy MinerLamp możliwy do kupienia
     * @param l Wskaźnik na obiekt klasy MinerLamp
     */
    void setLamp(MinerLamp *l);
    /**
     * @brief Metoda odejmująca od pieniędzy gracza zadaną liczbę
     * @param m Liczba pieniędzy do odjęcia
     */
    void subMoney(double m);
    /**
     * @brief Metoda zwracająca wskaźnik na magazyn węgla
     * @return Wskaźnik na magazyn węgla
     */
    Storage* getStorage();
    /**
     * @brief Metoda odświeżająca ilość pracowników biurowych
     */
    void refreshOfficeWorkersAmount();
    /**
     * @brief Metoda odświeżająca ilość księgowych
     */
    void refreshAccountantsAmount();
    /**
     * @brief Metoda zwracająca liczbę strajkujących w danym miesiącu górników
     * @return Liczbę strajkujących w danym miesiącu górników
     */
    int randomStrike();
    /**
     * @brief Metoda obliczająca ile pieniędzy "szkolnych" musi zapłacić gracz na dzieci górników (Działa gdy pora roku to jesień)
     * @return Ilość pieniędzy do zapłacenia
     */
    double moneyForChildren();
    /**
     * @brief Metoda zwracająca ilość pracowników biurowych
     * @return Ilość pracowników biurowych
     */
    int getOfficeWorkersAmount();
    /**
     * @brief Metoda ustawiająca wielkość przychodów w miesiącu
     * @param r Ilość zarobionych pieniędzy
     */
    void setLastMonthRevenues(double r);
    /**
     * @brief Metoda obliczająca finalną redukcję wszystkich przedmiotów pracowników górnych
     * @return Finalną redukcję
     */
    double itemsReduction();
    /**
     * @brief Metoda obliczająca finalną redukcję opłat za magazyn obliczaną na podstawie redukcji księgowych
     * @return Finalną redukcję
     */
    double getAccStorageReduction();
    /**
     * @brief Metoda dodająca lub usuwająca księgowych z listy na podstawie przychodów z poprzedniego miesiąca
     */
    void createAcc();
    /**
     * @brief Metoda zwracająca listę księgowych
     * @return Listę księgowych
     */
    std::vector <Accountant*> getAccountantsVector();
    /**
     * @brief Metoda zwracająca listę pracowników biurowych
     * @return Listę pracowników biurowych
     */
    std::vector <OfficeWorker*> getOfficeWorkersVector();
    /**
     * @brief Metoda zwracająca pracownika biurowego z listy
     * @param i Numer pracownika na liście
     * @return Wskaźnik na określonego pracownika
     */
    OfficeWorker* getOneOfficeWorker(int i);
    /**
     * @brief Metoda zwracająca księgowego z listy
     * @param i Numer księgowego na liście
     * @return Wskaźnik na określonego księgowego
     */
    Accountant* getOneAccountant(int i);
    /**
     * @brief Metoda zwracająca wskaźnik na kopalnię węgla kamiennego
     * @return Wskaźnik na kopalnię węgla kamiennego
     */
    BlackCoalMine* getBlackCoalMine();
    /**
     * @brief Metoda zwracająca wskaźnik na kopalnię węgla brunatnego
     * @return Wskaźnik na kopalnię węgla brunatnego
     */
    BrownCoalMine* getBrownCoalMine();
    /**
     * @brief Metoda zwracająca wskaźnik na kopalnię węgla mieszanego
     * @return Wskaźnik na kopalnię węgla mieszanego
     */
    MixedCoalMine* getMixedCoalMine();
    /**
     * @brief Metoda zwalniająca miejsce wcześniej wykorzystywane na listę górników
     */
    void deleteMinersList();
    /**
     * @brief Metoda zwalniająca miejsce wcześniej wykorzystywane na kopalnie
     */
    void deleteMines();
    /**
     * @brief Metoda dodająca określoną liczbę pieniędzy do pieniędzy gracza
     * @param m Liczba pieniędzy
     */
    void addMoney(double m);
    /**
     * @brief Metoda zwalniająca miejsce wcześniej wykorzystywane na obiekt klasy MinerHat
     */
    void deleteHat();
    /**
     * @brief Metoda zwalniająca miejsce wcześniej wykorzystywane na obiekt klasy MinerSuit
     */
    void deleteSuit();
    /**
     * @brief Metoda zwalniająca miejsce wcześniej wykorzystywane na obiekt klasy MinerLamp
     */
    void deleteLamp();
};

#endif // GAME_H
