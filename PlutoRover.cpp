#include "PlutoRover.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

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

void PlutoRover::moveRover(vector<char> commands){
    for (int iCommand = 0; iCommand < commands.size(); iCommand++){
        if(commands[iCommand] == 'F' ||commands[iCommand] == 'B' ){
            displaceRover(commands[iCommand]);
        }
        else if(commands[iCommand] == 'L' || commands[iCommand]=='R'){
            turnRover(commands[iCommand]);
        }
    }
    
}
void PlutoRover::turnRover(char rightOrLeft){
    if(rightOrLeft == 'L'){
        if(Direction == 'N'){
            Direction = 'W';
        }
        else if(Direction=='W'){
            Direction = 'S';
        }
        else if(Direction == 'S'){
            Direction='E';
        }
        else if (Direction=='E'){
            Direction='N';
        }
    }
    else{
        if(Direction == 'N'){
            Direction='E';
        }
        else if(Direction == 'E'){
            Direction='S';
        }
        else if(Direction=='S'){
            Direction='W';
        }
        else if(Direction=='W'){
            Direction='N';
        }
    }
    
}
void PlutoRover::displaceRover(char forwardOrBackward){
    if(forwardOrBackward == 'F'){
        if(Direction == 'N'){//the square directly north of (x.y) is (x,y+1)
            //check here if obstacle is located at (x, y+1).  return if that's the case.  Repeat for other 7 conditions;
            for(int iObstacle = 0; iObstacle<obstacleX.size(); iObstacle++){
                if(obstacleX[iObstacle]==xPos &&obstacleY[iObstacle]==(yPos+1)){
                    return;
                }
            }
            yPos++;
            if(yPos>=PLUTOCIRCUMFERENCE){
                yPos = yPos - PLUTOCIRCUMFERENCE;
            }
        }
        else if(Direction == 'S'){
            yPos--;
            if(yPos<0){
                yPos = yPos + PLUTOCIRCUMFERENCE;
            }
        }
        else if(Direction == 'E'){
            xPos++;
            if(xPos>=PLUTOCIRCUMFERENCE){
                xPos = xPos - PLUTOCIRCUMFERENCE;
            }
        }
        else if(Direction == 'W'){
            xPos--;
            if(xPos<0){
                xPos = xPos + PLUTOCIRCUMFERENCE;
            }
        }
    }
    else{
        if(Direction == 'N'){//the square directly north of (x.y) is (x,y+1)
            yPos--;
            if(yPos<0){
                yPos = yPos + PLUTOCIRCUMFERENCE;
            }
        }
        else if(Direction == 'S'){
            yPos++;
            if(yPos>=PLUTOCIRCUMFERENCE){
                yPos = yPos - PLUTOCIRCUMFERENCE;
            }
        }
        else if(Direction == 'E'){
            xPos--;
            if(xPos<0){
                xPos = xPos + PLUTOCIRCUMFERENCE;
            }
        }
        else if(Direction == 'W'){
            xPos++;
            
            if(xPos>=PLUTOCIRCUMFERENCE){
                xPos = xPos - PLUTOCIRCUMFERENCE;
            }
        }
        
    }
}
void PlutoRover::addObstacle(int x, int y){
    obstacleX.push_back(x);
    obstacleY.push_back(y);
}

