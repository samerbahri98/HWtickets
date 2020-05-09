#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "CSV.h"
#include "Ticket.h"

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

Ticket::Ticket(int client, string content, string title) : client(client), content(content), title(title)
{

    CSV ticketsFile("tickets.csv");
    id = ticketsFile.generateId();
    agent = -1;
    ticketPriority = Medium;
    ticketStatus = New;
};

Ticket::Ticket(int client, int agent, string content, string title) : client(client), agent(agent), content(content), title(title)
{
    CSV ticketsFile("tickets.csv");
    id = ticketsFile.generateId();
    ticketPriority = Medium;
    ticketStatus = New;
};
Ticket::Ticket(int id,
               int client,
               int agent,
               status ticketStatus,
               priority ticketPriority,
               string content,
               string title)
    : id(id),
      client(client),
      agent(agent),
      ticketStatus(ticketStatus),
      ticketPriority(ticketPriority),
      content(content),
      title(title){};

void Ticket::save()
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
