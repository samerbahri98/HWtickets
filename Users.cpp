#include <iostream>
#include <string>
#include <fstream>
#include "Users.h"

using namespace std;

inline void writeCredentials(string &username, string &password)
{
    cout << "Please write your username" << endl;
    cin >> username;
    cout << "Please write your password" << endl;
    cin >> password;
};

User::User()
{
    ifstream usersFile;
    int nol = 0;
    string line;
    usersFile.open("./users.csv");
    while (getline(usersFile, line))
        nol++;
    usersFile.close();
    userType = "";
    id = nol++;
    writeCredentials(userName, userPassword);
};

void User::signUp()
{
    fstream usersFile;
    usersFile.open("./users.csv", ios::out | ios::app);
    usersFile << this->id << "," << this->userName << "," << this->userPassword << "," << this->userType << endl;
    usersFile.close();
};
