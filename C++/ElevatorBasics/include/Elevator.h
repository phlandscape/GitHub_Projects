#ifndef ELEVATOR_H
#define ELEVATOR_H

// container includes
#include <string>
#include <list>

// streams includes
#include <iostream>

//other includes
#include <ctime>
#include <algorithm>

/** \brief
 *  Fail Report class
 *  later used to be catched by the caller of the Elevator class
 *  currently the Elevator class itself uses it to state the error occurred
 * \param
 * \param
 * \return
 *
 */
struct Fail
{
public:
    Fail ( const std::string& Event )
        :
        MyEvent ( Event )
    {
    }
    void saywhat()
    {
        if ( MyEvent == "defect" )
        {
            std::cout << "The Elevator is defect, please dial a Technician." << std::endl;
        }
        else if ( MyEvent == "blocked" )
        {
            std::cout << "Something is blocking the Elevator door, please remove it." << std::endl;
        }
        else
        {
            std::cout << "There is an unknown problem with the Elevator please dial a Technician and a Software Engineer." << std::endl;
        }
    }
    std::string what()
    {
        return MyEvent;
    }
    std::string MyEvent;
};
class Elevator
{
// ***** Typedefs & Enums *****
private:
    enum reports
    {
        ABORT = 0 ,
        FAILED = 0 ,
        DONE = 1 ,
        OK = 1
    };
    // using 2^x values for bitwise comparisons
    enum states
    {
        OPEN = 1 ,
        CLOSED = 2 ,
        OPENING = 4 ,
        CLOSING = 8
    };
// ***** Correctness Checks *****
private:
    bool no_interrupts ( const std::string& Event );

// ***** Constructors *****
public:
    Elevator() : mState ( CLOSED ) {};
// ***** Destructor *****
public:
    ~Elevator();

    /** Access state
     * \return The current value of state
     */
// ***** Use class "Elevator" *****
public:                                      // INTERFACE
    bool UseElevator ( std::istream& in );
    int GetState()
    {
        return mState;
    }
    void SayState();
// ***** Command Evaluating *****
private:
    bool StartAction ( const std::string& command, const std::string& Event );

// ***** StateModifier *****
private:
    bool close ( const std::string& Event );
    bool open ( const std::string& Event );
    void SetState ( int val )
    {
        mState = val;
    }
// ***** inline StateChecks *****
private:
    bool is_closing()
    {
        return ( this->GetState() & CLOSING );
    }
    bool is_opening()
    {
        return ( this->GetState() & OPENING );
    }
    bool is_open()
    {
        return ( this->GetState() & OPEN );
    }
    bool is_closed()
    {
        return ( this->GetState() & CLOSED );
    }
// ***** EVENTS *****
private:
    std::string GenerateEvent()
    {
        srand ( time ( NULL ) );
        auto iter = Possible_Events.begin();
        advance ( iter, rand() % Possible_Events.size() );
        return *iter;
    }
// ***** VARIABLES *****
private:
    int mState; // Current State of the Elevator as defined by the enum states
    static const std::string free;
    static const std::string blocked;
    static const std::string defect;
    static const std::list<std::string> Possible_Events;
};
#endif // ELEVATOR_H
