/* Artifact: AccessControlSystem
   Description: Manages user login, access checking, and door control
   Who wrote: Mitchell Nasser
   Date: 4-22-2025 
*/
#ifndef ACCESS_CONTROL_SYSTEM_H
#define ACCESS_CONTROL_SYSTEM_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class AccessControlSystem {
private:
	string businessHours; // allowed window

public:
	// constructor
	AccessControlSystem ();

	// business hours accessors
	void setBusinessHours (const string& hours);
	string getBusinessHours () const;

	// access methods
	bool verifyCredentials(const string& userID, const string& password);
	bool checkAccessLevel(const string& userID, const string& requestedLevel);
	void grantAccess(const string& userID, const string& level);
	void denyAccess(const string& userID, const string& level);
	void logAccessAttempt(const string& userID, const string& level, bool success);
	void lockAccess(); // locks
	void unlockAccess(); // unlocks
	void initiateLockdown(); // secures all simulated locks 

	
	string currentTime() const; // gets the current timestamp

};

#endif
