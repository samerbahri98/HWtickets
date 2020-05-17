#include <iostream>
#include <string>
#include <vector>
#include "Agent.h"
#include "Queue.h"
#include "Menu.h"
#include "Controller.h"
#include "Ticket.h"
#include "CSV.h"

using namespace std;

Agent::Agent(string username, string password) : User(username, password) { userType = "Agent"; };

Agent::Agent(const User &U) : User(U) { userType = "Agent"; }

void Agent::mainMenuDisplay() const
{
    int selector;
    vector<string> commands = {"Display new tickets", "Display my tickets", "Display unassigned tickets", "Update new Tickets", "Update my tickets", "Update unassigned tickets", "Close"};
    Menu mainMenu(commands, pleaseSelect);
    mainMenu.display(selector);
    bool newTicketNeeded = false;

    switch (selector)
    {
    case 0:
        ticketsDisplay(4, "New");
        break;
    case 1:
        ticketsDisplay(2, to_string(id));
        break;
    case 2:
        ticketsDisplay(2, to_string(-1));
        break;
    case 3:
        ticketsUpdate(4, "New");
        break;
    case 4:
        ticketsUpdate(2, to_string(id));
        break;
    case 5:
        ticketsUpdate(2, to_string(-1));
        break;
    case 6:
        isLoggedIn = false;
        break;
    default:
        cout<<impossible<<endl;
        break;
    };
    if (newTicketNeeded)
    {
        Ticket newTicket(id);
        newTicket.save();
        newTicketNeeded = false;
    };

    return;
}