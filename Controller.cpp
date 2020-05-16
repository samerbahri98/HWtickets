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

Menu LoginMenu(LoginMenuItems, pleaseSelect);
int selector = 0;
bool isLoggedIn = false;
bool wantsLogOut = false;
int sizeOfQueue = 0;

void areYouSure(string that)
{
    vector<string> yesNo = {"Yes", "No"};
    Menu YesNoMenu(yesNo, "Are your sure that you want to " + that + "?");
    YesNoMenu.display(selector);
}

void mainLoop()
{ //authentification sequence

    isLoggedIn = false;
    wantsLogOut = false;
    LoginMenu.display(selector);

    cin.ignore(); // BUG: the 1st input is being skipped
    string username, password;
    writeCredentials(username, password);
    // User *newUser = new User(username, password);
    User *newUser = nullptr;

    switch (selector)
    {
    case 0:
        newUser = new Client(username, password);
        newUser->login();
        break;
    case 1:
        newUser = new Agent(username, password);
        newUser->login();
        break;
    case 2:
        newUser = new Admin(username, password);
        newUser->login();
        break;
    case 3:
        newUser = new Client(username, password);
        newUser->signUp();
        break;
    case 4:
        newUser = new Agent(username, password);
        newUser->signUp();
        break;
    case 5:
        newUser = new Admin(username, password);
        newUser->signUp();
        break;
    default:
        break;
    }
    if (newUser->userType != "")
        isLoggedIn = true;
    while (isLoggedIn)
    {
        newUser->mainMenuDisplay();
        if (wantsLogOut)
        {
            isLoggedIn = false;
            newUser = nullptr;
        }
    };
}
