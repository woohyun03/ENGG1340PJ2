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
    vector<Mal> Mals;
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
    void setRowCol(int malNum, int row, int col);
    int getPreviousRow(int malNum);
    int getPreviousCol(int malNum);
    void setPreviousRowCol(int malNum, int row, int col);
    Mal getMal(int malNum);
    void set_cannot_finish(int malNum);
    bool win();
    void check_Carried();
    void moveMal(int malNum, int moveNum);
    void newRowCol (Mal &playerMal, int &moveNum);
    void can_finish(Mal &playerMal);
    void finish(Mal &playerMal, int &moveNum);
};

#endif