#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Map.h"
#include "Player.h"
using namespace std;

void save_game(const string &filename, const Map &gameMap, const Player &player1, const Player &player2, int counter);
bool load_game(const string &filename, Map &gameMap, Player &player1, Player &player2, int &counter);
