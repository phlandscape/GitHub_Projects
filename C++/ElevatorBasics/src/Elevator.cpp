#include "../include/Elevator.h"

// container include
#include <string>
#include <list>

// streams includes
#include <iostream>

using namespace std;

// static variable definitions
const string Elevator::free ( "free" );
const string Elevator::blocked ( "blocked" );
const string Elevator::defect ( "defect" );

const list<string> Elevator::Possible_Events =
{
    {free}, {free},
    {free}, {free},
    {free}, {free},
    {free}, {free},
    {free}, {free},
    {free}, {free},
    {blocked}, {blocked},
    {defect}
} ;


//***** Destructor *****
Elevator::~Elevator()
{
    //dtor
}
// INTERFACE BEGIN
bool Elevator::UseElevator ( std::istream& in )
{
    // first word is the command

    std::string command;
    if ( in )
    {
        in >> command;
        // generate random event
        string Event =  GenerateEvent();
        return StartAction ( command, Event );
    }
    return FAILED;
}
void Elevator::SayState()
{
    switch ( mState )
    {
    case OPEN:
        cout << "The Elevator is now Open." << endl;
        break;
    case CLOSED:
        cout << "The Elevator is now Closed." << endl;
        break;
    case OPENING:
        cout << "The Elevator is currently in the progress of opening." << endl;
        break;
    case CLOSING:
        cout << "The Elevator is currently in the progress of closing." << endl;
        break;
    default:
        cout << "This should not happen. There is a problem in the Source Code please dial your favorite Software Engineer." << endl;
        exit(ABORT);
    }
}
// INTERFACE END
inline bool Elevator::no_interrupts ( const string& Event )
{
    if ( Event == "free" )
    {
        return OK;
    }
    else
    {
        return ABORT;
    }
}

bool Elevator::close ( const string& Event )
{
    if ( is_open() )
    {
        SetState ( CLOSING );
        SayState();
        if ( no_interrupts ( Event ) )
        {
            SetState ( CLOSED );
            return DONE;
        }
        else
        {
            SetState ( OPEN );
            Fail Happening ( Event );
            Happening.saywhat();
            return FAILED;
        }
    }
    else
    {
        cout << "The Elevator is already closed." << endl;
        return FAILED;
    }
}
bool Elevator::open ( const string& Event )
{
    if ( is_closed() )
    {
        SetState ( OPENING );
        SayState();
        if ( no_interrupts ( Event ) )
        {
            SetState ( OPEN );
            return DONE;
        }
        else
        {
            SetState ( CLOSED );
            Fail Happening ( Event );
            Happening.saywhat();
            return FAILED;
        }
    }
    else
    {
        cout << "The Elevator is already opened." << endl;
        return FAILED;
    }
}
bool Elevator::StartAction ( const std::string& command, const std::string& Event )
{
    if ( command == "open" )
    {
        return  open ( Event );
    }
    if ( command == "close" )
    {
        return  close ( Event );
    }
    return ABORT;
}

