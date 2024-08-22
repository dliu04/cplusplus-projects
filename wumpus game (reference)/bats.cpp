#include "bats.h"

#include <iostream>

using namespace std;

//Bats Implementation

Bats::Bats(){
    //default constructor
} 

Bats::~Bats(){
    //virtual destructor
} 

void Bats::percept() const{
    cout << "You hear wings flapping." << endl;
}

void Bats::encounter() const{
    //Bat behavior
}