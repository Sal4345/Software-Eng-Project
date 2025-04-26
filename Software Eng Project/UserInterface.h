
//Bolivar Morales 4-22-2025
#pragma once
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>

// Forward declarations
class AccessControlSystem;
class User;
class Admin;
class Employee;

// Handles interactions with the user (console-based) 
class UserInterface {
private:
    AccessControlSystem& acs; // Reference to the main system

    // Private methods for specific user menus
    void displayAdminMenu(Admin* admin);
    void displayEmployeeMenu(Employee* employee);
    void displayVisitorMenu(User* visitor);

public:
    UserInterface(AccessControlSystem& system); // Constructor

    // Methods based on diagrams/requirements
    void displayLoginScreen();
    void displayAccessRequest(User* user);
    void showAccessHistory(User* user);
    void showUserPrivileges(User* user);
    // showAccessApproval 
    // modifyUserInfo 

    // Main loop to run the interface
    void run();
};

#endif // USERINTERFACE_H