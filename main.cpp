#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Client.h"
#include "Agent.h"
#include "Client.h"
#include "Admin.h"
#include "Ticket.h"
#include "Queue.h"
#include "Controller.h"

using namespace std;

int main()
{
    //authentification sequence
    LoginMenu.display(selector);
    Agent* loggedAgent;
    Client* loggedClient;
    // Admin* loggedAdmin;
    User* loggedUser= new User(LoginMenuSelection(selector));
    if (loggedUser->userType!="") isLoggedIn=true;
    if(loggedUser->userType=="Agent") loggedUser = new Agent(loggedUser);
    if(loggedUser->userType=="Client") loggedUser = new Client(loggedUser);
    while(isLoggedIn)loggedUser->mainMenuDisplay();

    // Ticket newTicket(LoggedUser->id);
    // newTicket.save();
    // newTicket.updateInput(LoggedUser->id);


    //
    // Client newClient;
    // newClient.login();
    // Ticket newTicket(8, -1, "n7rcha ena", "yeeeae");
    // newTicket.save();

    // newTicket.updateInput(10);
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