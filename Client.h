#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "User.h"

class Client : public User
{
public:
    Client() : User() { userType = "Client"; };
};

#endif //CLIENT_H