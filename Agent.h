#ifndef AGNET_H
#define AGENT_H

#include <iostream>
#include <string>
#include "User.h"

using namespace std;

class Agent : public User
{
public:
    Agent(string username,string password);
    Agent(User U);
    void mainMenuDisplay() override;
    void newTicketsDisplay();
    void newTicketsUpdate();
    void myTicketsDisplay();
    void myTicketsUpdate();
};

#endif // AGENT_H