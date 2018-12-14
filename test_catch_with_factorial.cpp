#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "PlutoRover.hpp"

TEST_CASE( "Rover is Initialized", "[initializeRover]" ) {
    PlutoRover* rover = new PlutoRover();
    REQUIRE(rover->xPos == 0);
    REQUIRE(rover->yPos == 0);
    REQUIRE(rover->Direction == 'N');

}