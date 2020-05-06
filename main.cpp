#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Users.h"
#include "Controller.h"

using namespace std;

int main()
{
    
    Agent newAgent;
    newAgent.signUp();
    Client newClient;
    newClient.signUp();
    Ticket newTicket(newClient.id,newAgent.id,"n7eb kammounti barcha ena");
    newTicket.save();

    CSV ticketFile("./tickets.csv");

    ticketFile.fetch();


    // string line;
    // fstream tickets;
    // tickets.open("./tickets.csv", ios::in);
    // while (getline(tickets, line))cout<<line<<endl;
    // tickets.close();
    // return 0;
    
}