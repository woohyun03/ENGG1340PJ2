#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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

void saveGameName(string filename);
int Get_Number_of_Saved_Games();
void loadGameNames();
void save_game(string &filename, Map &gameMap, Player &player1, Player &player2);
void load_game(string &filename, Map &gameMap, Player &player1, Player &player2);
int askWhichTicket(vector<int> &tickets);
vector<string> askMalMovement(int turn, Player one, Player two);
int getTicket();
string getTicketName(int ticketNum);
void move_or_carry_Mal(Player &player, int playerNum, int malSelect, string malSign, int TicketResult, Map &gameMap, int pRow, int pCol, int row, int col);
void killMal(Map &gameMap, Player &opponent, int playerNum, int newRow, int newCol);
void displayTicket(int moves);
void moveMalDisplay(Map &gameMap, string malSign, int previRow, int previCol, int row, int col);
void PrintExplain(int row, int col);
#endif