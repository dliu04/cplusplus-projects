#include "game.h"

#include <iostream>
#include <vector>

using namespace std;

int deal_cards(vector <int> hand){
    // Deal two cards to the player
    for (int i = 0; i < 2; i++){
        hand.push_back(rand() % 11 + 1);
    }
    return 0;
}

void play_game(int money){

}