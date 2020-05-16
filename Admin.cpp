#include <iostream>
#include <string>
#include <vector>
#include "Agent.h"
#include "Admin.h"
#include "User.h"
#include "Queue.h"
#include "Menu.h"
#include "Controller.h"
#include "Ticket.h"
#include "CSV.h"

using namespace std;

Admin::Admin(string username, string password)
    : User(username, password)
{
    userType = "Admin";
};

Admin::Admin(const User &U) : User(U) { userType = "Admin"; };

void Admin::mainMenuDisplay() const
{
    int selector;
    vector<string> commands = {"Display new tickets",
                               "Display my tickets",
                               "Display unassigned tickets",
                               "Display created tickets",
                               "Display All tickets",
                               "Update new Tickets",
                               "Update my tickets",
                               "Update unassigned tickets",
                               "Update created tickets",
                               "Update All tickets",
                               "Create ticket",
                               "Quit"};
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
        ticketsDisplay(1, to_string(id));
        break;
    case 4:
        ticketsDisplay(-1, "");
        break;
    case 5:
        ticketsUpdate(4, "New");
        break;
    case 6:
        ticketsUpdate(2, to_string(id));
        break;
    case 7:
        ticketsUpdate(2, to_string(-1));
        break;
    case 8:
        ticketsUpdate(1, to_string(id));
        break;
    case 9:
        ticketsUpdate(-1, "");
        break;
    case 10:
        newTicketNeeded = true;
        break;
    case 11:
        isLoggedIn = false;
    default:
        cout << impossible << endl;
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