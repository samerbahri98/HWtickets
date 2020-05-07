#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Users.h"
#include "Controller.h"

using namespace std;

int main()
{
    Client newClient;
    newClient.login();
    Ticket newTicket(newClient.id,-1,"n7eb kammounti barcha ena");
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