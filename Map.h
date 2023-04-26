#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>
#include "Station.h"
using namespace std;

class Map {
private:
    string mapChart[60][77];
    Station mapPlayerLocation[7][7]; 
    void removeMal(int row, int col);
    void addMal(int row, int col, string mal[3][3]);
    int* mapPlayerLocation_to_mapChart(int row, int col);

public:
    Map();
    Map(Station mapPlayerLocation[7][7]);
    Station getPlayerLocation(int row, int col);
    void moveMal(int previRow, int previCol, int row, int col, string mal[3][3]);
    void movePlayerLocation(int previRow, int previCol, int row, int col);
    void removePlayerLocation(int row, int col, int playerNum, int malNum);
    void addPlayerLocation(int row, int col, int playerNum, int malNum);
    void UpdatePlayerLocation(int previRow, int previCol, int row, int col, int playerNum, int malNum);
    string printMap();
    
};

#endif