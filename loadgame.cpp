#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "Functions.h"
#include "Map.h"
#include "Player.h"
#include "Station.h"
#include "Mal.h"
using namespace std;

void loadGame(Map& gameMap, Player& player1, Player& player2, int& counter) {
    ifstream inFile("saved_game.txt");

    // Loading game data from file
    if (inFile.is_open()) {
        // Loading gameMap data
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int color, type;
                inFile >> color >> type;
                gameMap.setStationColor(i, j, static_cast<Color>(color));
                gameMap.setStationType(i, j, static_cast<StationType>(type));
            }
        }

        // Loading player1 data
        string name;
        inFile >> name;
        player1.setName(name);
        for (int i = 0; i < NUM_MAL; i++) {
            int row, col, numMalPassedStart;
            inFile >> row >> col >> numMalPassedStart;
            player1.setRow(i, row);
            player1.setCol(i, col);
            player1.setNumMalPassedStart(i, numMalPassedStart);
        }

        // Loading player2 data
        inFile >> name;
        player2.setName(name);
        for (int i = 0; i < NUM_MAL; i++) {
            int row, col, numMalPassedStart;
            inFile >> row >> col >> numMalPassedStart;
            player2.setRow(i, row);
            player2.setCol(i, col);
            player2.setNumMalPassedStart(i, numMalPassedStart);
        }

        // Loading counter
        inFile >> counter;

        inFile.close();
        cout << "Game loaded successfully." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}
