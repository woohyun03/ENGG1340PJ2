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

void saveGame(Map gameMap, Player player1, Player player2, int counter) {
    ofstream outFile("saved_game.txt");

    // Saving game data to file
    if (outFile.is_open()) {
        // Saving gameMap data
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                outFile << gameMap.getStationType(i, j) << " ";
            }
            outFile << endl;
        }

        // Saving player1 data
        outFile << player1.getName() << " ";
        for (int i = 0; i < NUM_MAL; i++) {
            outFile << player1.getRow(i) << " " << player1.getCol(i) << " " << player1.getNumMalPassedStart(i) << " ";
        }
        outFile << endl;

        // Saving player2 data
        outFile << player2.getName() << " ";
        for (int i = 0; i < NUM_MAL; i++) {
            outFile << player2.getRow(i) << " " << player2.getCol(i) << " " << player2.getNumMalPassedStart(i) << " ";
        }
        outFile << endl;

        // Saving counter
        outFile << counter << endl;

        outFile.close();
        cout << "Game saved successfully." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}
