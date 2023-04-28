#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

Player::Player() {
    name = "";
    first = {6, 0, false, false};
    second = {6, 0, false, false};
    third = {6, 0, false, false};
}

Player::Player(string name, int first1, int first2, int second1, int second2, int third1, int third2) {
    this->name = name;
    first = {first1, first2, false, false};
    second = {second1, second2, false, false};
    third = {third1, third2, false, false};
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

int Player::getFirstRow() {
    return first.row;
}

int Player::getFirstCol() {
    return first.column;
}

int Player::getSecondRow() {
    return second.row;
}

int Player::getSecondCol() {
    return second.column;
}

int Player::getThirdRow() {
    return third.row;
}

int Player::getThirdCol() {
    return third.column;
}

void Player::moveMal(int malNum, int moveNum, Map &playerMap) {
    if (malNum == 1){
        int previRow = first.row;
        int previCol = first.column;
        int* newRC = newRowCol(first, moveNum);
    } else if (malNum == 2){
        int previRow = second.row;
        int previCol = second.column;
        int* newRC = newRowCol(second, moveNum);
    } else if (malNum == 3){
        int previRow = second.row;
        int previCol = second.column;
        int* newRC = newRowCol(second, moveNum);
    }
}

int* Player::newRowCol (Mal &playerMal, int &moveNum){
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
    return newRowCol;
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
    if (playerMal.row != 0 || playerMal.column != 0 ){
        playerMal.can_finish = true;
    }
}

void Player::finish(Mal &playerMal, int &moveNum){
    if (playerMal.row == 6 && playerMal.column == 0 && moveNum >=1 && playerMal.can_finish){
        playerMal.finished = true;
    }
}