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

Station (*Map::get_mapPlayerLocation())[7][7] {
    return &mapPlayerLocation;
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

void Map::removePlayerLocation(int row, int col, int playerNum, int malNum){
    if (playerNum == 1){
        if (malNum == 1){
            mapPlayerLocation[row][col].Playerone_first = false;
        } else if(malNum == 2){
            mapPlayerLocation[row][col].Playerone_second = false;
        } else if (malNum ==3){
            mapPlayerLocation[row][col].Playerone_third = false;
        }
    } else if (playerNum == 2){
        if (malNum == 1){
            mapPlayerLocation[row][col].Playertwo_first = false;
        } else if(malNum == 2){
            mapPlayerLocation[row][col].Playertwo_second = false;
        } else if (malNum ==3){
            mapPlayerLocation[row][col].Playertwo_third = false;
        }
    }
}

void Map::addPlayerLocation(int row, int col, int playerNum, int malNum){
    if (playerNum == 1){
        if (malNum == 1){
            mapPlayerLocation[row][col].Playerone_first = true;
        } else if(malNum == 2){
            mapPlayerLocation[row][col].Playerone_second = true;
        } else if (malNum ==3){
            mapPlayerLocation[row][col].Playerone_third = true;
        }
    } else if (playerNum == 2){
        if (malNum == 1){
            mapPlayerLocation[row][col].Playertwo_first = true;
        } else if(malNum == 2){
            mapPlayerLocation[row][col].Playertwo_second = true;
        } else if (malNum ==3){
            mapPlayerLocation[row][col].Playertwo_third = true;
        }
    }
}

void Map::UpdatePlayerLocation(int previRow, int previCol, int row, int col, int playerNum, int malNum) {
    removePlayerLocation(previRow, previCol, playerNum, malNum);
    addPlayerLocation(row, col, playerNum, malNum);
}

string Map::printMap(){

}