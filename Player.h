#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Mal.h"
#include "Map.h"
using namespace std;

class Player {
  private:
    string name;
    Mal first;
    Mal second;
    Mal third;

  public:
    Player();
    Player(string name, int first1, int first2, int second1, int second2, int third1, int third2);
    string getName();
    void setName(string name);
    int getFirstRow();
    int getFirstCol();
    int getSecondRow();
    int getSecondCol();
    int getThirdRow();
    int getThirdCol();
    void moveMal(int malNum, int moveNum, Map &playerMap);
    int* newRowCol (Mal &playerMal, int &moveNum);
};

#endif