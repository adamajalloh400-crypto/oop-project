#ifndef SALONMANAGER_H  // Include guard: prevents multiple inclusions of this header file
#define SALONMANAGER_H  // Define the include guard macro

#include <iostream>     // Include input/output stream library for cout and cin
#include <string>       // Include string library to use std::string
#include <vector>       // Include vector library to store multiple appointments

using namespace std;    // Use standard namespace to avoid writing std:: everywhere

// Define a class called Appointment to hold salon booking details
class Appointment {
private: // Private members can only be accessed inside this class
    string clientName;  // Store client's name (e.g., "John Smith")
    string service;     // Store service type: Haircut, Dye, etc (e.g., "Haircut")
    double price;       // Store price of the service (e.g., 25.99)
    string time;        // Store appointment time like "10:00 AM"

public: // Public members can be accessed from outside the class
    // Constructor: runs automatically when we create an Appointment object
    Appointment(string name, string srv, double prc, string tm) {
        this->clientName = name;  // Use this-> to assign parameter name to member clientName
        this->service = srv;      // Use this-> to assign parameter srv to member service
        this->price = prc;        // Use this-> to assign parameter prc to member price
        this->time = tm;          // Use this-> to assign parameter tm to member time
    }
  
    // Method to display appointment details
    void displayInfo() {
        cout << "\n--- Appointment Details ---" << endl;  // Print header separator
        cout << "Client: " << this->clientName << endl;   // Print client name using this->
        cout << "Service: " << this->service << endl;     // Print service using this->
        cout << "Price: $" << this->price << endl;        // Print price using this->
        cout << "Time: " << this->time << endl;           // Print time using this->
        cout << "---------------------------" << endl;    // Print footer separator
    }

    // Getter method to return client name for searching
    string getClientName() {
        return this->clientName;  // Return clientName using this->
    }
};
  
// Class to manage all appointments in the salon
class SalonManager {
private:
    vector<Appointment> bookings;  // Vector to store all Appointment objects (dynamic array)

public:
    // Method to add a new appointment with user input
    void addAppointment() {
        string name, service, time;  // Declare variables to hold user input strings
        double price;                // Declare variable for price input (decimal number)
  
        cin.ignore();                // Clear input buffer before getline (removes leftover newline)
        cout << "Enter client name: ";  // Ask user for client name
        getline(cin, name);          // Read full line including spaces for name (e.g., "John Doe")
  
        cout << "Enter service: ";   // Ask user for service type
        getline(cin, service);       // Read full service name (e.g., "Hair Coloring")
  
        cout << "Enter price: $";    // Ask user for price with dollar sign prompt
        cin >> price;                // Read price as double (e.g., 49.99)
        
        cin.ignore();                // Clear buffer again before next getline (removes newline)
        cout << "Enter time: ";      // Ask user for time slot
        getline(cin, time);          // Read full time string (e.g., "2:30 PM")
  
        // Create Appointment object using constructor and add to vector
        Appointment newApp(name, service, price, time);  // Call constructor with user data
        this->bookings.push_back(newApp);  // Add newApp to bookings vector using this->
  
        cout << "Appointment added successfully!" << endl;  // Confirm success to user
    }
  
    // Method to show all booked appointments
    void showAllAppointments() {
        if (this->bookings.empty()) {  // Check if vector is empty using this->
            cout << "No appointments booked yet." << endl;  // Inform user no bookings exist
            return;  // Exit function early without showing anything
        }
  
        cout << "\n=== All Salon Appointments ===" << endl;  // Print title header
        for (int i = 0; i < this->bookings.size(); i++) {  // Loop through vector using this->
            cout << "\nAppointment #" << i + 1;  // Print appointment number (1-based index)
            this->bookings[i].displayInfo();    // Call displayInfo for each appointment object
        }
    }
  
    // Method to search appointment by client name
    void searchAppointment() {
        if (this->bookings.empty()) {  // Check if there are any bookings
            cout << "No appointments to search." << endl;  // Tell user vector is empty
            return;  // Exit function early
        }
  
        string searchName;  // Variable to hold search input from user
        cin.ignore();       // Clear buffer before getline (removes leftover newline)
        cout << "Enter client name to search: ";  // Ask user for name to search
        getline(cin, searchName);  // Read full search name (supports spaces)
  
        bool found = false;  // Flag to track if we found a match (starts as false)
        
        for (int i = 0; i < this->bookings.size(); i++) {  // Loop through all bookings
            if (this->bookings[i].getClientName() == searchName) {  // Compare names (case-sensitive)
                cout << "Found appointment:";  // Notify user that match was found
                this->bookings[i].displayInfo();  // Show matching appointment details
                found = true;  // Set flag to true indicating at least one match found
            }
        }
  
        if (!found) {  // If no match was found (found is still false)
            cout << "No appointment found for " << searchName << endl;  // Tell user no match
        }
    }
};

#endif  // End of include guard: closes the #ifndef SALONMANAGER_H block