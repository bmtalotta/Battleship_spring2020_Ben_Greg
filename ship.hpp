// ship.hpp
// Greg Talotta
// 2019-09-24
//
// For CS 372 Fall 2019
// Header for ship class

#ifndef FILE_SHIP_HPP_INCLUDED
#define FILE_SHIP_HPP_INCLUDED
#include <utility>
using std::pair;

class Ship{
    public:
        explicit Ship(int size = 0, int x = 0, int y = 0) :_status(true),
                        _size(size),
                        _pos(x,y)
        {
        }

        bool getStatus()
        {
            return _status;
        }

        int getSize()
        {
            return _size;
        }

        pair<int,int> getPos()
        {
            return _pos;
        }


    private:
        bool _status;
        int _size;
        pair<int,int> _pos; 


};

#endif  //#ifndef FILE_SHIP_HPP_INCLUDED

