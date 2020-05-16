#ifndef USER_H
#define USER_H

using namespace std;

//This is the User Class,
//
//This class abstracted, the classes Admin, Agent and Client inherit from it.
class User
{
protected:
    string userName, userPassword;

public:
    int id;
    string userType;
    User(string userName, string userPassword);
    User(const User *U);
    ~User(){};
    void signUp();
    void login();
    virtual void mainMenuDisplay() const = 0;
    void ticketsDisplay(int column, string value) const;
    void ticketsUpdate(int column, string value) const;
};

#endif // USER_H