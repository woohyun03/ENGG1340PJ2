#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;


//Initializing the vector named Mals.
Player::Player() {
    name = "";
    Mal first = {6, 0, 6, 0, false, false, false};
    Mal second = {6, 0, 6, 0, false, false, false};
    Mal third = {6, 0, 6, 0, false, false, false};
    Mals.push_back(first);
    Mals.push_back(second);
    Mals.push_back(third);
}

//Constructor for vector mal.
Player::Player(string name, int first1, int first2, int second1, int second2, int third1, int third2) {
    this->name = name;
    Mal first = {first1, first2, 6, 0, false, false, false};
    Mal second = {second1, second2, 6, 0, false, false, false};
    Mal third = {third1, third2, 6, 0, false, false, false};
    Mals.push_back(first);
    Mals.push_back(second);
    Mals.push_back(third);
}

//Function for getting a name.
string Player::getName() {
    return name;
}

//Function for setting a name.
void Player::setName(string name) {
    this->name = name;
}


//Function for getting a row
int Player::getRow(int malNum){
    return Mals[malNum-1].row;
}

//Function for getting a column
int Player::getCol(int malNum){
    return Mals[malNum-1].column;
}

//Function for setting a row and column
void Player::setRowCol(int malNum, int row, int col){
    Mals[malNum-1].row = row;
    Mals[malNum-1].column = col;
}

//Function for getting preivous row
int Player::getPreviousRow(int malNum){
    return Mals[malNum-1].previousRow;
}

//Function for getting preivous col
int Player::getPreviousCol(int malNum){
    return Mals[malNum-1].previousColumn;
}

//Function for setting a Previous column
void Player::setPreviousRowCol(int malNum, int row, int col){
    Mals[malNum-1].previousRow = row;
    Mals[malNum-1].previousColumn = col;
}

//Function for getting a mal
Mal Player::getMal(int malNum){
    return Mals[malNum-1];
}

//Function for setting a Mal with input of malNum, row, col.
void Player::setMal(int malNum, int row, int col, bool can_finish, bool finished, bool carried){
    Mals[malNum-1].row = row;
    Mals[malNum-1].column = col;
    Mals[malNum-1].can_finish = can_finish;
    Mals[malNum-1].finished = finished;
    Mals[malNum-1].carried = carried;
}

//Changing the bool type can_finish member in Mal class
void Player::set_cannot_finish(int malNum){
    Mals[malNum-1].can_finish = false;
}

// Checking whether the player win or not
bool Player::win(){
    if (Mals[0].finished && Mals[1].finished && Mals[2].finished){
        return true;
    } else {
        return false;
    }
}

// Checking whether mals are carried or not.
void Player::check_Carried(){
    Mals[0].carried = false;
    Mals[1].carried = false;
    Mals[2].carried = false;
    for (int i = 0; i <= 3; i++ ){
        for (int j = i+1;  j<= 3; j++){
            if ((Mals[i].row !=6 || Mals[i].can_finish) && (Mals[i].column !=0 || Mals[i].can_finish) &&  (Mals[j].row !=6 || Mals[j].can_finish) && (Mals[j].column !=0 || Mals[j].can_finish) &&Mals[i].row == Mals[j].row && Mals[i].column == Mals[j].column){
                Mals[i].carried = true;
                Mals[j].carried = true;
            }
        }
    }
}

void Player::set_not_Carried(int malNum){
    Mals[malNum - 1].carried = false;
}

bool Player::no_Mal_on_Map(){
    if ( Mals[0].row == Mals[1].row && Mals[1].row == Mals[2].row && Mals[2].row == 6 && Mals[0].column == Mals[1].column && Mals[1].column == Mals[2].column && Mals[2].column == 0 ){
        return true;
    } 
    return false;
}

// Function for moving mal.
void Player::moveMal(int malNum, int moveNum) {
    int currentRow = Mals[malNum-1].row;
    int currentCol = Mals[malNum-1].column;
    if (moveNum != -1){
        Mals[malNum-1].previousRow = Mals[malNum-1].row;
        Mals[malNum-1].previousColumn = Mals[malNum-1].column;
    }
    newRowCol(Mals[malNum-1], moveNum);
    if (moveNum == -1){
        Mals[malNum-1].previousRow = currentRow;
        Mals[malNum-1].previousColumn = currentCol;
    }
}

//Function for new col and row with number of moving
void Player::newRowCol (Mal &playerMal, int &moveNum){
    can_finish(playerMal);
    if (moveNum == -1){
        Back(playerMal);
    }
    while (moveNum > 0){
        if (playerMal.can_finish){
            finish(playerMal, moveNum);
            if (playerMal.finished){
                break;
            }
        }
        if (playerMal.row == playerMal.column && playerMal.row == 3){
            center(playerMal, moveNum);
        } else if ((playerMal.row == playerMal.column && playerMal.row != 0) || (playerMal.row + playerMal.column == 6 && playerMal.row != 6)){
            corner_and_diagonal(playerMal, moveNum);
        } else if (playerMal.row == 6 || playerMal.row == 0 || playerMal.column == 0 || playerMal.column == 6){
            moveStraight(playerMal, moveNum);
        }
    }
    can_finish(playerMal);
    int newRowCol[2] = {playerMal.row, playerMal.column};
}

//Functions when mal is in edges
void Player::only_six_positions_in_edges(Mal &playerMal){
    if (playerMal.row == 6 && playerMal.column == 3){
        playerMal.column += 1;
    } else if (playerMal.row == 3 && playerMal.column == 0){
        playerMal.row += 1;
    } else if (playerMal.row == 3 && playerMal.column == 6){
        playerMal.row -= 1;
    } else if (playerMal.row == 0 && playerMal.column == 3){
        playerMal.column -= 1;
    }
}

//Functions for moving straight
void Player::moveStraight(Mal &playerMal, int &moveNum){
    if (playerMal.row == 6){
        while (playerMal.column != 6 && moveNum != 0){
            playerMal.column += 1;
            moveNum -= 1;
            only_six_positions_in_edges(playerMal);
        }
    } if (playerMal.column == 6){
        while (playerMal.row != 0 && moveNum != 0){
            playerMal.row -= 1;
            moveNum -= 1;
            only_six_positions_in_edges(playerMal);
        }
    } if (playerMal.row == 0){
        while (playerMal.column != 0 && moveNum != 0){
            playerMal.column -= 1;
            moveNum -= 1;
            only_six_positions_in_edges(playerMal);
        }
    } if (playerMal.column == 0){
        while (playerMal.row !=6 && moveNum != 0){
            playerMal.row += 1;
            moveNum -= 1;
            only_six_positions_in_edges(playerMal);
        }
    }
}

//Funtions when mal is in corner or diagonal
void Player::corner_and_diagonal(Mal &playerMal, int &moveNum){
    if (playerMal.row == playerMal.column && playerMal.row != 0){
        while (playerMal.row != 0 && moveNum != 0){
            playerMal.row -= 1;
            playerMal.column -= 1;
            moveNum -= 1;
        }
    } else if (playerMal.row + playerMal.column == 6 && playerMal.row != 6){
        while(playerMal.row != 6 && moveNum != 0){
            playerMal.row += 1;
            playerMal.column -= 1;
            moveNum -= 1;
        }
    }
}

//Function when mal is in center
void Player::center(Mal &playerMal, int &moveNum){
    if (playerMal.row == playerMal.column && playerMal.row == 3){
        while(playerMal.row != 6 && moveNum != 0){
            playerMal.row += 1;
            playerMal.column -= 1;
            moveNum -= 1;
        }
    }
}

//Function when moving back
void Player::Back(Mal &playerMal){
    if (playerMal.row == 3 && playerMal.column == 3){
        if (playerMal.previousRow == 2 || playerMal.previousRow == 1 || playerMal.previousRow == 0){
            playerMal.row -= 1;
            playerMal.column += 1;
        } else if (playerMal.previousRow == 4 || playerMal.previousRow == 5 || playerMal.previousRow == 6){
            playerMal.row += 1;
            playerMal.column += 1;
        }
    } else if (playerMal.row == 0 && playerMal.column == 0){
        if (playerMal.previousRow == 0){
            playerMal.column += 1;
        } else if (playerMal.previousRow == 1){
            playerMal.row += 1;
            playerMal.column += 1;
        }
    } else if (playerMal.row == 6 && playerMal.column == 0 && playerMal.can_finish){
        if (playerMal.previousColumn == 0){
            playerMal.row -= 1;
        } else if (playerMal.row + playerMal.column == 6){
            playerMal.row -= 1;
            playerMal.column += 1;
        }
    } else if (playerMal.row == 6 && 0 < playerMal.column){
        playerMal.column -=1;
        if (playerMal.row == 6 && playerMal.column == 3){
            playerMal.column -= 1;
        }
    } else if (playerMal.column == 6 && 6 > playerMal.row){
        playerMal.row +=1;
        if (playerMal.row == 3 && playerMal.column == 6){
            playerMal.row += 1;
        }
    } else if (playerMal.row == 0 && playerMal.column < 6){
        playerMal.column += 1;
        if (playerMal.row == 0 && playerMal.column == 3){
            playerMal.column += 1;
        }
    } else if (playerMal.column == 0 && playerMal.row > 0){
        playerMal.row -= 1;
        if (playerMal.row == 3 && playerMal.column == 0){
            playerMal.row -= 1;
        }
    } else if (playerMal.row == playerMal.column){
        playerMal.row += 1;
        playerMal.column += 1;
        only_six_positions_in_edges(playerMal);
    } else if (playerMal.row + playerMal.column == 6){
        playerMal.row -= 1;
        playerMal.column += 1;
        only_six_positions_in_edges(playerMal);
    }
}

//Function for when playermal can finish.
void Player::can_finish(Mal &playerMal){
    if (playerMal.row != 6 || playerMal.column != 0 ){
        playerMal.can_finish = true;
    }
}

//Functions when playermal finished.
void Player::finish(Mal &playerMal, int &moveNum){
    if (playerMal.row == 6 && playerMal.column == 0 && moveNum >=1 && playerMal.can_finish){
        playerMal.finished = true;
    }
}
