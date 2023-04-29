#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

Player::Player() {
    name = "";
    first = {6, 0, 6, 0, false, false};
    second = {6, 0, 6, 0, false, false};
    third = {6, 0, 6, 0, false, false};
}

Player::Player(string name, int first1, int first2, int second1, int second2, int third1, int third2) {
    this->name = name;
    first = {first1, first2, 6, 0, false, false};
    second = {second1, second2, 6, 0, false, false};
    third = {third1, third2, 6, 0, false, false};
}

string Player::getName() {
    return name;
}

void Player::setName(string name) {
    this->name = name;
}

int Player::getRow(int malNum){
    if (malNum == 1){
        return first.row;
    } else if (malNum == 2){
        return second.row;
    } else {
        return third.row;
    }
}

int Player::getCol(int malNum){
    if (malNum == 1){
        return first.column;
    } else if (malNum == 2){
        return second.column;
    } else {
        return third.column;
    }
}

void Player::setRowCol(int malNum, int row, int col){
    if (malNum == 1){
        first.row = row;
        first.column = col;
    } else if (malNum == 2){
        second.row = row;
        second.column = col;
    } else {
        second.row = row;
        second.column = col;
    }
}

int Player::getPreviousRow(int malNum){
    if (malNum == 1){
        return first.previousRow;
    } else if (malNum == 2){
        return second.previousRow;
    } else {
        return third.previousRow;
    }
}

int Player::getPreviousCol(int malNum){
    if (malNum == 1){
        return first.previousRow;
    } else if (malNum == 2){
        return second.previousRow;
    } else {
        return third.previousRow;
    }
}

void Player::moveMal(int malNum, int moveNum) {
    if (malNum == 1){
        first.previousRow = first.row;
        first.previousColumn = first.column;
        newRowCol(first, moveNum);
    } else if (malNum == 2){
        second.previousRow = second.row;
        second.previousColumn = second.column;
        newRowCol(second, moveNum);
    } else if (malNum == 3){
        third.previousRow = second.row;
        third.previousColumn = second.column;
        newRowCol(second, moveNum);
    }
}

void Player::newRowCol (Mal &playerMal, int &moveNum){
    if (moveNum == -1){
        Back(playerMal);
    }
    while (moveNum > 0){
        if (playerMal.can_finish){
            finish(playerMal, moveNum);
        }
        if (playerMal.row == playerMal.column && playerMal.row == 3){
            center(playerMal, moveNum);
        }
        if ((playerMal.row == playerMal.column && playerMal.row != 0) || (playerMal.row + playerMal.column == 6 && playerMal.row != 6)){
            corner_and_diagonal(playerMal, moveNum);
        }
        if (playerMal.row == 6 || playerMal.row == 0 || playerMal.column == 0 || playerMal.column == 6){
            moveStraight(playerMal, moveNum);
        }
    }
    int newRowCol[2] = {playerMal.row, playerMal.column};
}

void Player::only_six_positions_in_edges(Mal playerMal){
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

void Player::moveStraight(Mal &playerMal, int &moveNum){
    if (playerMal.row == 6){
        while (playerMal.column != 6 && moveNum != 0){
            only_six_positions_in_edges(playerMal);
            playerMal.column += 1;
            moveNum -= 1;
        }
    } else if (playerMal.column == 6){
        while (playerMal.row != 0 && moveNum != 0){
            only_six_positions_in_edges(playerMal);
            playerMal.row -= 1;
            moveNum -= 1;
        }
    } else if (playerMal.row == 0){
        while (playerMal.column != 0 && moveNum != 0){
            only_six_positions_in_edges(playerMal);
            playerMal.column -= 1;
            moveNum -= 1;
        }
    } else if (playerMal.column == 0){
        while (playerMal.row !=6 && moveNum != 0){
            only_six_positions_in_edges(playerMal);
            playerMal.row += 1;
            moveNum -= 1;
        }
    }
}

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

void Player::center(Mal &playerMal, int &moveNum){
    if (playerMal.row == playerMal.column && playerMal.row == 3){
        while(playerMal.row != 6 && moveNum != 0){
            playerMal.row += 1;
            playerMal.column -= 1;
            moveNum -= 1;
        }
    }
}

void Player::Back(Mal &playerMal){
    if (playerMal.row == 6 && 0 < playerMal.column){
        playerMal.column -=1;
    } else if (playerMal.column == 6 && 6 > playerMal.row){
        playerMal.row +=1;
    } else if (playerMal.row == 0 && playerMal.column < 6){
        playerMal.column += 1;
    } else if (playerMal.column == 0 && playerMal.row){

    }
}

void Player::can_finish(Mal &playerMal){
    if (playerMal.row != 6 || playerMal.column != 0 ){
        playerMal.can_finish = true;
    }
}

void Player::finish(Mal &playerMal, int &moveNum){
    if (playerMal.row == 6 && playerMal.column == 0 && moveNum >=1 && playerMal.can_finish){
        playerMal.finished = true;
    }
}