/*********************************************************************
** Program Filename: main.cpp
** Author: Dylan Liu
** Date: 11/27/23
** Description: Hunt the Wumpus game!
** Input: User's width and length
** Output: The game
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
	//set the random seed
	srand(time(NULL));

	//Intitialize default values
	int wid = 5, len = 5;
	char userChoice;
	bool debug = false;
	bool valid = false;
	Game g;

	//get two inputs: size of the cave(wid and len)
	//make sure to error handle later
	cout << "Please enter the width of the room (4-50): ";
	cin >> wid;
	while (valid == false){
		if (wid > 50 || wid < 4){
			cout << "Error! Please reinput: ";
			cin >> wid;
		} else valid = true;
	}

	valid = false;
	cout << "Please enter the length of the room (4-50): ";
	cin >> len;
	while (valid == false){
		if (len > 50 || len < 4){
			cout << "Error! Please reinput: ";
			cin >> len;
		} else valid = true;
	}

	//get the 3rd input --> debug mode or not
	valid = false;
	cout << "Would you like to run in debug mode? (y/n): ";
	cin >> userChoice;
	while (valid == false){
		if (userChoice == 'y' || userChoice == 'n'){
			valid = true;
		} else {
			cout << "Error! Please reinput: ";
			cin >> userChoice;
		}
	}

	if (userChoice == 'y'){
		debug = true;
	} else if (userChoice == 'n'){
		debug = false;
	}

	//Play game
	g.play_game(wid, len, debug);

	return 0;
}