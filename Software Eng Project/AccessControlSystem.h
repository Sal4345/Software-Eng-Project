#ifndef ACCESS_CONTROL_SYSTEM_H
#define ACCESS_CONTROL_SYSTEM_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class AccessControlSystem {
private:
	string businessHours;

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
	void lockAccess();
	void unlockAccess();
	void initiateLockdown();

	
	string currentTime() const;

};

#endif