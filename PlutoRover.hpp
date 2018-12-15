#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int PLUTOCIRCUMFERENCE = 100; //you can't go further than 100 in the x or the y direction, you will wrap to zero
class PlutoRover{
    public:
    int xPos;
    int yPos;
    char Direction;
    vector<int> obstacleX;
    vector<int> obstacleY;
    
    PlutoRover();
    PlutoRover(int x, int y, char direction);
    
    void moveRover(vector<char> commands);
    void turnRover(char rightOrLeft);
    void displaceRover(char forwardOrBackward);
    void addObstacle(int obsX, int obsY);

};
