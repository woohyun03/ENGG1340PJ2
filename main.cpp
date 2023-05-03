//Including libraries and other files
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

//Comments in this file explains the general flow of the game play.

int main(){
    //Defining types of variables used for the game play
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
    
     //For aesthetic purpose
    for (int i = 0; i < 20; i++){
        cout << endl;
    }
    
    
    //Welcoming ASCII art
    WelcomeText();
    this_thread::sleep_for(chrono::seconds(1));
    
    //For aesthetic purpose
    typingEffect("Welcome to Korean Traditional Yut Game (MTR EDITION) !!!! ");
    this_thread::sleep_for(chrono::seconds(1));
    cout << endl;
    typingEffect("Press Enter to Continue and read the rule");
    getline(cin, input);

    //Rule Explaing
    cout << endl;
    gameRuleText();
    cout << endl;
    typingEffect("Press Enter to Continue");
    getline(cin, input);
    
    //If there are saved games, the system asks the player which game to load. If unsuccessful or no saved games, create a new game to play
    if (Get_Number_of_Saved_Games() >0){
        typingEffect("You have " + to_string(Get_Number_of_Saved_Games()) + " saved games.");
        cout << endl;
        loadGameNames();
        typingEffect("Type the game you want to load.");
        cout << endl;
        cin >> input;
        int loadfailed = 0;
        load_game(input, gameMap, player1, player2, loadfailed);
        if (loadfailed == 1){
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
        }
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
    


    //For aesthetic purpose
    typingEffect("We will start game in...");
    cout << endl;
    for (int i = 0; i < 3; i++){
        cout << "\r" << 3 - i << "..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }


    while (true) {
        //Printing map to show the game status    
        gameMap.printMap();       

        //For aesthetic purpose
        for (int i = 0; i < 100; i++) {
            cout << "-";
        }
        cout << endl;
        
        //Asks the player to continue or save the game when turn changes. Does not process until the player enters a valid input. Game will still continue after saving
        if (counter != -1){
            typingEffect("Continue the Game? ('q' for exit / 's' to save / Press Enter to continue)");
            cout << endl;
            if (!input.empty()){
            cin.ignore(); 
            }
            getline(cin, input);
            while (input != "q" && input != "s" && !input.empty()){
                cout << "Invalid input. Please enter a valid character 'q' or 's'." << endl;
                cout << "Type here: ";
                cin.ignore(); 
                cin >> input;
            }
            if (input == "q"){
                cout << "Exit the Game." << endl;
                break;
            } else if(input == "s"){
                cout << "Game Name : ";
                cin >> input;
                save_game(input, gameMap, player1, player2);
                cout << "Game will be continued..." << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                break;
            }
        }
        
        //Able to track which player's turn
        counter = counter + 1;

        //Showing who's turn using counter
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
        
        //For aesthetic purpose
        typingEffect("Press Enter to roll the Yut (Get the Ticket)!!");
        if (!input.empty()){
            cin.ignore();   
        }
        getline(cin, input);
        
        //For aesthetic purpose
        typingEffect("Your ticket is...");
        cout << endl;
        for (int i = 0; i < 3; i++){
            cout <<  3 - i << "..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }



        while (true){
            //Saves the tickets that players have gained until now
            TicketResult = getTicket();
            tickets.push_back(TicketResult);
            
             //Shows which ticket the player gained
            cout << getTicketName(TicketResult) << "!!!" << endl;
            displayTicket(TicketResult);
            this_thread::sleep_for(chrono::seconds(2));
            if (turn == 0){
                if (player1.no_Mal_on_Map() && TicketResult == -1){
                    break;
                }
            } else {
                if (player2.no_Mal_on_Map() && TicketResult == -1){
                    break;
                }
            }
            
            //Showing player that he or she is able to roll the Yut once more (get ticket once more) as the player picked a special ticket
            if (TicketResult < 4){
                break;
            } else if (TicketResult >= 4){
                cout << endl;
                typingEffect("Wow!! You got " + getTicketName(TicketResult) + " ticket! You can roll the Yut one more Time! Press Enter to roll the Yut.");
                getline(cin, input);
                cout << "Your ticket is..." << endl;
                for (int i = 0; i < 3; i++){
                    cout << "\r" << 3 - i << "..." << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                }       
            } 
        }
        if (turn == 0){
            //When player gains secret ticket when there is no mal in the board (for each player)
            if (player1.no_Mal_on_Map() && TicketResult == -1){
                cout << "You do not have any Mal to move backward!" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                tickets.clear();
                continue;
            }
        } else {
            //When player gains secret ticket when there is no mal in the board (for each player)
            if (player2.no_Mal_on_Map() && TicketResult == -1){
                cout << "You do not have any Mal to move backward!" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                tickets.clear();
                continue;
            }
        }
        


        while (tickets.size() != 0){
            //Showing game status during the game
            gameMap.printMap();


            //Check if the player's mal is being carried, depending on which player's turn it is
            if (turn == 0){
                player1.check_Carried();
            } else if (turn == 1) {
                player2.check_Carried();
            }
            
            //Asking which ticket to use and which mal to move to a player. Asks until the player types a correct input
            TicketResult = askWhichTicket(tickets);
            displayTicket(TicketResult);
            vector<string> malVector = askMalMovement(turn, player1, player2);
            cin >> malSelect;
            while (malSelect < 1 || malSelect > malVector.size()){
                cout << "Invalid input. Please input an appropriate mal number 1-3" << endl;
                cout << "Type here: ";
                cin.ignore(); 
                cin >> malSelect;
            }
            
            //Showing the location of the mal selected by the player before the movement
            if (turn == 0){
                cout << "Current Position of " << malVector[malSelect-1] << " is " << gameMap.mapPlayerLocation_to_station(player1.getRow(malSelect),player1.getCol(malSelect)) << endl;
            } else if (turn == 1) {
                cout << "Current Position of " << malVector[malSelect-1] << " is " << gameMap.mapPlayerLocation_to_station(player2.getRow(malSelect),player2.getCol(malSelect)) << endl;
            }
            this_thread::sleep_for(chrono::seconds(1));
            cout << endl;

            //Save the location of the selected mal after the movement, display some features of the game (ticket, map ..etc)
            if (turn == 0){
                move_or_carry_Mal(player1, 0, malSelect, malVector[malSelect-1], TicketResult, gameMap, player1.getRow(malSelect), player1.getCol(malSelect));
                if (player1.getMal(stoi(malVector[malSelect-1].substr(1,1))).finished){
                    gameMap.removeMal(player1.getRow(malSelect), player1.getCol(malSelect));
                } else {
                    moveMalDisplay(gameMap, player1, malVector[malSelect-1], player1.getPreviousRow(malSelect), player1.getPreviousCol(malSelect),player1.getRow(malSelect), player1.getCol(malSelect));
                }
            } else if (turn == 1) {
                move_or_carry_Mal(player2, 1, malSelect, malVector[malSelect-1], TicketResult, gameMap, player2.getRow(malSelect), player2.getCol(malSelect));
                if (player1.getMal(stoi(malVector[malSelect-1].substr(1,1))).finished){
                    gameMap.removeMal(player2.getRow(malSelect), player2.getCol(malSelect));
                } else {
                    moveMalDisplay(gameMap, player2, malVector[malSelect-1], player2.getPreviousRow(malSelect), player2.getPreviousCol(malSelect),player2.getRow(malSelect), player2.getCol(malSelect));
                }
            }

            //Showing the new position of the selected mal
            if (turn == 0){
                cout << malVector[malSelect-1] << " will move to " << gameMap.mapPlayerLocation_to_station(player1.getRow(malSelect),player1.getCol(malSelect)) << endl;
            } else if (turn == 1) {
                cout << malVector[malSelect-1] << " will move to " << gameMap.mapPlayerLocation_to_station(player2.getRow(malSelect),player2.getCol(malSelect)) << endl;
            }
            this_thread::sleep_for(chrono::seconds(2));

            //Explaining the location that the mal arrived, and check if the moved mal killed any opponent's mal       
            if (turn == 0){
                PrintExplain(player1.getRow(malSelect),player1.getCol(malSelect));
            } else if (turn == 1) {
                PrintExplain(player2.getRow(malSelect),player2.getCol(malSelect));
            }
            
            if (turn == 0){
                if (killMal(gameMap, player2, turn, player1.getRow(malSelect), player1.getCol(malSelect))){
                    typingEffect("Wow!! You killed the opponent's mal. You can roll the Yut one more Time!");
                    cout << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << endl;
                    while (true){
                        gameMap.printMap();
                        typingEffect("Your ticket is...");
                        cout << endl;
                        for (int i = 0; i < 3; i++){
                            cout <<  3 - i << "..." << endl;
                            this_thread::sleep_for(chrono::seconds(1));
                        }
                        //Saves the tickets that players have gained until now
                        TicketResult = getTicket();
                        tickets.push_back(TicketResult);
                        
                        //Shows which ticket the player gained
                        cout << getTicketName(TicketResult) << "!!!" << endl;
                        displayTicket(TicketResult);
                        this_thread::sleep_for(chrono::seconds(2));
                        
                        //Showing player that he or she is able to roll the Yut once more (get ticket once more) as the player picked a special ticket
                        if (TicketResult < 4){
                            break;
                        } else if (TicketResult >= 4){
                            cout << endl;
                            typingEffect("Wow!! You got " + getTicketName(TicketResult) + " ticket! You can roll the Yut one more Time! Press Enter to roll the Yut.");
                            cout << endl;
                            this_thread::sleep_for(chrono::seconds(2));
                            cout << endl;
                            cout << "Your ticket is..." << endl;
                            for (int i = 0; i < 3; i++){
                                cout << "\r" << 3 - i << "..." << endl;
                                this_thread::sleep_for(chrono::seconds(1));
                            }         
                        } 
                    }
                }
            } else if (turn == 1) {
                if (killMal(gameMap, player1, turn, player2.getRow(malSelect), player2.getCol(malSelect))){
                    typingEffect("Wow!! You killed the opponent's mal. You can roll the Yut one more Time!");
                    cout << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << endl;
                    while (true){
                        gameMap.printMap();
                        typingEffect("Your ticket is...");
                        cout << endl;
                        for (int i = 0; i < 3; i++){
                            cout <<  3 - i << "..." << endl;
                            this_thread::sleep_for(chrono::seconds(1));
                        }
                        //Saves the tickets that players have gained until now
                        TicketResult = getTicket();
                        tickets.push_back(TicketResult);
                        
                        //Shows which ticket the player gained
                        cout << getTicketName(TicketResult) << "!!!" << endl;
                        displayTicket(TicketResult);
                        this_thread::sleep_for(chrono::seconds(2));
                        
                        //Showing player that he or she is able to roll the Yut once more (get ticket once more) as the player picked a special ticket
                        if (TicketResult < 4){
                            break;
                        } else if (TicketResult >= 4){
                            cout << endl;
                            typingEffect("Wow!! You got " + getTicketName(TicketResult) + " ticket! You can roll the Yut one more Time!");
                            cout << endl;
                            this_thread::sleep_for(chrono::seconds(2));
                            cout << endl;
                            cout << "Your ticket is..." << endl;
                            for (int i = 0; i < 3; i++){
                                cout << "\r" << 3 - i << "..." << endl;
                                this_thread::sleep_for(chrono::seconds(1));
                            }         
                        } 
                    }
                }
            }
            //Check if the game is over or not. If the game is over, change the "checkwin" variable to know if the game has ended or not
            if(turn == 0 && player1.win()){
                cout << "Game Over! Player 1 (" << player1.getName() << ") wins!!!" << endl;
                checkwin = 1;
                break;           
            } else if (turn == 1 && player2.win()){
                cout << "Game Over! Player 2 (" << player2.getName() << ") wins!!!" << endl;
                checkwin = 1;
                break;
            }

        }

        //When the game is over, the program automatically ends 
        if (checkwin == 1){
            typingEffect("Game is over. Finished game will not be saved");
            typingEffect("Thank you for playing. See you in the next game!!!");
            break; 
        }
        //If the game is not over, change the turn   
        typingEffect("Press Enter to Change the turn");
        cin.ignore(); 
        getline(cin, input);
    }
    return 0;
}
