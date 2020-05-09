#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"

using namespace std;

Menu::Menu(vector<string> rows) : rows(rows) { message = ""; };
Menu::Menu(vector<string> rows, string message) : rows(rows), message(message){};
void Menu::display(int &option)
{
    cout << message << endl;
    for (int i = 0; i < rows.size(); i++)
        cout << i << ":\t" << rows[i] << endl;
    cin >> option;
}