// ship.hpp
// Greg Talotta and Ben Talotta
// 2019-09-24
//
// For CS 372 Fall 2019
// Header for ship class

#ifndef FILE_SHIP_HPP_INCLUDED
#define FILE_SHIP_HPP_INCLUDED
#include <utility>
#include <vector>
using std::vector;
using std::pair;

class Ship{
    public:
        explicit Ship(int size = 0, int x = 0, int y = 0, bool vert = true) :_aliveStatus(true),
                        _size(size), _position(x,y), _vertical(vert)
        {
            _location.push_back(_position);
            for(int i = 1; i < _size; ++i)
            {
                if(_vertical)
                {
                    _location.push_back({x, y+i});
                }
                else
                {
                    _location.push_back({x+i, y});
                }
            }
        }

        bool getStatus()
        {
            return _aliveStatus;
        }

        vector<pair<int,int>> getLocation()
        {
            return _location;
        }

        int getSize()
        {
            return _size;
        }

        pair<int,int> getPos()
        {
            return _position;
        }

        bool getVertical()
        {
            return _vertical;
        }
        
        bool incrementHit()
        {
            _amountHit += 1;
            if(_amountHit == _size)
            {
                _aliveStatus = false;
            }
            return _aliveStatus;
        }



    private:
        bool _aliveStatus = true;
        int _size;
        pair<int,int> _position; 
        bool _vertical;
        int _amountHit = 0;
        vector<pair<int,int>> _location;

};

#endif  //#ifndef FILE_SHIP_HPP_INCLUDED

