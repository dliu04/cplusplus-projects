#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"

#include <iostream>

using namespace std;

//Game Implementation

Game::Game(){
	//Game constructor
	//Your code here:
	this->length = 0;
	this->width = 0;
	this->num_arrows = 0;
	this->debug_view = true; //set to false later
	this->player_confusion = 0;
	this->player_dead = false;
	this->player_win = false;
}

Game::~Game(){
	//Game destructor
	// Free memory allocated for events
    for (int i = 0; i < this->length; ++i) {
        for (int j = 0; j < this->width; ++j) {
            if (this->gameboard[i][j].get_Event_bool()) {
                delete this->gameboard[i][j].getEvent();
            }
        }
    }
}

void Game::set_up(int l, int w){
	//set up the game
	this->length = l;
	this->width = w;

	this->num_arrows = 3; 	//start with 3 arrows
	
	// Create the game board: 2D vector of Room objects

	for (int i = 0; i < l; i++){
		vector<Room> length_vec;

		for (int j = 0; j < w; j++)
			length_vec.push_back(Room());

	this->gameboard.push_back(length_vec);
	}

	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold) into the board
	wumpus_setup(); //you can run this function agian to move wumpus
	bats_setup();
	gold_setup();
	stalactites_setup();
	player_setup();
}

void Game::move_checker(char& input){
	bool valid = false;
	while (valid == false){
		if (input != 'w' && input != 'a' && input != 's' && input != 'd' && input != 'f'){
			cout << "Error! Input type not accepted. Please reinput: ";
			cin >> input;
			cin.ignore(256, '\n');
		} else {
			valid = true;
		}
	}

	return;
}

void Game::direction_checker(char& input){
	bool valid = false;
	while (valid == false){
		if (input != 'w' && input != 'a' && input != 's' && input != 'd'){
			cout << "Error! Input type not accepted. Please reinput: ";
			cin >> input;
			cin.ignore(256, '\n');
		} else {
			valid = true;
		}
	}

	return;
}

//Event setups

void Game::wumpus_setup(){
	bool fullWumpus = false;
	while (fullWumpus == false){
		int x_random = rand() % (this->width);
		int y_random = rand() % (this->length);
		if (this->gameboard[y_random][x_random].get_Emptiness() == true) { //if the room is not empty
            Wumpus* wumpusEvent = new Wumpus; //due to abstract class
            this->gameboard[y_random][x_random].setEvent(wumpusEvent); //create wumpus object and set it to that
			this->gameboard[y_random][x_random].set_Emptiness(false);
			this->gameboard[y_random][x_random].set_Event_bool(true);
			this->gameboard[y_random][x_random].set_Wumpus_bool(true);
			this->gameboard[y_random][x_random].set_Symbol('W');
			fullWumpus = true;
		}
	}
}

void Game::bats_setup(){
	bool Bats1 = false;
	while (Bats1 == false){
		int x_random = rand() % (this->width);
		int y_random = rand() % (this->length);
		if (this->gameboard[y_random][x_random].get_Emptiness() == true) { 
            Bats* bat1Event = new Bats; //due to abstract class
            this->gameboard[y_random][x_random].setEvent(bat1Event); 
			this->gameboard[y_random][x_random].set_Emptiness(false);
			this->gameboard[y_random][x_random].set_Event_bool(true);
			this->gameboard[y_random][x_random].set_Bats_bool(true);
			this->gameboard[y_random][x_random].set_Symbol('B');
			Bats1 = true;
		}
	}

	bool Bats2 = false;
	while (Bats2 == false){
		int x_random = rand() % (this->width);
		int y_random = rand() % (this->length);
		if (this->gameboard[y_random][x_random].get_Emptiness() == true) { 
            Bats* bat2Event = new Bats; //due to abstract class
            this->gameboard[y_random][x_random].setEvent(bat2Event);
			this->gameboard[y_random][x_random].set_Emptiness(false);
			this->gameboard[y_random][x_random].set_Event_bool(true);
			this->gameboard[y_random][x_random].set_Bats_bool(true);
			this->gameboard[y_random][x_random].set_Symbol('B');
			Bats2 = true;
		}
	}	
}

void Game::gold_setup(){
	bool fullGold = false;
	while (fullGold == false){
		int x_random = rand() % (this->width);
		int y_random = rand() % (this->length);
		if (this->gameboard[y_random][x_random].get_Emptiness() == true) { //if the room is not empty
            Gold* goldEvent = new Gold; //due to abstract class
            this->gameboard[y_random][x_random].setEvent(goldEvent); //create wumpus object and set it to that
			this->gameboard[y_random][x_random].set_Emptiness(false);
			this->gameboard[y_random][x_random].set_Event_bool(true);
			this->gameboard[y_random][x_random].set_Gold_bool(true);
			this->gameboard[y_random][x_random].set_Symbol('G');
			fullGold = true;
		}
	}
}

void Game::stalactites_setup(){
	bool Stal1 = false;
	while (Stal1 == false){
		int x_random = rand() % (this->width);
		int y_random = rand() % (this->length);
		if (this->gameboard[y_random][x_random].get_Emptiness() == true) { 
            Stalactites* stal1Event = new Stalactites; //due to abstract class
            this->gameboard[y_random][x_random].setEvent(stal1Event); 
			this->gameboard[y_random][x_random].set_Emptiness(false);
			this->gameboard[y_random][x_random].set_Event_bool(true);
			this->gameboard[y_random][x_random].set_Stalactites_bool(true);
			this->gameboard[y_random][x_random].set_Symbol('S');
			Stal1 = true;
		}
	}
	bool Stal2 = false;
	while (Stal2 == false){
		int x_random = rand() % (this->width);
		int y_random = rand() % (this->length);
		if (this->gameboard[y_random][x_random].get_Emptiness() == true) { 
            Stalactites* stal2Event = new Stalactites; //due to abstract class
            this->gameboard[y_random][x_random].setEvent(stal2Event);
			this->gameboard[y_random][x_random].set_Emptiness(false);
			this->gameboard[y_random][x_random].set_Event_bool(true);
			this->gameboard[y_random][x_random].set_Stalactites_bool(true);
			this->gameboard[y_random][x_random].set_Symbol('S');
			Stal2 = true;
		}
	}	
}

void Game::player_setup(){ //Spawns player in random location
	bool fullPlayer = false;
	while (fullPlayer == false){
		int x_random = rand() % (this->width);
		int y_random = rand() % (this->length);
		if (this->gameboard[y_random][x_random].get_Emptiness() == true) {
			this->adventurer.setPosition(x_random, y_random);
			this->escaperopeX = x_random;
			this->escaperopeY = y_random;
			fullPlayer = true;
		}
	}
}

void Game::stalactite_event(){
	int chance = rand() % 2;

	if (chance == 0){
		cout << "A stalactite falls and crushes you!" << endl;
		this->player_dead = true;
	}
}

void Game::gold_event(int x, int y){
	this->gameboard[y][x].emptyEvent(this->gameboard[y][x].getEvent());
	this->gameboard[y][x].set_Emptiness(true);
	this->gameboard[y][x].set_Event_bool(false);
	this->gameboard[y][x].set_Gold_bool(false);
	this->gameboard[y][x].set_Symbol('0');
	adventurer.setCarryingGold(true);
	cout << "*** You have picked up the gold!! ***" << endl;
}

void Game::bat_event(){
	cout << "Super bats made you confused!" << endl;
	this->player_confusion = 5;
	this->is_confused = true;
}

//Note: you need to modify this function
void Game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;
	
	string line = "";
	for (int i = 0; i < this->width; ++i)
		line += "-----";

	for (int i = 0; i < this->length; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->width; ++j)
		{
			bool playerDisplayed = false;

			if (j == this->adventurer.getX() && i == this->adventurer.getY()){
				cout << "*";
				playerDisplayed = true;
			} else cout << " ";
			
			if (this->gameboard[i][j].get_Emptiness() == true){
				cout << "  ||";
			} else if (this->debug_view == true && playerDisplayed == false){
				this->gameboard[i][j].cout_Symbol();
			} else cout << "  ||";
		}
		cout << endl;
	}
	cout << line << endl;

	if (this->is_confused == true){
		cout << "You are confused for " << this->player_confusion << " more turns." << endl;
	}
}

bool Game::check_win() const{
	//check if game over/win
	if (this->player_win == true){
		return true;
	}
	if (this->player_dead == true){
		cout << "=================================" << endl;
		cout << "Game over! Better luck next time." << endl;
		return true;
	}
	return false;
}

void Game::move_up() {
	int x = this->adventurer.getX();
	int y = this->adventurer.getY();

	if ((this->adventurer.getY() - 1) < 0) {//If the adventurer will go outta bounds
		cout << "Error! Out of bounds! Do something else." << endl;
	} else {
		y = y - 1;
		adventurer.setPosition(x, y);
	}

	return;
}

void Game::move_down() {
	int x = this->adventurer.getX();
	int y = this->adventurer.getY();

	if ((this->adventurer.getY() + 1) > this->length - 1) {//If the adventurer will go outta bounds
		cout << "Error! Out of bounds! Do something else." << endl;
	} else {
		y = y + 1;
		adventurer.setPosition(x, y);
	}
	
	return;
}

void Game::move_left() {
	int x = this->adventurer.getX();
	int y = this->adventurer.getY();

	if ((this->adventurer.getX() - 1) < 0) {//If the adventurer will go outta bounds
		cout << "Error! Out of bounds! Do something else." << endl;
	} else {
		x = x - 1;
		adventurer.setPosition(x, y);
	}
	
	return;
}

void Game::move_right() {
	int x = this->adventurer.getX();
	int y = this->adventurer.getY();

	if ((this->adventurer.getX() + 1) > this->width - 1) {//If the adventurer will go outta bounds
		cout << "Error! Out of bounds! Do something else." << endl;
	} else {
		x = x + 1;
		adventurer.setPosition(x, y);
	}
	
	return;
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;

	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');
	direction_checker(dir);

	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room
	//generate a random number from 0-3, if the number is not 0, then move
	int chance = rand() % 4;

	if (chance != 0){
		cout << "The wumpus jumps to the sound of the arrow..." << endl;
		for (int i = 0; i < this->length; i++){
			for (int j = 0; j < this->width; j++){
				if (this->gameboard[i][j].get_Wumpus_bool() == true){
					this->gameboard[i][j].emptyEvent(this->gameboard[i][j].getEvent());
					this->gameboard[i][j].set_Emptiness(true);
					this->gameboard[i][j].set_Event_bool(false);
					this->gameboard[i][j].set_Wumpus_bool(false);
					this->gameboard[i][j].set_Symbol('0');
					wumpus_setup();
				}
			}
		}
	}

	return;
}

void Game::wumpus_command(int wumpus_y, int wumpus_x){
	Wumpus* wumpusEvent = new Wumpus; //due to abstract class
	this->gameboard[wumpus_y][wumpus_x].setEvent(wumpusEvent); //create wumpus object and set it to that
	this->gameboard[wumpus_y][wumpus_x].set_Emptiness(false);
	this->gameboard[wumpus_y][wumpus_x].set_Event_bool(true);
	this->gameboard[wumpus_y][wumpus_x].set_Wumpus_bool(true);
	this->gameboard[wumpus_y][wumpus_x].set_Symbol('W');

	return;
}

void Game::wumpus_walk(){
	//Wumpus no longer slumbers, he walks now
	int wumpus_x;
	int wumpus_y;

	bool wumpus_moved = false;

	for (int i = 0; i < this->length; i++){
		for (int j = 0; j < this->width; j++){
			if (this->gameboard[i][j].get_Wumpus_bool() == true){
				this->gameboard[i][j].emptyEvent(this->gameboard[i][j].getEvent());
				this->gameboard[i][j].set_Emptiness(true);
				this->gameboard[i][j].set_Event_bool(false);
				this->gameboard[i][j].set_Wumpus_bool(false);
				this->gameboard[i][j].set_Symbol('0');
				wumpus_y = i;
				wumpus_x = j;
			}
		}
	}

	while (wumpus_moved == false){
		int chance = (rand() % 8) + 1; //generates number from 1-8
		switch (chance) {
			case 1:
				if ((wumpus_y - 1) >= 0)
					if (this->gameboard[wumpus_y - 1][wumpus_x].get_Event_bool() == false){
						wumpus_command((wumpus_y - 1), wumpus_x);
						wumpus_moved = true;
					}

				break;
			case 2:
				if ((wumpus_y - 1) >= 0 && (wumpus_x - 1) >= 0)
					if (this->gameboard[wumpus_y - 1][wumpus_x - 1].get_Event_bool() == false){
						wumpus_command((wumpus_y - 1), (wumpus_x - 1));
						wumpus_moved = true;
					}
				break;
			case 3:
				if ((wumpus_x - 1) >= 0)
					if (this->gameboard[wumpus_y][wumpus_x - 1].get_Event_bool() == false){
						wumpus_command(wumpus_y, (wumpus_x - 1));
						wumpus_moved = true;
					}
				break;
			case 4:
				if ((wumpus_y + 1) <= this->length - 1)
					if (this->gameboard[wumpus_y + 1][wumpus_x].get_Event_bool() == false){
						wumpus_command((wumpus_y + 1), wumpus_x);
						wumpus_moved = true;
					}	
				break;
			case 5:
				if ((wumpus_y + 1) <= this->length - 1 && (wumpus_x + 1) <= this->width - 1)
					if (this->gameboard[wumpus_y + 1][wumpus_x + 1].get_Event_bool() == false){
						wumpus_command((wumpus_y + 1), (wumpus_x + 1));
						wumpus_moved = true;
					}	
				break;
			case 6:
				if ((wumpus_x + 1) <= this->width - 1)
					if (this->gameboard[wumpus_y][wumpus_x + 1].get_Event_bool() == false){
						wumpus_command(wumpus_y, (wumpus_x + 1));
						wumpus_moved = true;
					}
				break;
			case 7:
				if ((wumpus_y - 1) >= 0 && (wumpus_x + 1) <= this->width - 1)
					if (this->gameboard[wumpus_y - 1][wumpus_x + 1].get_Event_bool() == false){
						wumpus_command((wumpus_y - 1), (wumpus_x + 1));
						wumpus_moved = true;
					}
				break;
			case 8:
				if ((wumpus_y + 1) <= this->length - 1 && (wumpus_x - 1) >= 0) 
					if (this->gameboard[wumpus_y + 1][wumpus_x - 1].get_Event_bool() == false){
						wumpus_command((wumpus_y + 1), (wumpus_x - 1));
						wumpus_moved = true;
					}
				break;
		}
	}
	return;
}

void Game::fire_arrow(){
	// The player may fire arrow...
	if (this->num_arrows > 0){ //checks if player has no more arrows left
		char dir = get_dir();
		bool hit = false;
		int x = adventurer.getX();
		int y = adventurer.getY();
		this->num_arrows--;
		
		if (dir == 'w'){
			for (int i = y; i >= 0; i--){
				if (this->gameboard[i][x].get_Wumpus_bool() == true){
					hit = true;
				}
			}
		} else if (dir == 's'){
			for (int i = y; i < this->length; i++){
				if (this->gameboard[i][x].get_Wumpus_bool() == true){
					hit = true;
				}
			}
		} else if (dir == 'a'){
			for (int i = x; i >= 0; i--){
				if (this->gameboard[y][i].get_Wumpus_bool() == true){
					hit = true;
				}
			}
		} else if (dir == 'd'){
			for (int i = x; i < this->width; i++){
				if (this->gameboard[y][i].get_Wumpus_bool() == true){
					hit = true;
				}
			}
		}

		if (hit == true) {
			cout << "=========================================" << endl;
			cout << "You have shot the Wumpus! You win!!!" << endl;
			this->player_win = true;
			return;
			} else {
				cout << "Drats! Missed!" << endl;
				wumpus_move();
			}
	} else 
		cout << "You have run out of arrows..." << endl;
	
	return;
}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
	if (this->is_confused == false){
		switch(c){
			case 'w':
				Game::move_up();
				break;
			case 'a':
				Game::move_left();
				break;
			case 's':
				Game::move_down();
				break;
			case 'd':
				Game::move_right();
				break;
		}
	} else if (this->is_confused == true){
		switch(c){
			case 's':
				Game::move_up();
				break;
			case 'd':
				Game::move_left();
				break;
			case 'w':
				Game::move_down();
				break;
			case 'a':
				Game::move_right();
				break;
		}
		player_confusion--;
	}
}

char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	
	cin >> c;
	cin.ignore(256, '\n');
	move_checker(c);
	cout << endl << "------------------------------------" << endl << endl;

	return c;
}

void Game::check_percept(){
	int x = adventurer.getX();
	int y = adventurer.getY();

	//Play Percept... making sure that my program does not overead the array
	if ((y - 1) >= 0)
	if (this->gameboard[y - 1][x].get_Event_bool() == true)
		this->gameboard[y - 1][x].play_Percept();

	if ((y - 1) >= 0 && (x - 1) >= 0)
	if (this->gameboard[y - 1][x - 1].get_Event_bool() == true)
		this->gameboard[y - 1][x - 1].play_Percept();

	if ((x - 1) >= 0)
	if (this->gameboard[y][x - 1].get_Event_bool() == true)
		this->gameboard[y][x - 1].play_Percept();

	if ((y + 1) <= this->length - 1)
	if (this->gameboard[y + 1][x].get_Event_bool() == true)
		this->gameboard[y + 1][x].play_Percept();

	if ((y + 1) <= this->length - 1 && (x + 1) <= this->width - 1)
	if (this->gameboard[y + 1][x + 1].get_Event_bool() == true)
		this->gameboard[y + 1][x + 1].play_Percept();

	if ((x + 1) <= this->width - 1)
	if (this->gameboard[y][x + 1].get_Event_bool() == true)
		this->gameboard[y][x + 1].play_Percept();

	if ((y - 1) >= 0 && (x + 1) <= this->width - 1)
	if (this->gameboard[y - 1][x + 1].get_Event_bool() == true)
		this->gameboard[y - 1][x + 1].play_Percept();

	if ((y + 1) <= this->length - 1 && (x - 1) >= 0)
	if (this->gameboard[y + 1][x - 1].get_Event_bool() == true)
		this->gameboard[y + 1][x - 1].play_Percept();

	return;
}

void Game::check_event(){
	int x = adventurer.getX();
	int y = adventurer.getY();

	//Play Event
	if (this->gameboard[y][x].get_Event_bool() == true){
		this->gameboard[y][x].play_Event();
	}
	
	if (this->gameboard[y][x].get_Wumpus_bool() == true){
		this->player_dead = true;
	}

	if (this->gameboard[y][x].get_Stalactites_bool() == true){
		stalactite_event();
	}

	if (this->gameboard[y][x].get_Bats_bool() == true){
		bat_event();
	}

	if (this->gameboard[y][x].get_Gold_bool() == true){
		gold_event(x, y);
	}

	if (this->escaperopeX == x && this->escaperopeY == y && adventurer.getCarryingGold() == true){
		cout << "***You have successfully escaped with the gold!***" << endl;
		player_win = true;
	}
}

//Note: you need to modify this function
void Game::play_game(int w, int l, bool d){
	Game::set_up(l, w);
	this->debug_view = d;
	char input, arrow_input;
	
	while (Game::check_win() == false){
		if (this->player_confusion > 0)
			this->is_confused = true;
		else
			this->is_confused = false;

		//print game board
		Game::display_game();

		//display percerts around player's location
		//Your code here:
		check_percept();

		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		Game::move(input);

		//3. may or may not encounter events
		//Your code here:
		wumpus_walk();
		check_event();
	}
	return;
}