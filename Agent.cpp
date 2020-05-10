#include <iostream>
#include <string>
#include <vector>
#include "Agent.h"
#include "Menu.h"
#include "Controller.h"
#include "Ticket.h"

using namespace std;

Agent::Agent(string username, string password) : User(username, password) { userType = "Agent"; };

Agent::Agent(User U):User(U){}   


void Agent::mainMenuDisplay()
{
    vector<string> commands = {"Create ticket", "Look at created tickets", "Logout", "Quit"};
    Menu mainMenu(commands, pleaseSelect);
    mainMenu.display(selector);
    bool newTicket = false;
    switch (selector)
    {
    case 0:
        newTicket = true;
        break;

    default:
        break;
    };
    if (newTicket)
    {
        Ticket newTicket(id);
        newTicket.save();
        newTicket = false;
        mainMenuDisplay();
    };
}