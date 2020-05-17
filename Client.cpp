#include <iostream>
#include <string>
#include <vector>
#include "Client.h"
#include "User.h"
#include "Menu.h"
#include "Controller.h"
#include "Ticket.h"
#include "Queue.h"

using namespace std;
//Constructor
Client::Client(string username, string password) : User(username, password) { userType = "Client"; };
//copy Constructor
Client::Client(const User &U) : User(U) { userType = "Client"; };
//Override from User Class
void Client::mainMenuDisplay() const
{
    vector<string> commands = {"Create ticket", "Display created tickets", "Quit"};
    Menu mainMenu(commands, pleaseSelect);
    mainMenu.display(selector); //selector is global variable

    switch (selector)
    {
    case 0: //Create ticket
        ticketCreate();
        break;
    case 1:                               //Display created tickets
        ticketsDisplay(1, to_string(id)); //column 1(Client)=id
        break;
    case 2: //Quit
        isLoggedIn = false;
        break;
    default: //impossible input
        cout << impossible << endl;
        break;
    };

    return;
}