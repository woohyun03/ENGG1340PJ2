#include <iostream>
// ANSI escape codes for colors
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define GRAY "\033[37m"
#define BROWN "\033[38;2;205;127;50m"
using namespace std;

void displayTicket(int moves)
{
    if (moves == 4)
    {
        cout << CYAN << "   _________ _________ _________ _________ _________ _________ _________ _________" << RESET << "\n";
        cout << CYAN << "  /         |         |         |         |         |         |         |         |" << RESET << "\n";
        cout << CYAN << " /    P    /    L    /    A    /    T    /    I    /    N    /    U    /    M    /" << RESET << "\n";
        cout << CYAN << "/_________/_________/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        cout << CYAN << "┌─────────┐\n";
        cout << CYAN << "│ x     x │\n";
        cout << CYAN << "│         │\n";
        cout << CYAN << "│         │\n";
        cout << CYAN << "│         │\n";
        cout << CYAN << "│ x     x │\n";
        cout << CYAN << "└─────────┘\n\n";
    }
    
    else if (moves == 3)
    {
        cout << YELLOW << "   _________ _________ _________ _________ " << RESET << "\n";
        cout << YELLOW << "  /         |         |         |         |" << RESET << "\n";
        cout << YELLOW << " /    G    /    O    /    L    /    D    /" << RESET << "\n";
        cout << YELLOW << "/_________/_________/_________/_________/" << RESET << "\n";
        cout << YELLOW << "┌─────────┐\n";
        cout << YELLOW << "│ x       │\n";
        cout << YELLOW << "│         │\n";
        cout << YELLOW << "│    x    │\n";
        cout << YELLOW << "│         │\n";
        cout << YELLOW << "│       x │\n";
        cout << YELLOW << "└─────────┘\n\n";
    }
    else if (moves == 2)
    {
        cout << GRAY << "   _________ _________ _________ _________ _________ _________ " << RESET << "\n";
        cout << GRAY << "  /         |         |         |         |         |         |" << RESET << "\n";
        cout << GRAY << " /    S    /    I    /    L    /    V    /    E    /    R    /" << RESET << "\n";
        cout << GRAY << "/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        cout << GRAY << "┌─────────┐\n";
        cout << GRAY << "│ x       │\n";
        cout << GRAY << "│         │\n";
        cout << GRAY << "│         │\n";
        cout << GRAY << "│         │\n";
        cout << GRAY << "│       x │\n";
        cout << GRAY << "└─────────┘\n\n";
    }
    else if (moves == 1)
    {
        cout << BROWN << "   _________ _________ _________ _________ _________ _________" << RESET << "\n";
        cout << BROWN << "  /         |         |         |         |         |         |" << RESET << "\n";
        cout << BROWN << " /    B    /    R    /    O    /    N    /    Z    /    E    /" << RESET << "\n";
        cout << BROWN << "/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        cout << BROWN << "┌─────────┐\n";
        cout << BROWN << "│         │\n";
        cout << BROWN << "│         │\n";
        cout << BROWN << "│    x    │\n";
        cout << BROWN << "│         │\n";
        cout << BROWN << "│         │\n";
        cout << BROWN << "└─────────┘\n\n";
    }
    else if (moves == 5)
    {
        cout << BLUE << "   _________ _________ _________ _________ _________ _________ _________" << RESET << "\n";
        cout << BLUE << "  /         |         |         |         |         |        |          |" << RESET << "\n";
        cout << BLUE << " /    D    /    I    /    A    /    M    /    O    /    N   /     D    /" << RESET << "\n";
        cout << BLUE << "/_________/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        cout << BLUE << "┌─────────┐\n";
        cout << BLUE << "│ x     x │\n";
        cout << BLUE << "│         │\n";
        cout << BLUE << "│    x    │\n";
        cout << BLUE << "│         │\n";
        cout << BLUE << "│ x     x │\n";
        cout << BLUE << "└─────────┘\n\n";
    }
    else if (moves == -1)
    {
        cout << MAGENTA << "   _________ _________ _________ _________ _________ _________" << RESET << "\n";
        cout << MAGENTA << "  /         |         |         |         |         |         |" << RESET << "\n";
        cout << MAGENTA << " /    S    /    E    /    C    /    R    /    E    /    T    /" << RESET << "\n";
        cout << MAGENTA << "/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        cout << MAGENTA <<  "┌─────────┐\n";
        cout << MAGENTA <<  "│ ?     ? │\n";
        cout << MAGENTA <<  "│         │\n";
        cout << MAGENTA <<  "│    ?    │\n";
        cout << MAGENTA <<  "│         │\n";
        cout << MAGENTA <<  "│ ?     ? │\n";
        cout << MAGENTA <<  "└─────────┘\n\n";
    }

}
