#include <iostream>
#include <string>
#include <vector>
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
    int turnShower;
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
            cout << "It is Player 1's turn";
            turnShower = 0;
        }
        else{
            cout << "It is Player 2's turn";
            turnShower = 1;
        }

        vector<string> malVector = askMalMovement(turnShower, player1, player2);
        cin >> malSelect;

        if (turnShower == 0){
            cout << "Current Position of " << malVector[malSelect] << " is" << gameMap.mapPlayerLocation_to_station(player1.getRow(malSelect),player1.getCol(malSelect)) << endl;
        } else {
            cout << "Current Position of " << malVector[malSelect] << " is" << gameMap.mapPlayerLocation_to_station(player2.getRow(malSelect),player2.getCol(malSelect)) << endl;
        }

        TicketResult = getTicket();
        cout << "Your ticket is..." << TicketResult << endl;

        //move mal and save other info (function to be added)
        //display map (functions to be added)

        cout << "You have arrived to..." << /*place explantion functio << endl*/;

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
    cout << "Game Over! Player" << turnShower << "wins!!!" << endl;
    return 0;
}
