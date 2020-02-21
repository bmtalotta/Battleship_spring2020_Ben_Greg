//game.hpp
// Ben Talotta
// 2019-09-24
//
// For CS 372 Fall 2019
// Header for ship class

#ifndef FILE_GAME_HPP_INCLUDED
#define FILE_GAME_HPP_INCLUDED
#include "ship.hpp"
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::vector;
using std::pair;
class game
{
    public:
        game()
        {
            
        }
        void playGame()
        {
            while(playing())
            {
                int crap = 0;
                playerOneTurn();
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" ;
                cout << "It is now player two's turn, hit enter to continue\n";
                cin.ignore();
                playerTwoTurn();
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" ;
                cout << "It is now player one's turn, hit enter to continue\n";
                cin.ignore();
            }
        }
    private:
        void playerOneTurn()
        {
            printGuessBoard(player1AlreadyShot,player2Ships);
            cout << "----------------------------\n";
            printPlayerBoard(player1Ships);
            guess(player1AlreadyShot,player2Ships); 
            
        }
        void playerTwoTurn()
        {
            printGuessBoard(player2AlreadyShot,player1Ships);
            cout << "----------------------------\n";
            printPlayerBoard(player2Ships);
            guess(player2AlreadyShot,player1Ships);
        }
        void guess(vector<pair<int,int>>&shots, vector<Ship> ships)
        {   
            while(true)
            {
                cout << "enter x\n";
                int x;
                int y;
                cin >> x;
                cout << "enter y\n";
                cin >> y;
                pair<int,int> currShot = {x,y}; 
                if(std::find(shots.begin(), shots.end(),currShot) ==  shots.end())
                {
                    shots.push_back(currShot);
                    for(int i = 0; i < ships.size(); ++i)
                    {
                        if(std::find(ships[i]._location.begin(), ships[i]._location.end(),currShot) !=  ships[i]._location.end())
                        {
                            ships[i].incrementHit();
                            cout << "hit";
                            cout << "\n \n hit enter to continue";
                            cin.ignore();
                            cin.get();
                            return;
                        }
                    }
                    cout << "miss";
                    cout << "\n \n hit enter to continue";
                    cin.ignore();
                    cin.get();
                    return;
                }else
                {
                    cout << "you already shot there \n";
                    cout << "shoot again \n";
                }
            }
        }


        void printPlayerBoard(vector<Ship> ships)
        {
            vector<pair<int,int>> shipCoords;
            for(int i = 0; i < ships.size(); ++i)
            {
                shipCoords.insert(shipCoords.end(), ships[i]._location.begin(), ships[i]._location.end());
            }
            for(int i = 1; i < 11; ++i)
            {
                for(int j = 1; j < 11; ++j)
                {
                    pair<int,int> currPos = {j,i};
                    if(std::find(shipCoords.begin(), shipCoords.end(),currPos) !=  shipCoords.end())
                    {
                        cout << " s ";
                    }else
                    {
                        cout << " ~ ";
                    }
                    
                }
                cout << "\n";
            }
        }
        
        void printGuessBoard(vector<pair<int,int>>&shots, vector<Ship> ships)
        {
            vector<pair<int,int>> shipCoords;
            for(int i = 0; i < ships.size(); ++i)
            {
                shipCoords.insert(shipCoords.end(), ships[i]._location.begin(), ships[i]._location.end());
            }
            for(int i = 1; i < 11; ++i)
            {
                for(int j = 1; j < 11; ++j)
                {
                    pair<int,int> currPos = {j,i};
                    if(std::find(shots.begin(), shots.end(),currPos) !=  shots.end())
                    {
                        if(std::find(shipCoords.begin(), shipCoords.end(),currPos) !=  shipCoords.end())
                        {
                            cout << " x ";
                        }else
                        {
                            cout << " O ";
                        }
                    }else
                    {
                        cout << " ~ ";
                    }
                    
                    
                }
                cout << "\n";
            }
        }

        bool playing()
        {
            bool teamstat = false;
            for(int i = 0; i < player1Ships.size(); ++i)
            {
                if(player1Ships[i].getStatus() == true)
                {
                    teamstat = true;
                }
            }
            if(teamstat == false)
            {
                cout << "\n player 2 wins \n";
                return false;
            }
            teamstat = false;
            for(int i = 0; i < player2Ships.size(); ++i)
            {
                if(player2Ships[i].getStatus() == true)
                {
                    teamstat = true;
                }
            }
            if(teamstat == false)
            {
                cout << "\n player 1 wins \n";
                return false;
            }
            return true;
        }
        vector<pair<int,int>> player1AlreadyShot;
        vector<Ship> player1Ships = {Ship(2, 1, 1), Ship(3, 2, 1), Ship(3, 3, 1), Ship(4,4,1), Ship(5,5,1)};
        vector<pair<int,int>> player2AlreadyShot;
        vector<Ship> player2Ships = {Ship(2, 10, 1), Ship(3, 9, 1), Ship(3, 8, 1), Ship(4,7,1), Ship(5,6,1)};
};


#endif  //#ifndef FILE_GAME_HPP_INCLUDED

