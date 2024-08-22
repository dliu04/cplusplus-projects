#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation

Gold::Gold(){
    //default constructor
} 

Gold::~Gold(){
    //virtual destructor
}

void Gold::percept() const{
    cout << "You see a glimmer nearby." << endl;
}
void Gold::encounter() const{
    //gold behavior
}
