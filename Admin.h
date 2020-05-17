#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User
{
public:
    Admin(string username, string password);       //Constructor
    Admin(const User &U);                          //copy Constructor
    ~Admin(){};                                    //Destructor
    virtual void mainMenuDisplay() const override; //Override from User Class

};

#endif // ADMIN_H