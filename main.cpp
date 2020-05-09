#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Client.h"
#include "Ticket.h"
#include "Queue.h"

using namespace std;

int main()
{
    
    Client newClient;
    newClient.login();
    Ticket newTicket(newClient.id,-1,"n7eb kammounti barcha ena","yeeeae");
    newTicket.save();

    Queue tickets ("tickets.csv");
    tickets.fetch();
    tickets.display();
    cout << "===========" << endl;
    newTicket.ticketPriority=Low;
    newTicket.update();
    tickets.fetch();
    tickets.display();
    return 0;
    
}