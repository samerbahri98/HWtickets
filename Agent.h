#include <iostream>
#include <string>
#include "User.h"

using namespace std;

class Agent : public User
{
public:
    Agent() : User() { userType = "Agent"; };
};