#include "Menu.h"
#include "User.h"

using namespace std;

// Controller.h and Controller.cpp are not files of a class, they are the global variables and functions

//global variables
extern int selector;
extern bool isLoggedIn;
extern int sizeOfQueue;
extern vector<int>margin;
extern Menu LoginMenu;
extern User *loggedUser;
User* LoginMenuSelection(int selector);

//global constants
const vector<string> LoginMenuItems = {"Login as a Client",
                                 "Login as an Agent",
                                 "Login as an Admin",
                                 "Sign up as a Client",
                                 "Sign up as an Agent",
                                 "Sign up as an Admin"};

const string pleaseSelect = "Please type the index of the option you wish to click";
const string impossible = "Error: impossible input";

//global functions
void checkSelector(int option);
void areYouSure(string that);
void mainLoop();
void writeCredentials(string &username, string &password);
