#include "AccessControlSystem.h"

AccessControlSystem::AccessControlSystem() : businessHours("08:00-5:00")
{
}

void AccessControlSystem::setBusinessHours(const string& hours)
{
	businessHours = hours;
}

string AccessControlSystem::getBusinessHours() const
{
	return businessHours;
}

bool AccessControlSystem::verifyCredentials(const string& userID, const string& password)
{
	return (userID == "admin" && password == "password");
}

bool AccessControlSystem::checkAccessLevel(const string& userID, const string& requestedLevel)
{
	return (requestedLevel == "standard" || requestedLevel == "admin");
}

void AccessControlSystem::grantAccess(const string& userID, const string& level)
{
	unlockAccess();
	logAccessAttempt(userID, level, true);
	cout << "Access granted to " << userID << " at level " << level << endl;
}

void AccessControlSystem::denyAccess(const string& userID, const string& level)
{
	lockAccess();
	logAccessAttempt(userID, level, false);
	cout << "Access denied to " << userID << "at level " << level << endl;
}

void AccessControlSystem::logAccessAttempt(const string& userID, const string& level, bool success)
{
	cout << "[LOG] " << currentTime() << " - User: " << userID << endl;
	cout << ", Level: " << level << endl;
	cout << ", Success: " << (success ? "Yes" : "No") << endl;
}

void AccessControlSystem::lockAccess()
{
	cout << "*LOCKING ACCESS*" << endl;
}

void AccessControlSystem::unlockAccess()
{
	cout << "*UNLOCKING ACCESS*" << endl;
}

void AccessControlSystem::initiateLockdown()
{
	cout << "*** INITIATING LOCKDOWN ***" << endl;
	lockAccess();
	cout << "The system is now in lockdown mode." << endl;
}

string AccessControlSystem::currentTime() const
{
	time_t t = time(nullptr);
	tm tmStruct = *localtime(&t);
	char buf[20];
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tmStruct);
	return string(buf);
}
