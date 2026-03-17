// ============================================
// Cinema & Hotel Booking Management System
// Phase 2: Encapsulation
// OOP Concepts: Private Members, Getters/Setters,
//               Data Hiding, Input Validation
// ============================================

#include <iostream>
#include <string>
using namespace std;

// ============================================
// CUSTOMER CLASS (Encapsulated)
// ============================================
class Customer {
private:
    int customerId;
    string name;
    string phone;
    string email;

public:
    // --- Getters ---
    int getCustomerId() { return customerId; }
    string getName() { return name; }
    string getPhone() { return phone; }
    string getEmail() { return email; }

    // --- Setters with Validation ---
    void setCustomerId(int id) {
        if (id > 0) {
            customerId = id;
        } else {
            cout << "Error: Customer ID must be positive." << endl;
        }
    }

    void setName(string n) {
        if (n.length() > 0) {
            name = n;
        } else {
            cout << "Error: Name cannot be empty." << endl;
        }
    }

    void setPhone(string p) {
        if (p.length() == 10) {
            phone = p;
        } else {
            cout << "Error: Phone number must be exactly 10 digits." << endl;
        }
    }

    void setEmail(string e) {
        // Basic check: must contain @ and .
        if (e.find('@') != string::npos && e.find('.') != string::npos) {
            email = e;
        } else {
            cout << "Error: Invalid email format." << endl;
        }
    }

    // --- Input Method (uses setters for validation) ---
    void input() {
        int id;
        string n, p, e;

        cout << "Enter Customer ID: ";
        cin >> id;
        setCustomerId(id);

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, n);
        setName(n);

        cout << "Enter Phone (10 digits): ";
        cin >> p;
        setPhone(p);

        cout << "Enter Email: ";
        cin >> e;
        setEmail(e);
    }

    // --- Display Method ---
    void display() {
        cout << "  Customer ID : " << customerId << endl;
        cout << "  Name        : " << name << endl;
        cout << "  Phone       : " << phone << endl;
        cout << "  Email       : " << email << endl;
    }
};

// ============================================
// SHOW CLASS (Encapsulated)
// ============================================
class Show {
private:
    int showId;
    string movieName;
    string time;
    int hallNo;
    int availableSeats;

public:
    // --- Getters ---
    int getShowId() { return showId; }
    string getMovieName() { return movieName; }
    string getTime() { return time; }
    int getHallNo() { return hallNo; }
    int getAvailableSeats() { return availableSeats; }

    // --- Setters with Validation ---
    void setShowId(int id) {
        if (id > 0) {
            showId = id;
        } else {
            cout << "Error: Show ID must be positive." << endl;
        }
    }

    void setMovieName(string m) {
        if (m.length() > 0) {
            movieName = m;
        } else {
            cout << "Error: Movie name cannot be empty." << endl;
        }
    }

    void setTime(string t) {
        if (t.length() > 0) {
            time = t;
        } else {
            cout << "Error: Time cannot be empty." << endl;
        }
    }

    void setHallNo(int h) {
        if (h >= 1 && h <= 10) {
            hallNo = h;
        } else {
            cout << "Error: Hall number must be between 1 and 10." << endl;
        }
    }

    void setAvailableSeats(int s) {
        if (s >= 0 && s <= 300) {
            availableSeats = s;
        } else {
            cout << "Error: Seats must be between 0 and 300." << endl;
        }
    }

    // --- Book a Seat ---
    bool bookSeat() {
        if (availableSeats > 0) {
            availableSeats--;
            return true;
        } else {
            cout << "Error: No seats available for this show." << endl;
            return false;
        }
    }

    // --- Cancel a Seat ---
    void cancelSeat() {
        if (availableSeats < 300) {
            availableSeats++;
        }
    }

    // --- Input Method ---
    void input() {
        int id, h, s;
        string m, t;

        cout << "Enter Show ID: ";
        cin >> id;
        setShowId(id);

        cout << "Enter Movie Name: ";
        cin.ignore();
        getline(cin, m);
        setMovieName(m);

        cout << "Enter Show Time (e.g. 6:30PM): ";
        cin >> t;
        setTime(t);

        cout << "Enter Hall No (1-10): ";
        cin >> h;
        setHallNo(h);

        cout << "Enter Available Seats (0-300): ";
        cin >> s;
        setAvailableSeats(s);
    }

    // --- Display Method ---
    void display() {
        cout << "  Show ID     : " << showId << endl;
        cout << "  Movie       : " << movieName << endl;
        cout << "  Time        : " << time << endl;
        cout << "  Hall        : " << hallNo << endl;
        cout << "  Seats Left  : " << availableSeats << endl;
    }
};

// ============================================
// ROOM CLASS (Encapsulated)
// ============================================
class Room {
private:
    int roomNo;
    string type;        // Standard, Deluxe, Suite
    float pricePerNight;
    bool isAvailable;

public:
    // --- Getters ---
    int getRoomNo() { return roomNo; }
    string getType() { return type; }
    float getPricePerNight() { return pricePerNight; }
    bool getIsAvailable() { return isAvailable; }

    // --- Setters with Validation ---
    void setRoomNo(int r) {
        if (r > 0) {
            roomNo = r;
        } else {
            cout << "Error: Room number must be positive." << endl;
        }
    }

    void setType(string t) {
        if (t == "Standard" || t == "Deluxe" || t == "Suite") {
            type = t;
        } else {
            cout << "Error: Room type must be Standard, Deluxe, or Suite." << endl;
        }
    }

    void setPricePerNight(float p) {
        if (p > 0) {
            pricePerNight = p;
        } else {
            cout << "Error: Price must be positive." << endl;
        }
    }

    void setIsAvailable(bool a) {
        isAvailable = a;
    }

    // --- Mark Room as Booked ---
    void markBooked() {
        if (isAvailable) {
            isAvailable = false;
        } else {
            cout << "Error: Room is already booked." << endl;
        }
    }

    // --- Mark Room as Available ---
    void markAvailable() {
        isAvailable = true;
    }

    // --- Input Method ---
    void input() {
        int r;
        string t;
        float p;

        cout << "Enter Room No: ";
        cin >> r;
        setRoomNo(r);

        cout << "Enter Room Type (Standard/Deluxe/Suite): ";
        cin >> t;
        setType(t);

        cout << "Enter Price Per Night (Rs.): ";
        cin >> p;
        setPricePerNight(p);

        isAvailable = true; // New rooms are available by default
    }

    // --- Display Method ---
    void display() {
        cout << "  Room No     : " << roomNo << endl;
        cout << "  Type        : " << type << endl;
        cout << "  Price/Night : Rs." << pricePerNight << endl;
        cout << "  Status      : " << (isAvailable ? "Available" : "Booked") << endl;
    }
};

// ============================================
// MAIN - Demonstrating Encapsulation
// ============================================
int main() {
    cout << "========================================" << endl;
    cout << "  Cinema & Hotel Booking System" << endl;
    cout << "  Phase 2 - Encapsulation" << endl;
    cout << "========================================" << endl << endl;

    // --- Customer Demo ---
    Customer c;
    cout << "--- Enter Customer Details ---" << endl;
    c.input();
    cout << endl;

    // Demonstrate that validation works
    cout << "--- Testing Validation ---" << endl;
    cout << "Setting phone to '123' (should fail):" << endl;
    c.setPhone("123");  // Will print error

    cout << "Setting phone to '9876543210' (should pass):" << endl;
    c.setPhone("9876543210");  // Will succeed
    cout << "Phone is now: " << c.getPhone() << endl;
    cout << endl;

    // --- Show Demo ---
    Show s;
    cout << "--- Enter Show Details ---" << endl;
    s.input();
    cout << endl;

    // Demonstrate seat booking
    cout << "--- Testing Seat Booking ---" << endl;
    cout << "Seats before booking: " << s.getAvailableSeats() << endl;
    s.bookSeat();
    cout << "Seats after booking 1: " << s.getAvailableSeats() << endl;
    s.cancelSeat();
    cout << "Seats after cancelling: " << s.getAvailableSeats() << endl;
    cout << endl;

    // --- Room Demo ---
    Room r;
    cout << "--- Enter Room Details ---" << endl;
    r.input();
    cout << endl;

    // Demonstrate room booking
    cout << "--- Testing Room Booking ---" << endl;
    cout << "Room status: " << (r.getIsAvailable() ? "Available" : "Booked") << endl;
    r.markBooked();
    cout << "After booking: " << (r.getIsAvailable() ? "Available" : "Booked") << endl;
    r.markAvailable();
    cout << "After freeing: " << (r.getIsAvailable() ? "Available" : "Booked") << endl;
    cout << endl;

    // Demonstrate invalid type
    cout << "--- Testing Invalid Room Type ---" << endl;
    cout << "Setting type to 'Luxury' (should fail):" << endl;
    r.setType("Luxury");  // Will print error
    cout << endl;

    // --- Display All ---
    cout << "========================================" << endl;
    cout << "         Final Summary" << endl;
    cout << "========================================" << endl;

    cout << endl << "--- Customer Info ---" << endl;
    c.display();

    cout << endl << "--- Show Info ---" << endl;
    s.display();

    cout << endl << "--- Room Info ---" << endl;
    r.display();

    cout << endl << "========================================" << endl;
    cout << "  Phase 2 Complete!" << endl;
    cout << "  Encapsulation Applied:" << endl;
    cout << "  - All attributes are now PRIVATE" << endl;
    cout << "  - Access only through getters/setters" << endl;
    cout << "  - Input validation in setters" << endl;
    cout << "========================================" << endl;

    return 0;
}
