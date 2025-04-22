#pragma once
#ifndef ACCESSLOGENTRY_H
#define ACCESSLOGENTRY_H

#include <string>
#include <chrono> // For timestamps

// Represents a single entry in the access log
struct AccessLogEntry {
    std::string userName;
    std::string userID;
    std::chrono::system_clock::time_point timestamp;
    std::string accessLevelRequested; // Or room/resource requested
    bool accessGranted;
    std::string details; // Optional additional details

    // Constructor Declaration
    AccessLogEntry(std::string uname, std::string uid, std::string levelReq, bool granted, std::string dets = "");
};

#endif // ACCESSLOGENTRY_H