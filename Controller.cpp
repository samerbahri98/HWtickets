#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "Controller.h"

using namespace std;

//generic functions
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

//cvs class
CSV::CSV(string fileName) : fileName(fileName) {}

void CSV::create(string content)
{
    fstream file;
    file.open(this->fileName, ios::out | ios::app);
    file << content << endl;
    file.close();
}

void CSV::fetch()
{
    int id, client, agent;
    string line, content, priority, status;
    fstream file;
    // ss >> id >> comma >> client >> comma >> agent >> comma >> content >> comma >> priority >> comma >> status >> comma;
    file.open(this->fileName, ios::in);
    while (getline(file, line))
    {
        stringstream ss(line);
        string word;
        while(ss >> word)if(word!=",") cout << word<< "| \t";
        cout << endl;
        // ss << line;
        // cout << id << "\t" << client << "\t" << agent << "\t" << content << "\t" << priority << "\t" << status << endl;
    }
    file.close();
};

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
    content << this->id << " , "
            << this->client << " , "
            << this->agent << " , "
            << this->content << " , "
            << priorityMap(this->ticketPriority) << " , "
            << statusMap(this->ticketStatus) << " , ";
    CSV ticketsFile("./tickets.csv");
    ticketsFile.create(content.str());
}
/*
MenuItem::MenuItem(Parameters *pHead) : pHead(pHead)
{
    head = this;
    next = nullptr;
};

MenuItem::MenuItem(Parameters *pHead, MenuItem *head) : pHead(pHead), head(head)
{
    MenuItem *p = head;
    //    for(MenuItem*p=head;p=nullptr;p=p->next)
    while (p->next != nullptr)
        p = p->next;
    p->next = this;
};

Menu::Menu(MenuItem *head) : head(head){};

void Menu::display()
{
    for (MenuItem *m = this->head; m != nullptr; m = m->next)
    {
        for (Parameters *p = m->pHead; p != nullptr; p = p->next)
        {
            cout << p->value << "\t";
        };
        cout << endl;
    }
};



Queue::Queue(){
    fileName="tickets.csv";
    menu=fetch();

};

Menu Queue::fetch(){

};


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
