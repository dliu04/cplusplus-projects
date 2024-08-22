#ifndef EVENT_H
#define EVENT_H 

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{
protected:
    char eventSymbol;
	
public:
    /*********************************************************************
    ** Function: virtual void precept() const = 0
    ** Description: A pure virtual function that transforms this class into
                    an abstract class
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The function will be modified depending on the class call
    *********************************************************************/ 
    virtual void percept() const = 0;

    /*********************************************************************
    ** Function: virtual void encounter() const = 0
    ** Description: A pure virtual function that transforms this class into
                    an abstract class
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The function will be modified depending on the class call,
                        which will play specific encounter messages
    *********************************************************************/ 
    virtual void encounter() const = 0;
};
#endif