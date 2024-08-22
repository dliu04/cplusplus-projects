#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 

#include "event.h"
#include "room.h"
#include "player.h"

using namespace std;

//Game interface 
class Game
{
private:
	//Create a player
	Player adventurer;

	//declare a 2D vector of Room objects:
	vector <vector<Room> > gameboard;

	//Note to self: vectors function like gameboard[row][column]
	//or gameboard[length][width] or better, gameboard[y][x]
	
	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of arrows remaining
	bool debug_view;		//debug mode or not
	bool debug_quit;		//debug quit
	bool is_confused;
	int player_confusion;

	int escaperopeX;
	int escaperopeY;

	//feel free to add more variables...
	bool player_dead;
	bool player_win;

public:

	/*********************************************************************
	** Function: Game()
	** Description: Game constructor that initializes default variables
	** Parameters: None
	** Pre-Conditions: Game object is created
	** Post-Conditions: None
	*********************************************************************/ 
	Game();
	
	/*********************************************************************
	** Function: ~Game()
	** Description: Game destructor that deletes all dynamically allocated memory
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: Game object goes out of scope
	*********************************************************************/ 
	~Game();

	/*********************************************************************
	** Function: get_gameboard() 
	** Description: Gets and returns the game onject
	** Parameters: None
	** Pre-Conditions: Game object exists
	** Post-Conditions: Returns game object
	*********************************************************************/ 
	Game get_gameboard();

	/*********************************************************************
	** Function: set_up(int, int)
	** Description: Sets the game up when called
	** Parameters: Width, length
	** Pre-Conditions: Take user input for width and length
	** Post-Conditions: The gameboard, events and stats are set up correctly
	*********************************************************************/ 
	void set_up(int, int);

	void move_checker(char&);

	void direction_checker(char&);

	//Event setups

	/*********************************************************************
	** Function: wumpus_setup()
	** Description: Sets the wumpus event up
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: Wumpus event is assigned to a random room object
						on the board
	*********************************************************************/ 
	void wumpus_setup();

	/*********************************************************************
	** Function: bats_setup()
	** Description: Sets the Bats event up
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: Two Bats event is assigned to a random room object
						on the board
	*********************************************************************/ 
	void bats_setup();

	/*********************************************************************
	** Function: gold_setup()
	** Description: Sets the gold event up
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: Gold event is assigned to a random room object
						on the board
	*********************************************************************/ 
	void gold_setup();

	/*********************************************************************
	** Function: stalactites_setup()
	** Description: Sets the stalactite event up
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: Stalactite event is assigned to a random room object
						on the board
	*********************************************************************/ 
	void stalactites_setup();

	/*********************************************************************
	** Function: player_setup()
	** Description: Sets the player event up
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: Player event is assigned to a random room object
						on the board
	*********************************************************************/ 
	void player_setup();

	/*********************************************************************
	** Function: stalactite_event()
	** Description: Plays the corresponding encounter
	** Parameters: None
	** Pre-Conditions: Proper establishment of the event
	** Post-Conditions: The corresponding encounter takes place
	*********************************************************************/ 
	void stalactite_event();

	/*********************************************************************
	** Function: gold_event()
	** Description: Plays the corresponding encounter
	** Parameters: Gold event position
	** Pre-Conditions: Proper establishment of the event
	** Post-Conditions: The corresponding encounter takes place and the
						gold event is then deleted
	*********************************************************************/ 
	void gold_event(int, int);

	/*********************************************************************
	** Function: bat_event()
	** Description: Plays the corresponding encounter
	** Parameters: None
	** Pre-Conditions: Proper establishment of the event
	** Post-Conditions: The corresponding encounter takes place
	*********************************************************************/ 
	void bat_event();

	/*********************************************************************
	** Function: display_game()
	** Description: Displays the game board for the width and length,
					and either couts a space or the corresponding 
					assigned character for the event
	** Parameters: None
	** Pre-Conditions: Game vector is created with width and length
	** Post-Conditions: The game is displayed
	*********************************************************************/ 
	void display_game() const;

	/*********************************************************************
	** Function: check_win()
	** Description: Checks if the player has won. Exits the game if true.
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: None
	*********************************************************************/ 
	bool check_win() const;

	/*********************************************************************
	** Function: get_dir()
	** Description: Gets the direction of the arrow.
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: None
	*********************************************************************/ 
	char get_dir();

	/*********************************************************************
	** Function: wumpus_move()
	** Description: Moves the wumpus to a random empty room or on top of 
					the player.
	** Parameters: None
	** Pre-Conditions: The wumpus is triggered to move
	** Post-Conditions: Original wumpus event deleted, new wumpus event
						created elsewhere
	*********************************************************************/ 
	void wumpus_move();

	/*********************************************************************
	** Function: wumpus_command(int, int)
	** Description: Makes the Wumpus walk to a designated X and Y value.
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: Updates the Wumpus' position
	*********************************************************************/
	void wumpus_command(int, int);

	/*********************************************************************
	** Function: wumpus_walk()
	** Description: Makes the Wumpus walk every turn.
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: Wumpus walks to an adjacent room.
	*********************************************************************/
	void wumpus_walk();

	/*********************************************************************
	** Function: fire_arrow()
	** Description: Calls the get_dir and then runs a for loop to check all 
					rooms adjacent to the arrow.
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: Couts if the wumpus is hit or not
	*********************************************************************/ 
	void fire_arrow();

	/*********************************************************************
	** Function: move_up()
	** Description: Moves the player up.
	** Parameters: None
	** Pre-Conditions: Player input
	** Post-Conditions: Player moves up
	*********************************************************************/ 
	void move_up();

	/*********************************************************************
	** Function: move_down()
	** Description: Moves the player down.
	** Parameters: None
	** Pre-Conditions: Player input
	** Post-Conditions: Player moves down
	*********************************************************************/ 
	void move_down();

	/*********************************************************************
	** Function: move_left()
	** Description: Moves the player left.
	** Parameters: None
	** Pre-Conditions: Player input
	** Post-Conditions: Player moves left
	*********************************************************************/ 
	void move_left();

	/*********************************************************************
	** Function: move_right()
	** Description: Moves the player right.
	** Parameters: None
	** Pre-Conditions: Player input
	** Post-Conditions: Player moves right
	*********************************************************************/ 
	void move_right();

	/*********************************************************************
	** Function: move(char)
	** Description: Takes user input and calls a corresponding move function.
	** Parameters: char of the direction
	** Pre-Conditions: User inputs a char
	** Post-Conditions: Player moves
	*********************************************************************/ 
	void move(char);

	/*********************************************************************
	** Function: get_input()
	** Description: Gets the player's input to move
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: Char is returned
	*********************************************************************/ 
	char get_input();

	/*********************************************************************
	** Function: check_percept()
	** Description: Checks for a precept within the player's vicinity.
	** Parameters: None
	** Pre-Conditions: Player object exists
	** Post-Conditions: Calls corresponding Event percepts
	*********************************************************************/ 
	void check_percept();

	/*********************************************************************
	** Function: check_event()
	** Description: Checks if there is an event at the current X and Y coordinate.
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: If there is an event, play the encounter. If there isn't,
						do nothing.
	*********************************************************************/ 
	void check_event();

	/*********************************************************************
	** Function: play_game(int, int, bool)
	** Description: Plays the game.
	** Parameters: Width, length, and debug mode
	** Pre-Conditions: The parameters have been retrieved from the player.
	** Post-Conditions: The game is then played.
	*********************************************************************/ 
	void play_game(int, int, bool);
	
};
#endif