#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Users.h"
#include "CSV.h"

using namespace std;

inline void writeCredentials(string &username, string &password)
{
    cout << "Please write your username" << endl;
    getline(cin, username);
    cout << "Please write your password" << endl;
    getline(cin, password);
};

User::User()
{
    id = -1;
    writeCredentials(userName, userPassword);
};

void User::signUp()
{
    vector<vector<string>> matrix;
    CSV usersFile("./users.csv");
    usersFile.fetch(matrix);
    id = matrix.size();
    matrix.clear();
    stringstream ss;
    ss << id << " , " << userName << " , " << userPassword << " , " << userType << " , ";
    usersFile.create(ss.str());
    ss.clear();
};

void User::login()
{
    vector<vector<string>> matrix;
    CSV usersFile("./users.csv");
    usersFile.fetch(matrix);
    bool userExists = false, passExists = false;
    cout << matrix.size() << "x" << matrix[0].size() << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (userName.compare(matrix[i][1]) == 0)
        {
            userExists = true;
            if (userPassword.compare(matrix[i][2]) == 0)
            {
                passExists = true;
                id = stoi(matrix[i][0]);
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