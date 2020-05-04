inline void writeCredentials();

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