#ifndef AGNET_H
#define AGENT_H

#include <iostream>
#include <string>
#include "User.h"

using namespace std;

class Agent : public User
{
public:
    Agent(string username, string password);
    Agent(User U);
    void mainMenuDisplay() override;
    void ticketsDisplay(int column, string value);
    void ticketsUpdate(int column, string value);
};

#endif // AGENT_H