#include <string>
#include <vector>
#include <iostream>
#include "PlutoRover.cpp"

using namespace std;

main(){
    PlutoRover* rover = new PlutoRover();
    vector<char> commands;
    commands.push_back('L');
    commands.push_back('F');
    
    rover->moveRover(commands);
    cout<<rover->Direction;

}