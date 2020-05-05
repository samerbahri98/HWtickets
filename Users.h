#include <iostream>
#include <string>

using namespace std;


inline void writeCredentials();

///This is the User Class
///
///This class is for users. it has the basic previledges
class User
{
protected:
    
    string userName, userPassword, userType;

public:
    int id;
    User();
    void signUp();

};

class Agent : public User
{
public:
    Agent() : User() { userType = "Agent"; };
};

class Client : public User
{
public:
    Client() : User() { userType = "Client"; };
};