//Bolivar Morales 4-22-2025
#pragma once
#ifndef ACCESSLOG_H
#define ACCESSLOG_H

#include <vector>
#include <string>
#include "AccessLogEntry.h" // Needs the entry struct definition

// Manages the collection of access log entries 
class AccessLog {
private:
    std::vector<AccessLogEntry> logEntries;

public:
    AccessLog(); // Constructor Declaration

    // Methods based on diagrams/requirements
    // storeLogs, retrieveLogs 
    void storeLog(const AccessLogEntry& entry);
    std::vector<AccessLogEntry> retrieveLogs(); // Consider const return?
    std::vector<AccessLogEntry> retrieveLogsForUser(const std::string& userID); // Added for specific history 

    // Display methods (could also be in UserInterface)
    void displayAllLogs() const;
    void displayUserLogs(const std::string& userID) const;
};

#endif // ACCESSLOG_H