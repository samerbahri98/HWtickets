#include <iostream>
#include <string>
#include "User.h"

class Client : public User
{
public:
    Client() : User() { userType = "Client"; };
};