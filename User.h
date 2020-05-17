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
    User(string userName, string userPassword);          //Constructor
    User(const User *U);                                 //Copy Constructor
    ~User(){};                                           //Destructor
    void signUp();                                       //Save credentials in users.csv, get an id then login
    void login();                                        //Login
    virtual void mainMenuDisplay() const = 0;            //abstract function to navigate the program, will be override by subclasses
    void ticketsDisplay(int column, string value) const; //fetch tickets from the tickets.csv, might be filtered (cells in column = value)
    void ticketsUpdate(int column, string value) const;  //select and update a ticket, the list might be filtered (cells in column = value)
    void ticketCreate() const;                           //create Ticket (default agent = -1 )
};

#endif // USER_H