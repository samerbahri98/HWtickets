#include <iostream>
#include <string>
#include <vector>
#include "Admin.h"
#include "User.h"
#include "Queue.h"
#include "Menu.h"
#include "Controller.h"
#include "Ticket.h"

using namespace std;
//Constructor
Admin::Admin(string username, string password)
    : User(username, password)
{
    userType = "Admin";
};
//copy Constructor
Admin::Admin(const User &U) : User(U) { userType = "Admin"; };
//Override from User Class
void Admin::mainMenuDisplay() const
{
    vector<string> commands = {"Display new tickets",
                               "Display my tickets",
                               "Display unassigned tickets",
                               "Display created tickets",
                               "Display All tickets",
                               "Update new Tickets",
                               "Update my tickets",
                               "Update unassigned tickets",
                               "Update created tickets",
                               "Update All tickets",
                               "Create ticket",
                               "Quit"};
    Menu mainMenu(commands, pleaseSelect);
    mainMenu.display(selector);

    switch (selector)
    {
    case 0:                       //Display new tickets
        ticketsDisplay(4, "New"); //column 4(priority)=New
        break;
    case 1:                               //Display my tickets
        ticketsDisplay(2, to_string(id)); //column 2(Agent)=id
        break;
    case 2:                               //Display unassigned tickets
        ticketsDisplay(2, to_string(-1)); //column 2(Agent)<0
        break;
    case 3:                               //Display created tickets
        ticketsDisplay(1, to_string(id)); //column 1(Client)=id
        break;
    case 4:                     //Display All tickets
        ticketsDisplay(-1, ""); //column 1(Client)<0
        break;
    case 5:                      //Update new Tickets
        ticketsUpdate(4, "New"); //column 4(priority)=New
        break;
    case 6:                              //Update my tickets
        ticketsUpdate(2, to_string(id)); //column 2(Agent)=id
        break;
    case 7:                              //Update unassigned tickets
        ticketsUpdate(2, to_string(-1)); //column 2(Agent)<0
        break;
    case 8:                              //Update created tickets
        ticketsUpdate(1, to_string(id)); //column 1(Client)=id
        break;
    case 9:                    //Update All tickets
        ticketsUpdate(-1, ""); //column 1(Client)<0
        break;
    case 10: //Create ticket
        ticketCreate();
        break;
    case 11: //Quit
        isLoggedIn = false;
        break;
    default: //impossible input
        cout << impossible << endl;
        break;
    };

    return;
}