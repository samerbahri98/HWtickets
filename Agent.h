#ifndef AGNET_H
#define AGENT_H

#include"User.h"

using namespace std;

class Agent : public User
{
public:
    Agent(string username, string password);
    Agent(const User &U);
    ~Agent(){};
    virtual void mainMenuDisplay() const override ;
};

#endif // AGENT_H