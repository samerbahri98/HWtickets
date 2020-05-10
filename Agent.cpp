#include <iostream>
#include <string>
#include "Agent.h"

using namespace std;

Agent::Agent(string username, string password) : User(username,password) { userType = "Agent"; };