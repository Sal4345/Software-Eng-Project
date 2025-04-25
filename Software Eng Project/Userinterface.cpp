
#include "Userinterface.h"
//Carlos R 4-25-2025
using namespace std;

void showUserprivilages();
void displayAccessrequest(string, string);
void showAccesshistory();
void displayUnlockroom(int);
void displayLockdownrequest();

int main()
{
	int choice;
	int roomnum = 50;
	string username, password;

	const int  ACCESS = 1, //cases number values
		       UNLOCK = 2,
			   LOCKDOWN = 3,
		       LOGOUT = 4;

	do
	{
		showUserprivilages();
		cin >> choice;

		while (choice < ACCESS || choice > LOGOUT) //error message for wrong menu choice
		{
			cout << "Please enter a correct menu choice!: ";
			cin >> choice;
		}

		if (choice != LOGOUT)
		{

			switch (choice)
			{
			    case ACCESS:
				     displayAccessrequest(username, password);
					 if (username == "admin" && password == "admin") {
						 cout << "Acess Granted! to " << username << endl;
					 }
					 else {
						 cout << "Access Denied to " << username << endl;
					 }
					 break;
					 
				case UNLOCK:
					displayUnlockroom(roomnum);
					if (roomnum >= 1 && roomnum <= 100) {
						cout << "Access Granted! to " << username << endl;
					}
					else {
						cout << "Access Dennied to " << username << endl;
					}
					break;

				case LOCKDOWN:
					displayLockdownrequest();
		
			}
		}
	} while (choice != LOGOUT);
	return 0;

}
    // displays main menu 
	void showUserprivilages()
	{
		    cout << "\n-------Welcome to-------\n-Access Control System!-\n\n---Would you like to ... " << endl; 
			cout << " 1.Access Login History\n 2.Unlock a room\n 3.Request Lockdown\n 4.Log out\n\n" << endl;
	}
	
	void displayAccessrequest(string username, string password)
	{
		cout << "\nAccess Request Page\n\nPlease enter your credentials\n\nUsername: ";
		cin >> username;

		cout << "\nPassword: ";
		cin >> password;
	}

	void showAccesshistory()
	{
		cout << "Log Access History ...";
	
	}

	void displayUnlockroom(int roomnum)
	{
		cout << "What room would you like to unlock? " << endl;
		cin >> roomnum;
	}

	void displayLockdownrequest()
	{
		cout << "LockDown Request Page" << endl;
	}