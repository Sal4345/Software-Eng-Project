//Isaac Opata
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Administrator {
private:
    string adminID;
    string password;
    unordered_map<string, pair<string, string>> userList; // userID -> {username, accessLevel}
    vector<string> accessLogs;

public:
    Administrator(const string& id, const string& pass);

    bool verifyAdminCredentials(const string& id, const string& pass);
    void addUser(const string& userID, const string& username, const string& accessLevel);
    void removeUser(const string& userID);
    void modifyUserAccess(const string& userID, const string& newAccessLevel);
    void viewAccessLogs();
    void initiateSystemLockdown();
};

#endif // ADMINISTRATOR_H#pragma once
