#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "User.h"

class Client : public User
{
public:
    Client(string username,string password);
    Client(const User &U);
    virtual void mainMenuDisplay() const override ;
};

#endif //CLIENT_H