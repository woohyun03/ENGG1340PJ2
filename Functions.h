#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include "Map.h"
#include "Player.h"
#include "Station.h"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define GRAY "\033[37m"
#define BROWN "\033[38;2;205;127;50m"
using namespace std;

vector<string> askMalMovement(int turn, Player one, Player two);
int getTicket();
string getTicketName(int ticketNum);
void killMal(Map &gameMap, int playerNum, int killerMalNum, int newRow, int newCol);
void displayTicket(int moves);
void moveMalDisplay(Map &gameMap, int playerNum, int malNum, int previRow, int previCol, int row, int col);

#endif