#include "event.h"
#include "room.h"

#include <iostream>

using namespace std;

//Room Implementation

Room::Room(){
    this->isEmpty = true; //make all rooms empty when initialized
    this->hasEvent = false;
    this->hasWumpus = false;
    this->hasStalactites = false;
    this->hasBats = false;
    this->hasGold = false;
    this->event = nullptr;
    this->symbol = '0';
}

Room::~Room(){
    if (this->event != nullptr) {
        this->event = nullptr;
    }
}

void Room::setEvent(Event* newEvent){
    this->event = newEvent;
    this->isEmpty = false;
}

void Room::emptyEvent(Event* existingEvent){
    if (existingEvent != nullptr){
        delete existingEvent;
    }
    existingEvent = nullptr;
    this->isEmpty = true;
}

Event* Room::getEvent() const{
    return this->event;
}

void Room::cout_Symbol() const{
    cout << this->symbol << " ||";
}

void Room::set_Symbol(char input){
    this->symbol = input;
}

bool Room::get_Emptiness() const{
    return this->isEmpty;
}

void Room::set_Emptiness(bool input){
    this->isEmpty = input;
}

bool Room::get_Event_bool(){
    return this->hasEvent;
}

void Room::set_Event_bool(bool input){
    this->hasEvent = input;
}

bool Room::get_Wumpus_bool(){
    return this->hasWumpus;
}

void Room::set_Wumpus_bool(bool input){
    this->hasWumpus = input;
}

bool Room::get_Stalactites_bool(){
    return this->hasStalactites;
}

void Room::set_Stalactites_bool(bool input){
    this->hasStalactites = input;
}

bool Room::get_Bats_bool(){
    return this->hasBats;
}

 void Room::set_Bats_bool(bool input){
    this->hasBats = input;
 }

bool Room::get_Gold_bool(){
    return this->hasGold;
}

void Room::set_Gold_bool(bool input){
    this->hasGold = input;
}

void Room::play_Percept(){
    event->percept();
}

void Room::play_Event(){
    event->encounter();
}
