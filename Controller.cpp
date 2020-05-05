#include <iostream>
#include <string>
#include <fstream>

#include "Controller.h"

using namespace std;

inline int generateId()
{
    ifstream usersFile;
    int nol = 0;
    string line;
    usersFile.open("./tickets.csv");
    while (getline(usersFile, line))
        nol++;
    usersFile.close();
    return nol++;
}

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

Ticket::Ticket(int client, string content) : client(client), content(content)
{

    id = generateId();
    agent = -1;
    ticketPriority = Medium;
    ticketStatus = New;
};

Ticket::Ticket(int client, int agent, string content) : client(client), agent(agent), content(content)
{
    id = generateId();
    ticketPriority = Medium;
    ticketStatus = New;
};
Ticket::Ticket(int id,
               int client,
               int agent,
               status ticketStatus,
               priority ticketPriority,
               string content)
    : id(id),
      client(client),
      agent(agent),
      ticketStatus(ticketStatus),
      ticketPriority(ticketPriority),
      content(content){};

void Ticket::save()
{
    fstream ticketsFile;
    ticketsFile.open("tickets.csv", ios::out | ios::app);
    ticketsFile << this->id << ","
                << this->client << ","
                << this->agent << ","
                << this->content << ","
                << priorityMap(this->ticketPriority) << ","
                << statusMap(this->ticketStatus) << ","

                << endl;

    ticketsFile.close();
}
/*
void Ticket::update()
{
    fstream ticketsFile;
    string line;
    ticketsFile.open("tickets.csv");
    while (getline(ticketsFile, line))
    {

    }
}
*/