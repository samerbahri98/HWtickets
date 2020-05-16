#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "CSV.h"
#include "Ticket.h"
#include "Controller.h"

using namespace std;

//generic functions

inline string statusMap(status p)
{
    switch (p)
    {
    case New:
        return "New";
        break;
    case Open:
        return "Open";
        break;
    case Pending:
        return "Pending";
        break;
    case Closed:
        return "Closed";
        break;
    }
};

inline string priorityMap(priority p)
{
    switch (p)
    {
    case Low:
        return "Low";
        break;
    case Medium:
        return "Medium";
        break;
    case High:
        return "High";
        break;
    case Urgent:
        return "Urgent";
        break;
    }
};

//cvs class

//ticket class

Ticket::Ticket(int client):client(client)
{
    cin.ignore(); // BUG: the 1st input is being skipped
    cout << "Please write the title of your ticket" << endl;
    getline(cin,title);
    cout << "Please describe your ticket" << endl;
    getline(cin,content);
    CSV ticketsFile("tickets.csv");
    id = ticketsFile.generateId();
    agent = -1;
    ticketPriority = Medium;
    ticketStatus = New;
    cout << "Thank you for reaching out, our agents will look into your issue"<< endl;
};

Ticket::Ticket(int id,
               int client,
               int agent,
               status ticketStatus,
               priority ticketPriority,
               string title,
               string content)
    : id(id),
      client(client),
      agent(agent),
      ticketStatus(ticketStatus),
      ticketPriority(ticketPriority),
      content(content),
      title(title){};

void Ticket::save() const
{
    stringstream content;
    content << id << " , "
            << client << " , "
            << agent << " , "
            << priorityMap(ticketPriority) << " , "
            << statusMap(ticketStatus) << " , "
            << " ["
            << " , "
            << this->title << " , "
            << "] "
            << " , "
            << " ["
            << " , "
            << this->content << " , "
            << "] "
            << " , "
            << " ";
    CSV ticketsFile("tickets.csv");
    ticketsFile.create(content.str());
}

void Ticket::update()
{
    stringstream content;
    content << id << " , "
            << client << " , "
            << agent << " , "
            << priorityMap(ticketPriority) << " , "
            << statusMap(ticketStatus) << " , "
            << " ["
            << " , " << this->title << " , "
            << "] "
            << " , "
            << " ["
            << " , " << this->content << " , "
            << "] "
            << " , "
            << " ";
    CSV ticketsFile("tickets.csv");
    ticketsFile.update(id, content.str());
}

void Ticket::accept(int agentId)
{
    areYouSure("accept this ticket");
    if (selector == 0)
        agent = agentId;
};

void Ticket::changePriority()
{
    vector<string> possibleChanges = {"Urgent", "High", "Medium", "Low"};
    Menu possibleChangesMenu(possibleChanges);
    possibleChangesMenu.display(selector);
    switch (selector)
    {
    case 0:
        ticketPriority = Urgent;
        break;
    case 1:
        ticketPriority = High;
        break;
    case 2:
        ticketPriority = Medium;
        break;
    case 3:
        ticketPriority = Low;
        break;
    default:
        break;
    }
}

void Ticket::close(int agentId)
{
    areYouSure("close this ticket");
    if (selector == 0)
        ticketStatus = Closed;
    agent = agentId;
}

void Ticket::changeStatus()
{
    vector<string> possibleChanges = {"New", "Open", "Pending", "Closed"};
    Menu possibleChangesMenu(possibleChanges);
    possibleChangesMenu.display(selector);
    switch (selector)
    {
    case 0:
        ticketStatus = New;
        break;
    case 1:
        ticketStatus = Open;
        break;
    case 2:
        ticketStatus = Pending;
        break;
    case 3:
        ticketStatus = Closed;
        break;
    default:
        break;
    }
}

void Ticket::updateInput(int agentId)
{
    vector<string> possibleChanges = {"Accept", "Change Priority", "Change Status", "Close Ticket", "Cancel"};
    Menu possibleChangesMenu(possibleChanges,pleaseSelect);
    possibleChangesMenu.display(selector);
    switch (selector)
    {
    case 0:
        accept(agentId);
        break;
    case 1:
        changePriority();
        break;
    case 2:
        changeStatus();
        break;
    case 3:
        close(agentId);
        break;
    case 4: return;
    default:
        cout<<impossible<<endl;
        throw exception();
        break;
    }
    update();
}
