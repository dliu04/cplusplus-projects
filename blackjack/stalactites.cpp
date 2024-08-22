#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

Stalactites::Stalactites(){
    //default constructor
} 

Stalactites::~Stalactites(){
    //virtual destructor
} 

void Stalactites::percept() const{
    cout << "You hear water dripping." << endl;
}

void Stalactites::encounter() const{
    cout << "Stalactites loom over you..." << endl;
}
