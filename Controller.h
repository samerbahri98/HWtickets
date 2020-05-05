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
private:
    int id, client, agent;
    status ticketStatus;
    priority ticketPriority;
    string content;

public:
    Ticket(int client, string content);
    Ticket(int client, int agent, string content);
    Ticket(int id,
           int client,
           int agent,
           status ticketStatus,
           priority ticketPriority,
           string content);
    void save();
    void update();
};