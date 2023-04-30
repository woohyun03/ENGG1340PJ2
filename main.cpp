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

int main(){
    Map gameMap;
    Player player1;
    Player player2;
    int counter = -1;
    int turn;
    int TicketResult;
    string input;
    int malSelect;
    vector<int> tickets;

    cout << "Welcome to ... Korean Traditional Yut Game (MTR EDITION) !!!" << endl;
    cout << "Enter player 1's name: ";
    cin >> input;
    player1.setName(input);
    cout << "Enter player 2's name: ";
    cin >> input;
    player2.setName(input);

    while (true) {

        gameMap.printMap();

        for (int i = 0; i < 50; i++) {
            cout << "-";
        }
        cout << endl;


        counter = counter + 1;
        if (counter != -1){
            cout << "Continue the Game? ('q' for exit / 's' to save / 'l' to load / press Enter if you want to continue): ";
        cin >> input;
        if (input == "q" || input == "Q") {
            cout << "Exit the Game." << endl;
            break;
        } else if (input == "s" || input == "S") {
            cout << "Enter the filename to save the game state: ";
            cin >> input;
            save_game(input, gameMap, player1, player2, counter);
            cout << "Game state saved." << endl;
            continue;
        } else if (input == "l" || input == "L") {
            cout << "Enter the filename to load the game state: ";
            cin >> input;
            if (load_game(input, gameMap, player1, player2, counter)) {
                cout << "Game state loaded." << endl;
            } else {
                cout << "Failed to load the game state." << endl;
            }
            continue;
        }


        if(counter % 2 == 0){
            cout << "It is "<< player1.getName() << "'s turn";
            turn = 0;
        }
        else{
            cout << "It is "<< player2.getName() << "'s turn";
            turn = 1;
        }
        cout << endl;


        cout << "Press Enter to roll the Yut (Get the ticket)";
        cin >> input;
        cout << "Your ticket is..." << endl;
        for (int i = 0; i < 3; i++){
            this_thread::sleep_for(chrono::seconds(1));
            cout << "\r" << 3 - i << "..." << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));

        while (true){
            TicketResult = getTicket();
            tickets.push_back(TicketResult);
            cout << getTicketName(TicketResult) << "!!!" << endl;
            if (TicketResult < 4){
                break;
            }else if (TicketResult >= 4){
                cout << endl;
                cout << "Wow!! You got " << getTicketName(TicketResult) << " ticket! You can roll the Yut one more Time! Press Enter to roll the Yut." << endl;
                cin >> input;
                cout << "Your ticket is..." << endl;
                for (int i = 0; i < 3; i++){
                    this_thread::sleep_for(chrono::seconds(1));
                    cout << "\r" << 3 - i << "..." << endl;
                }
                this_thread::sleep_for(chrono::seconds(1));
            } 
        }

        gameMap.printMap();

        while (tickets.size() != 0){
            if (turn == 0){
                player1.check_Carried();
            } else {
                player2.check_Carried();
            }

            TicketResult = askWhichTicket(tickets);
            vector<string> malVector = askMalMovement(turn, player1, player2);
            cin >> malSelect;

            if (turn == 0){
                cout << "Current Position of " << malVector[malSelect] << " is" << gameMap.mapPlayerLocation_to_station(player1.getRow(malSelect),player1.getCol(malSelect)) << endl;
            } else {
                cout << "Current Position of " << malVector[malSelect] << " is" << gameMap.mapPlayerLocation_to_station(player2.getRow(malSelect),player2.getCol(malSelect)) << endl;
            }

            this_thread::sleep_for(chrono::seconds(1));
            cout << endl;

            if (turn == 0){
                move_or_carry_Mal(player1, 0, malSelect, malVector[malSelect], TicketResult, gameMap, player1.getPreviousRow(malSelect), player1.getPreviousCol(malSelect), player1.getRow(malSelect), player1.getCol(malSelect));
                if (player1.getMal(stoi(malVector[malSelect].substr(1,1))).finished){
                    gameMap.removeMal(player1.getRow(malSelect), player1.getCol(malSelect));
                } else {
                    moveMalDisplay(gameMap, malVector[malSelect], player1.getPreviousRow(malSelect), player1.getPreviousCol(malSelect),player1.getRow(malSelect), player1.getCol(malSelect));
                }
            } else {
                move_or_carry_Mal(player2, 1, malSelect, malVector[malSelect], TicketResult, gameMap, player2.getPreviousRow(malSelect), player2.getPreviousCol(malSelect), player2.getRow(malSelect), player2.getCol(malSelect));
                if (player1.getMal(stoi(malVector[malSelect].substr(1,1))).finished){
                    gameMap.removeMal(player2.getRow(malSelect), player2.getCol(malSelect));
                } else {
                    moveMalDisplay(gameMap, malVector[malSelect], player2.getPreviousRow(malSelect), player2.getPreviousCol(malSelect),player2.getRow(malSelect), player2.getCol(malSelect));
                }
            }


            if (turn == 0){
                cout << malVector[malSelect] << " will move to" << gameMap.mapPlayerLocation_to_station(player1.getRow(malSelect),player1.getCol(malSelect)) << endl;
            } else {
                cout << malVector[malSelect] << " will move to" << gameMap.mapPlayerLocation_to_station(player2.getRow(malSelect),player2.getCol(malSelect)) << endl;
            }

            this_thread::sleep_for(chrono::seconds(2));

            gameMap.printMap();
            
            PrintExplain(player1.getRow(malSelect),player1.getCol(malSelect));
            if (turn == 0){
                killMal(gameMap, player2, turn, player1.getRow(malSelect), player1.getCol(malSelect));
            } else {
                killMal(gameMap, player1, turn, player2.getRow(malSelect), player2.getCol(malSelect));
            }
        }


        if(turn == 0 && player1.win()){
            cout << "Game Over! Player 1 (" << player1.getName() << ") wins!!!" << endl;
        } else if (player2.win()){
            cout << "Game Over! Player 2 (" << player2.getName() << ") wins!!!" << endl;
        }
    }
    return 0;
}
