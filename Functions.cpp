#include <iostream>
#include <string>
#include "Functions.h"
#include "Map.h"
#include "Player.h"
#include "Station.h"
#include "CImg.h"
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

int getTicket(){
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

void killMal(Map &gameMap, int killerPlayerNum, int row, int col){
    bool killFirst = false;
    bool killSecond = false;
    bool killThird = false;

    if (killerPlayerNum == 0){
        if (gameMap.getPlayerLocation(row, col).Playertwo_first){
            killFirst = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playertwo_second){
            killSecond = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playertwo_third){
            killThird = true;
        }
    } else if (killerPlayerNum == 1){
        if (gameMap.getPlayerLocation(row, col).Playerone_first){
            killFirst = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playerone_second){
            killSecond = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playerone_third){
            killThird = true;
        }
    }

    cout << "You killed the opponent's mal number:";

    if (killFirst){
        gameMap.removePlayerLocation(row, col, (killerPlayerNum + 1)%2, 1);
        cout << " 1";
    }
    if (killSecond){
        gameMap.removePlayerLocation(row, col, (killerPlayerNum + 1)%2, 2);
        cout << " 2";
    }
    if (killThird){
        gameMap.removePlayerLocation(row, col, (killerPlayerNum + 1)%2, 3);
        cout << " 3";
    }

    cout << "." << endl;
}

void moveMalDisplay(Map &gameMap, int playerNum, int malNum, int previRow, int previCol, int row, int col){
    if (playerNum == 0, malNum == 1){
        string arrA1[3][3] = {
            {"A", "1", "A"},
            {"1", " ", "1"},
            {"A", "1", "A"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA1);
    }
    
    if (playerNum == 0, malNum == 2){
        string arrA2[3][3] = {
            {"A", "2", "A"},
            {"2", " ", "2"},
            {"A", "2", "A"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA2);
    };
   if (playerNum == 0, malNum == 3){
        string arrA3[3][3] = {
            {"A", "3", "A"},
            {"3", " ", "3"},
            {"A", "3", "A"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA3);
    };
   if (playerNum == 0, malNum == 12){
        string arrA12[3][3] = {
            {"A", "1", "2"},
            {"1", " ", "A"},
            {"A", "2", "1"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA12);
    };
   if (playerNum == 0, malNum = 23){
        string arrA23[3][3] = {
            {"A", "2", "3"},
            {"2", " ", "A"},
            {"A", "3", "2"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA23);
    };

   if (playerNum == 0, malNum = 13){
        string arrA13[3][3] = {
            {"A", "1", "3"},
            {"1", " ", "A"},
            {"A", "3", "1"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA13);
    };
   if (playerNum == 0, malNum = 123){
        string arrA123[3][3] = {
            {"A", "1", "2"},
            {"3", " ", "3"},
            {"2", "1", "A"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrA123);
    };


   if (playerNum == 1, malNum = 1){
        string arrB1[3][3] = {
            {"B", "1", "B"},
            {"1", " ", "1"},
            {"B", "1", "B"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB1);
    };

   if (playerNum == 1, malNum = 2){
        string arrB2[3][3] = {
            {"B", "2", "B"},
            {"2", " ", "2"},
            {"B", "2", "B"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB2);
    };
   if (playerNum == 1, malNum = 3){
        string arrB3[3][3] = {
            {"B", "3", "B"},
            {"3", " ", "3"},
            {"B", "3", "B"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB3);
    };

   if (playerNum == 1, malNum = 12){
        string arrB12[3][3] = {
            {"B", "1", "2"},
            {"1", " ", "B"},
            {"B", "2", "1"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB12);
    };

   if (playerNum == 1, malNum = 23){
        string arrB23[3][3] = {
            {"B", "2", "3"},
            {"2", " ", "B"},
            {"B", "3", "2"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB23);
    };

   if (playerNum == 1, malNum = 13){
        string arrB13[3][3] = {
            {"B", "1", "3"},
            {"1", " ", "B"},
            {"B", "3", "1"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB13);
    };

   if (playerNum == 1, malNum = 123){
        string arrB123[3][3] = {
            {"B", "1", "2"},
            {"3", " ", "3"},
            {"2", "1", "B"}
            };
        gameMap.moveMal(previRow, previCol, row, col, arrB123);
    };


}

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


int IndexInMapDisplay[29][2] =
    {
        { 2, 2 }, //Kowloon
        { 2, 16 }, //Symphony of Lights
        { 2, 30 }, //Mong Kok
        { 2, 44 },//Ladies' Market
        { 2, 58 },//Soho
        { 2, 72 },//North Point
        { 10, 14 }, //Wong Tai Sin
        { 10, 60 }, //Night Market
        { 12, 2 }, //HKSM
        { 12, 72 }, //Golden Computer Arcade
        { 19, 26 }, //Elements Mall 
        { 19, 48 }, //Promenade
        { 23, 2 }, //HKMOH
        { 23, 72 }, //Langham Place
        { 28, 37 }, //Tsim Sa Tsui
        { 33, 2 }, //HKMOA
        { 33, 72 }, //Avenue of Stars
        { 37, 26 }, //Clock Tower
        { 37, 48 }, //Lan Kwai Fong
        { 44, 2 }, //Repluse Bay
        { 44, 72 }, //Tai O
        { 46, 14 }, //Victoria Peak
        { 46, 60 }, //Tai Kwun
        { 54, 2 }, //HKU
        { 54, 16 }, //Disneyland
        { 54, 30 }, //Ocean Park
        { 54, 44 }, //Man Mo
        { 54, 58 }, //Western Market
        { 54, 72 }, //Admiralty
    };

void PrintExplain(int row, int col)
{
    if (row == 0 && col == 0)
    {
        CImg<unsigned char> image("Kowloon.jpeg");
        cout << image << endl;
        cout << "You have arrived at Kowloon. There is a Kowloon Park, which is large park with gardens, lakes, and a swimming pool." << endl;
    }
    else if (row == 0 && col == 1)
    {
        CImg<unsigned char> image("SymphonyOfLight.jpeg");
        cout << image << endl;
        cout << "You have arrived at Symphony of Lights. It is a light and sound show that illuminates the skyline every night." << endl;
    }
    else if (row == 0 && col == 2)
    {
        CImg<unsigned char> image("MongKok.jpeg");
        cout << image << endl;
        cout << "You have arrived at Mong Kok. It is a bustling neighborhood with markets, street food, and nightlife." << endl;
    }
    else if (row == 0 && col == 4)
    {
        CImg<unsigned char> image("LadiesMarket.jpeg");
        cout << image << endl;
        cout << "You have arrived at Ladies' Market. It is a street market in Mong Kok that sells clothes, accessories, and souvenirs." << endl;
    }
    else if (row == 0 && col == 5)
    {
        CImg<unsigned char> image("Soho.jpeg");
        cout << image << endl;
        cout << "You have arrived at Soho. It is a neighborhood in Central with trendy bars and restaurants." << endl;
    }
    else if (row == 0 && col == 6)
    {
        CImg<unsigned char> image("NorthPoint.jpeg");
        cout << image << endl;
        cout << "You have arrived at North Point. It is a densely populated area that is known for its vibrant local atmosphere, with a mix of residential, commercial, and industrial spaces." << endl;
    }
    else if (row == 1 && col == 0)
    {
        CImg<unsigned char> image("HongKongScienceMuseum.jpeg");
        cout << image << endl;
        cout << "You have arrived at Hong Kong Science Museum. It is a museum with interactive exhibits on science and technology." << endl;
    }
    else if (row == 1 && col == 1)
    {
        CImg<unsigned char> image("WongTaiSin.jpeg");
        cout << image << endl;
        cout << "You have arrived at Wong Tai Sin Temple. It is a Taoist temple in Kowloon that is known for granting wishes." << endl;
    }
    else if (row == 1 && col == 5)
    {
        CImg<unsigned char> image("HKstreetnightmarket.jpeg");
        cout << image << endl;
        cout << "You have arrived at Temple Street Night Market. It is a bustling night market in Yau Ma Tei that sells a variety of goods." << endl;
    }
    else if (row == 1 && col == 6)
    {
        CImg<unsigned char> image("GoldenComputerArcade.jpeg");
        cout << image << endl;
        cout << "You have arrived at Golden Computer Arcade. It is a shopping center in Sham Shui Po that sells electronics and computer components." << endl;
    }
    else if (row == 2 && col == 0)
    {
        CImg<unsigned char> image("HKmuseumofhistory.jpeg");
        cout << image << endl;
        cout << "You have arrived at Hong Kong Museum of History. It is a museum that traces the history of Hong Kong." << endl;
    }
    else if (row == 2 && col == 2)
    {
        CImg<unsigned char> image("Elementhall.jpeg");
        cout << image << endl;
        cout << "You have arrived at Elements Mall. It is a shopping mall in Kowloon with luxury brands and fine dining restaurants." << endl;
    }
    else if (row == 2 && col == 4)
    {
        CImg<unsigned char> image("Promenade.jpeg");
        cout << image << endl;
        cout << "You have arrived at Tsim Sha Tsui Promenade. It is a waterfront promenade with stunning views of the harbor." << endl;
    }
    else if (row == 2 && col == 6)
    {
        CImg<unsigned char> image("LanghamPlace.jpeg");
        cout << image << endl;
        cout << "You have arrived at Langham Place. It is a shopping mall in Mong Kok with a variety of stores and a cinema." << endl;
    }
    else if (row == 3 && col == 3)
    {
        CImg<unsigned char> image("TsimShaTsui.jpeg");
        cout << image << endl;
        cout << "You have arrived at Tsim Sa Tsui. It is a popular tourist and shopping district located in the southern part of Kowloon Peninsula in Hong Kong." << endl;
    }
    else if (row == 4 && col == 0)
    {
        CImg<unsigned char> image("HKmuseumofart.jpeg");
        cout << image << endl;
        cout << "You have arrived at Hong Kong Museum of Art. It is a museum showcasing Chinese art and culture." << endl;
    }
    else if (row == 4 && col == 2)
    {
        CImg<unsigned char> image("clocktower.jpeg");
        cout << image << endl;
        cout << "You have arrived at The Clock Tower. It is a historic landmark in Tsim Sha Tsui." << endl;
    }
    else if (row == 4 && col == 4)
    {
        CImg<unsigned char> image("lankwaifong.jpeg");
        cout << image << endl;
        cout << "You have arrived at Lan Kwai Fong. It is a nightlife district in Central known for its bars and clubs." << endl;
    }
    else if (row == 4 && col == 6)
    {
        CImg<unsigned char> image("AvenueOfStars.jpeg");
        cout << image << endl;
        cout << "You have arrived at Avenue of Stars. It is a promenade dedicated to Hong Kong's film industry." << endl;
    }
    else if (row == 5 && col == 0)
    {
        CImg<unsigned char> image("repulsebay.jpeg");
        cout << image << endl;
        cout << "You have arrived at Repulse Bay. It is a beach with stunning views and plenty of water sports activities." << endl;
    }
    else if (row == 5 && col == 1)
    {
        CImg<unsigned char> image("VictoriaPeak.jpeg");
        cout << image << endl;
        cout << "You have arrived at Victoria Peak. It is a popular tourist destination with a spectacular view of Hong Kong's skyline." << endl;
    }
    else if (row == 5 && col == 5)
    {
        CImg<unsigned char> image("taikwun.jpeg");
        cout << image << endl;
        cout << "You have arrived at Tai Kwun. It is a heritage site that houses art galleries, restaurants, and shops." << endl;
    }
    else if (row == 5 && col == 6)
    {
        CImg<unsigned char> image("Tai O.jpeg");
        cout << image << endl;
        cout << "You have arrived at Tai O. It is a fishing village on Lantau Island with traditional stilt houses and a peaceful atmosphere" << endl;
    }
    else if (row == 6 && col == 0)
    {
        CImg<unsigned char> image("HKU.jpeg");
        cout << image << endl;
        cout << "You have arrived at HKU. Located on Hong Kong Island, HKU has a beautiful campus that features a blend of modern and historic buildings, as well as green spaces and cultural landmarks." << endl;
    }
    else if (row == 6 && col == 1)
    {
        CImg<unsigned char> image("hkdisneyland.jpeg");
        cout << image << endl;
        cout << "You have arrived at Hong Kong Disneyland. It is a theme park with attractions for all ages." << endl;
    }
    else if (row == 6 && col == 2)
    {
        CImg<unsigned char> image("OceanPark.jpeg");
        cout << image << endl;
        cout << "You have arrived at Ocean Park. It is a marine-life theme park with thrilling rides and animal exhibits." << endl;
    }
    else if (row == 6 && col == 4)
    {
        CImg<unsigned char> image("ManMo.jpeg");
        cout << image << endl;
        cout << "You have arrived at Man Mo Temple. It is a historic temple in Sheung Wan dedicated to the gods of literature and martial arts." << endl;
    }
    else if (row == 6 && col == 5)
    {
        CImg<unsigned char> image("WesternMarket.jpeg");
        cout << image << endl;
        cout << "You have arrived at Western Market. It is a restored Edwardian-style building with shops selling souvenirs and handicrafts." << endl;
    }
    else if (row == 6 && col == 6)
    {
        CImg<unsigned char> image("Admiralty.jpeg");
        cout << image << endl;
        cout << "You have arrived at Admiralty. It is a major commercial and financial hub in Hong Kong, and is home to many important government buildings, including the Central Government Complex and the Legislative Council Complex." << endl;
    }
}
