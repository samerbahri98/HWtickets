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

Client::Client(User U) : User(U){};

void Client::createdTickets()
{
    Queue createdQueue("tickets.csv");
    createdQueue.fetch();
    cout << "id|Client|Agent|Priority|Status|Title|Content|" << endl;
    cout<<"---------------------------------------------------------"<<endl;
    createdQueue.filter(1, to_string(id));
    createdQueue.map("users.csv", {1, 2}, 1);
    createdQueue.display();
    cout<<"N/A: Not Assigned"<<endl;
};

void Client::mainMenuDisplay()
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
        createdTickets();
        break;
    case 2:
        exit(EXIT_SUCCESS);
    default:
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