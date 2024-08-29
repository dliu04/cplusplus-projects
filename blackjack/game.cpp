#include "game.h"

#include <iostream>
#include <vector>

using namespace std;

void play_game(int money){
    // Receive the bet
    
    // Deal the cards

    // Display the cards

    // Ask player decision

    // Dealer's turn

    // Display the winner

    // Ask to play again
}

vector <int> create_hand(){
    // Create a vector to hold the player's hand
    vector <int> hand;

    return hand;
}


vector <int> deal_cards(vector <int> hand){
    // Deal two cards to the player
    for (int i = 0; i < 2; i++){
        int card_number = rand() % 11 + 1;
        cout << "Card " << i + 1 << ": " << card_number << endl;
        hand.push_back(card_number);
    }

    return hand;
}

