#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

///This is the User Class
///
///This class is for users. it has the basic previledges
class User
{
protected:
    string userName, userPassword;

public:
    int id;
    string userType;
    User(string userName, string userPassword);
    User(const User *U);
    ~User(){};
    void signUp();
    void login();
    virtual void mainMenuDisplay() const = 0;
    void ticketsDisplay(int column, string value) const;
    void ticketsUpdate(int column, string value) const;
};

#endif // USER_H