#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <vector>
#include "ship.hpp"
#include <utility>
using std::pair;

TEST_CASE("a ship returns true if it is alive"){
    Ship rowboat = Ship();
    CHECK(rowboat.getStatus() == true);
}

TEST_CASE("ship size is shipshape and ready to go"){
    Ship rowboat = Ship(2);
    Ship skipper = Ship(3);
    Ship boatymcboatface = Ship(4);
    Ship airfighter = Ship(5);
    CHECK(rowboat.getSize() == 2);
    CHECK(skipper.getSize() == 3);
    CHECK(boatymcboatface.getSize() == 4);
    CHECK(airfighter.getSize() == 5);
}

TEST_CASE("a ship has a start position"){
    for(int i = 1; i < 10 ; ++i){
        for(int j = 1; j < 10; ++j){
            Ship rowboat = Ship(2, i, j);
            pair<int,int> mypair(i,j);
            CHECK(rowboat.getPos() == mypair);
        }
    }
}
