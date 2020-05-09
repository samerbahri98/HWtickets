#ifndef AGNET_H
#define AGENT_H

#include <iostream>
#include <string>
#include "User.h"

using namespace std;

class Agent : public User
{
public:
    Agent() : User() { userType = "Agent"; };
};

#endif // AGENT_H