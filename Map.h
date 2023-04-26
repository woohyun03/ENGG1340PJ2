#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>
#include "Station.h"
using namespace std;

class Map {
private:
    string mapChart[100][100];
    Station mapPlayerLocation[7][7]; 
    void removeMal(int row, int col);
    void addMal(int row, int col, string** mal);

public:
    Map();
    Map(Station mapPlayerLocation[7][7]);
    Station (*get_mapPlayerLocation())[7][7];
    void moveMal(int previRow, int previCol, int row, int col, string** mal);
    void movePlayerLocation(int previRow, int previCol, int row, int col);
    void removePlayerLocation(int row, int col, int playerNum, int malNum);
    void addPlayerLocation(int row, int col, int playerNum, int malNum);
    void UpdatePlayerLocation(int previRow, int previCol, int row, int col, int playerNum, int malNum);
    string printMap();
    
};

#endif