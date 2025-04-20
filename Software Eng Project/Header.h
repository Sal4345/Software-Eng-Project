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

}
;