#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Menu
{
public:
    vector<string> rows;
    string message;
    Menu(vector<string> rows);
    Menu(vector<string> rows , string message);
    void display(int &option) const;
    //    void back();
};

#endif // MENU_H