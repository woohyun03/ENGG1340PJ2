#include <iostream>
using namespace std;

int main(){
    cout << "=== Korean Traditional Yut Game (MTR EDITION) ===" << endl;
    int counter = -1;
    int turnShower;

    while (true) {
        counter = counter + 1;
        cout << "Continue the Game? ('q' for exit): ";
        string input;
        getline(cin, input);

        if (input == "q" || input == "Q") {
            cout << "Exit the Game." << endl;
            break;
        }
        int malSelect;
        if(counter % 2 == 0){
            cout << "Which mal would you like to move? (1,2,3)" << endl;
            turnShower = 1;
        }
        else{
            cout << "Which mal would you like to move? (4,5,6)" << endl;
            turnShower = 2;
        }
        cin >> malSelect;
        cout << "Current Position of " << "mal number " << malSelect << " is" << PositionArray[malSelect] << endl;
        TicketResult = getTicket();
        cout << "Your ticket is..." << TicketResult << endl;

        //move mal and save other info (function to be added)
        //display map (functions to be added)

        cout << "You have arrived to..." << //place explantion functio << endl;

        for(int i = 0, i < 5; ++i){
            if(currentPosition == PositionArray[i]){
                if(//catched opponent's mal){
                    cout << "You have Killed the oppoent's mal number " << MalArray[i] << endl;
                    PositionArray[i] = 0;
                }
                else{
                    cout << "You are now carrying this mal" << endl;
                    //carry mal function to be added
                }
            }
        }
        if(//winning condition){
            break
        }
        cout << "Your turn has ended, it is player " << turnShower << "'s turn" << /n << endl;
    }
    cout << "Game Over! Player" << turnShower << "wins!!!" << endl;
    return 0;
}
