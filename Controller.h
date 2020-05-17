#include "Menu.h"
#include "User.h"

using namespace std;

// Controller.h and Controller.cpp are not files of a class, they are the global variables and functions

//global variables
extern int selector;       //for menu navigation
extern bool isLoggedIn;    //flag if there is a logged in use, if no the program closes
extern int sizeOfQueue;    //to display if there are tickets in a queue or not
extern vector<int> margin; //to flag unauthorized inputs
extern Menu LoginMenu;     //for authentification
extern User *loggedUser;   //for authorization

//global constants
const vector<string> LoginMenuItems = {"Login as a Client",
                                       "Login as an Agent",
                                       "Login as an Admin",
                                       "Sign up as a Client",
                                       "Sign up as an Agent",
                                       "Sign up as an Admin"};

const string pleaseSelect = "Please type the index of the option you wish to click";  //for menus and tickets updates
const string impossible = "Error: impossible input";

//global functions
void checkSelector(int option);                            //flag unauthorized input
void areYouSure(string that);                              //confirmation for critical operations
void mainLoop();                                           //to continuously run the program
void writeCredentials(string &username, string &password); //user inputs
