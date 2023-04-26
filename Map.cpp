#include <iostream>
#include <string>
#include <array>
#include <map>
#include "Map.h"
#include "Station.h"
#include "MapChartDisplay.h"
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

    for (int i = 0; i < 60; i++){
        for (int j = 0; j< 70; j++){
            mapChart[i][j] = external_map[i][j];
        }
    }
}

Map::Map(Station mapPlayerLocation[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            this->mapPlayerLocation[i][j] = mapPlayerLocation[i][j];
        }
    }
}

Station Map::getPlayerLocation(int row, int col){
    return mapPlayerLocation[row][col];
}

int* mapPlayerLocation_to_mapChart(int row, int col){
    map<array<int, 2>, array<int, 2>> rowColMatch;
    
    rowColMatch[{{6,0}}] = {{54,2}}; //HKU
    rowColMatch[{{6,1}}] = {{54,16}}; //Disneyland
    rowColMatch[{{6,2}}] = {{54,30}}; //Ocean Park
    rowColMatch[{{6,4}}] = {{54,44}}; //Man Mo
    rowColMatch[{{6,5}}] = {{54,58}}; //Western Market
    rowColMatch[{{6,6}}] = {{54,72}}; //Admiralty
    
    rowColMatch[{{5,0}}] = {{44,2}}; //Repulse Bay
    rowColMatch[{{5,1}}] = {{44,14}}; //Victoria Park
    rowColMatch[{{5,5}}] = {{44,60}}; //Tai Kwun
    rowColMatch[{{5,6}}] = {{44,72}}; //Tai O
    
    rowColMatch[{{4,0}}] = {{33,2}}; //HKMOA
    rowColMatch[{{4,2}}] = {{37,26}}; //Clock Tower
    rowColMatch[{{4,4}}] = {{37,48}}; //Lan Kwai Fong
    rowColMatch[{{4,6}}] = {{33,72}}; //Avenue of Stars
    
    rowColMatch[{{3,3}}] = {{28,37}}; //Tsim Sha Tsui 
    
    rowColMatch[{{2,0}}] = {{23,2}}; //HKMOH
    rowColMatch[{{2,2}}] = {{19,26}}; //Elements Mall
    rowColMatch[{{2,4}}] = {{19,48}}; //Promenade
    rowColMatch[{{2,6}}] = {{23,72}}; //Lagham Place
    
    rowColMatch[{{1,0}}] = {{12,2}}; //HKSM
    rowColMatch[{{1,1}}] = {{10,14}}; //Wong Tai Sin
    rowColMatch[{{1,5}}] = {{10,60}}; //Night Market
    rowColMatch[{{1,6}}] = {{12,72}}; //Golden Computer Arcade
    
    rowColMatch[{{0,0}}] = {{2,2}}; //Kowloon
    rowColMatch[{{0,1}}] = {{2,16}}; //Sympony of Lights
    rowColMatch[{{0,2}}] = {{2,30}}; //Mong Kok
    rowColMatch[{{0,4}}] = {{2,44}}; //Ladies' Market
    rowColMatch[{{0,5}}] = {{2,58}}; //Soho
    rowColMatch[{{0,6}}] = {{2,72}}; //North Point

    int IndexInMapDisplay[29][2] =
    
    {
        { 2, 2 }, //Kowloon
        { 2, 16 }, //Symphony of Lights
        { 2, 30 }, //Mong Kok
        { 2, 44 },//Ladies' Market
        { 2, 58 },//Soho
        { 2, 72 },//North Point
        { 10, 14 }, //Wong Tai Sin
        { 10, 60 }, //Night Market
        { 12, 2 }, //HKSM
        { 12, 72 }, //Golden Computer Arcade
        { 19, 26 }, //Elements Mall 
        { 19, 48 }, //Promenade
        { 23, 2 }, //HKMOH
        { 23, 72 }, //Langham Place
        { 28, 37 }, //Tsim Sa Tsui
        { 33, 2 }, //HKMOA
        { 33, 72 }, //Avenue of Stars
        { 37, 26 }, //Clock Tower
        { 37, 48 }, //Lan Kwai Fong
        { 44, 2 }, //Repluse Bay
        { 44, 72 }, //Tai O
        { 46, 14 }, //Victoria Peak
        { 46, 60 }, //Tai Kwun
        { 54, 2 }, //HKU
        { 54, 16 }, //Disneyland
        { 54, 30 }, //Ocean Park
        { 54, 44 }, //Man Mo
        { 54, 58 }, //Western Market
        { 54, 72 }, //Admiralty
    };
}

void Map::removeMal(int row, int col){
    for (int i = row; i < row+3; i++){
        for (int j = col; j < col+3; j++){
            mapChart[i][j] = " ";
        }
    }
}

void Map::addMal(int row, int col, string mal[3][3]){
    for (int i = row; i < row+3; i++){
        for (int j = col; j < col+3; j++){
            mapChart[i][j] = mal[i][j];
        }
    }
}

void Map::moveMal(int previRow, int previCol, int row, int col, string mal[3][3]) {
    removeMal(previRow, previCol);
    addMal(row, col, mal);
}

void Map::removePlayerLocation(int row, int col, int playerNum, int malNum){
    if (playerNum == 0){
        if (malNum == 1){
            mapPlayerLocation[row][col].Playerone_first = false;
        } else if(malNum == 2){
            mapPlayerLocation[row][col].Playerone_second = false;
        } else if (malNum ==3){
            mapPlayerLocation[row][col].Playerone_third = false;
        }
    } else if (playerNum == 1){
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
    if (playerNum == 0){
        if (malNum == 1){
            mapPlayerLocation[row][col].Playerone_first = true;
        } else if(malNum == 2){
            mapPlayerLocation[row][col].Playerone_second = true;
        } else if (malNum ==3){
            mapPlayerLocation[row][col].Playerone_third = true;
        }
    } else if (playerNum == 1){
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
