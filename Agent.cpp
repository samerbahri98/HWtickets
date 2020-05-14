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

Agent::Agent(User U) : User(U) {}

void Agent::ticketsDisplay(int column, string value)
{
    Queue createdQueue("tickets.csv");
    createdQueue.fetch();
    createdQueue.filter(column, value);
}

void Agent::ticketsUpdate(int column, string value)
{
    cout << "Please write the id of the ticket" << endl;
    ticketsDisplay(column, value);
    if (sizeOfQueue != 0)
    {
        cin >> selector;
        vector<string> row;
        CSV ticketVector("tickets.csv");
        ticketVector.getLine(selector, row);
        priority p;
        if (row[3].at(0) == 'U')
            p = Urgent;
        else if (row[3].at(0) == 'H')
            p = High;
        else if (row[3].at(0) == 'M')
            p = Medium;
        else
            p = Low;

        status s;
        if (row[4].at(0) == 'N')
            s = New;
        else if (row[4].at(0) == 'O')
            s = Open;
        else if (row[4].at(0) == 'P')
            s = Pending;
        else
            s = Closed;

        Ticket updateTicket(stoi(row[0]), stoi(row[1]), stoi(row[2]), s, p, row[5], row[6]);
        updateTicket.updateInput(id);
    }
};

void Agent::mainMenuDisplay()
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