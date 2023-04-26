#include <iostream>
#include <string>
#include "Functions.h"
#include "Map.h"
#include "Player.h"
#include "Station.h"
using namespace std;

void killMal(Map &gameMap, int killerPlayerNum, int row, int col){
    bool killFirst = false;
    bool killSecond = false;
    bool killThird = false;

    if (killerPlayerNum == 1){
        if (gameMap.getPlayerLocation(row, col).Playertwo_first){
            killFirst = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playertwo_second){
            killSecond = true;
        }
        if (gameMap.getPlayerLocation(row, col).Playertwo_third){
            killThird = true;
        }
    } else if (killerPlayerNum == 2){
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
        gameMap.removePlayerLocation(row, col, killerPlayerNum + 1, 1);
        cout << " 1";
    }
    if (killSecond){
        gameMap.removePlayerLocation(row, col, killerPlayerNum + 1, 2);
        cout << " 2";
    }
    if (killThird){
        gameMap.removePlayerLocation(row, col, killerPlayerNum + 1, 3);
        cout << " 3";
    }

    cout << "." << endl;
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

void PrintExplain(int mapdisplayindex[2])
{
    if (mapdisplayindex[0] == 2 & mapdisplayindex[1] == 2)
    {
        cout << "You have arrived at Koloon. There is a Kowloon Park, which is large park with gardens, lakes, and a swimming pool." << endl;
    }
    else if (mapdisplayindex[0] == 2 & mapdisplayindex[1] == 16)
    {
        cout << "You have arrived at Symphony of Lights. It is a light and sound show that illuminates the skyline every night." << endl;
    }
    else if (mapdisplayindex[0] == 2 & mapdisplayindex[1] == 30)
    {
        cout << "You have arrived at Mong Kok. It is a bustling neighborhood with markets, street food, and nightlife." << endl;
    }
    else if (mapdisplayindex[0] == 2 & mapdisplayindex[1] == 44)
    {
        cout << "You have arrived at Ladies' Market. It is a street market in Mong Kok that sells clothes, accessories, and souvenirs." << endl;
    }
    else if (mapdisplayindex[0] == 2 & mapdisplayindex[1] == 58)
    {
        cout << "You have arrived at Soho. It is a neighborhood in Central with trendy bars and restaurants." << endl;
    }
    else if (mapdisplayindex[0] == 2 & mapdisplayindex[1] == 72)
    {
        cout << "You have arrived at North Point. It is a densely populated area that is known for its vibrant local atmosphere, with a mix of residential, commercial, and industrial spaces." << endl;
    }
    else if (mapdisplayindex[0] == 10 & mapdisplayindex[1] == 14)
    {
        cout << "You have arrived at Wong Tai Sin Temple. It is a Taoist temple in Kowloon that is known for granting wishes." << endl;
    }
    else if (mapdisplayindex[0] == 10 & mapdisplayindex[1] == 60)
    {
        cout << "You have arrived at Temple Street Night Market. It is a bustling night market in Yau Ma Tei that sells a variety of goods." << endl;
    }
    else if (mapdisplayindex[0] == 12 & mapdisplayindex[1] == 2)
    {
        cout << "You have arrived at Hong Kong Science Museum. It is a museum with interactive exhibits on science and technology." << endl;
    }
    else if (mapdisplayindex[0] == 12 & mapdisplayindex[1] == 72)
    {
        cout << "You have arrived at Golden Computer Arcade. It is a shopping center in Sham Shui Po that sells electronics and computer components." << endl;
    }
    else if (mapdisplayindex[0] == 19 & mapdisplayindex[1] == 26)
    {
        cout << "You have arrived at Elements Mall. It is a shopping mall in Kowloon with luxury brands and fine dining restaurants." << endl;
    }
    else if (mapdisplayindex[0] == 19 & mapdisplayindex[1] == 48)
    {
        cout << "You have arrived at Tsim Sha Tsui Promenade. It is a waterfront promenade with stunning views of the harbor." << endl;
    }
    else if (mapdisplayindex[0] == 23 & mapdisplayindex[1] == 2)
    {
        cout << "You have arrived at Hong Kong Museum of History. It is a museum that traces the history of Hong Kong." << endl;
    }
    else if (mapdisplayindex[0] == 23 & mapdisplayindex[1] == 72)
    {
        cout << "You have arrived at Langham Place. It is a shopping mall in Mong Kok with a variety of stores and a cinema." << endl;
    }
    else if (mapdisplayindex[0] == 28 & mapdisplayindex[1] == 37)
    {
        cout << "You have arrived at Tsim Sa Tsui. It is a popular tourist and shopping district located in the southern part of Kowloon Peninsula in Hong Kong." << endl;
    }
    else if (mapdisplayindex[0] == 33 & mapdisplayindex[1] == 2)
    {
        cout << "You have arrived at Hong Kong Museum of Art. It is a museum showcasing Chinese art and culture." << endl;
    }
    else if (mapdisplayindex[0] == 33 & mapdisplayindex[1] == 72)
    {
        cout << "You have arrived at Avenue of Stars. It is a promenade dedicated to Hong Kong's film industry." << endl;
    }
    else if (mapdisplayindex[0] == 37 & mapdisplayindex[1] == 26)
    {
        cout << "You have arrived at The Clock Tower. It is a historic landmark in Tsim Sha Tsui." << endl;
    }
    if (mapdisplayindex[0] == 37 & mapdisplayindex[1] == 48)
    {
        cout << "You have arrived at Lan Kwai Fong. It is a nightlife district in Central known for its bars and clubs." << endl;
    }
    else if (mapdisplayindex[0] == 44 & mapdisplayindex[1] == 2)
    {
        cout << "You have arrived at Repulse Bay. It is a beach with stunning views and plenty of water sports activities." << endl;
    }
    else if (mapdisplayindex[0] == 44 & mapdisplayindex[1] == 72)
    {
        cout << "You have arrived at Tai O. It is a fishing village on Lantau Island with traditional stilt houses and a peaceful atmosphere" << endl;
    }
    else if (mapdisplayindex[0] == 46 & mapdisplayindex[1] == 14)
    {
        cout << "You have arrived at Victoria Peak. It is a popular tourist destination with a spectacular view of Hong Kong's skyline." << endl;
    }
    else if (mapdisplayindex[0] == 46 & mapdisplayindex[1] == 60)
    {
        cout << "You have arrived at Tai Kwun. It is a heritage site that houses art galleries, restaurants, and shops." << endl;
    }
    else if (mapdisplayindex[0] == 54 & mapdisplayindex[1] == 2)
    {
        cout << "You have arrived at HKU. Located on Hong Kong Island, HKU has a beautiful campus that features a blend of modern and historic buildings, as well as green spaces and cultural landmarks." << endl;
    }
    else if (mapdisplayindex[0] == 54 & mapdisplayindex[1] == 16)
    {
        cout << "You have arrived at Hong Kong Disneyland. It is a theme park with attractions for all ages." << endl;
    }
    else if (mapdisplayindex[0] == 54 & mapdisplayindex[1] == 30)
    {
        cout << "You have arrived at Ocean Park. It is a marine-life theme park with thrilling rides and animal exhibits." << endl;
    }
    else if (mapdisplayindex[0] == 54 & mapdisplayindex[1] == 44)
    {
        cout << "You have arrived at Man Mo Temple. It is a historic temple in Sheung Wan dedicated to the gods of literature and martial arts." << endl;
    }
    else if (mapdisplayindex[0] == 54 & mapdisplayindex[1] == 58)
    {
        cout << "You have arrived at Western Market. It is a restored Edwardian-style building with shops selling souvenirs and handicrafts." << endl;
    }
    else if (mapdisplayindex[0] == 54 & mapdisplayindex[1] == 72)
    {
        cout << "You have arrived at Admiralty. It is a major commercial and financial hub in Hong Kong, and is home to many important government buildings, including the Central Government Complex and the Legislative Council Complex." << endl;
    }
    


    
    
}
