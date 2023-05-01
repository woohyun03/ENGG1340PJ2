#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>
#include "Functions.h"
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

void typingEffect(string outputText){
    for (int i = 0; i < outputText.length(); i++) {
        char c = outputText[i];
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(30));
    }
}

void saveGameName(string filename){
    ofstream outFile;
    outFile.open("Games.txt", ios::app);

    if (outFile.fail()) {
        cout << "Error opening file for saving game names." << endl;
        return;
    }

    outFile << filename << endl;

    outFile.close();
    cout << "Game name saved successfully." << endl;
}

int Get_Number_of_Saved_Games(){
    ifstream inFile;
    inFile.open("Games.txt");

    if (inFile.fail()) {
        cout << "Error opening file for loading game names." << endl;
        return 0;
    }

    int count = 0;
    string line;

    while (getline(inFile, line)) {
        count++;
    }

    inFile.close();

    return count;
}

void loadGameNames(){
    ifstream inFile;
    inFile.open("Games.txt");

    if (inFile.fail()) {
        cout << "Error opening file for loading game names." << endl;
        return;
    }

    vector<string> gameNames;
    string gameName;

    while (getline(inFile, gameName)) {
        gameNames.push_back(gameName);
    }

    inFile.close();

    cout << "Saved Games: ";
    for (int i = 0; i < gameNames.size(); i++) {
        cout << gameNames[i] << "   ";
    }
    cout << endl;
}


void save_game(string filename, Map gameMap, Player player1, Player player2) {
    ofstream outFile;
    outFile.open(filename.c_str());

    if (outFile.fail()) {
        cout << "Error opening file for saving game state." << endl;
        return;
    }

    // Save players' names and counter
    outFile << player1.getName() << endl;
    outFile << player2.getName() << endl;

    // Saving player1 data
    for (int i = 1; i <= 3; i++) {
        outFile << i;
        outFile << player1.getMal(i).row;
        outFile << player1.getMal(i).column;
        outFile << player1.getMal(i).can_finish;
        outFile << player1.getMal(i).finished;
        outFile << player1.getMal(i).carried << endl;
    }


    // Saving player2 data
    for (int i = 1; i <= 3; i++) {
        outFile << i;
        outFile << player2.getMal(i).row;
        outFile << player2.getMal(i).column;
        outFile << player2.getMal(i).can_finish;
        outFile << player2.getMal(i).finished;
        outFile << player2.getMal(i).carried << endl;
    }
    
    outFile.close();
    cout << "Game saved successfully." << endl;
    //Need to be finished
}

void load_game(string filename, Map &gameMap, Player &player1, Player &player2) {
    ifstream inFile;
    inFile.open(filename.c_str());

    if (inFile.fail()) {
        cout << "Error opening file for loading game state." << endl;
        return;
    }

    // Load players' names and counter
    string player1Name, player2Name;
    inFile >> player1Name >> player2Name;
    player1.setName(player1Name);
    player2.setName(player2Name);

    int malNum, row, column;
    bool can_finish, finished, carried;
    // Load player1 data
    for (int i = 1; i <= 3; i++) {
        inFile >> malNum >> row >> column >> boolalpha >> can_finish >> boolalpha >> finished >> boolalpha >> carried;
        player1.setMal(malNum, row, column, can_finish, finished, carried);
    }

    for (int i = 1; i<=3; i++){
        gameMap.addPlayerLocation(player1.getMal(i).row, player1.getMal(i).row, 0, i);
    }


    // Load player2 data
    for (int i = 1; i <= 3; i++) {
        inFile >> malNum >> row >> column >> boolalpha >> can_finish >> boolalpha >> finished >> boolalpha >> carried;
        player2.setMal(malNum, row, column, can_finish, finished, carried);
    }
     for (int i = 1; i<=3; i++){
        gameMap.addPlayerLocation(player2.getMal(i).row, player2.getMal(i).row, 0, i);
    }

    inFile.close();
    cout << "Game loaded successfully." << endl;
}

int askWhichTicket(vector<int> &tickets){
    if (tickets.size() == 1){
        cout << "You got " << getTicketName(tickets[0]) << " ticket." << endl;
        int ticket = tickets[0];
        tickets.clear();
        return ticket;
    }
    int input = 0;
    cout << endl;
    cout << "You got " << tickets.size() << " moves." << endl;
    for (int i = 0; i < tickets.size(); i++){
        cout << i + 1 << ". " << getTicketName(tickets[i]) << "     ";
    }
    cout << endl;
    cout << "Please choose the Ticket you want to use: ";
    cin >> input;
    while (input < 1 || input > tickets.size()){
        cout << "Invalid input. Please input a proper number for ticket use." << endl;
        cout << "Type here: ";
        cin >> input;
    }
    tickets.erase(tickets.begin() + input);
    return input;
}

vector<string> askMalMovement(int turn, Player one, Player two){
    vector<string> choices;
    bool alreadyAdded = false;

    if (turn == 0){
        for (int i = 1; i <= 3; i++) {
            Mal currentMal = one.getMal(i);
            
            if (currentMal.finished) {
                continue;
            } else if (currentMal.carried) {
                string prefix = "A" + to_string(i);
                for (int j = i + 1; j <= 3; j++) {
                    if (one.getMal(j).carried) {
                        prefix += to_string(j);
                    }
                }
                for (int j = 0; j < choices.size(); j ++){
                    for (int a= 0; a < choices[j].length(); a++){
                        if (choices[j].substr(a,1) == to_string(i)){
                            alreadyAdded = true;
                        }
                    }
                }
                if (!alreadyAdded){
                    choices.push_back(prefix);
                }
            } else {
                choices.push_back("A" + to_string(i));
            }
        }
    } else {
        for (int i = 1; i <= 3; i++) {
            Mal currentMal = two.getMal(i);
            
            if (currentMal.finished) {
                continue;
            } else if (currentMal.carried) {
                string prefix = "B" + to_string(i);
                for (int j = i + 1; j <= 3; j++) {
                    if (two.getMal(j).carried) {
                        prefix += to_string(j);
                    }
                }
                for (int j = 0; j < choices.size(); j ++){
                    for (int a= 0; a < choices[j].length(); a++){
                        if (choices[j].substr(a,1) == to_string(i)){
                            alreadyAdded = true;
                        }
                    }
                }
                if (!alreadyAdded){
                    choices.push_back(prefix);
                }
            } else {
                choices.push_back("B" + to_string(i));
            }
        }
    }
    

    if (choices.size() == 1){
        cout << "Which mal would you like to move?      " << "1. " << choices[0] << endl;
    } else if (choices.size() == 2 ){
        cout << "Which mal would you like to move?      " << "1. " << choices[0] << "      2. " << choices[1] << endl;
    } else{
        cout << "Which mal would you like to move?      " << "1. " << choices[0] << "      2. " << choices[1] << "      3. " << choices[2] << endl;
    }
    return choices;
}


int getTicket(){
    int randNum = rand() % 16 + 1;
    if (randNum == 1)
        return 5; //diamond
    else if (randNum == 2)
        return 4; //platinum
    else if (randNum <= 6)
        return 3; //gold
    else if (randNum <= 12)
        return 2; //silver
    else if (randNum <= 16)
        if ((rand() % 4 + 1) == 1)
            return -1; //secret
        return 1; //bronze
    return 0;
}

string getTicketName(int ticketNum){
    if (ticketNum == 5)
        return "Diamond";
    else if (ticketNum == 4)
        return "Platinum";
    else if (ticketNum == 3)
        return "Gold";
    else if (ticketNum == 2)
        return "Silver";
    else if (ticketNum == 1)
        return "Bronze";
    else
        return "Secret";
}

void move_or_carry_Mal(Player &player, int playerNum, int malSelect, string malSign, int TicketResult, Map &gameMap, int pRow, int pCol, int row, int col){
    if (malSign.length() == 2){
        player.moveMal(malSelect, TicketResult);
        gameMap.UpdatePlayerLocation(pRow, pCol, row, col, playerNum, malSelect);
    } else if (malSign.length() == 3){
        player.moveMal(stoi(malSign.substr(1,1)), TicketResult);
        gameMap.UpdatePlayerLocation(pRow, pCol, row, col, playerNum, stoi(malSign.substr(1,1)));

        player.moveMal(stoi(malSign.substr(2,1)), TicketResult);
        gameMap.UpdatePlayerLocation(pRow, pCol, row, col, playerNum, stoi(malSign.substr(2,1)));
    } else {
        player.moveMal(stoi(malSign.substr(1,1)), TicketResult);
        gameMap.UpdatePlayerLocation(pRow, pCol, row, col, playerNum, stoi(malSign.substr(1,1)));

        player.moveMal(stoi(malSign.substr(2,1)), TicketResult);
        gameMap.UpdatePlayerLocation(pRow, pCol, row, col, playerNum, stoi(malSign.substr(2,1)));

        player.moveMal(stoi(malSign.substr(3,1)), TicketResult);
        gameMap.UpdatePlayerLocation(pRow, pCol, row, col, playerNum, stoi(malSign.substr(3,1)));
    }
}

void killMal(Map &gameMap, Player &opponent, int killerPlayerNum, int row, int col){
    bool killFirst = false;
    bool killSecond = false;
    bool killThird = false;

    if (killerPlayerNum == 0){
        if (gameMap.getPlayerLocation(row, col).Playertwo_first){
            killFirst = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playertwo_second){
            killSecond = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playertwo_third){
            killThird = true;
        }
    } else if (killerPlayerNum == 1){
        if (gameMap.getPlayerLocation(row, col).Playerone_first){
            killFirst = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playerone_second){
            killSecond = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playerone_third){
            killThird = true;
        }
    }

    if (!killFirst && !killSecond && !killThird){
        return;
    }

    cout << "You killed the opponent's mal number:";

    if (killFirst){
        gameMap.UpdatePlayerLocation(row, col, 6, 0, (killerPlayerNum + 1)%2, 1);
        opponent.setRowCol(1,6,0);
        opponent.set_cannot_finish(1);
        cout << " 1";
    }
    if (killSecond){
        gameMap.UpdatePlayerLocation(row, col, 6, 0, (killerPlayerNum + 1)%2, 2);
        opponent.setRowCol(2,6,0);
        opponent.set_cannot_finish(2);
        cout << " 2";
    }
    if (killThird){
        gameMap.UpdatePlayerLocation(row, col, 6, 0, (killerPlayerNum + 1)%2, 3);
        opponent.setRowCol(3,6,0);
        opponent.set_cannot_finish(3);
        cout << " 3";
    }

    cout << "." << endl;
}

void moveMalDisplay(Map &gameMap, string malSign, int previRow, int previCol, int row, int col){
    if (malSign == "A1"){
        string arrA1[3][3] = {
            {"A", "1", "A"},
            {"1", " ", "1"},
            {"A", "1", "A"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA1);
    }
    
    if (malSign == "A2"){
        string arrA2[3][3] = {
            {"A", "2", "A"},
            {"2", " ", "2"},
            {"A", "2", "A"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA2);
    };
   if (malSign == "A3"){
        string arrA3[3][3] = {
            {"A", "3", "A"},
            {"3", " ", "3"},
            {"A", "3", "A"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA3);
    };
   if (malSign == "A12"){
        string arrA12[3][3] = {
            {"A", "1", "2"},
            {"1", " ", "A"},
            {"A", "2", "1"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA12);
    };
   if (malSign == "A23"){
        string arrA23[3][3] = {
            {"A", "2", "3"},
            {"2", " ", "A"},
            {"A", "3", "2"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA23);
    };

   if (malSign == "A13"){
        string arrA13[3][3] = {
            {"A", "1", "3"},
            {"1", " ", "A"},
            {"A", "3", "1"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA13);
    };
   if (malSign == "A123"){
        string arrA123[3][3] = {
            {"A", "1", "2"},
            {"3", " ", "3"},
            {"2", "1", "A"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA123);
    };


   if (malSign == "B1"){
        string arrB1[3][3] = {
            {"B", "1", "B"},
            {"1", " ", "1"},
            {"B", "1", "B"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB1);
    };

   if (malSign == "B2"){
        string arrB2[3][3] = {
            {"B", "2", "B"},
            {"2", " ", "2"},
            {"B", "2", "B"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB2);
    };
   if (malSign == "B3"){
        string arrB3[3][3] = {
            {"B", "3", "B"},
            {"3", " ", "3"},
            {"B", "3", "B"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB3);
    };

   if (malSign == "B12"){
        string arrB12[3][3] = {
            {"B", "1", "2"},
            {"1", " ", "B"},
            {"B", "2", "1"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB12);
    };

   if (malSign == "B23"){
        string arrB23[3][3] = {
            {"B", "2", "3"},
            {"2", " ", "B"},
            {"B", "3", "2"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB23);
    };

   if (malSign == "B13"){
        string arrB13[3][3] = {
            {"B", "1", "3"},
            {"1", " ", "B"},
            {"B", "3", "1"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB13);
    };

   if (malSign == "B123"){
        string arrB123[3][3] = {
            {"B", "1", "2"},
            {"3", " ", "3"},
            {"2", "1", "B"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB123);
    };


}

void displayTicket(int moves){
    if (moves == 4)
    {
        cout << CYAN << "   _________ _________ _________ _________ _________ _________ _________ _________" << RESET << "\n";
        cout << CYAN << "  /         |         |         |         |         |         |         |         |" << RESET << "\n";
        cout << CYAN << " /    P    /    L    /    A    /    T    /    I    /    N    /    U    /    M    /" << RESET << "\n";
        cout << CYAN << "/_________/_________/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        cout << CYAN << "┌─────────┐\n";
        cout << CYAN << "│ x     x │\n";
        cout << CYAN << "│         │\n";
        cout << CYAN << "│         │\n";
        cout << CYAN << "│         │\n";
        cout << CYAN << "│ x     x │\n";
        cout << CYAN << "└─────────┘\n\n";
    }
    
    else if (moves == 3)
    {
        cout << YELLOW << "   _________ _________ _________ _________ " << RESET << "\n";
        cout << YELLOW << "  /         |         |         |         |" << RESET << "\n";
        cout << YELLOW << " /    G    /    O    /    L    /    D    /" << RESET << "\n";
        cout << YELLOW << "/_________/_________/_________/_________/" << RESET << "\n";
        cout << YELLOW << "┌─────────┐\n";
        cout << YELLOW << "│ x       │\n";
        cout << YELLOW << "│         │\n";
        cout << YELLOW << "│    x    │\n";
        cout << YELLOW << "│         │\n";
        cout << YELLOW << "│       x │\n";
        cout << YELLOW << "└─────────┘\n\n";
    }
    else if (moves == 2)
    {
        cout << GRAY << "   _________ _________ _________ _________ _________ _________ " << RESET << "\n";
        cout << GRAY << "  /         |         |         |         |         |         |" << RESET << "\n";
        cout << GRAY << " /    S    /    I    /    L    /    V    /    E    /    R    /" << RESET << "\n";
        cout << GRAY << "/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        cout << GRAY << "┌─────────┐\n";
        cout << GRAY << "│ x       │\n";
        cout << GRAY << "│         │\n";
        cout << GRAY << "│         │\n";
        cout << GRAY << "│         │\n";
        cout << GRAY << "│       x │\n";
        cout << GRAY << "└─────────┘\n\n";
    }
    else if (moves == 1)
    {
        cout << BROWN << "   _________ _________ _________ _________ _________ _________" << RESET << "\n";
        cout << BROWN << "  /         |         |         |         |         |         |" << RESET << "\n";
        cout << BROWN << " /    B    /    R    /    O    /    N    /    Z    /    E    /" << RESET << "\n";
        cout << BROWN << "/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        cout << BROWN << "┌─────────┐\n";
        cout << BROWN << "│         │\n";
        cout << BROWN << "│         │\n";
        cout << BROWN << "│    x    │\n";
        cout << BROWN << "│         │\n";
        cout << BROWN << "│         │\n";
        cout << BROWN << "└─────────┘\n\n";
    }
    else if (moves == 5)
    {
        cout << BLUE << "   _________ _________ _________ _________ _________ _________ _________" << RESET << "\n";
        cout << BLUE << "  /         |         |         |         |         |        |          |" << RESET << "\n";
        cout << BLUE << " /    D    /    I    /    A    /    M    /    O    /    N   /     D    /" << RESET << "\n";
        cout << BLUE << "/_________/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        cout << BLUE << "┌─────────┐\n";
        cout << BLUE << "│ x     x │\n";
        cout << BLUE << "│         │\n";
        cout << BLUE << "│    x    │\n";
        cout << BLUE << "│         │\n";
        cout << BLUE << "│ x     x │\n";
        cout << BLUE << "└─────────┘\n\n";
    }
    else if (moves == -1)
    {
        cout << MAGENTA << "   _________ _________ _________ _________ _________ _________" << RESET << "\n";
        cout << MAGENTA << "  /         |         |         |         |         |         |" << RESET << "\n";
        cout << MAGENTA << " /    S    /    E    /    C    /    R    /    E    /    T    /" << RESET << "\n";
        cout << MAGENTA << "/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        cout << MAGENTA <<  "┌─────────┐\n";
        cout << MAGENTA <<  "│ ?     ? │\n";
        cout << MAGENTA <<  "│         │\n";
        cout << MAGENTA <<  "│    ?    │\n";
        cout << MAGENTA <<  "│         │\n";
        cout << MAGENTA <<  "│ ?     ? │\n";
        cout << MAGENTA <<  "└─────────┘\n\n";
    }

}

void PrintExplain(int row, int col){
    if (row == 0 && col == 0)
    {
        cout << "You have arrived at Kowloon. There is a Kowloon Park, which is large park with gardens, lakes, and a swimming pool." << endl;
    }
    else if (row == 0 && col == 1)
    {
        cout << "You have arrived at Symphony of Lights. It is a light and sound show that illuminates the skyline every night." << endl;
    }
    else if (row == 0 && col == 2)
    {
        cout << "You have arrived at Mong Kok. It is a bustling neighborhood with markets, street food, and nightlife." << endl;
    }
    else if (row == 0 && col == 4)
    {
        cout << "You have arrived at Ladies' Market. It is a street market in Mong Kok that sells clothes, accessories, and souvenirs." << endl;
    }
    else if (row == 0 && col == 5)
    {
        cout << "You have arrived at Soho. It is a neighborhood in Central with trendy bars and restaurants." << endl;
    }
    else if (row == 0 && col == 6)
    {
        cout << "You have arrived at North Point. It is a densely populated area that is known for its vibrant local atmosphere, with a mix of residential, commercial, and industrial spaces." << endl;
    }
    else if (row == 1 && col == 0)
    {
        cout << "You have arrived at Hong Kong Science Museum. It is a museum with interactive exhibits on science and technology." << endl;
    }
    else if (row == 1 && col == 1)
    {
        cout << "You have arrived at Wong Tai Sin Temple. It is a Taoist temple in Kowloon that is known for granting wishes." << endl;
    }
    else if (row == 1 && col == 5)
    {
        cout << "You have arrived at Temple Street Night Market. It is a bustling night market in Yau Ma Tei that sells a variety of goods." << endl;
    }
    else if (row == 1 && col == 6)
    {
        cout << "You have arrived at Golden Computer Arcade. It is a shopping center in Sham Shui Po that sells electronics and computer components." << endl;
    }
    else if (row == 2 && col == 0)
    {
        cout << "You have arrived at Hong Kong Museum of History. It is a museum that traces the history of Hong Kong." << endl;
    }
    else if (row == 2 && col == 2)
    {
        cout << "You have arrived at Elements Mall. It is a shopping mall in Kowloon with luxury brands and fine dining restaurants." << endl;
    }
    else if (row == 2 && col == 4)
    {
        cout << "You have arrived at Tsim Sha Tsui Promenade. It is a waterfront promenade with stunning views of the harbor." << endl;
    }
    else if (row == 2 && col == 6)
    {
        cout << "You have arrived at Langham Place. It is a shopping mall in Mong Kok with a variety of stores and a cinema." << endl;
    }
    else if (row == 3 && col == 3)
    {
        cout << "You have arrived at Tsim Sa Tsui. It is a popular tourist and shopping district located in the southern part of Kowloon Peninsula in Hong Kong." << endl;
    }
    else if (row == 4 && col == 0)
    {
        cout << "You have arrived at Hong Kong Museum of Art. It is a museum showcasing Chinese art and culture." << endl;
    }
    else if (row == 4 && col == 2)
    {
        cout << "You have arrived at The Clock Tower. It is a historic landmark in Tsim Sha Tsui." << endl;
    }
    else if (row == 4 && col == 4)
    {
        cout << "You have arrived at Lan Kwai Fong. It is a nightlife district in Central known for its bars and clubs." << endl;
    }
    else if (row == 4 && col == 6)
    {
        cout << "You have arrived at Avenue of Stars. It is a promenade dedicated to Hong Kong's film industry." << endl;
    }
    else if (row == 5 && col == 0)
    {
        cout << "You have arrived at Repulse Bay. It is a beach with stunning views and plenty of water sports activities." << endl;
    }
    else if (row == 5 && col == 1)
    {
        cout << "You have arrived at Victoria Peak. It is a popular tourist destination with a spectacular view of Hong Kong's skyline." << endl;
    }
    else if (row == 5 && col == 5)
    {
        cout << "You have arrived at Tai Kwun. It is a heritage site that houses art galleries, restaurants, and shops." << endl;
    }
    else if (row == 5 && col == 6)
    {
        cout << "You have arrived at Tai O. It is a fishing village on Lantau Island with traditional stilt houses and a peaceful atmosphere" << endl;
    }
    else if (row == 6 && col == 0)
    {
        cout << "You have arrived at HKU. Located on Hong Kong Island, HKU has a beautiful campus that features a blend of modern and historic buildings, as well as green spaces and cultural landmarks." << endl;
    }
    else if (row == 6 && col == 1)
    {
        cout << "You have arrived at Hong Kong Disneyland. It is a theme park with attractions for all ages." << endl;
    }
    else if (row == 6 && col == 2)
    {
        cout << "You have arrived at Ocean Park. It is a marine-life theme park with thrilling rides and animal exhibits." << endl;
    }
    else if (row == 6 && col == 4)
    {
        cout << "You have arrived at Man Mo Temple. It is a historic temple in Sheung Wan dedicated to the gods of literature and martial arts." << endl;
    }
    else if (row == 6 && col == 5)
    {
        cout << "You have arrived at Western Market. It is a restored Edwardian-style building with shops selling souvenirs and handicrafts." << endl;
    }
    else if (row == 6 && col == 6)
    {
        cout << "You have arrived at Admiralty. It is a major commercial and financial hub in Hong Kong, and is home to many important government buildings, including the Central Government Complex and the Legislative Council Complex." << endl;
    }
}
