#ifndef BATS_H
#define BATS_H 

#include "event.h"

//Bats Interface

class Bats : public Event
{
private:

public:
    /*********************************************************************
    ** Function: Bats()
    ** Description: Bats default constructor
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Declares Bats
    *********************************************************************/ 
    Bats();

    /*********************************************************************
    ** Function: ~Bats
    ** Description: Bats virtual destructor
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: None
    *********************************************************************/ 
    ~Bats();

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