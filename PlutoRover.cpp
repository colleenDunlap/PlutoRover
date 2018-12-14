#include "PlutoRover.hpp"
#include <string>
#include <vector>
#include <iostream>
PlutoRover::PlutoRover(){
        xPos = 0;
        yPos = 0;
        Direction = 'N';
}
PlutoRover::PlutoRover(int x, int y, char direction){
    xPos = x%PLUTOCIRCUMFERENCE;
    yPos = y%PLUTOCIRCUMFERENCE;
    Direction = direction;
}
