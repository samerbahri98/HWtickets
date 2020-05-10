#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "User.h"
#include "CSV.h"

using namespace std;


User::User(string userName, string userPassword):userName(userName),userPassword(userPassword){
    id=-1;
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
                if(userType.compare(matrix[i][3]))
                passExists=false;
                else{
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