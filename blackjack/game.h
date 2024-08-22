#ifndef GAME_H
#define GAME_H 

#include <iostream>
#include <vector>

class Game 
{
private:
    int money;
    int bet;
    vector <int> dealer_hand;
    vector <int> player_hand;
    
public:
    vector <int> get_dealer_hand;
    vector <int> deal_cards(vector <int>);
    void play_game(int);
};

#endif