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

// Controller.h and Controller.cpp are not files of a class, they are instances of the class Menu.


//Global variables
int selector = 0;
bool isLoggedIn = false;
bool wantsLogOut = false;
int sizeOfQueue = 0;
vector<int> margin={};
User *loggedUser = nullptr;
Menu LoginMenu(LoginMenuItems, pleaseSelect);

//Global functions
void checkSelector(int option){
    bool test = false;
    for(int i=0;i<margin.size();i++)
        if(option==margin[i]){
            test=true;
            break;
        }
    if(!test){
        cout<<impossible<<endl;
        delete loggedUser;
        throw exception();
    }
    else{
        margin={};
    }
}

void areYouSure(string that)
{
    vector<string> yesNo = {"Yes", "No"};
    Menu YesNoMenu(yesNo, "Are your sure that you want to " + that + "?");
    YesNoMenu.display(selector);
}

void mainLoop()
{ 
    //declatarions
    isLoggedIn = false;
    string username, password;
    //authentification sequence
    LoginMenu.display(selector);
    cin.ignore(); // BUG: the 1st input is being skipped
    writeCredentials(username, password);
    switch (selector)
    {
    case 0:
        loggedUser = new Client(username, password);
        loggedUser->login();
        break;
    case 1:
        loggedUser = new Agent(username, password);
        loggedUser->login();
        break;
    case 2:
        loggedUser = new Admin(username, password);
        loggedUser->login();
        break;
    case 3:
        loggedUser = new Client(username, password);
        loggedUser->signUp();
        break;
    case 4:
        loggedUser = new Agent(username, password);
        loggedUser->signUp();
        break;
    case 5:
        loggedUser = new Admin(username, password);
        loggedUser->signUp();
        break;
    default:
        cout<<impossible<<endl;
        break;
    }
    //authorization
    if (loggedUser->userType != "")
        isLoggedIn = true;
    while (isLoggedIn)
        loggedUser->mainMenuDisplay();
    //dynamic memory
    delete loggedUser;
    std::exit(EXIT_SUCCESS);
}

void writeCredentials(string &username, string &password)
{
    cout << "Please write your username" << endl;
    getline(cin, username);
    cout << "Please write your password" << endl;
    getline(cin, password);
};