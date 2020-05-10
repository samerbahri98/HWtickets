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
    
    string userName, userPassword, userType;

public:
    int id;
    User(string userName,string userPassword);
    void signUp();
    void login();
};



#endif // USER_H