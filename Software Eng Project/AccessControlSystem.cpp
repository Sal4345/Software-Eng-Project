/* Artifact: AccessControlSystem
   Description: Implements login checks and door actions
   Who wrote: Mitchell Nasser
   Date: 4-22-2025 
*/
#include "AccessControlSystem.h"

// initialize with regular business hours
AccessControlSystem::AccessControlSystem() : businessHours("08:00-5:00")
{
}

void AccessControlSystem::setBusinessHours(const string& hours)
{
	businessHours = hours; //update hours for access
}

string AccessControlSystem::getBusinessHours() const
{
	return businessHours; //return stored hours
}

bool AccessControlSystem::verifyCredentials(const string& userID, const string& password)
{
	return (userID == "admin" && password == "password"); //check for user credentials match stored credentials
}

bool AccessControlSystem::checkAccessLevel(const string& userID, const string& requestedLevel)
{
	return (requestedLevel == "standard" || requestedLevel == "admin"); //allows standard or admin levels
}

void AccessControlSystem::grantAccess(const string& userID, const string& level)
{
	unlockAccess(); // opens the door
	logAccessAttempt(userID, level, true);
	cout << "Access granted to " << userID << " at level " << level << endl;
}

void AccessControlSystem::denyAccess(const string& userID, const string& level)
{
	lockAccess(); // keeps door closed
	logAccessAttempt(userID, level, false);
	cout << "Access denied to " << userID << "at level " << level << endl;
}

void AccessControlSystem::logAccessAttempt(const string& userID, const string& level, bool success)
{
	cout << "[LOG] " << currentTime() << " - User: " << userID << endl; // records the attempt with a timestamp
	cout << ", Level: " << level << endl;
	cout << ", Success: " << (success ? "Yes" : "No") << endl;
}

void AccessControlSystem::lockAccess()
{
	cout << "*LOCKING ACCESS*" << endl; // simulating hardware lock
}

void AccessControlSystem::unlockAccess()
{
	cout << "*UNLOCKING ACCESS*" << endl; // simulating hardware unlock
}

void AccessControlSystem::initiateLockdown()
{
	cout << "*** INITIATING LOCKDOWN ***" << endl;
	lockAccess(); // locking all access
	cout << "The system is now in lockdown mode." << endl;
}

string AccessControlSystem::currentTime() const
{
	time_t t = time(nullptr);
	tm tmStruct = *localtime(&t);
	char buf[20];
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tmStruct);
	return string(buf); //our timestamp format
}
