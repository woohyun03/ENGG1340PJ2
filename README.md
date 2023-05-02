Korean Traditional Yut Game (MTR Edition) - README

Welcome to the Korean Traditional Yut Game (MTR Edition)! This game is a text-based implementation of the classic Korean board game, Yutnori, with some added MTR elements.


Team Members:
•	Kim Yumin (3036050611)
•	Kim Suhan (3036106197)
•	Shim Eunseop (3036106197)
•	
How to Play

1.	Compile the program and run the executable.
2.	Enter the names of the two players.
3.	Players take turns rolling the Yut (a special ticket) to determine how many steps they can move their pieces, called Mal, on the game board.
4.	If a player rolls a special ticket (e.g., Platinum or Diamond), they get to roll the Yut again.
5.	When it's a player's turn, they choose which Mal to move based on the ticket they received.
6.	The Mal will move according to the ticket, and its new position will be displayed.
7.	If a Mal lands on a spot occupied by the opponent's Mal, the opponent's Mal will be removed from the game board (killed).
8.	Players continue to take turns until one player meets the winning condition.
9.	The game ends and the winner is announced.



Game Components

main.cpp
The `main.cpp` file contains the main game loop and logic.

Functions.h
The `Functions.h` file contains various functions to handle game mechanics such as ticket rolling, Mal movement, and Mal killing.

Map.h
The `Map.h` file defines the game board and the methods to manipulate and display it.

Player.h
The `Player.h` file defines the player class, which includes player names and Mals.

Station.h
The `Station.h` file defines the station class, which represents locations on the game board.

Mal.h
The `Mal.h` file defines the Mal class, which represents the game pieces.

Dependencies

- C++ Standard Library
- `<iostream>`
- `<string>`
- `<vector>`
- `<chrono>`
- `<thread>`
- `<fstream>`



Components

Main.cpp	

Name	Type	Description
gameMap	Map	Represents the game map
player1	Player	Represents the first player
player2	Player	Represents the second player
counter	int	Counts the number of turns
turn	int	Indicates whose turn it is (0 for player1, 1 for player2)
TicketResult	int	Stores the result of the ticket roll
input	string	Stores user input
malSelect	int	Stores the selected Mal index
tickets	vector<int>	Stores the remaining tickets
malVector	vector<string>	Stores the list of Mal names to be displayed



Functions.cpp
Name	Type	Description	Parameter
save_game	void	Saves the game state to a file	string &filename, Map &gameMap, Player &player1, Player &player2, int counter
load_game	bool	Loads the game state from a file	string &filename, Map &gameMap, Player &player1, Player &player2, int &counter
askWhichTicket	int	Asks the user which ticket they want to use	vector<int> &tickets
askMalMovement	vector<string>	Asks the user which mal they want to move	int turn, Player one, Player two
getTicket	int	Generates and returns a random ticket	
getTicketName	string	Returns the name of a ticket based on the ticket number	int ticketNum
move_or_carry_Mal	void	Moves or carries a mal based on the malSign string	Player &player, int playerNum, int malSelect, string malSign, int TicketResult, Map &gameMap, int pRow, int pCol, int row, int col
killMal	void	Kills an opponent's mal based on its location	Map &gameMap, Player &opponent, int killerPlayerNum, int row, int col
moveMalDisplay	void	Updates the game map after moving a mal	Map &gameMap, string malSign, int previRow, int previCol, int row, int col



### Functions.cpp
>부가설명

|Name|Type|Type|Parameter|
|:-:|:-:|:-:|:-:|
|save_game|void|Saves the game state to a file|string &filename, Map &gameMap, Player &player1, Player &player2, int counter|
|load_game|bool|Loads the game state from a file| string &filename, Map &gameMap, Player &player1, Player &player2, int &counter|
|askWhichTicket|int|Asks the user which ticket they want to use| vector<int> &tickets|
|askMalMovement|vector<string>|Asks the user which mal they want to move| int turn, Player one, Player two|
|getTicket|int|Generates and returns a random ticket| N/A|
|getTicketName|string|Returns the name of a ticket based on the ticket number|int ticketNum|
|move_or_carry_Mal|void|Moves or carries a mal based on the malSign string| Player &player, int playerNum, int malSelect, string malSign, int TicketResult, Map &gameMap, int pRow, int pCol, int row, int col|
|killMal|void|Kills an opponent's mal based on its location| Map &gameMap, Player &opponent, int killerPlayerNum, int row, int col|
|moveMalDisplay|void|Updates the game map after moving a mal| Map &gameMap, string malSign, int previRow, int previCol, int row, int col|
|player1|Player|Represents| avs|













How to Compile and Run

1. Make sure you have a C++ compiler installed on your system (e.g., g++).
2. Compile the program using the following command in the terminal:

g++ main.cpp Functions.h Map.h Player.h Station.h Mal.h -o yut_game

![image](https://user-images.githubusercontent.com/125568011/235663903-278b3640-6304-44bd-b836-51fe8d3bed71.png)
