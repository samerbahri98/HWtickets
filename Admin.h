#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include "User.h"


using namespace std;

class Admin : public User
{
public:
    Admin(string username, string password);
    Admin(const User& U);

    ~Admin(){};
    virtual void mainMenuDisplay() const override ;
};

#endif // ADMIN_H