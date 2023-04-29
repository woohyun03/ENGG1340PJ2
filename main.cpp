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
            cout << "Continue the Game? ('q' for exit / press Enter if you want to continue): ";
            cin >> input;
            if (input == "q" || input == "Q") {
                cout << "Exit the Game." << endl;
                break;
            }
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

        TicketResult = getTicket();
        cout << getTicketName(TicketResult) << "!!!" << endl;


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
            cout << malVector[malSelect] << " will move to" << gameMap.mapPlayerLocation_to_station(player1.getRow(malSelect),player1.getCol(malSelect)) << endl;
        } else {
            cout << malVector[malSelect] << " will move to" << gameMap.mapPlayerLocation_to_station(player2.getRow(malSelect),player2.getCol(malSelect)) << endl;
        }

        if (turn == 0){
            move_or_carry_Mal(player1, 0, malSelect, malVector[malSelect], TicketResult, gameMap, player1.getPreviousRow(malSelect), player1.getPreviousCol(malSelect), player1.getRow(malSelect), player1.getCol(malSelect));
            moveMalDisplay(gameMap, malVector[malSelect], player1.getPreviousRow(malSelect), player1.getPreviousCol(malSelect),player1.getRow(malSelect), player1.getCol(malSelect));
        } else {
            move_or_carry_Mal(player2, 1, malSelect, malVector[malSelect], TicketResult, gameMap, player2.getPreviousRow(malSelect), player2.getPreviousCol(malSelect), player2.getRow(malSelect), player2.getCol(malSelect));
            moveMalDisplay(gameMap, malVector[malSelect], player2.getPreviousRow(malSelect), player2.getPreviousCol(malSelect),player2.getRow(malSelect), player2.getCol(malSelect));
        }

        this_thread::sleep_for(chrono::seconds(2));

        gameMap.printMap();

        cout << malVector[malSelect] << " have arrived to " << gameMap.mapPlayerLocation_to_station(player1.getRow(malSelect),player1.getCol(malSelect))<<endl;

        for(int i = 0, i < 5; ++i){
            if(currentPosition == PositionArray[i]){
                if(/*catched opponent's mal*/){
                    cout << "You have Killed the oppoent's mal number " << MalArray[i] << endl;
                    PositionArray[i] = 0;
                }
                else{
                    cout << "You are now carrying this mal" << endl;
                    //carry mal function to be added
                }
            }
        }
        if(/*winning condition*/){
            break
        }
        cout << "Your turn has ended, it is player " << turnShower << "'s turn" << /n << endl;
    }
    cout << "Game Over! Player" << turn << "wins!!!" << endl;
    return 0;
}
