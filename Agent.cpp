#include <iostream>
#include <string>
#include <vector>
#include "Agent.h"
#include "Queue.h"
#include "Menu.h"
#include "Controller.h"
#include "Ticket.h"

using namespace std;

Agent::Agent(string username, string password) : User(username, password) { userType = "Agent"; };

Agent::Agent(User U) : User(U) {}

void Agent::newTicketsDisplay()
{
    Queue createdQueue("tickets.csv");
    createdQueue.fetch();
    createdQueue.filter(4, "New");
}

void Agent::myTicketsDisplay()
{
    Queue createdQueue("tickets.csv");
    createdQueue.fetch();
    createdQueue.filter(2, to_string(id));
}

void Agent::newTicketsUpdate()
{   
    cout<<"Please write the id of the ticket"<<endl;
    newTicketsDisplay();
    cin >> selector;
    
}

void Agent::myTicketsUpdate()
{
}

void Agent::mainMenuDisplay()
{
    int selector;
    vector<string> commands = {"Display new tickets", "Display my tickets", "Update new Tickets", "Update my tickets", "Close"};
    Menu mainMenu(commands, pleaseSelect);
    mainMenu.display(selector);
    bool newTicketNeeded = false;

    switch (selector)
    {
    case 0:
        newTicketsDisplay();
        break;
    case 1:
        myTicketsDisplay();
        break;
    case 2:
        newTicketsUpdate();
        break;
    case 3:
        myTicketsUpdate();
        break;
    case 4:
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