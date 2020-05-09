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


class Ticket
{
public:
    int id, client, agent;
    status ticketStatus;
    priority ticketPriority;
    string content, title;
    Ticket(int client, string content , string title);
    Ticket(int client, int agent, string content, string title);
    Ticket(int id,
           int client,
           int agent,
           status ticketStatus,
           priority ticketPriority,
           string content,
           string title);
    void save();
    void updateInput();
    void update();
};
