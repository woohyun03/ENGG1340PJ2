#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

Player::Player() {
    name = "";
    Mal first = {6, 0, 6, 0, false, false, false};
    Mal second = {6, 0, 6, 0, false, false, false};
    Mal third = {6, 0, 6, 0, false, false, false};
    Mals.push_back(first);
    Mals.push_back(second);
    Mals.push_back(third);
}

Player::Player(string name, int first1, int first2, int second1, int second2, int third1, int third2) {
    this->name = name;
    Mal first = {first1, first2, 6, 0, false, false, false};
    Mal second = {second1, second2, 6, 0, false, false, false};
    Mal third = {third1, third2, 6, 0, false, false, false};
    Mals.push_back(first);
    Mals.push_back(second);
    Mals.push_back(third);
}

string Player::getName() {
    return name;
}

void Player::setName(string name) {
    this->name = name;
}

int Player::getRow(int malNum){
    return Mals[malNum-1].row;
}

int Player::getCol(int malNum){
    return Mals[malNum-1].column;
}

void Player::setRowCol(int malNum, int row, int col){
    Mals[malNum-1].row = row;
    Mals[malNum-1].column = col;
}

int Player::getPreviousRow(int malNum){
    return Mals[malNum-1].previousRow;
}

int Player::getPreviousCol(int malNum){
    return Mals[malNum-1].previousColumn;
}

void Player::setPreviousRowCol(int malNum, int row, int col){
    Mals[malNum-1].previousRow = row;
    Mals[malNum-1].previousColumn = col;
}

Mal Player::getMal(int malNum){
    return Mals[malNum-1];
}

void Player::setMal(int malNum, int row, int col, bool can_finish, bool finished, bool carried){
    Mals[malNum-1].row = row;
    Mals[malNum-1].column = col;
    Mals[malNum-1].can_finish = can_finish;
    Mals[malNum-1].finished = finished;
    Mals[malNum-1].carried = carried;
}

void Player::set_cannot_finish(int malNum){
    Mals[malNum-1].can_finish = false;
}

bool Player::win(){
    if (Mals[0].finished && Mals[1].finished && Mals[2].finished){
        return true;
    } else {
        return false;
    }
}

void Player::check_Carried(){
    Mals[0].carried = false;
    Mals[1].carried = false;
    Mals[2].carried = false;
    for (int i = 0; i < 3; i++ ){
        for (int j = i; j<3; j++){
            if ((Mals[i].row !=6 || Mals[i].can_finish) && (Mals[i].column !=0 || Mals[i].can_finish) && Mals[i].row == Mals[j].row && Mals[i].column == Mals[j].column){
                Mals[i].carried = true;
                Mals[j].carried = true;
            }
        }
    }
}

void Player::moveMal(int malNum, int moveNum) {
    Mals[malNum-1].previousRow = Mals[malNum-1].row;
    Mals[malNum-1].previousColumn = Mals[malNum-1].column;
    newRowCol(Mals[malNum-1], moveNum);
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

void Player::moveStraight(Mal &playerMal, int &moveNum){
    if (playerMal.row == 6){
        while (playerMal.column != 6 && moveNum != 0){
            only_six_positions_in_edges(playerMal);
            playerMal.column += 1;
            moveNum -= 1;
        }
    } if (playerMal.column == 6){
        while (playerMal.row != 0 && moveNum != 0){
            only_six_positions_in_edges(playerMal);
            playerMal.row -= 1;
            moveNum -= 1;
        }
    } if (playerMal.row == 0){
        while (playerMal.column != 0 && moveNum != 0){
            only_six_positions_in_edges(playerMal);
            playerMal.column -= 1;
            moveNum -= 1;
        }
    } if (playerMal.column == 0){
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
    if (playerMal.row == 3 && playerMal.column == 3){
        if (playerMal.previousRow == 2){
            playerMal.row -= 1;
            playerMal.column += 1;
        } else if (playerMal.previousRow == 4){
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
    } else if (playerMal.row == 6 && 0 < playerMal.column){
        playerMal.column -=1;
    } else if (playerMal.column == 6 && 6 > playerMal.row){
        playerMal.row +=1;
    } else if (playerMal.row == 0 && playerMal.column < 6){
        playerMal.column += 1;
    } else if (playerMal.column == 0 && playerMal.row > 0){
        playerMal.row -= 1;
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