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

void displayTicket(const std::string& type)
{
    int moves = 0; // Initialize moves to 0
    if (type == "platinum")
    {
        std::cout << CYAN << "   _________ _________ _________ _________ _________ _________ _________ _________" << RESET << "\n";
        std::cout << CYAN << "  /         |         |         |         |         |         |         |         |" << RESET << "\n";
        std::cout << CYAN << " /    P    /    L    /    A    /    T    /    I    /    N    /    U    /    M    /" << RESET << "\n";
        std::cout << CYAN << "/_________/_________/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        std::cout << CYAN << "┌─────────┐\n";
        std::cout << CYAN << "│ x     x │\n";
        std::cout << CYAN << "│         │\n";
        std::cout << CYAN << "│         │\n";
        std::cout << CYAN << "│         │\n";
        std::cout << CYAN << "│ x     x │\n";
        std::cout << CYAN << "└─────────┘\n\n";
        moves=4;
    }
    
    else if (type == "gold")
    {
        std::cout << YELLOW << "   _________ _________ _________ _________ " << RESET << "\n";
        std::cout << YELLOW << "  /         |         |         |         |" << RESET << "\n";
        std::cout << YELLOW << " /    G    /    O    /    L    /    D    /" << RESET << "\n";
        std::cout << YELLOW << "/_________/_________/_________/_________/" << RESET << "\n";
        std::cout << YELLOW << "┌─────────┐\n";
        std::cout << YELLOW << "│ x       │\n";
        std::cout << YELLOW << "│         │\n";
        std::cout << YELLOW << "│    x    │\n";
        std::cout << YELLOW << "│         │\n";
        std::cout << YELLOW << "│       x │\n";
        std::cout << YELLOW << "└─────────┘\n\n";
        moves=3;
    }
    else if (type == "silver")
    {
        std::cout << GRAY << "   _________ _________ _________ _________ _________ _________ " << RESET << "\n";
        std::cout << GRAY << "  /         |         |         |         |         |         |" << RESET << "\n";
        std::cout << GRAY << " /    S    /    I    /    L    /    V    /    E    /    R    /" << RESET << "\n";
        std::cout << GRAY << "/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        std::cout << GRAY << "┌─────────┐\n";
        std::cout << GRAY << "│ x       │\n";
        std::cout << GRAY << "│         │\n";
        std::cout << GRAY << "│         │\n";
        std::cout << GRAY << "│         │\n";
        std::cout << GRAY << "│       x │\n";
        std::cout << GRAY << "└─────────┘\n\n";
        moves=2;
    }
    else if (type == "bronze")
    {
        std::cout << BROWN << "   _________ _________ _________ _________ _________ _________" << RESET << "\n";
        std::cout << BROWN << "  /         |         |         |         |         |         |" << RESET << "\n";
        std::cout << BROWN << " /    B    /    R    /    O    /    N    /    Z    /    E    /" << RESET << "\n";
        std::cout << BROWN << "/_________/_________/_________/_________/_________/_________/" << RESET << "\n"
        std::cout << BROWN << "┌─────────┐\n";
        std::cout << BROWN << "│         │\n";
        std::cout << BROWN << "│         │\n";
        std::cout << BROWN << "│    x    │\n";
        std::cout << BROWN << "│         │\n";
        std::cout << BROWN << "│         │\n";
        std::cout << BROWN << "└─────────┘\n\n";
        moves=1;
    }
    else if (type == "diamond")
    {
        std::cout << BLUE << "   _________ _________ _________ _________ _________ _________ _________" << RESET << "\n";
        std::cout << BLUE << "  /         |         |         |         |         |        |          |" << RESET << "\n";
        std::cout << BLUE << " /    D    /    I    /    A    /    M    /    O    /    N   /     D    /" << RESET << "\n";
        std::cout << BLUE << "/_________/_________/_________/_________/_________/_________/_________/" << RESET << "\n";
        std::cout << BLUE << "┌─────────┐\n";
        std::cout << BLUE << "│ x     x │\n";
        std::cout << BLUE << "│         │\n";
        std::cout << BLUE << "│    x    │\n";
        std::cout << BLUE << "│         │\n";
        std::cout << BLUE << "│ x     x │\n";
        std::cout << BLUE << "└─────────┘\n\n";
        moves=5;
    }
    else if (type == "secret")
    {
    std::cout << MAGENTA << "   _________ _________ _________ _________ _________ _________" << RESET << "\n";
    std::cout << MAGENTA << "  /         |         |         |         |         |         |" << RESET << "\n";
    std::cout << MAGENTA << " /    S    /    E    /    C    /    R    /    E    /    T    /" << RESET << "\n";
    std::cout << MAGENTA << "/_________/_________/_________/_________/_________/_________/" << RESET << "\n"
    std::cout << MAGENTA <<  "┌─────────┐\n";
    std::cout << MAGENTA <<  "│ ?     ? │\n";
    std::cout << MAGENTA <<  "│         │\n";
    std::cout << MAGENTA <<  "│    ?    │\n";
    std::cout << MAGENTA <<  "│         │\n";
    std::cout << MAGENTA <<  "│ ?     ? │\n";
    std::cout << MAGENTA <<  "└─────────┘\n\n";
        moves=-1;
    }

}
