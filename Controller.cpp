// Controller.h and Controller.cpp are not files of a class, they are instances of the class Menu.

#include <iostream>
#include <vector>
#include <string>

#include "Controller.h"
#include "Menu.h"
#include "User.h"
#include "Client.h"
#include "Agent.h"
#include "Admin.h"

using namespace std;

void writeCredentials(string &username, string &password)
{
    cout << "Please write your username" << endl;
    getline(cin, username);
    cout << "Please write your password" << endl;
    getline(cin, password);
};

User *LoginMenuSelection(int selector)
{
    cin.ignore(); // BUG: the 1st input is being skipped
    string username, password;
    writeCredentials(username, password);
    User *newUser = new User(username,password);

    switch (selector)
    {
    case 0:
        newUser->userType="Client";
        newUser->login();
        break;
    case 1:
        newUser->userType="Agent";
        newUser->login();
        break;
    case 3:
        newUser->userType="Client";
        newUser->signUp();
        break;
    case 4:
        newUser->userType="Agent";
        newUser->signUp();
        break;
    default:
        return nullptr;
        break;
    }
    return newUser;
};
Menu LoginMenu(LoginMenuItems, pleaseSelect);

int selector = 0;

bool isLoggedIn = false;

void areYouSure(string that)
{
    vector<string> yesNo = {"Yes", "No"};
    Menu YesNoMenu(yesNo, "Are your sure that you want to " + that + "?");
    YesNoMenu.display(selector);
}

