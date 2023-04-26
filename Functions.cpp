#include <iostream>
#include <string>
#include "Functions.h"
#include "Map.h"
#include "Player.h"
#include "Station.h"
using namespace std;

void killMal(Map &gameMap, int killerPlayerNum, int row, int col){
    bool killFirst = false;
    bool killSecond = false;
    bool killThird = false;

    if (killerPlayerNum == 1){
        if (gameMap.getPlayerLocation(row, col).Playertwo_first){
            killFirst = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playertwo_second){
            killSecond = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playertwo_third){
            killThird = true;
        }
    } else if (killerPlayerNum == 2){
        if (gameMap.getPlayerLocation(row, col).Playerone_first){
            killFirst = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playerone_second){
            killSecond = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playerone_third){
            killThird = true;
        }
    }

    cout << "You killed the opponent's mal number(s):";

    if (killFirst){
        gameMap.removePlayerLocation(row, col, killerPlayerNum + 1, 1);
        cout << " 1";
    }
    if (killSecond){
        gameMap.removePlayerLocation(row, col, killerPlayerNum + 1, 2);
        cout << " 2";
    }
    if (killThird){
        gameMap.removePlayerLocation(row, col, killerPlayerNum + 1, 3);
        cout << " 3";
    }

    cout << "." << endl;
}

