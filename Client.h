#ifndef CLIENT_H
#define CLIENT_H

#include "User.h"

using namespace std;

class Client : public User
{
public:
    Client(string username, string password);      //Constructor
    Client(const User &U);                         //copy Constructor
    ~Client();                                     //Destructor
    virtual void mainMenuDisplay() const override; //Override from User Class
};

#endif //CLIENT_H