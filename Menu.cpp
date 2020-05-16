#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Controller.h"

using namespace std;

Menu::Menu(vector<string> rows) : rows(rows) { message = ""; };
Menu::Menu(vector<string> rows, string message) : rows(rows), message(message){};
void Menu::display(int &option)
{
    cout << endl;
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
    checkSelector(option);
}