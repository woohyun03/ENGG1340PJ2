#include <iostream>
#include <string>
#include <array>
#include <map>
#include <utility> 
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
        for (int j = 0; j< 77; j++){
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
    typedef pair<int, int> rowCol;
    map< rowCol, string > rowColMatch;
    rowColMatch.insert(make_pair(make_pair(6, 0), "HKU"));
    rowColMatch.insert(make_pair(make_pair(6, 1), "Disneyland"));
    rowColMatch.insert(make_pair(make_pair(6, 2), "Ocean Park"));
    rowColMatch.insert(make_pair(make_pair(6, 4), "Man Mo"));
    rowColMatch.insert(make_pair(make_pair(6, 5), "Western Market"));
    rowColMatch.insert(make_pair(make_pair(6, 6), "Admiralty"));
    rowColMatch.insert(make_pair(make_pair(5, 0), "Repulse Bay"));
    rowColMatch.insert(make_pair(make_pair(5, 1), "Victoria Park"));
    rowColMatch.insert(make_pair(make_pair(5, 5), "Tai Kwun"));
    rowColMatch.insert(make_pair(make_pair(5, 6), "Tai O"));
    rowColMatch.insert(make_pair(make_pair(4, 0), "HKMOA"));
    rowColMatch.insert(make_pair(make_pair(4, 2), "Clock Tower"));
    rowColMatch.insert(make_pair(make_pair(4, 4), "Lan Kwai Fong"));
    rowColMatch.insert(make_pair(make_pair(4, 6), "Avenue of Stars"));
    rowColMatch.insert(make_pair(make_pair(3, 3), "Tsim Sha Tsui"));
    rowColMatch.insert(make_pair(make_pair(2, 0), "HKMOH"));
    rowColMatch.insert(make_pair(make_pair(2, 2), "Elements Mall"));
    rowColMatch.insert(make_pair(make_pair(2, 4), "Promenade"));
    rowColMatch.insert(make_pair(make_pair(2, 6), "Lagham Place"));
    rowColMatch.insert(make_pair(make_pair(1, 0), "HKSM"));
    rowColMatch.insert(make_pair(make_pair(1, 1), "Wong Tai Sin"));
    rowColMatch.insert(make_pair(make_pair(1, 5), "Night Market"));
    rowColMatch.insert(make_pair(make_pair(1, 6), "Golden Computer Arcade"));
    rowColMatch.insert(make_pair(make_pair(0, 0), "Kowloon"));
    rowColMatch.insert(make_pair(make_pair(0, 1), "Sympony of Lights"));
    rowColMatch.insert(make_pair(make_pair(0, 2), "Mong Kok"));
    rowColMatch.insert(make_pair(make_pair(0, 4), "Ladies' Market"));
    rowColMatch.insert(make_pair(make_pair(0, 5), "Soho"));
    rowColMatch.insert(make_pair(make_pair(0, 6), "North Point"));

    return rowColMatch[make_pair(row, col)];

}

pair<int, int> Map::mapPlayerLocation_to_mapChart(int row, int col){
    typedef pair<int, int> rowCol;
    typedef pair<int, int> resultRowCol;
    map< rowCol, resultRowCol > rowColMatch;
    rowColMatch.insert(make_pair(make_pair(6,0), make_pair(54,2))); //HKU
    rowColMatch.insert(make_pair(make_pair(6,1), make_pair(54,16))); //Disneyland
    rowColMatch.insert(make_pair(make_pair(6,2), make_pair(54,30))); //Ocean Park
    rowColMatch.insert(make_pair(make_pair(6,4), make_pair(54,44))); //Man Mo
    rowColMatch.insert(make_pair(make_pair(6,5), make_pair(54,58))); //Western Market
    rowColMatch.insert(make_pair(make_pair(6,6), make_pair(54,72))); //Admiralty
    rowColMatch.insert(make_pair(make_pair(5,0), make_pair(44,2))); //Repulse Bay
    rowColMatch.insert(make_pair(make_pair(5,1), make_pair(44,14))); //Victoria Park
    rowColMatch.insert(make_pair(make_pair(5,5), make_pair(44,60))); //Tai Kwun
    rowColMatch.insert(make_pair(make_pair(5,6), make_pair(44,72))); //Tai O
    rowColMatch.insert(make_pair(make_pair(4,0), make_pair(33,2))); //HKMOA
    rowColMatch.insert(make_pair(make_pair(4,2), make_pair(37,26))); //Clock Tower
    rowColMatch.insert(make_pair(make_pair(4,4), make_pair(37,48))); //Lan Kwai Fong
    rowColMatch.insert(make_pair(make_pair(4,6), make_pair(33,72))); //Avenue of Stars
    rowColMatch.insert(make_pair(make_pair(3,3), make_pair(28,37))); //Tsim Sha Tsui
    rowColMatch.insert(make_pair(make_pair(2,0), make_pair(23,2))); //HKMOH
    rowColMatch.insert(make_pair(make_pair(2,2), make_pair(19,26))); //Elements Mall
    rowColMatch.insert(make_pair(make_pair(2,4), make_pair(19,48))); //Promenade
    rowColMatch.insert(make_pair(make_pair(2,6), make_pair(23,72))); //Lagham Place
    rowColMatch.insert(make_pair(make_pair(1,0), make_pair(12,2))); //HKSM
    rowColMatch.insert(make_pair(make_pair(1,1), make_pair(10,14))); //Wong Tai Sin
    rowColMatch.insert(make_pair(make_pair(1,5), make_pair(10,60))); //Night Market
    rowColMatch.insert(make_pair(make_pair(1,6), make_pair(12,72))); //Golden Computer Arcade
    rowColMatch.insert(make_pair(make_pair(0,0), make_pair(2,2))); //Kowloon
    rowColMatch.insert(make_pair(make_pair(0,1), make_pair(2,16))); //Sympony
    rowColMatch.insert(make_pair(make_pair(0,2), make_pair(2,30))); //Mong Kok
    rowColMatch.insert(make_pair(make_pair(0,4), make_pair(2,44))); //Ladies' Market
    rowColMatch.insert(make_pair(make_pair(0,5), make_pair(2,58))); //Soho
    rowColMatch.insert(make_pair(make_pair(0,6), make_pair(2,72))); //North Point

    return rowColMatch[make_pair(row,col)];
}

void Map::removeMal(int row, int col){
    pair<int, int> rowCol = mapPlayerLocation_to_mapChart(row,col);

    for (int i = rowCol.first; i < rowCol.first+3; i++){
        for (int j = rowCol.second; j < rowCol.second+3; j++){
            mapChart[i][j] = " ";
        }
    }
}

void Map::addMal(int row, int col, string mal[3][3]){
    pair<int, int> rowCol = mapPlayerLocation_to_mapChart(row,col);

    for (int i = rowCol.first; i < rowCol.first+3; i++){
        for (int j = rowCol.second; j < rowCol.second+3; j++){
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

void Map::printMap(){
    for (int i=0;i<60;i++) {
        for (int j=0;j<77;j++) {
            cout << mapChart[i][j];
        }
        cout << "" << endl;
    }
}
