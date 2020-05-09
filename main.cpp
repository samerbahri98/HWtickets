#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Client.h"
#include "Ticket.h"
#include "Queue.h"
#include "Controller.h"

using namespace std;

int main()
{
    //authentification sequence
    // LoginMenu.display(selector);
    //
    // Client newClient;
    // newClient.login();
    Ticket newTicket(8, -1, "n7eb kammounti barcha ena", "yeeeae");
    newTicket.save();

    newTicket.updateInput(10);
    // Queue tickets("tickets.csv");
    // tickets.fetch();
    // tickets.display();
    // cout << "===========" << endl;
    // newTicket.ticketPriority = Low;
    // newTicket.update();
    // tickets.fetch();
    // tickets.display();
    return 0;
}