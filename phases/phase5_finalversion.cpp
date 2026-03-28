// ================================================================
// Cinema & Hotel Booking Management System
// Phase 6: Final Polished Version
// ================================================================
// OOP Concepts Applied:
//   1. Classes & Objects (CO1)
//   2. Encapsulation - private members, getters/setters (CO2)
//   3. Arrays of Objects - collections, searching (CO3)
//   4. Inheritance - Booking -> MovieBooking, HotelBooking (CO4)
//   5. UML Diagrams - documented separately (CO5)
//
// Team Members:
//   Kunal Shukla      - RA2511056010237
//   Kushagra Jain      - RA2511056010289
//   Nourice            - RA2511056010290
//
// ================================================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ================================================================
// CONSTANTS
// ================================================================
const int MAX_CUSTOMERS = 50;
const int MAX_SHOWS = 10;
const int MAX_ROOMS = 20;
const int MAX_MOVIE_BOOKINGS = 100;
const int MAX_HOTEL_BOOKINGS = 100;

// ================================================================
// CLASS: Customer
// Demonstrates: Classes, Objects, Encapsulation
// ================================================================
class Customer {
private:
    int customerId;
    string name;
    string phone;
    string email;

public:
    // Constructor - initializes all attributes
    Customer() : customerId(0), name(""), phone(""), email("") {}

    // --- Getters (Encapsulation) ---
    int getCustomerId() { return customerId; }
    string getName() { return name; }
    string getPhone() { return phone; }
    string getEmail() { return email; }

    // --- Setters with Validation (Encapsulation + Data Hiding) ---
    bool setCustomerId(int id) {
        if (id > 0) { customerId = id; return true; }
        cout << "  [!] Customer ID must be positive." << endl;
        return false;
    }

    bool setName(string n) {
        if (n.length() > 0) { name = n; return true; }
        cout << "  [!] Name cannot be empty." << endl;
        return false;
    }

    bool setPhone(string p) {
        if (p.length() == 10) {
            // Verify all digits
            for (int i = 0; i < 10; i++) {
                if (p[i] < '0' || p[i] > '9') {
                    cout << "  [!] Phone must contain only digits." << endl;
                    return false;
                }
            }
            phone = p;
            return true;
        }
        cout << "  [!] Phone must be exactly 10 digits." << endl;
        return false;
    }

    bool setEmail(string e) {
        if (e.find('@') != string::npos && e.find('.') != string::npos) {
            email = e; return true;
        }
        cout << "  [!] Invalid email format (must contain @ and .)" << endl;
        return false;
    }

    // --- Input ---
    void input() {
        int id; string n, p, e;
        cout << "  Enter Customer ID   : "; cin >> id; setCustomerId(id);
        cout << "  Enter Name          : "; cin.ignore(); getline(cin, n); setName(n);
        cout << "  Enter Phone (10 dig): "; cin >> p; setPhone(p);
        cout << "  Enter Email         : "; cin >> e; setEmail(e);
    }

    // --- Display (table row format) ---
    void display() {
        cout << "  | " << left << setw(6) << customerId
             << "| " << setw(20) << name
             << "| " << setw(12) << phone
             << "| " << setw(24) << email << "|" << endl;
    }

    // --- Display (detailed card format) ---
    void displayCard() {
        cout << "  +------------------------------------------+" << endl;
        cout << "  | CUSTOMER DETAILS                         |" << endl;
        cout << "  +------------------------------------------+" << endl;
        cout << "  | ID    : " << left << setw(33) << customerId << "|" << endl;
        cout << "  | Name  : " << left << setw(33) << name << "|" << endl;
        cout << "  | Phone : " << left << setw(33) << phone << "|" << endl;
        cout << "  | Email : " << left << setw(33) << email << "|" << endl;
        cout << "  +------------------------------------------+" << endl;
    }
};

// ================================================================
// CLASS: Show
// Demonstrates: Encapsulation, Data Validation
// ================================================================
class Show {
private:
    int showId;
    string movieName;
    string time;
    int hallNo;
    int totalSeats;
    int availableSeats;

public:
    Show() : showId(0), movieName(""), time(""), hallNo(0),
             totalSeats(0), availableSeats(0) {}

    // Getters
    int getShowId() { return showId; }
    string getMovieName() { return movieName; }
    string getTime() { return time; }
    int getHallNo() { return hallNo; }
    int getTotalSeats() { return totalSeats; }
    int getAvailableSeats() { return availableSeats; }

    // Setters with Validation
    void setShowId(int id) {
        if (id > 0) showId = id;
        else cout << "  [!] Show ID must be positive." << endl;
    }
    void setMovieName(string m) {
        if (m.length() > 0) movieName = m;
        else cout << "  [!] Movie name cannot be empty." << endl;
    }
    void setTime(string t) {
        if (t.length() > 0) time = t;
        else cout << "  [!] Time cannot be empty." << endl;
    }
    void setHallNo(int h) {
        if (h >= 1 && h <= 10) hallNo = h;
        else cout << "  [!] Hall number must be 1-10." << endl;
    }
    void setAvailableSeats(int s) {
        if (s >= 0 && s <= 300) { availableSeats = s; totalSeats = s; }
        else cout << "  [!] Seats must be 0-300." << endl;
    }

    // Book / Cancel Seat
    bool bookSeat() {
        if (availableSeats > 0) { availableSeats--; return true; }
        cout << "  [!] No seats available for this show." << endl;
        return false;
    }
    void cancelSeat() {
        if (availableSeats < totalSeats) availableSeats++;
    }

    void input() {
        int id, h, s; string m, t;
        cout << "  Enter Show ID       : "; cin >> id; setShowId(id);
        cout << "  Enter Movie Name    : "; cin.ignore(); getline(cin, m); setMovieName(m);
        cout << "  Enter Show Time     : "; cin >> t; setTime(t);
        cout << "  Enter Hall No (1-10): "; cin >> h; setHallNo(h);
        cout << "  Enter Total Seats   : "; cin >> s; setAvailableSeats(s);
    }

    void display() {
        cout << "  | " << left << setw(6) << showId
             << "| " << setw(22) << movieName
             << "| " << setw(10) << time
             << "| " << setw(6) << hallNo
             << "| " << setw(5) << availableSeats
             << "/" << left << setw(5) << totalSeats << "|" << endl;
    }
};

// ================================================================
// CLASS: Room
// Demonstrates: Encapsulation, State Management
// ================================================================
class Room {
private:
    int roomNo;
    string type;
    float pricePerNight;
    bool isAvailable;

public:
    Room() : roomNo(0), type(""), pricePerNight(0), isAvailable(true) {}

    int getRoomNo() { return roomNo; }
    string getType() { return type; }
    float getPricePerNight() { return pricePerNight; }
    bool getIsAvailable() { return isAvailable; }

    void setRoomNo(int r) {
        if (r > 0) roomNo = r;
        else cout << "  [!] Room number must be positive." << endl;
    }
    void setType(string t) {
        if (t == "Standard" || t == "Deluxe" || t == "Suite") type = t;
        else cout << "  [!] Type must be Standard, Deluxe, or Suite." << endl;
    }
    void setPricePerNight(float p) {
        if (p > 0) pricePerNight = p;
        else cout << "  [!] Price must be positive." << endl;
    }
    void setIsAvailable(bool a) { isAvailable = a; }

    void markBooked() {
        if (isAvailable) isAvailable = false;
        else cout << "  [!] Room already booked." << endl;
    }
    void markAvailable() { isAvailable = true; }

    void input() {
        int r; string t; float p;
        cout << "  Enter Room No       : "; cin >> r; setRoomNo(r);
        cout << "  Enter Type (Standard/Deluxe/Suite): "; cin >> t; setType(t);
        cout << "  Enter Price/Night   : "; cin >> p; setPricePerNight(p);
        isAvailable = true;
    }

    void display() {
        cout << "  | " << left << setw(6) << roomNo
             << "| " << setw(10) << type
             << "| Rs." << setw(10) << fixed << setprecision(0) << pricePerNight
             << "| " << setw(12) << (isAvailable ? "Available" : "Booked") << "|" << endl;
    }
};

// ================================================================
// BASE CLASS: Booking (Phase 4 - Inheritance)
// Demonstrates: Base Class, Protected Members
// ================================================================
class Booking {
protected:
    int bookingId;
    int customerId;
    string customerName;
    string date;
    float totalAmount;
    string bookingType;

public:
    Booking() : bookingId(0), customerId(0), customerName(""),
                date(""), totalAmount(0), bookingType("") {}

    // Getters
    int getBookingId() { return bookingId; }
    int getCustomerId() { return customerId; }
    string getCustomerName() { return customerName; }
    string getDate() { return date; }
    float getTotalAmount() { return totalAmount; }
    string getBookingType() { return bookingType; }

    // Setters
    void setBookingId(int id) {
        if (id > 0) bookingId = id;
        else cout << "  [!] Booking ID must be positive." << endl;
    }
    void setCustomerId(int id) {
        if (id > 0) customerId = id;
        else cout << "  [!] Customer ID must be positive." << endl;
    }
    void setCustomerName(string n) { customerName = n; }
    void setDate(string d) {
        if (d.length() > 0) date = d;
        else cout << "  [!] Date cannot be empty." << endl;
    }
    void setTotalAmount(float a) {
        if (a >= 0) totalAmount = a;
        else cout << "  [!] Amount cannot be negative." << endl;
    }

    // Base display
    void display() {
        cout << "  Booking #" << bookingId << " | "
             << bookingType << " | Customer: "
             << customerName << " (ID:" << customerId << ")"
             << " | Rs." << fixed << setprecision(0) << totalAmount << endl;
    }
};

// ================================================================
// DERIVED CLASS: MovieBooking (inherits Booking)
// Demonstrates: Inheritance, Method Overriding, Code Reuse
// ================================================================
class MovieBooking : public Booking {
private:
    string movieName;
    string showTime;
    int seatNumber;
    int hallNumber;
    int showId;

public:
    MovieBooking() : movieName(""), showTime(""), seatNumber(0),
                     hallNumber(0), showId(0) {
        bookingType = "Movie";
    }

    // Getters
    string getMovieName() { return movieName; }
    string getShowTime() { return showTime; }
    int getSeatNumber() { return seatNumber; }
    int getHallNumber() { return hallNumber; }
    int getShowId() { return showId; }

    // Setters
    void setMovieName(string m) { movieName = m; }
    void setShowTime(string t) { showTime = t; }
    void setSeatNumber(int s) {
        if (s > 0) seatNumber = s;
        else cout << "  [!] Seat number must be positive." << endl;
    }
    void setHallNumber(int h) { hallNumber = h; }
    void setShowId(int id) { showId = id; }

    // Input for movie booking
    void input(int bId, int custId, string custName) {
        setBookingId(bId);
        setCustomerId(custId);
        setCustomerName(custName);

        string d; int seat; float price;
        cout << "  Enter Booking Date (DD/MM/YYYY): "; cin >> d; setDate(d);
        cout << "  Enter Seat Number              : "; cin >> seat; setSeatNumber(seat);
        cout << "  Enter Ticket Price (Rs.)       : "; cin >> price; setTotalAmount(price);
    }

    // Overridden display - MOVIE TICKET format
    void display() {
        cout << "  +--------------------------------------------+" << endl;
        cout << "  |            ** MOVIE TICKET **               |" << endl;
        cout << "  +--------------------------------------------+" << endl;
        cout << "  | Booking ID  : " << left << setw(29) << bookingId << "|" << endl;
        cout << "  | Customer    : " << left << setw(29) << customerName << "|" << endl;
        cout << "  | Customer ID : " << left << setw(29) << customerId << "|" << endl;
        cout << "  | Date        : " << left << setw(29) << date << "|" << endl;
        cout << "  +--------------------------------------------+" << endl;
        cout << "  | Movie       : " << left << setw(29) << movieName << "|" << endl;
        cout << "  | Show Time   : " << left << setw(29) << showTime << "|" << endl;
        cout << "  | Hall No     : " << left << setw(29) << hallNumber << "|" << endl;
        cout << "  | Seat No     : " << left << setw(29) << seatNumber << "|" << endl;
        cout << "  +--------------------------------------------+" << endl;
        cout << "  | TOTAL       : Rs." << left << setw(25) << fixed << setprecision(0) << totalAmount << "|" << endl;
        cout << "  +--------------------------------------------+" << endl;
    }

    // Compact display for booking list
    void displayRow() {
        cout << "  | " << left << setw(6) << bookingId
             << "| " << setw(8) << customerId
             << "| " << setw(12) << customerName
             << "| " << setw(18) << movieName
             << "| " << setw(8) << showTime
             << "| " << setw(5) << seatNumber
             << "| Rs." << setw(8) << fixed << setprecision(0) << totalAmount << "|" << endl;
    }
};

// ================================================================
// DERIVED CLASS: HotelBooking (inherits Booking)
// Demonstrates: Inheritance, Method Overriding, Code Reuse
// ================================================================
class HotelBooking : public Booking {
private:
    int roomNumber;
    string roomType;
    string checkIn;
    string checkOut;
    int nights;
    float pricePerNight;

public:
    HotelBooking() : roomNumber(0), roomType(""), checkIn(""),
                     checkOut(""), nights(0), pricePerNight(0) {
        bookingType = "Hotel";
    }

    // Getters
    int getRoomNumber() { return roomNumber; }
    string getRoomType() { return roomType; }
    string getCheckIn() { return checkIn; }
    string getCheckOut() { return checkOut; }
    int getNights() { return nights; }
    float getPricePerNight() { return pricePerNight; }

    // Setters
    void setRoomNumber(int r) {
        if (r > 0) roomNumber = r;
        else cout << "  [!] Room number must be positive." << endl;
    }
    void setRoomType(string t) { roomType = t; }
    void setCheckIn(string d) { checkIn = d; }
    void setCheckOut(string d) { checkOut = d; }
    void setNights(int n) {
        if (n > 0) nights = n;
        else cout << "  [!] Nights must be at least 1." << endl;
    }
    void setPricePerNight(float p) { pricePerNight = p; }

    // Input for hotel booking
    void input(int bId, int custId, string custName) {
        setBookingId(bId);
        setCustomerId(custId);
        setCustomerName(custName);

        string d, ci, co; int n; float ppn;
        cout << "  Enter Booking Date (DD/MM/YYYY)  : "; cin >> d; setDate(d);
        cout << "  Enter Check-In Date (DD/MM/YYYY) : "; cin >> ci; setCheckIn(ci);
        cout << "  Enter Check-Out Date (DD/MM/YYYY): "; cin >> co; setCheckOut(co);
        cout << "  Enter Number of Nights           : "; cin >> n; setNights(n);
        cout << "  Enter Price Per Night (Rs.)      : "; cin >> ppn; setPricePerNight(ppn);

        float total = ppn * n;
        setTotalAmount(total);
        cout << "  >> Total Amount: Rs." << fixed << setprecision(0) << total << endl;
    }

    // Overridden display - HOTEL RECEIPT format
    void display() {
        cout << "  +--------------------------------------------+" << endl;
        cout << "  |           ** HOTEL RECEIPT **               |" << endl;
        cout << "  +--------------------------------------------+" << endl;
        cout << "  | Booking ID  : " << left << setw(29) << bookingId << "|" << endl;
        cout << "  | Customer    : " << left << setw(29) << customerName << "|" << endl;
        cout << "  | Customer ID : " << left << setw(29) << customerId << "|" << endl;
        cout << "  | Date        : " << left << setw(29) << date << "|" << endl;
        cout << "  +--------------------------------------------+" << endl;
        cout << "  | Room No     : " << left << setw(29) << roomNumber << "|" << endl;
        cout << "  | Room Type   : " << left << setw(29) << roomType << "|" << endl;
        cout << "  | Check-In    : " << left << setw(29) << checkIn << "|" << endl;
        cout << "  | Check-Out   : " << left << setw(29) << checkOut << "|" << endl;
        cout << "  | Nights      : " << left << setw(29) << nights << "|" << endl;
        cout << "  | Rate/Night  : Rs." << left << setw(25) << fixed << setprecision(0) << pricePerNight << "|" << endl;
        cout << "  +--------------------------------------------+" << endl;
        cout << "  | TOTAL       : Rs." << left << setw(25) << fixed << setprecision(0) << totalAmount << "|" << endl;
        cout << "  +--------------------------------------------+" << endl;
    }

    // Compact display for booking list
    void displayRow() {
        cout << "  | " << left << setw(6) << bookingId
             << "| " << setw(8) << customerId
             << "| " << setw(12) << customerName
             << "| Rm " << setw(4) << roomNumber
             << "| " << setw(10) << roomType
             << "| " << setw(4) << nights << "N"
             << " | Rs." << setw(8) << fixed << setprecision(0) << totalAmount << "|" << endl;
    }
};

// ================================================================
// GLOBAL DATA (Array of Objects - Phase 3)
// ================================================================
Customer customers[MAX_CUSTOMERS];
Show shows[MAX_SHOWS];
Room rooms[MAX_ROOMS];
MovieBooking movieBookings[MAX_MOVIE_BOOKINGS];
HotelBooking hotelBookings[MAX_HOTEL_BOOKINGS];

int customerCount = 0;
int showCount = 0;
int roomCount = 0;
int movieBookingCount = 0;
int hotelBookingCount = 0;
int nextBookingId = 1001;

// ================================================================
// UTILITY FUNCTIONS
// ================================================================
void printLine(int len = 70) {
    cout << "  ";
    for (int i = 0; i < len; i++) cout << "-";
    cout << endl;
}
void printDoubleLine(int len = 70) {
    cout << "  ";
    for (int i = 0; i < len; i++) cout << "=";
    cout << endl;
}
void pressEnter() {
    cout << endl << "  Press Enter to continue...";
    cin.ignore();
    cin.get();
}

// --- Search Helpers ---
int findCustomer(int id) {
    for (int i = 0; i < customerCount; i++)
        if (customers[i].getCustomerId() == id) return i;
    return -1;
}
int findShow(int id) {
    for (int i = 0; i < showCount; i++)
        if (shows[i].getShowId() == id) return i;
    return -1;
}
int findRoom(int no) {
    for (int i = 0; i < roomCount; i++)
        if (rooms[i].getRoomNo() == no) return i;
    return -1;
}
int findMovieBooking(int bId) {
    for (int i = 0; i < movieBookingCount; i++)
        if (movieBookings[i].getBookingId() == bId) return i;
    return -1;
}
int findHotelBooking(int bId) {
    for (int i = 0; i < hotelBookingCount; i++)
        if (hotelBookings[i].getBookingId() == bId) return i;
    return -1;
}

// ================================================================
// 1. CUSTOMER MANAGEMENT
// ================================================================
void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        cout << "  [!] Maximum customers reached (" << MAX_CUSTOMERS << ")." << endl;
        return;
    }
    cout << endl << "  --- Add New Customer ---" << endl;
    customers[customerCount].input();
    int newId = customers[customerCount].getCustomerId();
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].getCustomerId() == newId) {
            cout << "  [!] Customer ID " << newId << " already exists." << endl;
            return;
        }
    }
    customerCount++;
    cout << "  [+] Customer added successfully! (Total: " << customerCount << ")" << endl;
}

void viewAllCustomers() {
    if (customerCount == 0) { cout << "  [!] No customers registered." << endl; return; }
    cout << endl << "  --- All Customers (" << customerCount << ") ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "ID" << "| " << setw(20) << "Name"
         << "| " << setw(12) << "Phone" << "| " << setw(24) << "Email" << "|" << endl;
    printLine();
    for (int i = 0; i < customerCount; i++) customers[i].display();
    printLine();
}

void searchCustomer() {
    if (customerCount == 0) { cout << "  [!] No customers to search." << endl; return; }
    int id; cout << "  Enter Customer ID to search: "; cin >> id;
    int idx = findCustomer(id);
    if (idx != -1) {
        cout << "  [+] Customer found:" << endl;
        customers[idx].displayCard();
        // Show their bookings too
        int mb = 0, hb = 0;
        for (int i = 0; i < movieBookingCount; i++)
            if (movieBookings[i].getCustomerId() == id) mb++;
        for (int i = 0; i < hotelBookingCount; i++)
            if (hotelBookings[i].getCustomerId() == id) hb++;
        cout << "  Active Bookings: " << mb << " movie, " << hb << " hotel" << endl;
    } else {
        cout << "  [!] Customer ID " << id << " not found." << endl;
    }
}

void deleteCustomer() {
    if (customerCount == 0) { cout << "  [!] No customers to delete." << endl; return; }
    int id; cout << "  Enter Customer ID to delete: "; cin >> id;
    int idx = findCustomer(id);
    if (idx != -1) {
        // Check for active bookings
        for (int i = 0; i < movieBookingCount; i++) {
            if (movieBookings[i].getCustomerId() == id) {
                cout << "  [!] Cannot delete - customer has active movie bookings." << endl;
                return;
            }
        }
        for (int i = 0; i < hotelBookingCount; i++) {
            if (hotelBookings[i].getCustomerId() == id) {
                cout << "  [!] Cannot delete - customer has active hotel bookings." << endl;
                return;
            }
        }
        cout << "  Deleting: " << customers[idx].getName() << " (ID: " << id << ")" << endl;
        for (int j = idx; j < customerCount - 1; j++) customers[j] = customers[j + 1];
        customerCount--;
        cout << "  [+] Customer deleted. Remaining: " << customerCount << endl;
    } else {
        cout << "  [!] Customer ID " << id << " not found." << endl;
    }
}

// ================================================================
// 2. SHOW MANAGEMENT
// ================================================================
void addShow() {
    if (showCount >= MAX_SHOWS) { cout << "  [!] Maximum shows reached." << endl; return; }
    cout << endl << "  --- Add New Show ---" << endl;
    shows[showCount].input();
    int newId = shows[showCount].getShowId();
    for (int i = 0; i < showCount; i++) {
        if (shows[i].getShowId() == newId) {
            cout << "  [!] Show ID " << newId << " already exists." << endl;
            return;
        }
    }
    showCount++;
    cout << "  [+] Show added! (Total: " << showCount << ")" << endl;
}

void viewAllShows() {
    if (showCount == 0) { cout << "  [!] No shows available." << endl; return; }
    cout << endl << "  --- All Shows (" << showCount << ") ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "ID" << "| " << setw(22) << "Movie"
         << "| " << setw(10) << "Time" << "| " << setw(6) << "Hall"
         << "| " << setw(11) << "Seats" << "|" << endl;
    printLine();
    for (int i = 0; i < showCount; i++) shows[i].display();
    printLine();
}

// ================================================================
// 3. ROOM MANAGEMENT
// ================================================================
void addRoom() {
    if (roomCount >= MAX_ROOMS) { cout << "  [!] Maximum rooms reached." << endl; return; }
    cout << endl << "  --- Add New Room ---" << endl;
    rooms[roomCount].input();
    int newNo = rooms[roomCount].getRoomNo();
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].getRoomNo() == newNo) {
            cout << "  [!] Room No " << newNo << " already exists." << endl;
            return;
        }
    }
    roomCount++;
    cout << "  [+] Room added! (Total: " << roomCount << ")" << endl;
}

void viewAllRooms() {
    if (roomCount == 0) { cout << "  [!] No rooms available." << endl; return; }
    cout << endl << "  --- All Rooms (" << roomCount << ") ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "Room" << "| " << setw(10) << "Type"
         << "| " << setw(14) << "Price/Night" << "| " << setw(12) << "Status" << "|" << endl;
    printLine();
    for (int i = 0; i < roomCount; i++) rooms[i].display();
    printLine();
}

void viewAvailableRooms() {
    if (roomCount == 0) { cout << "  [!] No rooms registered." << endl; return; }
    cout << endl << "  --- Available Rooms ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "Room" << "| " << setw(10) << "Type"
         << "| " << setw(14) << "Price/Night" << "| " << setw(12) << "Status" << "|" << endl;
    printLine();
    int found = 0;
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].getIsAvailable()) { rooms[i].display(); found++; }
    }
    if (found == 0)
        cout << "  | No available rooms at the moment.                              |" << endl;
    printLine();
    cout << "  Available: " << found << " / " << roomCount << " rooms" << endl;
}

// ================================================================
// 4. MOVIE BOOKING (Inheritance - MovieBooking : Booking)
// ================================================================
void bookMovieTicket() {
    if (movieBookingCount >= MAX_MOVIE_BOOKINGS) {
        cout << "  [!] Maximum movie bookings reached." << endl; return;
    }
    if (customerCount == 0) {
        cout << "  [!] No customers. Add a customer first (Option 1)." << endl; return;
    }
    if (showCount == 0) {
        cout << "  [!] No shows. Add a show first (Option 5)." << endl; return;
    }

    cout << endl << "  --- Book Movie Ticket ---" << endl;

    // Step 1: Verify customer
    int custId;
    cout << "  Enter Customer ID: "; cin >> custId;
    int custIdx = findCustomer(custId);
    if (custIdx == -1) {
        cout << "  [!] Customer not found." << endl; return;
    }
    cout << "  Customer: " << customers[custIdx].getName() << endl;

    // Step 2: Show available shows
    cout << endl;
    viewAllShows();

    // Step 3: Select show
    int showId;
    cout << endl << "  Enter Show ID to book: "; cin >> showId;
    int showIdx = findShow(showId);
    if (showIdx == -1) { cout << "  [!] Show not found." << endl; return; }
    if (shows[showIdx].getAvailableSeats() <= 0) {
        cout << "  [!] No seats available for this show." << endl; return;
    }

    // Step 4: Create MovieBooking
    cout << endl << "  Booking for: " << shows[showIdx].getMovieName()
         << " at " << shows[showIdx].getTime()
         << " (Hall " << shows[showIdx].getHallNo() << ")" << endl << endl;

    movieBookings[movieBookingCount].input(nextBookingId, custId,
                                            customers[custIdx].getName());
    movieBookings[movieBookingCount].setMovieName(shows[showIdx].getMovieName());
    movieBookings[movieBookingCount].setShowTime(shows[showIdx].getTime());
    movieBookings[movieBookingCount].setHallNumber(shows[showIdx].getHallNo());
    movieBookings[movieBookingCount].setShowId(shows[showIdx].getShowId());

    shows[showIdx].bookSeat();

    cout << endl << "  [+] Movie ticket booked successfully!" << endl << endl;
    movieBookings[movieBookingCount].display();

    movieBookingCount++;
    nextBookingId++;
}

void cancelMovieBooking() {
    if (movieBookingCount == 0) {
        cout << "  [!] No movie bookings to cancel." << endl; return;
    }

    int bId;
    cout << "  Enter Booking ID to cancel: "; cin >> bId;
    int idx = findMovieBooking(bId);
    if (idx != -1) {
        cout << "  Cancelling:" << endl;
        movieBookings[idx].display();

        // Free the seat
        int sId = movieBookings[idx].getShowId();
        int showIdx = findShow(sId);
        if (showIdx != -1) shows[showIdx].cancelSeat();

        for (int j = idx; j < movieBookingCount - 1; j++)
            movieBookings[j] = movieBookings[j + 1];
        movieBookingCount--;
        cout << "  [+] Movie booking cancelled. Seat freed." << endl;
    } else {
        cout << "  [!] Booking ID " << bId << " not found in movie bookings." << endl;
    }
}

// ================================================================
// 5. HOTEL BOOKING (Inheritance - HotelBooking : Booking)
// ================================================================
void bookHotelRoom() {
    if (hotelBookingCount >= MAX_HOTEL_BOOKINGS) {
        cout << "  [!] Maximum hotel bookings reached." << endl; return;
    }
    if (customerCount == 0) {
        cout << "  [!] No customers. Add a customer first (Option 1)." << endl; return;
    }
    if (roomCount == 0) {
        cout << "  [!] No rooms. Add a room first (Option 9)." << endl; return;
    }

    cout << endl << "  --- Book Hotel Room ---" << endl;

    // Step 1: Verify customer
    int custId;
    cout << "  Enter Customer ID: "; cin >> custId;
    int custIdx = findCustomer(custId);
    if (custIdx == -1) {
        cout << "  [!] Customer not found." << endl; return;
    }
    cout << "  Customer: " << customers[custIdx].getName() << endl;

    // Step 2: Show available rooms
    cout << endl;
    viewAvailableRooms();

    // Step 3: Select room
    int roomNo;
    cout << endl << "  Enter Room No to book: "; cin >> roomNo;
    int roomIdx = findRoom(roomNo);
    if (roomIdx == -1) { cout << "  [!] Room not found." << endl; return; }
    if (!rooms[roomIdx].getIsAvailable()) {
        cout << "  [!] Room " << roomNo << " is already booked." << endl; return;
    }

    // Step 4: Create HotelBooking
    cout << endl << "  Booking Room " << rooms[roomIdx].getRoomNo()
         << " (" << rooms[roomIdx].getType()
         << " - Rs." << fixed << setprecision(0) << rooms[roomIdx].getPricePerNight()
         << "/night)" << endl << endl;

    hotelBookings[hotelBookingCount].input(nextBookingId, custId,
                                            customers[custIdx].getName());
    hotelBookings[hotelBookingCount].setRoomNumber(rooms[roomIdx].getRoomNo());
    hotelBookings[hotelBookingCount].setRoomType(rooms[roomIdx].getType());

    rooms[roomIdx].markBooked();

    cout << endl << "  [+] Hotel room booked successfully!" << endl << endl;
    hotelBookings[hotelBookingCount].display();

    hotelBookingCount++;
    nextBookingId++;
}

void cancelHotelBooking() {
    if (hotelBookingCount == 0) {
        cout << "  [!] No hotel bookings to cancel." << endl; return;
    }

    int bId;
    cout << "  Enter Booking ID to cancel: "; cin >> bId;
    int idx = findHotelBooking(bId);
    if (idx != -1) {
        cout << "  Cancelling:" << endl;
        hotelBookings[idx].display();

        // Free the room
        int roomNo = hotelBookings[idx].getRoomNumber();
        int roomIdx = findRoom(roomNo);
        if (roomIdx != -1) rooms[roomIdx].markAvailable();

        for (int j = idx; j < hotelBookingCount - 1; j++)
            hotelBookings[j] = hotelBookings[j + 1];
        hotelBookingCount--;
        cout << "  [+] Hotel booking cancelled. Room freed." << endl;
    } else {
        cout << "  [!] Booking ID " << bId << " not found in hotel bookings." << endl;
    }
}

// ================================================================
// 6. VIEW ALL BOOKINGS
// ================================================================
void viewAllBookings() {
    int total = movieBookingCount + hotelBookingCount;
    if (total == 0) { cout << "  [!] No bookings yet." << endl; return; }

    cout << endl;
    printDoubleLine();
    cout << "        All Bookings (" << total << " total)" << endl;
    printDoubleLine();

    if (movieBookingCount > 0) {
        cout << endl << "  MOVIE BOOKINGS (" << movieBookingCount << "):" << endl;
        printLine(75);
        cout << "  | " << left << setw(6) << "BkID"
             << "| " << setw(8) << "CustID"
             << "| " << setw(12) << "Name"
             << "| " << setw(18) << "Movie"
             << "| " << setw(8) << "Time"
             << "| " << setw(5) << "Seat"
             << "| " << setw(12) << "Amount" << "|" << endl;
        printLine(75);
        for (int i = 0; i < movieBookingCount; i++)
            movieBookings[i].displayRow();
        printLine(75);
    }

    if (hotelBookingCount > 0) {
        cout << endl << "  HOTEL BOOKINGS (" << hotelBookingCount << "):" << endl;
        printLine(65);
        cout << "  | " << left << setw(6) << "BkID"
             << "| " << setw(8) << "CustID"
             << "| " << setw(12) << "Name"
             << "| " << setw(8) << "Room"
             << "| " << setw(10) << "Type"
             << "| " << setw(6) << "Stay"
             << "| " << setw(12) << "Amount" << "|" << endl;
        printLine(65);
        for (int i = 0; i < hotelBookingCount; i++)
            hotelBookings[i].displayRow();
        printLine(65);
    }

    // Revenue summary
    float movieRevenue = 0, hotelRevenue = 0;
    for (int i = 0; i < movieBookingCount; i++)
        movieRevenue += movieBookings[i].getTotalAmount();
    for (int i = 0; i < hotelBookingCount; i++)
        hotelRevenue += hotelBookings[i].getTotalAmount();

    cout << endl;
    printDoubleLine();
    cout << "  Summary:" << endl;
    cout << "    Movie Bookings : " << movieBookingCount
         << "  (Revenue: Rs." << fixed << setprecision(0) << movieRevenue << ")" << endl;
    cout << "    Hotel Bookings : " << hotelBookingCount
         << "  (Revenue: Rs." << fixed << setprecision(0) << hotelRevenue << ")" << endl;
    cout << "    Total Revenue  : Rs." << fixed << setprecision(0)
         << (movieRevenue + hotelRevenue) << endl;
    printDoubleLine();
}

// ================================================================
// MAIN MENU
// ================================================================
void displayMenu() {
    cout << endl;
    printDoubleLine();
    cout << "      Cinema & Hotel Booking Management System" << endl;
    cout << "      Final Version | All OOP Concepts Applied" << endl;
    printDoubleLine();
    cout << endl;
    cout << "  CUSTOMER MANAGEMENT" << endl;
    cout << "    1.  Add Customer" << endl;
    cout << "    2.  View All Customers" << endl;
    cout << "    3.  Search Customer" << endl;
    cout << "    4.  Delete Customer" << endl;
    cout << endl;
    cout << "  CINEMA MANAGEMENT" << endl;
    cout << "    5.  Add Show" << endl;
    cout << "    6.  View All Shows" << endl;
    cout << "    7.  Book Movie Ticket" << endl;
    cout << "    8.  Cancel Movie Booking" << endl;
    cout << endl;
    cout << "  HOTEL MANAGEMENT" << endl;
    cout << "    9.  Add Room" << endl;
    cout << "    10. View All Rooms" << endl;
    cout << "    11. View Available Rooms" << endl;
    cout << "    12. Book Hotel Room" << endl;
    cout << "    13. Cancel Hotel Booking" << endl;
    cout << endl;
    cout << "  REPORTS" << endl;
    cout << "    14. View All Bookings (with Revenue)" << endl;
    cout << endl;
    cout << "    0.  Exit" << endl;
    printDoubleLine();
    cout << "  Enter your choice: ";
}

// ================================================================
// MAIN FUNCTION
// ================================================================
int main() {
    int choice;

    cout << endl;
    printDoubleLine();
    cout << "  Welcome to the Cinema & Hotel Booking Management System!" << endl;
    cout << "  Developed by: Kunal Shukla, Kushagra Jain, Nourice" << endl;
    cout << "  B.Tech CSE (Data Science) - Semester 2" << endl;
    printDoubleLine();

    do {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "  [!] Invalid input. Please enter a number (0-14)." << endl;
            continue;
        }

        cout << endl;

        switch (choice) {
            case 1: addCustomer(); break;
            case 2: viewAllCustomers(); break;
            case 3: searchCustomer(); break;
            case 4: deleteCustomer(); break;
            case 5: addShow(); break;
            case 6: viewAllShows(); break;
            case 7: bookMovieTicket(); break;
            case 8: cancelMovieBooking(); break;
            case 9: addRoom(); break;
            case 10: viewAllRooms(); break;
            case 11: viewAvailableRooms(); break;
            case 12: bookHotelRoom(); break;
            case 13: cancelHotelBooking(); break;
            case 14: viewAllBookings(); break;
            case 0:
                cout << endl;
                printDoubleLine();
                cout << "  Thank you for using Cinema & Hotel Booking System!" << endl;
                cout << endl;
                cout << "  OOP Concepts Demonstrated:" << endl;
                cout << "    [CO1] Classes & Objecxts" << endl;
                cout << "    [CO2] Encapsulation (private, getters/setters)" << endl;
                cout << "    [CO3] Arrays of Objects & Collections" << endl;
                cout << "    [CO4] Inheritance (Booking -> MovieBooking, HotelBooking)" << endl;
                cout << "    [CO5] UML Diagrams (documented separately)" << endl;
                cout << endl;
                cout << "  Team: Kunal Shukla | Kushagra Jain | Nourice" << endl;
                printDoubleLine();
                break;
            default:
                cout << "  [!] Invalid choice. Please enter 0-14." << endl;
        }

    } while (choice != 0);

    return 0;
}
