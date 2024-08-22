// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player
{
private:
    int x; // Player's x-coordinate
    int y; // Player's y-coordinate
    bool isCarryingGold; // Flag to indicate if the player is carrying gold

public:
    /*********************************************************************
    ** Function: Player()
    ** Description: Player default constructor, establishes default values.
    ** Parameters: None
    ** Pre-Conditions: Player object is created
    ** Post-Conditions: Player default values are created
    *********************************************************************/ 
    Player(); // Constructor

    /*********************************************************************
    ** Function: setPosition
    ** Description: Sets the player's position every time it is updated.
    ** Parameters: Player's x coord and y coord
    ** Pre-Conditions: Player is updated or created
    ** Post-Conditions: X and Y coordinates of the class object is updated
    *********************************************************************/ 
    void setPosition(int, int); // Set player's position

    /*********************************************************************
    ** Function: getX()
    ** Description: Gets the player's X value.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Returns player's X value.
    *********************************************************************/ 
    int getX() const; // Get player's x-coordinate

    /*********************************************************************
    ** Function: getY()
    ** Description: Gets the player's Y value.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Returns player's Y value.
    *********************************************************************/ 
    int getY() const; // Get player's y-coordinate

    /*********************************************************************
    ** Function: setCarryingGold()
    ** Description: Sets the player's gold status
    ** Parameters: boolean variable
    ** Pre-Conditions: The player either has or doesn't have the gold
    ** Post-Conditions: Player's gold carrying is either true or false
    *********************************************************************/ 
    void setCarryingGold(bool); // Set carrying gold status

    /*********************************************************************
    ** Function: getCarryingGold() const
    ** Description: Returns the gold carrying status of the player
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Gold carrying status is returned
    *********************************************************************/ 
    bool getCarryingGold() const; // Get carrying gold status
};

#endif