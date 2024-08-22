#ifndef WUMPUS_H
#define WUMPUS_H 

#include "event.h"

//Wumpus Interface
class Wumpus : public Event
{
private:

public:
    /*********************************************************************
    ** Function: Wumpus()
    ** Description: Wumpus default constructor
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Declares Wumpus
    *********************************************************************/ 
    Wumpus();

    /*********************************************************************
    ** Function: ~Wumpus
    ** Description: Wumpus virtual destructor
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: None
    *********************************************************************/ 
    ~Wumpus();

    /*********************************************************************
    ** Function: void percept() const override
    ** Description: Overrides the Event percept function with a cout statement
                    specific to this class
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Couts percept statement
    *********************************************************************/ 
    virtual void percept() const override;

    /*********************************************************************
    ** Function: void encounter() const override
    ** Description: Overrides the Event encounter function with a cout statement
                    specific to this class
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Couts encounter statement
    *********************************************************************/ 
    virtual void encounter() const override;
};

#endif