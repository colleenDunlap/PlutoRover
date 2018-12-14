#include <string>
#include <vector>
#include <iostream>

const int PLUTOCIRCUMFERENCE = 100; //you can't go further than 100 in the x or the y direction, you will wrap to zero
class PlutoRover{
    public:
    int xPos;
    int yPos;
    char Direction;
    
    PlutoRover();
    PlutoRover(int x, int y, char direction);
};
