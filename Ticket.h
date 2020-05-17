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
    int id, client, agent;
    status ticketStatus;
    priority ticketPriority;
    string content, title;

public:
    Ticket(int client); //Constructor, the Client inputs the data //create Ticket (default agent = -1 )
    Ticket(int id,
           int client,
           int agent,
           status ticketStatus,
           priority ticketPriority,
           string title,
           string content);        //Constructor
    void save() const;             //Save in tickets.csv file
    void updateInput(int agentId); //Agent updates the input
    void update();                 //Save the updates in tickets.csv
    void accept(int agentId);      //agent= agentId 
    void changePriority();         //select new priority
    void changeStatus();           //select new status
    void close(int agentId);       //status=close AND agent=agentId
};
#endif //TICKET_H