#include "SaveLoad.h"

void save_game(const string &filename, const Map &gameMap, const Player &player1, const Player &player2, int counter) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cerr << "Error opening file for saving game state." << endl;
        return;
    }

    // Save players' names and counter
    outFile << player1.getName() << endl;
    outFile << player2.getName() << endl;
    outFile << counter << endl;

    // Save gameMap, player1, and player2 data (you'll need to create the appropriate functions in the respective classes)

    outFile.close();
}

bool load_game(const string &filename, Map &gameMap, Player &player1, Player &player2, int &counter) {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cerr << "Error opening file for loading game state." << endl;
        return false;
    }

    // Load players' names and counter
    string name;
    getline(inFile, name);
    player1.setName(name);
    getline(inFile, name);
    player2.setName(name);
    inFile >> counter;

    // Load gameMap, player1, and player2 data (you'll need to create the appropriate functions in the respective classes)

    inFile.close();
    return true;
}
