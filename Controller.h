#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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
    vector<string> Parameters;
    MenuItem(vector<string> Parameters);
    void display();
};

class Menu
{
public:
    vector<MenuItem> rows;
    Menu(vector<MenuItem> rows);
    void display();
    //    void select();
    //    void back();
};

class Queue
{
public:
    string fileName;

    vector<vector<string>>matrix;
    Queue(string fileName);
    ~Queue();
    void fetch();
    void display();
};
