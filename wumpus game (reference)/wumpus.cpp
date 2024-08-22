#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation

Wumpus::Wumpus(){
    //wumpus constructor
}

Wumpus::~Wumpus(){
    //Wumpus Destructor
}

void Wumpus::percept() const{
    cout << "You smell a terrible stench." << endl;
}

void Wumpus::encounter() const{
    cout << "You have run into the Wumpus!" << endl;
}
