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