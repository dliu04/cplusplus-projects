#ifndef ROOM_H
#define ROOM_H 

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room 
{
private:
    Event* event;
    bool isEmpty;
    bool hasEvent;
    bool hasWumpus;
    bool hasStalactites;
    bool hasBats;
    bool hasGold;
    char symbol;

public:
    /*********************************************************************
    ** Function: Room()
    ** Description: Default constructor for room object
    ** Parameters: None
    ** Pre-Conditions: Room object is created
    ** Post-Conditions: Default values are initialized
    *********************************************************************/ 
    Room();

    /*********************************************************************
    ** Function: ~Room()
    ** Description: Destructor for the room object
    ** Parameters: None
    ** Pre-Conditions: Room object goes out of scope
    ** Post-Conditions: Dynamically allocated memory is freed
    *********************************************************************/ 
    ~Room();

    /*********************************************************************
    ** Function: setEvent(Event*)
    ** Description: Sets an Event pointer to the room object
    ** Parameters: Event pointer
    ** Pre-Conditions: None
    ** Post-Conditions: Event pointer is established
    *********************************************************************/ 
    void setEvent(Event*); // Set a new event in the room

    /*********************************************************************
    ** Function: emptyEvent(Event*)
    ** Description: Deletes the event and frees the memory
    ** Parameters: Event pointer
    ** Pre-Conditions: None
    ** Post-Conditions: Event is deleted and the variables are reset
    *********************************************************************/ 
    void emptyEvent(Event*);

    /*********************************************************************
    ** Function: getEvent() const
    ** Description: Gets the event of the specific room
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Returns the event pointer pointing to that event
    *********************************************************************/ 
    Event* getEvent() const; // Getter to check for event in the room

    /*********************************************************************
    ** Function: cout_Symbol() const
    ** Description: Couts the corresponding room symbol
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: None
    *********************************************************************/ 
    void cout_Symbol() const;

    /*********************************************************************
    ** Function: set_Symbol(char)
    ** Description: Sets the room symbol to an event-specific character
    ** Parameters: Event character
    ** Pre-Conditions: None
    ** Post-Conditions: Room is assigned a certain character
    *********************************************************************/ 
    void set_Symbol(char);

    /*********************************************************************
    ** Function: get_Emptiness() const
    ** Description: Gets the emptiness/fullness of a room.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: True or false is returned for if the room is/isn't empty.
    *********************************************************************/ 
    bool get_Emptiness() const;

    /*********************************************************************
    ** Function: set_Emptiness(bool)
    ** Description: Sets the room's emptiness.
    ** Parameters: A boolean variable
    ** Pre-Conditions: None
    ** Post-Conditions: True or false will change the Room's emptiness
    *********************************************************************/ 
    void set_Emptiness(bool);

    /*********************************************************************
    ** Function: get_Event_bool
    ** Description: Gets the event's boolean variable to check if a room has
                    an event
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Returns whether or not the room has an event
    *********************************************************************/ 
    bool get_Event_bool();

    /*********************************************************************
    ** Function: set_Event_bool(bool)
    ** Description: Sets the room's hasEvent bool to true or false
    ** Parameters: Boolean variable
    ** Pre-Conditions: None
    ** Post-Conditions: room's hasEvent bool is either true or false
    *********************************************************************/ 
    void set_Event_bool(bool);

    /*********************************************************************
    ** Function: get_Wumpus_bool()
    ** Description: Checks if a room has a Wumpus in it. If yes, then return a true
    ** Parameters: None
    ** Pre-Conditions: Wumpus is in a Room
    ** Post-Conditions: Room state is returned as true/false depending on whether 
                        or not it contains a Wumpus
    *********************************************************************/ 
    bool get_Wumpus_bool();

    /*********************************************************************
    ** Function: set_Wumpus_bool(bool);
    ** Description: Sets the Wumpus boolean to true or false
    ** Parameters: Boolean variable
    ** Pre-Conditions: None
    ** Post-Conditions: Wumpus bool is now either true or false
    *********************************************************************/ 
    void set_Wumpus_bool(bool);

    /*********************************************************************
    ** Function: get_Stalactites_bool()
    ** Description: Gets and returns if the room has stalactites
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Returns whether or not there are Stalactites
    *********************************************************************/ 
    bool get_Stalactites_bool();

    /*********************************************************************
    ** Function: set_Stalactites_bool(bool);
    ** Description: Sets the Stalactites boolean to true or false
    ** Parameters: Boolean variable
    ** Pre-Conditions: None
    ** Post-Conditions: Stalactites bool is now either true or false
    *********************************************************************/ 
    void set_Stalactites_bool(bool);

    /*********************************************************************
    ** Function: get_Bats_bool()
    ** Description: Gets and returns if the room has bats
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Returns whether or not there are Bats
    *********************************************************************/  
    bool get_Bats_bool();

    /*********************************************************************
    ** Function: set_Bats_bool(bool);
    ** Description: Sets the Bats boolean to true or false
    ** Parameters: Boolean variable
    ** Pre-Conditions: None
    ** Post-Conditions: Bats bool is now either true or false
    *********************************************************************/ 
    void set_Bats_bool(bool);

    /*********************************************************************
    ** Function: get_Gold_bool()
    ** Description: Gets and returns if the room has gold
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Returns whether or not there are Gold
    *********************************************************************/ 
    bool get_Gold_bool();

    /*********************************************************************
    ** Function: set_Gold_bool(bool);
    ** Description: Sets the Gold boolean to true or false
    ** Parameters: Boolean variable
    ** Pre-Conditions: None
    ** Post-Conditions: Gold bool is now either true or false
    *********************************************************************/ 
    void set_Gold_bool(bool);

    /*********************************************************************
    ** Function: play_Percept()
    ** Description: plays the corresponding percept if player is within range
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Calls the corresponding Event percept function
    *********************************************************************/ 
    void play_Percept();

    /*********************************************************************
    ** Function: play_Event()
    ** Description: plays the corresponding encounter if player is within range
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Calls the corresponding Event encounter function
    *********************************************************************/ 
    void play_Event();
};

#endif 