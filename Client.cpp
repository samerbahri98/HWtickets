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

Client::Client(const User &U) : User(U) { userType = "Client"; };

Client::~Client() {}

void Client::mainMenuDisplay() const
{
    int selector;
    vector<string> commands = {"Create ticket", "Display created tickets", "Quit"};
    Menu mainMenu(commands, pleaseSelect);
    mainMenu.display(selector);

    switch (selector)
    {
    case 0: //Create ticket
        ticketCreate(); 
        break;
    case 1: //Display created tickets
        ticketsDisplay(1, to_string(id));
        break;
    case 2: //Quit
        isLoggedIn = false;
        break;
    default: //impossible input
        cout<<impossible<<endl; 
        break;
    };

    return;
}