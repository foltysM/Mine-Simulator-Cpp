#include "newminerslist.h"

NewMinersList::NewMinersList()
{

}

void NewMinersList::generateMinerList() {
    int list_size = minerList.size();
    int iter = 10-list_size;

    for(int i = 0; i<iter; i++)
    {
        Miner gornik;
        minerList.push_back(gornik);
    }

}


std::vector<Miner> NewMinersList::getMinersList(){
    return minerList;
}
