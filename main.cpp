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
    string outputText;
    
    for (int i = 0; i < 20; i++){
        cout << endl;
    }
    typingEffect("Welcome to Korean Traditional Yut Game (MTR EDITION) !!!! ");
    this_thread::sleep_for(chrono::seconds(1));
    cout << endl;
    typingEffect("Press Enter to Continue");
    getline(cin, input);

    if (Get_Number_of_Saved_Games() >0){
        typingEffect("You have " + to_string(Get_Number_of_Saved_Games()) + " saved games.");
        cout << endl;
        loadGameNames();
        typingEffect("Type the game you want to load.");
        cout << endl;
        cin >> input;
        load_game(input, gameMap, player1, player2);
    } else {
        typingEffect("There are no saved games. We will start a new game!");
        cout << endl;
        typingEffect("Press Enter to Start");
        getline(cin, input);
        typingEffect("Enter player 1's name: ");
        cin >> input;
        player1.setName(input);
        typingEffect("Enter player 2's name: ");
        cin >> input;
        player2.setName(input);
    }

    typingEffect("We will start game in...");
    cout << endl;
    for (int i = 0; i < 3; i++){
            this_thread::sleep_for(chrono::seconds(1));
            cout << "\r" << 3 - i << "..." << endl;
        }

    while (true) {

        gameMap.printMap();

        for (int i = 0; i < 100; i++) {
            cout << "-";
        }
        cout << endl;
        
        if (counter != -1){
            typingEffect("Continue the Game? ('q' for exit / 's' to save)");
            cout << endl;
            cin >> input;
            if (input == "q"){
                cout << "Exit the Game." << endl;
                break;
            } else if(input == "s"){
                cout << "Game Name : ";
                cin >> input;
                save_game(input, gameMap, player1, player2);
            }
        }

        counter = counter + 1;

        if(counter % 2 == 0){
            typingEffect("It is " + player1.getName() + "'s turn");
            turn = 0;
        }
        else{
            typingEffect("It is " + player2.getName() + "'s turn");
            turn = 1;
        }
        cout << endl;
        cout << endl;

        typingEffect("Press Enter to roll the Yut (Get the Ticket)!!");
        cin.ignore(); 
        getline(cin, input);

        typingEffect("Your ticket is...");
        for (int i = 0; i < 3; i++){
            this_thread::sleep_for(chrono::seconds(1));
            cout <<  3 - i << "..." << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));

        while (true){
            TicketResult = getTicket();
            tickets.push_back(TicketResult);
            cout << getTicketName(TicketResult) << "!!!" << endl;
            if (TicketResult < 4){
                break;
            } else if (TicketResult >= 4){
                cout << endl;
                cout << "Wow!! You got " << getTicketName(TicketResult) << " ticket! You can roll the Yut one more Time! Press Enter to roll the Yut." << endl;
                getline(cin, input);
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
            while (malSelect != 0 && malSelect != 1 && malSelect != 2){
                cout << "Invalid input. Please input a number from 0-2." << endl;
                cout << "Type here: ";
                cin >> malSelect;
            }
            

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
