#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"

//Stalactites Interface

class Stalactites : public Event
{
private:

public:
    /*********************************************************************
    ** Function: Stalactites()
    ** Description: Stalactites default constructor
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Declares Stalactites
    *********************************************************************/ 
    Stalactites();

    /*********************************************************************
    ** Function: ~Stalactites
    ** Description: Stalactites virtual destructor
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: None
    *********************************************************************/ 
    ~Stalactites();

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
