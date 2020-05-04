inline void writeCredentials();

///This is the User Class
///
///This class is for users. it has the basic previledges
class User {
protected:
	int id;
	std::string userName, userPassword , userType;

public:
	User();
	void signUp();

};

class Agent: protected  User {
    public:
    Agent():User(){userType="Agent";};
};

class Client: protected User {
    public:
    Client():User(){userType="Agent";};
};