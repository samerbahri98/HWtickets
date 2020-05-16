#include <iostream>
#include <string>
#include <vector>
#include "Client.h"
#include "Menu.h"
#include "Controller.h"
#include "Ticket.h"
#include "Queue.h"

using namespace std;

Client::Client(string username, string password) : User(username, password) { userType = "Client"; };

Client::Client(const User &U) : User(U) { userType = "Client"; };

Client::~Client() {}

void Client::mainMenuDisplay() const
{
    int selector;
    vector<string> commands = {"Create ticket", "Look at created tickets", "Quit"};
    Menu mainMenu(commands, pleaseSelect);
    mainMenu.display(selector);
    bool newTicketNeeded = false;

    switch (selector)
    {
    case 0:
        newTicketNeeded = true;
        break;
    case 1:
        ticketsDisplay(1, to_string(id));
        break;
    case 2:
        isLoggedIn = false;
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