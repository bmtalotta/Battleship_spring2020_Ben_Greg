// ship.hpp
// Greg Talotta
// 2019-09-24
//
// For CS 372 Fall 2019
// Header for ship class

#ifndef FILE_SHIP_HPP_INCLUDED
#define FILE_SHIP_HPP_INCLUDED

class Ship{
    public:
        explicit Ship(int size = 0) :_status(true),
                        _size(size)
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


    private:
        bool _status;
        int _size;


};

#endif  //#ifndef FILE_SHIP_HPP_INCLUDED

