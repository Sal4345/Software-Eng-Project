#include <iostream>
#include <string>
#pragma once
#ifndef USER_H
#define USER_H

using namespace std;

//Salih Azaz 4-22-2025

// Manages the user of the program

//includes accessors for username, userID, and password



// methods

class User
{

public:
	std::string getUsername(const std::string& Username);
	std::string getUserID(const std::string& UserID);
	std::string getUserAccessLevel(const std::string& Username, const std::string UserID, const std::string& level);
	std::string getPassword(const std::string&);
	 // void setUserID(); commenting out for now - Isaac already has this in Administrator class
	// void setUsername();  commenting out for now - Isaac already has this in Administrator class
	 // void setPassword(); commenting out for now - Isaac already has this in Administrator class
	 // void setUserAccessLevel();  commenting out for now - Isaac already has this in Administrator class
	bool isUserRegistered();

	// Username, UserID, Password, Access Level variables
private:
	std::string username;
	std::string UserID;
	std::string password;
	std::string level;

};

#endif


