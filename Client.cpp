#include <iostream>
#include <string>
#include "Client.h"

using namespace std;

Client::Client(string username, string password) : User(username,password){ userType = "Client"; };