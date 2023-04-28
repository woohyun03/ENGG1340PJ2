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

string Map::mapPlayerLocation_to_station(int row, int col){
    map<array<int, 2>, string> rowColMatch;
    
    rowColMatch[array<int, 2>{6,0}] = "HKU";
    rowColMatch[array<int, 2>{6,1}] = "Disneyland";
    rowColMatch[array<int, 2>{6,2}] = "Ocean Park";
    rowColMatch[array<int, 2>{6,4}] = "Man Mo";
    rowColMatch[array<int, 2>{6,5}] = "Western Market";
    rowColMatch[array<int, 2>{6,6}] = "Admiralty";
    
    rowColMatch[array<int, 2>{5,0}] = "Repulse Bay";
    rowColMatch[array<int, 2>{5,1}] = "Victoria Park";
    rowColMatch[array<int, 2>{5,5}] = "Tai Kwun";
    rowColMatch[array<int, 2>{5,6}] = "Tai O";
    
    rowColMatch[array<int, 2>{4,0}] = "HKMOA";
    rowColMatch[array<int, 2>{4,2}] = "Clock Tower";
    rowColMatch[array<int, 2>{4,4}] = "Lan Kwai Fong";
    rowColMatch[array<int, 2>{4,6}] = "Avenue of Stars";
    
    rowColMatch[array<int, 2>{3,3}] = "Tsim Sha Tsui";
    
    rowColMatch[array<int, 2>{2,0}] = "HKMOH";
    rowColMatch[array<int, 2>{2,2}] = "Elements Mall";
    rowColMatch[array<int, 2>{2,4}] = "Promenade";
    rowColMatch[array<int, 2>{2,6}] = "Lagham Place";
    
    rowColMatch[array<int, 2>{1,0}] = "HKSM";
    rowColMatch[array<int, 2>{1,1}] = "Wong Tai Sin";
    rowColMatch[array<int, 2>{1,5}] = "Night Market";
    rowColMatch[array<int, 2>{1,6}] = "Golden Computer Arcade";
    
    rowColMatch[array<int, 2>{0,0}] = "Kowloon";
    rowColMatch[array<int, 2>{0,1}] = "Sympony of Lights";
    rowColMatch[array<int, 2>{0,2}] = "Mong Kok";
    rowColMatch[array<int, 2>{0,4}] = "Ladies' Market";
    rowColMatch[array<int, 2>{0,5}] = "Soho";
    rowColMatch[array<int, 2>{0,6}] = "North Point";

    return rowColMatch[{row,col}];

}

array<int, 2> Map::mapPlayerLocation_to_mapChart(int row, int col){
    map<array<int, 2>, array<int, 2>> rowColMatch;
    
    rowColMatch[array<int, 2>{6,0}] = array<int, 2>{54,2}; //HKU
    rowColMatch[array<int, 2>{6,1}] = array<int, 2>{54,16}; //Disneyland
    rowColMatch[array<int, 2>{6,2}] = array<int, 2>{54,30}; //Ocean Park
    rowColMatch[array<int, 2>{6,4}] = array<int, 2>{54,44}; //Man Mo
    rowColMatch[array<int, 2>{6,5}] = array<int, 2>{54,58}; //Western Market
    rowColMatch[array<int, 2>{6,6}] = array<int, 2>{54,72}; //Admiralty
    
    rowColMatch[array<int, 2>{5,0}] = array<int, 2>{44,2}; //Repulse Bay
    rowColMatch[array<int, 2>{5,1}] = array<int, 2>{44,14}; //Victoria Park
    rowColMatch[array<int, 2>{5,5}] = array<int, 2>{44,60}; //Tai Kwun
    rowColMatch[array<int, 2>{5,6}] = array<int, 2>{44,72}; //Tai O
    
    rowColMatch[array<int, 2>{4,0}] = array<int, 2>{33,2}; //HKMOA
    rowColMatch[array<int, 2>{4,2}] = array<int, 2>{37,26}; //Clock Tower
    rowColMatch[array<int, 2>{4,4}] = array<int, 2>{37,48}; //Lan Kwai Fong
    rowColMatch[array<int, 2>{4,6}] = array<int, 2>{33,72}; //Avenue of Stars
    
    rowColMatch[array<int, 2>{3,3}] = array<int, 2>{28,37}; //Tsim Sha Tsui 
    
    rowColMatch[array<int, 2>{2,0}] = array<int, 2>{23,2}; //HKMOH
    rowColMatch[array<int, 2>{2,2}] = array<int, 2>{19,26}; //Elements Mall
    rowColMatch[array<int, 2>{2,4}] = array<int, 2>{19,48}; //Promenade
    rowColMatch[array<int, 2>{2,6}] = array<int, 2>{23,72}; //Lagham Place
    
    rowColMatch[array<int, 2>{1,0}] = array<int, 2>{12,2}; //HKSM
    rowColMatch[array<int, 2>{1,1}] = array<int, 2>{10,14}; //Wong Tai Sin
    rowColMatch[array<int, 2>{1,5}] = array<int, 2>{10,60}; //Night Market
    rowColMatch[array<int, 2>{1,6}] = array<int, 2>{12,72}; //Golden Computer Arcade
    
    rowColMatch[array<int, 2>{0,0}] = array<int, 2>{2,2}; //Kowloon
    rowColMatch[array<int, 2>{0,1}] = array<int, 2>{2,16}; //Sympony of Lights
    rowColMatch[array<int, 2>{0,2}] = array<int, 2>{2,30}; //Mong Kok
    rowColMatch[array<int, 2>{0,4}] = array<int, 2>{2,44}; //Ladies' Market
    rowColMatch[array<int, 2>{0,5}] = array<int, 2>{2,58}; //Soho
    rowColMatch[array<int, 2>{0,6}] = array<int, 2>{2,72}; //North Point

    return rowColMatch[{row,col}];

    /*int IndexInMapDisplay[29][2] =
    
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
    };*/
}

void Map::removeMal(int row, int col){
    array<int, 2> rowCol = mapPlayerLocation_to_mapChart(row,col);

    for (int i = rowCol[0]; i < rowCol[0]+3; i++){
        for (int j = rowCol[1]; j < rowCol[1]+3; j++){
            mapChart[i][j] = " ";
        }
    }
}

void Map::addMal(int row, int col, string mal[3][3]){
    array<int, 2> rowCol = mapPlayerLocation_to_mapChart(row,col);

    for (int i = rowCol[0]; i < rowCol[0]+3; i++){
        for (int j = rowCol[1]; j < rowCol[1]+3; j++){
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
    for (int i=0;i<60;i++) {
        for (int j=0;j<77;j++) {
            cout << mapChart[i][j];
        }
        cout << "" << endl;
    }
}
