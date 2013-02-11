#include <iostream>
#include "include/Elevator.h"

using namespace std;

int main()
{
    Elevator CCBuildingA;
    CCBuildingA.SayState();
    while ( cin )
    {
        if ( CCBuildingA.UseElevator ( cin ) )
        {
            CCBuildingA.SayState();
        }
        else
        {
            if ( cin )
            {
                cout << "Enter a valid input:" << endl;
            }
        }
    }
    return 0;
}
