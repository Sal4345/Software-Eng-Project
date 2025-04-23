#include <iostream>
#include <string>
using namespace std;

//Salih Azaz 4-22-2025

// Manages the user of the program

class User
{

public:
	std::string getUsername();
	void setUsername();
	std::string getUserID();
	void setUserID();
	std::string getUserAccessLevel();
	void setUserAccessLevel();
	bool isUserRegistered();
	void authenticateUser();

private:
	std::string username;
	std::string UserID;
	std::string UserAccessLevel;

};


