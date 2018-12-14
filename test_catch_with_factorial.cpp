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
    SECTION("Initialize Rover with Negative Placement Parameters"){
        PlutoRover* rover = new PlutoRover(-1, -99, 'E');
        
        REQUIRE(rover->xPos == 99);
        REQUIRE(rover->yPos == 1);
        REQUIRE(rover->Direction=='E');
    }
    

}

TEST_CASE("Moving the Rover","[rovingRover]"){
    PlutoRover* rover = new PlutoRover();
    vector<char> commands;
    //Move Forward and Backward Facing NorthS
    commands.push_back('F');
    commands.push_back('F');
    rover->moveRover(commands);
    REQUIRE(rover->xPos == 0);
    REQUIRE(rover->yPos == 2);
    
    commands.clear();
    commands.push_back('B');
    
    rover->moveRover(commands);
    REQUIRE(rover->xPos == 0);
    REQUIRE(rover->yPos == 1);
    //Move Forward and Backward Facing West (with wrapping)
    commands.clear();
    commands.push_back('L');
    commands.push_back('F');
    
    rover->moveRover(commands);
    REQUIRE(rover->xPos == 99);
    REQUIRE(rover->yPos == 1);
    
    commands.clear();
    commands.push_back('B');
    
    rover->moveRover(commands);
    REQUIRE(rover->xPos == 0);
    REQUIRE(rover->yPos==1);
    //Move Forward and Backward facing East
    commands.clear();
    commands.push_back('R');
    commands.push_back('R');
    commands.push_back('F');
    
    rover->moveRover(commands);
    REQUIRE(rover->xPos==1);
    REQUIRE(rover->yPos==1);
    
    commands.clear();
    commands.push_back('B');
    rover->moveRover(commands);
    REQUIRE(rover->xPos == 0);
    REQUIRE(rover->yPos==1);
    //Move Forward and Backward facing South (with wrapping)
    commands.clear();
    commands.push_back('R');
    commands.push_back('F');
    commands.push_back('F');
    
    rover->moveRover(commands);
    REQUIRE(rover->xPos == 0);
    REQUIRE(rover->yPos==99);
    
    commands.clear();
    commands.push_back('B');
    
    rover->moveRover(commands);
    REQUIRE(rover->xPos == 0);
    REQUIRE(rover->yPos==0);
    
}
TEST_CASE("Obstacle Detection"){
    PlutoRover* rover = new PlutoRover();
    PlutoObstacle* obstacle = new Obstacle(0,1):
    
    vector<char>commands;
    rover->moveRover.commands();
    
    REQUIRE(rover->yPos == 0);//rover should not move to area where new obstacle is
    
}






