#ifndef NEWMINERSLIST_H
#define NEWMINERSLIST_H

#include <vector>
#include "miner.h"

class NewMinersList
{
private:
    std::vector <Miner> minerList;

public:
    NewMinersList();
    void generateMinerList();
    std::vector<Miner> getMinersList();
};

#endif // NEWMINERSLIST_H
