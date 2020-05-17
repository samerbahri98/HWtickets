#include <iostream>
#include <string>
#include <vector>
#include "Agent.h"
#include "User.h"
#include "Queue.h"
#include "Menu.h"
#include "Controller.h"
#include "Ticket.h"

using namespace std;
//Constructor
Agent::Agent(string username, string password) : User(username, password) { userType = "Agent"; };
//copy Constructor
Agent::Agent(const User &U) : User(U) { userType = "Agent"; }
//Override from User Class
void Agent::mainMenuDisplay() const
{
    vector<string> commands = {"Display new tickets", "Display my tickets", "Display unassigned tickets", "Update new Tickets", "Update my tickets", "Update unassigned tickets", "Quit"};
    Menu mainMenu(commands, pleaseSelect);
    mainMenu.display(selector);

    switch (selector)
    {
    case 0:                       //Display new tickets
        ticketsDisplay(4, "New"); //column 4(priority)=New
        break;
    case 1:                               //Display my tickets
        ticketsDisplay(2, to_string(id)); //column 2(Agent)=id
        break;
    case 2:                               //Display unassigned tickets
        ticketsDisplay(2, to_string(-1)); //column 2(Agent)<0
        break;
    case 3:                      //Update new Tickets
        ticketsUpdate(4, "New"); //column 4(priority)=New
        break;
    case 4:                              //Update my tickets
        ticketsUpdate(2, to_string(id)); //column 2(Agent)=id
        break;
    case 5:                              //Update unassigned tickets
        ticketsUpdate(2, to_string(-1)); //column 2(Agent)<0
        break;
    case 6: //Quit
        isLoggedIn = false;
        break;
    default:
        cout << impossible << endl;
        break;
    };

    return;
}