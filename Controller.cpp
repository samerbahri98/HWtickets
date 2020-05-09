// Controller.h and Controller.cpp are not files of a class, they are instances of the class Menu.

#include <iostream>
#include <vector>
#include <string>

#include "Controller.h"
#include "Menu.h"
#include "Client.h"
#include "Agent.h"
#include "Admin.h"

using namespace std;

Menu LoginMenu(LoginMenuItems,pleaseSelect);

int selector =0;

void areYouSure(string that){
    vector<string> yesNo = {"Yes","No"};
    Menu YesNoMenu (yesNo, "Are your sure that you want to " + that + "?");
    YesNoMenu.display(selector);
}

// int LoginMenuSelection(int selector)
// {
//     Client newClient;
//     Agent newAgent;

//     switch (selector)
//     {
//     case 0:

//         newClient.login();
//         return newClient.id;
//         break;
//     case 1:
//         newAgent.login();
//         return newAgent.id;
//         break;
//     case 3:
//         newClient.signUp();
//         return newClient.id;
//         break;
//     case 4:
//         newAgent.signUp();
//         return newAgent.id;
//         break;
//     default:
//         break;
//     }
// };