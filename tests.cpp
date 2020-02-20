#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <vector>
#include "ship.hpp"
#include "game.hpp"
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

TEST_CASE("ship has a direction"){
    Ship rowboat = Ship(2, 1, 1, true);
    Ship skipper = Ship(2, 1, 1, false);
    Ship boatymcboatface = Ship(2, 1, 1, true);
    Ship airfighter = Ship(2, 1, 1, false);
    CHECK(rowboat.getVertical() == true);
    CHECK(skipper.getVertical() == false);
    CHECK(boatymcboatface.getVertical() == true);
    CHECK(airfighter.getVertical() == false);
}


TEST_CASE("shpe can sink"){
    Ship rowboat = Ship(2, 1, 1, true);
    Ship skipper = Ship(3, 1, 1, false);
    CHECK(rowboat.incrementHit() == true);
    CHECK(rowboat.incrementHit() == false);
    CHECK(skipper.incrementHit() == true);
    CHECK(skipper.incrementHit() == true);
    CHECK(skipper.incrementHit() == false);
}