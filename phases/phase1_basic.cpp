// ============================================
// Cinema & Hotel Booking Management System
// Phase 1: Basic Classes & Objects
// OOP Concepts: Classes, Objects, Methods, I/O
// ============================================

#include <iostream>
#include <string>
using namespace std;

class Customer {
public:
    int customerId;
    string name;
    string phone;

    void input() {
        cout << "Enter Customer ID: ";
        cin >> customerId;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Phone: ";
        cin >> phone;
    }

    void display() {
        cout << "Customer ID: " << customerId << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
    }
};

class Show {
public:
    int showId;
    string movieName;
    string time;
    int hallNo;
    int availableSeats;

    void input() {
        cout << "Enter Show ID: ";
        cin >> showId;
        cout << "Enter Movie Name: ";
        cin.ignore();
        getline(cin, movieName);
        cout << "Enter Show Time (e.g. 6:30PM): ";
        cin >> time;
        cout << "Enter Hall No: ";
        cin >> hallNo;
        cout << "Enter Available Seats: ";
        cin >> availableSeats;
    }

    void display() {
        cout << "Show ID: " << showId << endl;
        cout << "Movie: " << movieName << endl;
        cout << "Time: " << time << endl;
        cout << "Hall: " << hallNo << endl;
        cout << "Seats Available: " << availableSeats << endl;
    }
};

class Room {
public:
    int roomNo;
    string type; // Standard, Deluxe, Suite
    float pricePerNight;
    bool isAvailable;

    void input() {
        cout << "Enter Room No: ";
        cin >> roomNo;
        cout << "Enter Room Type (Standard/Deluxe/Suite): ";
        cin >> type;
        cout << "Enter Price Per Night: ";
        cin >> pricePerNight;
        isAvailable = true; // New rooms are available by default
    }

    void display() {
        cout << "Room No: " << roomNo << endl;
        cout << "Type: " << type << endl;
        cout << "Price/Night: Rs." << pricePerNight << endl;
        cout << "Status: " << (isAvailable ? "Available" : "Booked") << endl;
    }
};

int main() {
    cout << "========================================" << endl;
    cout << "  Cinema & Hotel Booking System" << endl;
    cout << "  Phase 1 - Basic Classes & Objects" << endl;
    cout << "========================================" << endl << endl;

    // --- Customer ---
    Customer c;
    cout << "--- Enter Customer Details ---" << endl;
    c.input();
    cout << endl;

    // --- Show ---
    Show s;
    cout << "--- Enter Show Details ---" << endl;
    s.input();
    cout << endl;

    // --- Room ---
    Room r;
    cout << "--- Enter Room Details ---" << endl;
    r.input();
    cout << endl;

    // --- Display All ---
    cout << "========================================" << endl;
    cout << "         Summary" << endl;
    cout << "========================================" << endl;

    cout << endl << "--- Customer Info ---" << endl;
    c.display();

    cout << endl << "--- Show Info ---" << endl;
    s.display();

    cout << endl << "--- Room Info ---" << endl;
    r.display();

    cout << endl << "========================================" << endl;
    cout << "  Phase 1 Complete!" << endl;
    cout << "========================================" << endl;

    return 0;
}
