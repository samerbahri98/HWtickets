#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "CSV.h"
#include "Controller.h"

using namespace std;

//generic functions
inline int generateId()
{
    ifstream usersFile;
    int nol = 0;
    string line;
    usersFile.open("tickets.csv");
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

//cvs class

//ticket class

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
    stringstream content;
    content << id << " , "
            << client << " , "
            << agent << " , "
            << priorityMap(ticketPriority) << " , "
            << statusMap(ticketStatus) << " , "
            << " ["
            << " , "
            << this->content << " , "
            << "] "
            << " , "
            << " ";
    CSV ticketsFile("tickets.csv");
    ticketsFile.create(content.str());
}

void Ticket::update(){
    stringstream content;
    content << id << " , "
            << client << " , "
            << agent << " , "
            << priorityMap(ticketPriority) << " , "
            << statusMap(ticketStatus) << " , "
            << " ["
            << " , "
            << this->content << " , "
            << "] "
            << " , "
            << " ";
    CSV ticketsFile("tickets.csv");
    ticketsFile.update(id,content.str());
}

//MenuItem
MenuItem::MenuItem(vector<string> Parameters) : Parameters(Parameters){};
void MenuItem::display()
{
    for (int i = 0; i < Parameters.size(); i++)
        cout << Parameters[i] << "|\t";
    cout << endl;
}

Menu::Menu(vector<MenuItem> rows) : rows(rows){};
void Menu::display()
{
    for (int i = 0; i < rows.size(); i++)
        rows[i].display();
}

Queue::Queue(string fileName) : fileName(fileName) { matrix = {}; };
void Queue::fetch()
{
    CSV ticketFile("tickets.csv");
    ticketFile.fetch(matrix);
}

Queue::~Queue(){matrix.clear();};

void Queue::display()
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << "|\t";
        cout << endl;
    };
};
