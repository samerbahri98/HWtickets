#ifndef AGNET_H
#define AGENT_H

#include "User.h"

class Agent : public User
{
public:
    Agent(string username, string password);       //Constructor
    Agent(const User &U);                          //copy Constructor
    ~Agent(){};                                    //Destructor
    virtual void mainMenuDisplay() const override; //Override from User Class
};

#endif // AGENT_H