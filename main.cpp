#include <iostream>
#include <string>
#include <fstream>

#include "Users.h"
#include "Controller.h"

using namespace std;

int main()
{
    Agent newAgent;
    newAgent.signUp();
    Client newClient;
    newClient.signUp();

    Ticket newTicket(newClient.id,newAgent.id,"n7eb kammounti ena");

    return 0;
}