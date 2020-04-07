#include <QDebug>
#include "game.h"

Game::Game()
{
    months = 0;
}

void Game::setMonths(int m)
{
    months = m;
}
int Game::getMonths()
{
    return months;
}


