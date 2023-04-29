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
    void only_six_positions_in_edges(Mal playerMal);
    void moveStraight(Mal &playerMal, int &moveNum);
    void corner_and_diagonal(Mal &playerMal, int &moveNum);
    void center(Mal &playerMal, int &moveNum);
    void Back(Mal &playerMal);

  public:
    Player();
    Player(string name, int first1, int first2, int second1, int second2, int third1, int third2);
    string getName();
    void setName(string name);
    int getRow(int malNum);
    int getCol(int malNum);
    int getPreviousRow(int malNum);
    int getPreviousCol(int malNum);
    int getFirstRow();
    int getFirstCol();
    int getSecondRow();
    int getSecondCol();
    int getThirdRow();
    int getThirdCol();
    void moveMal(int malNum, int moveNum, Map &playerMap);
    void newRowCol (Mal &playerMal, int &moveNum);
    void can_finish(Mal &playerMal);
    void finish(Mal &playerMal, int &moveNum);
};

#endif