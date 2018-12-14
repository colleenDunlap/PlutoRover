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
    if(xPos<0){
        xPos = xPos + PLUTOCIRCUMFERENCE;
    }
    yPos = y%PLUTOCIRCUMFERENCE;
    if(yPos<0){
        yPos = yPos + PLUTOCIRCUMFERENCE;
    }
    Direction = direction;
}
