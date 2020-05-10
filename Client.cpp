#include <iostream>
#include <string>
#include <vector>
#include "Client.h"
#include "Menu.h"
#include "Controller.h"
#include "Ticket.h"
#include "Queue.h"

using namespace std;

Client::Client(string username, string password) : User(username, password) { userType = "Client"; };

Client::Client(User U):User(U){};

void Client::createdTickets(){
    Queue createdQueue("tickets.csv");
    createdQueue.filter(1, to_string(this->id));
};

void Client::mainMenuDisplay () {
    int selector;
    vector<string> commands={"Create ticket","Look at created tickets","Logout","Quit"};
    Menu mainMenu(commands,pleaseSelect);
    mainMenu.display(selector);
    bool newTicketNeeded= false;
    createdTickets();
    switch (selector)
    {
    case 0:
        newTicketNeeded=true;
        break;
    case 1:
        createdTickets();
        break;
    default:
        break;
    };
    if(newTicketNeeded){
        Ticket newTicket(id);
        newTicket.save();
        newTicketNeeded = false;
    };

    return;
}