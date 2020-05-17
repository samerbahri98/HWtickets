#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Menu
{
    vector<string> rows;
    string message;
public:
    Menu(vector<string> rows);                 //Constructor without a top message
    Menu(vector<string> rows, string message); //Contructor with a top message
    ~Menu();                                   //Destructor
    void display(int &option) const;           //Display the menu and select the option
};

#endif // MENU_H