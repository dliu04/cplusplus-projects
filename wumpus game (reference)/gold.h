#ifndef GOLD_H
#define GOLD_H 

#include "event.h"

//Gold Interface

class Gold : public Event
{
private:

public:
    /*********************************************************************
    ** Function: Gold()
    ** Description: Gold default constructor
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Declares Gold
    *********************************************************************/ 
    Gold();

    /*********************************************************************
    ** Function: ~Gold
    ** Description: Gold virtual destructor
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: None
    *********************************************************************/ 
    ~Gold();

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