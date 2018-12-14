#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream>
#include "PlutoRover.cpp"

using namespace std;

TEST_CASE( "Rover is Initialized", "[initializeRover]" ) {
    PlutoRover* rover = new PlutoRover();
    cout<<rover->xPos;
    
    REQUIRE(rover->xPos == 0);
    REQUIRE(rover->yPos == 0);
    REQUIRE(rover->Direction == 'N');
    
    SECTION("Initialize Rover with Parameters"){
        PlutoRover* rover = new PlutoRover(3, 5, 'S');
        REQUIRE(rover->xPos == 3);
        REQUIRE(rover->yPos == 5);
        REQUIRE(rover->Direction=='S');
    }
    
    SECTION("Initialize Rover with Parameters Outside Planet Bounds"){
        PlutoRover* rover = new PlutoRover(200, 250, 'W');
        
        REQUIRE(rover->xPos == 0);
        REQUIRE(rover->yPos == 50);
        REQUIRE(rover->Direction=='W');
    }
    

}