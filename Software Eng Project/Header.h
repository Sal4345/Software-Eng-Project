#include <iostream>
#include <string>
using namespace std;

class User
{

public:
	string getUsername();
	void setUsername();
	string getUserID();
	void setUserID();
	string getUserAccessLevel();
	void setUserAccessLevel();
	bool isUserRegistered();

private:
	string username;
	string UserID;
	string UserAccessLevel;

};


class UserInterface
{
public: 
	void displayLoginPage();
	void displayAdminPage();
	void displayEmployeePage();

private:
	int userInput;
};