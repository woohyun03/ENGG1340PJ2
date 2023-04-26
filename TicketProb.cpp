#include <iostream>
using namepace std;

string getTicket(){
    int randNum = rand() % 16 + 1;
    if (randNum == 1)
        return "Diamond";
    else if (randNum <= 2)
        return "Platinum";
    else if (randNum <= 6)
        return "Gold";
    else if (randNum <= 8)
        return "Silver";
    else if (randNum <= 12)
        return "Bronze";
    else if (randNum <= 16)
        return "Secret";
}
