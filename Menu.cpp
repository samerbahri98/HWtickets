#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Controller.h"

using namespace std;

//Constructor without a top message
Menu::Menu(vector<string> rows) : rows(rows) { message = ""; };
//Contructor with a top message
Menu::Menu(vector<string> rows, string message) : rows(rows), message(message){};
//Destructor
Menu::~Menu(){
    rows.clear();
}
//Display the menu and select the option
void Menu::display(int &option) const
{
    cout << endl; //empty line to separate between menus
    cout << message << endl; 
    for (int i = 0; i < rows.size(); i++)
    {
        cout << i << ":\t" << rows[i] << endl;
        margin.push_back(i);
    }
    try
    {
        cin >> option;
    }
    catch (...)
    {
        cout << impossible << endl;
        throw exception();
    }
    cout << endl;
    checkSelector(option);//
}