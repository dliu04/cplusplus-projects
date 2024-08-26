#ifndef GAME_H
#define GAME_H 

#include <iostream>
#include <vector>
using namespace std;

void play_game(int money);
vector <int> create_hand();
vector <int> deal_cards(vector <int> hand);

#endif