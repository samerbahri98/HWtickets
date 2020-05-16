#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "User.h"
#include "Menu.h"
#include "Queue.h"
#include "CSV.h"
#include "Controller.h"
#include "Ticket.h"

using namespace std;

User::User(string userName, string userPassword) : userName(userName), userPassword(userPassword)
{
    id = -1;
}

User::User(const User *U)
{
    id = U->id;
    userType = U->userType;
    userName = U->userName;
    userPassword = U->userPassword;
}

void User::signUp()
{
    CSV usersFile("users.csv");
    id = usersFile.generateId();
    stringstream ss;
    ss << id << " , " << userName << " , " << userPassword << " , " << userType << " , ";
    usersFile.create(ss.str());
    ss.clear();
};

void User::login()
{
    vector<vector<string>> matrix;
    CSV usersFile("users.csv");
    usersFile.fetch(matrix);
    bool userExists = false, passExists = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (userName.compare(matrix[i][1]) == 0)
        {
            userExists = true;
            if (userPassword.compare(matrix[i][2]) == 0)
            {
                if (userType.compare(matrix[i][3]))
                    passExists = false;
                else
                {
                    passExists = true;
                    id = stoi(matrix[i][0]);
                }
            }
            else
            {
                continue;
            }
        }
    }
    matrix.clear();
    if (!(userExists))
    {
        cout << "user doesn't exist" << endl;
        exit(EXIT_FAILURE);
    }
    if (!(passExists))
    {
        cout << "wrong password" << endl;
        exit(EXIT_FAILURE);
    }
};

void User::ticketsUpdate(int column, string value) const
{
    cout << "Please write the id of the ticket" << endl;
    ticketsDisplay(column, value);
    if (sizeOfQueue != 0)
    {
        cin >> selector;
        vector<string> row;
        CSV ticketVector("tickets.csv");
        ticketVector.getLine(selector, row);
        priority p;
        if (row[3].at(0) == 'U')
            p = Urgent;
        else if (row[3].at(0) == 'H')
            p = High;
        else if (row[3].at(0) == 'M')
            p = Medium;
        else
            p = Low;

        status s;
        if (row[4].at(0) == 'N')
            s = New;
        else if (row[4].at(0) == 'O')
            s = Open;
        else if (row[4].at(0) == 'P')
            s = Pending;
        else
            s = Closed;

        Ticket updateTicket(stoi(row[0]), stoi(row[1]), stoi(row[2]), s, p, row[5], row[6]);
        updateTicket.updateInput(id);
    }
};

void User::ticketsDisplay(int column, string value) const
{
    Queue createdQueue("tickets.csv");
    createdQueue.fetch();
    cout << "id|Client|Agent|Priority|Status|Title|Content|" << endl;
    cout << "---------------------------------------------------------" << endl;
    if(column>=0)
    createdQueue.filter(column, value);
    createdQueue.map("users.csv", {1, 2}, 1);
    createdQueue.display();
    cout << "N/A: Not Assigned" << endl;
};