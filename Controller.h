#include <iostream>
#include <string>
#include <sstream>


using namespace std;

typedef enum priority
{
    Low,
    Medium,
    High,
    Urgent
} priority;
typedef enum status
{
    New,
    Open,
    Pending,
    Closed
} status;

typedef struct Parameters
{
    string value;
    struct Parameters *next;
} Parameters;

/*

*/


class CSV
{
public:
    string fileName;
    CSV(string fileName);
    void create(string content);
    void read();
    void fetch();
    void update(string content);
    void update(int line, string content);
    void remove(string content);
    void remove(int line);
};


class Ticket
{
public:
    int id, client, agent;
    status ticketStatus;
    priority ticketPriority;
    string content;
    Ticket(int client, string content);
    Ticket(int client, int agent, string content);
    Ticket(int id,
           int client,
           int agent,
           status ticketStatus,
           priority ticketPriority,
           string content);
    void save();
    //    void update();
};


/*
class MenuItem
{
public:
    Parameters * pHead;
    MenuItem *next;
    MenuItem *head;

    MenuItem(Parameters * pHead);
    MenuItem(Parameters * pHead, MenuItem *head);

    void update();
    void remove();
};

class Menu
{
public:
    MenuItem *head;
    Menu(MenuItem *head);
    void display();
    void select();
    void back();
};

class Queue
{
public:
    Menu menu;
    string fileName, queueName;
    Queue();
    Menu fetch();
    void update();
    void save();
};

*/