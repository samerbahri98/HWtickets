#include <iostream>
#include <string>

using namespace std;

enum priority
{
    Low,
    Medium,
    High,
    Urgent
};
enum status
{
    New,
    Open,
    Pending,
    Closed
};
/*

*/
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

class MenuItem
{
public:
    int id;
    string parameters[];
    MenuItem *next;

    MenuItem();
    MenuItem(MenuItem *head);

    void update();
    void remove();
};

class Menu
{
public:
    MenuItem *head;
    Menu();
    void display();
    void select();
    void back();
};

class Queue : public Menu {
    string fileName, queueName;
    Queue();
    void fetch();
    void save();
};