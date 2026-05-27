#include <iostream>     // Include input/output stream library for cout and cin
#include "SalonManager.h"  // Include our SalonManager class header file (the separated file)

using namespace std;    // Use standard namespace to avoid writing std:: everywhere

// Main function: program starts here
int main() {
    SalonManager salon;  // Create SalonManager object called salon (instance of the class)
    int choice;          // Variable to store user menu choice (integer 1-4)

    do {  // Start do-while loop for menu (executes at least once)
        cout << "\n===== Salon Management System =====" << endl;  // Print menu header
        cout << "1. Add New Appointment" << endl;      // Option 1: add appointment
        cout << "2. Show All Appointments" << endl;    // Option 2: display all appointments
        cout << "3. Search Appointment by Name" << endl;  // Option 3: search by client name
        cout << "4. Exit" << endl;                     // Option 4: exit program
        cout << "Enter your choice: ";                 // Ask user for choice
        cin >> choice;                                 // Read integer user choice

        switch (choice) {  // Switch statement based on user choice value
            case 1:  // If user chose 1
                salon.addAppointment();  // Call addAppointment method on salon object
                break;  // Exit switch block (prevents falling through to next case)
                
            case 2:  // If user chose 2
                salon.showAllAppointments();  // Call showAllAppointments method on salon object
                break;  // Exit switch block
                
            case 3:  // If user chose 3
                salon.searchAppointment();  // Call searchAppointment method on salon object
                break;  // Exit switch block
                
            case 4:  // If user chose 4
                cout << "Exiting system. Goodbye!" << endl;  // Print exit message
                break;  // Exit switch block
                
            default:  // If user entered any number other than 1,2,3,4
                cout << "Invalid choice. Try again." << endl;  // Show error message
        }  // End of switch statement
    } while (choice != 4);  // Keep looping until user chooses 4 (Exit option)

    return 0;  // Return 0 to operating system indicating program ended successfully
}  // End of main function