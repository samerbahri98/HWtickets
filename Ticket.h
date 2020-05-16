#ifndef TICKET_H
#define TICKET_H


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

class Ticket
{
public:
    int id, client, agent;
    status ticketStatus;
    priority ticketPriority;
    string content, title;
    Ticket(int client);
    Ticket(int id,
           int client,
           int agent,
           status ticketStatus,
           priority ticketPriority,
           string title,
           string content);
    void save() const;
    void updateInput(int agentId);
    void update();
    void accept(int agentId);
    void changePriority();
    void changeStatus();
    void close(int agentId);
};
#endif //TICKET_H