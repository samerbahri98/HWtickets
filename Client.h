#ifndef CLIENT_H
#define CLIENT_H

#include"User.h"

class Client : public User
{
public:
    Client(string username,string password);
    Client(const User &U);
    ~Client();
    virtual void mainMenuDisplay() const override ;
};

#endif //CLIENT_H