#include "player.h"



Player::Player(){
    cout << "Player Constructor has been called." << endl;
    this->x = 0;
    this->y = 0;
    this->isCarryingGold = false;
}

void Player::setPosition(int x, int y){
    this->x = x;
    this->y = y;
}

int Player::getX() const{
    return this->x;
}

int Player::getY() const{
    return this->y;
}

void Player::setCarryingGold(bool carryingGold){
    this->isCarryingGold = carryingGold;
}

bool Player::getCarryingGold() const{
    return this->isCarryingGold;
}