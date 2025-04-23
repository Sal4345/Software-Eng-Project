// --- Standard Library Includes ---
#include <iostream>  
#include <vector>    
#include <string>    
#include <map>       
#include <chrono>    
#include <iomanip>   
#include <ctime>     
#include <limits>    
#include <algorithm> 
#include <sstream>   
using namespace std;

// --- Custom Header Includes ---
// Include all the class definition header files
#include "User.h"
#include "AccessLog.h"
#include "AccessLogEntry.h"
#include "UserInterface.h"
//#include "AccessControlSystem.h"
//Bolivar Morales 4-22-2025
/**
 * @brief Formats a system_clock time_point into a "YYYY-MM-DD HH:MM:SS" string.
 * Uses platform-specific safe functions (localtime_s or localtime_r).
 * @param tp The time_point to format.
 * @return Formatted date and time string.
 */
string formatTime(const chrono::system_clock::time_point& tp) {
    time_t time = chrono::system_clock::to_time_t(tp);
    tm local_tm; // Create a tm struct to be filled

    // Use the appropriate platform-specific thread-safe function
#ifdef _WIN32
    localtime_s(&local_tm, &time); // MSVC/Windows safe version
#else
    localtime_r(&time, &local_tm); // POSIX safe version
#endif

    stringstream ss;
    ss << put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

/**
 * @brief Clears any error flags on cin and discards remaining characters
 * in the input buffer up to the next newline. Essential after
 * using `cin >> ...` before using `getline` or further `cin >>`.
 */
//Bolivar Morales 4-22-2025
void clearInputBuffer() {
    // Clear potential error flags first
    if (cin.fail()) {
        cin.clear();
    }
    // Discard characters until newline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


// --- Class Implementation: AccessLog ---
// Manages and provides access to access log entries.
//Bolivar Morales 4-22-2025
AccessLog::AccessLog() {} // Default constructor

// Stores a new log entry.
void AccessLog::storeLog(const AccessLogEntry& entry) {
    logEntries.push_back(entry);
    // In a real system, might append to a file or database here.
}

// Retrieves all log entries.
vector<AccessLogEntry> AccessLog::retrieveLogs() {
    return logEntries; // Returns a copy
}

// Retrieves log entries for a specific user ID.
vector<AccessLogEntry> AccessLog::retrieveLogsForUser(const string& userID) {
    vector<AccessLogEntry> userLogs;
    for (const auto& entry : logEntries) {
        if (entry.userID == userID) {
            userLogs.push_back(entry);
        }
    }
    return userLogs;
}
//Bolivar Morales 4-22-2025
// Displays all log entries to the console in a formatted table.
void AccessLog::displayAllLogs() const {
    cout << "\n--- Full Access Log ---" << endl;
    if (logEntries.empty()) {
        cout << "Log is empty." << endl;
        return;
    }
    // Print header
    cout << left << setw(15) << "User ID" << setw(20) << "User Name"
        << setw(25) << "Timestamp" << setw(10) << "Granted"
        << setw(20) << "Resource/Level Req" << "Details" << endl;
    cout << string(100, '-') << endl;
    // Print each entry
    for (const auto& entry : logEntries) {
        cout << left << setw(15) << entry.userID << setw(20) << entry.userName
            << setw(25) << formatTime(entry.timestamp) << setw(10) << (entry.accessGranted ? "Yes" : "No")
            << setw(20) << entry.accessLevelRequested << entry.details << endl;
    }
    cout << "-----------------------\n";
}
//Bolivar Morales 4-22-2025
// Displays log entries for a specific user ID in a formatted table.
void AccessLog::displayUserLogs(const string& userID) const {
    cout << "\n--- Access Log for User ID: " << userID << " ---" << endl;
    bool found = false;
    // Print header
    cout << left << setw(15) << "User ID" << setw(20) << "User Name"
        << setw(25) << "Timestamp" << setw(10) << "Granted"
        << setw(20) << "Resource/Level Req" << "Details" << endl;
    cout << string(100, '-') << endl;
    // Print matching entries
    for (const auto& entry : logEntries) {
        if (entry.userID == userID) {
            cout << left << setw(15) << entry.userID << setw(20) << entry.userName
                << setw(25) << formatTime(entry.timestamp) << setw(10) << (entry.accessGranted ? "Yes" : "No")
                << setw(20) << entry.accessLevelRequested << entry.details << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No log entries found for this user." << endl;
    }
    cout << "-----------------------------------\n";
}

//Salih Azaz 4/22/2025

User::User() {} // default constructor

// User Class Implementation

std::string User::getUsername() { // Pulls object username  - Salih Azaz 4/22/2025

    return username; 
}

void User::setUsername() {     // Modifies object username - Salih Azaz 4/22/2025
    cin >> username;
}

std::string User::getUserID() { // Pulls object UserID - Salih Azaz 4/22/2025
    return UserID;
}

void User::setUserID() {   // Modifies object UserID - Salih Azaz 4/22/2025
    cin >> UserID;
}

std::string User::getUserAccessLevel() {

}

//---------main-------------------------
int main() {
	cout << "Access Control Program V.10" << endl;                                                          // Salih Azaz (4/20/2025)
	cout << "Welcome! Please type the number of the option you wish to select: " << endl;                   // UI for Access Control Program
	cout << "1. login Menu\n" << "2. Admin Menu\n" << "3. Employee Menu\n";
																
	
}
