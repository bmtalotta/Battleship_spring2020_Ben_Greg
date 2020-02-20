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
        void playGame()
        {
            bool playing = true;
            while(playing)
            {
                int crap = 0;
                playerOneTurn();
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" ;
                cout << "It is know player two's turn, hit enter to conintue\n";
                cin >> crap;
                playerTwoTurn();
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" ;
                cout << "It is know player one's turn, hit enter to conintue\n";
                cin >> crap;
                bool playing = false;
            }
        }
    private:
        void playerOneTurn()
        {
           guess(player1AlreadyShot); 
        }
        void playerTwoTurn()
        {
            guess(player2AlreadyShot); 
        }
        void guess(vector<pair<int,int>>&shots)
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
                    return;
                }else
                {
                    cout << "you already shot there \n";
                    cout << "shoot again \n";
                }
            }
        }
        vector<pair<int,int>> player1AlreadyShot;
        vector<Ship> player1Ships;
        vector<pair<int,int>> player2AlreadyShot;
        vector<Ship> player2Ships;
};


#endif  //#ifndef FILE_GAME_HPP_INCLUDED

