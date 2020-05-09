
// Controller.h and Controller.cpp are not files of a class, they are instances of the class Menu.

#include <iostream>
#include <vector>
#include <string>

#include "Menu.h"

using namespace std;

extern int selector;
const vector<string> LoginMenuItems = {"Login as a Client",
                                 "Login as an Agent",
                                 "Login as an Admin",
                                 "Sign up as a Client",
                                 "Sign up as an Agent",
                                 "Sign up as an Admin"};

const string pleaseSelect = "Please type the index of the option you wish to click";

extern Menu LoginMenu;

void areYouSure(string that);

int LoginMenuSelection(int selector);

