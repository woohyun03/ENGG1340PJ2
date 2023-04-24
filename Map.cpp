#include <iostream>
#include <string>
#include "Map.h"
#include "Station.h"
using namespace std;

Map::Map() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            mapPlayerLocation[i][j].Playerone_first = false;
            mapPlayerLocation[i][j].Playerone_second = false;
            mapPlayerLocation[i][j].Playerone_third = false;
            mapPlayerLocation[i][j].Playertwo_first = false;
            mapPlayerLocation[i][j].Playertwo_second = false;
            mapPlayerLocation[i][j].Playerone_third = false;
        }
    }
    mapPlayerLocation[6][0].Playerone_first = true;
    mapPlayerLocation[6][0].Playerone_second = true;
    mapPlayerLocation[6][0].Playerone_third = true;
    mapPlayerLocation[6][0].Playertwo_first = true;
    mapPlayerLocation[6][0].Playertwo_second = true;
    mapPlayerLocation[6][0].Playerone_third = true;
}

Map::Map(Station mapPlayerLocation[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            this->mapPlayerLocation[i][j] = mapPlayerLocation[i][j];
        }
    }
}

void Map::removeMal(int row, int col){
    for (int i = row; i < row+3; i++){
        for (int j = col; j < col+3; j++){
            mapChart[i][j] = " ";
        }
    }
}

void Map::addMal(int row, int col, string** mal){
    for (int i = row; i < row+3; i++){
        for (int j = col; j < col+3; j++){
            mapChart[i][j] = mal[i][j];
        }
    }
}

void Map::moveMal(int previRow, int previCol, int row, int col, string** mal) {
    removeMal(previRow, previCol);
    addMal(row, col, mal);
}


void Map::UpdatePlayerLocation(int previRow, int previCol, int row, int col) {

}

string Map::printMap(){

}