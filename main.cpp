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
    int checkwin = 0;
    string input;
    int malSelect;
    vector<int> tickets;
    string outputText;
    //Defining types of variables used for the game play
    
    for (int i = 0; i < 20; i++){
        cout << endl;
    }
    //For aesthetic purpose
    
    typingEffect("Welcome to Korean Traditional Yut Game (MTR EDITION) !!!! ");
    this_thread::sleep_for(chrono::seconds(1));
    cout << endl;
    typingEffect("Press Enter to Continue");
    getline(cin, input);
    //For aesthetic purpose

    if (Get_Number_of_Saved_Games() >0){
        typingEffect("You have " + to_string(Get_Number_of_Saved_Games()) + " saved games.");
        cout << endl;
        loadGameNames();
        typingEffect("Type the game you want to load.");
        cout << endl;
        cin >> input;
        int loadfailed = 0;
        load_game(input, gameMap, player1, player2, loadfailed);
        if (loadfailed = 1){
            typingEffect("Failed to load game. We will start a new game.");
            cout << endl;
            typingEffect("Press Enter to Start");
            getline(cin, input);
            typingEffect("Enter player 1's name: ");
            cin >> input;
            player1.setName(input);
            typingEffect("Enter player 2's name: ");
            cin >> input;
            player2.setName(input);
            loadfailed = 0;            
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
    //If there are saved games, the system asks the player which game to load. If unsuccessful or no saved games, create a new game to play

    typingEffect("We will start game in...");
    cout << endl;
    for (int i = 0; i < 3; i++){
            this_thread::sleep_for(chrono::seconds(1));
            cout << "\r" << 3 - i << "..." << endl;
        }
    //For aesthetic purpose

    while (true) {        
        if (checkwin == 1){
            typingEffect("Game is over. Finished game will not be saved");
            typingEffect("Thank you for playing. See you in the next game!!!");
            break;
        //When the game is over, the program automatically ends     
            
        gameMap.printMap();
        //Printing map to show the game status

        for (int i = 0; i < 100; i++) {
            cout << "-";
        }
        cout << endl;
        //For aesthetic purpose
        
        if (counter != -1){
            typingEffect("Continue the Game? ('q' for exit / 's' to save)");
            cout << endl;
            cin >> input;
            while (input != "q" && input != "s"){
                cout << "Invalid input. Please enter a valid character 'q' or 's'." << endl;
                cout << "Type here: ";
                cin >> input;
            }
            if (input == "q"){
                cout << "Exit the Game." << endl;
                break;
            } else if(input == "s"){
                cout << "Game Name : ";
                cin >> input;
                save_game(input, gameMap, player1, player2);
                cout << "Game saved. Game will be continued..." << endl;
                cout << endl;
                cout << endl;
                cout << endl;
            }
        }
        //Asks the player to continue or save the game when turn changes. Does not process until the player enters a valid input. Game will still continue after saving

        counter = counter + 1;
        //Able to track which player's turn

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
        //Showing who's turn using counter

        typingEffect("Press Enter to roll the Yut (Get the Ticket)!!");
        cin.ignore(); 
        getline(cin, input);
        //For aesthetic purpose

        typingEffect("Your ticket is...");
        cout << endl;
        for (int i = 0; i < 3; i++){
            this_thread::sleep_for(chrono::seconds(1));
            cout <<  3 - i << "..." << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
        //For aesthetic purpose

        while (true){
            TicketResult = getTicket();
            tickets.push_back(TicketResult);
            //Saves the tickets that players have gained until now
            
            cout << getTicketName(TicketResult) << "!!!" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            //Shows which ticket the player gained
            
            if (TicketResult < 4){
                break;
            } else if (TicketResult >= 4){
                cout << endl;
                typingEffect("Wow!! You got " + getTicketName(TicketResult) + " ticket! You can roll the Yut one more Time! Press Enter to roll the Yut.");
                getline(cin, input);
                cout << "Your ticket is..." << endl;
                for (int i = 0; i < 3; i++){
                    this_thread::sleep_for(chrono::seconds(1));
                    cout << "\r" << 3 - i << "..." << endl;
                }
                this_thread::sleep_for(chrono::seconds(1));            
            } 
            //Showing player that he or she is able to roll the Yut once more (get ticket once more) as the player picked a special ticket
        }

        gameMap.printMap();
        //Showing game status during the game

        while (tickets.size() != 0){
            if (turn == 0){
                player1.check_Carried();
            } else if (turn == 1) {
                player2.check_Carried();
            }
            //Check if the player's mal is being carried, depending on which player's turn it is

            TicketResult = askWhichTicket(tickets);
            vector<string> malVector = askMalMovement(turn, player1, player2);
            cin >> malSelect;
            while (malSelect < 1 || malSelect > malVector.size()){
                cout << "Invalid input. Please input an appropriate mal number 1-3" << endl;
                cout << "Type here: ";
                cin >> malSelect;
            }
            //Asking which ticket to use and which mal to move to a player. Asks until the player types a correct input
            

            if (turn == 0){
                cout << "Current Position of " << malVector[malSelect-1] << " is " << gameMap.mapPlayerLocation_to_station(player1.getRow(malSelect),player1.getCol(malSelect)) << endl;
            } else if (turn == 1) {
                cout << "Current Position of " << malVector[malSelect-1] << " is " << gameMap.mapPlayerLocation_to_station(player2.getRow(malSelect),player2.getCol(malSelect)) << endl;
            }

            this_thread::sleep_for(chrono::seconds(1));
            cout << endl;
            //Showing the location of the mal selected by the player before the movement

            if (turn == 0){
                move_or_carry_Mal(player1, 0, malSelect, malVector[malSelect-1], TicketResult, gameMap, player1.getPreviousRow(malSelect), player1.getPreviousCol(malSelect), player1.getRow(malSelect), player1.getCol(malSelect));
                if (player1.getMal(stoi(malVector[malSelect-1].substr(1,1))).finished){
                    gameMap.removeMal(player1.getRow(malSelect), player1.getCol(malSelect));
                } else {
                    moveMalDisplay(gameMap, malVector[malSelect-1], player1.getPreviousRow(malSelect), player1.getPreviousCol(malSelect),player1.getRow(malSelect), player1.getCol(malSelect));
                }
            } else if (turn == 1) {
                move_or_carry_Mal(player2, 1, malSelect, malVector[malSelect-1], TicketResult, gameMap, player2.getPreviousRow(malSelect), player2.getPreviousCol(malSelect), player2.getRow(malSelect), player2.getCol(malSelect));
                if (player1.getMal(stoi(malVector[malSelect-1].substr(1,1))).finished){
                    gameMap.removeMal(player2.getRow(malSelect), player2.getCol(malSelect));
                } else {
                    moveMalDisplay(gameMap, malVector[malSelect-1], player2.getPreviousRow(malSelect), player2.getPreviousCol(malSelect),player2.getRow(malSelect), player2.getCol(malSelect));
                }
            }
            //Save the location of the selected mal after the movement, display some features of the game (ticket, map ..etc)


            if (turn == 0){
                cout << malVector[malSelect-1] << " will move to " << gameMap.mapPlayerLocation_to_station(player1.getRow(malSelect),player1.getCol(malSelect)) << endl;
            } else if (turn == 1) {
                cout << malVector[malSelect-1] << " will move to " << gameMap.mapPlayerLocation_to_station(player2.getRow(malSelect),player2.getCol(malSelect)) << endl;
            }
            this_thread::sleep_for(chrono::seconds(2));
            //Showing the new position of the selected mal
            
            PrintExplain(player1.getRow(malSelect),player1.getCol(malSelect));
            if (turn == 0){
                killMal(gameMap, player2, turn, player1.getRow(malSelect), player1.getCol(malSelect));
            } else if (turn == 1) {
                killMal(gameMap, player1, turn, player2.getRow(malSelect), player2.getCol(malSelect));
            }
            //Explaining the location that the mal arrived, and check if the moved mal killed any opponent's mal
            
            if(turn == 0 && player1.win()){
                cout << "Game Over! Player 1 (" << player1.getName() << ") wins!!!" << endl;
                checkwin = 1;
                break;           
            } else if (turn == 1 && player2.win()){
                cout << "Game Over! Player 2 (" << player2.getName() << ") wins!!!" << endl;
                checkwin = 1;
                break;
            }
            //Check if the game is over or not. If the game is over, change the "checkwin" variable to know if the game has ended or not
            
            typingEffect("Press Enter to Change the turn");
            cin.ignore(); 
            getline(cin, input);
            break;
            //If the game is not over, change the turn            
        }

    }
    return 0;
}
