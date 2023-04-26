#include <iostream>
using namepace std;

string getTicket(){
    int randNum = rand() % 16 + 1;
    if (randNum == 1)
        return 5; //diamond
    else if (randNum <= 2)
        return 4; //platinum
    else if (randNum <= 6)
        return 3; //gold
    else if (randNum <= 8)
        return 2; //silver
    else if (randNum <= 12)
        return 1; //bronze
    else if (randNum <= 16)
        return -1; //secret
}
