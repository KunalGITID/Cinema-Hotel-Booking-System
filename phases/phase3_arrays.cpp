// ============================================
// Cinema & Hotel Booking Management System
// Phase 3: Arrays & Object Collections
// OOP Concepts: Array of Objects, Searching,
//               Menu-Driven Interface, Collections
// ============================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ============================================
// CUSTOMER CLASS
// ============================================
class Customer {
private:
    int customerId;
    string name;
    string phone;
    string email;

public:
    // Constructor
    Customer() : customerId(0), name(""), phone(""), email("") {}

    // --- Getters ---
    int getCustomerId() { return customerId; }
    string getName() { return name; }
    string getPhone() { return phone; }
    string getEmail() { return email; }

    // --- Setters with Validation ---
    void setCustomerId(int id) {
        if (id > 0)
            customerId = id;
        else
            cout << "  [!] Customer ID must be positive." << endl;
    }

    void setName(string n) {
        if (n.length() > 0)
            name = n;
        else
            cout << "  [!] Name cannot be empty." << endl;
    }

    void setPhone(string p) {
        if (p.length() == 10)
            phone = p;
        else
            cout << "  [!] Phone must be exactly 10 digits." << endl;
    }

    void setEmail(string e) {
        if (e.find('@') != string::npos && e.find('.') != string::npos)
            email = e;
        else
            cout << "  [!] Invalid email format." << endl;
    }

    // --- Input ---
    void input() {
        int id;
        string n, p, e;

        cout << "  Enter Customer ID: ";
        cin >> id;
        setCustomerId(id);

        cout << "  Enter Name: ";
        cin.ignore();
        getline(cin, n);
        setName(n);

        cout << "  Enter Phone (10 digits): ";
        cin >> p;
        setPhone(p);

        cout << "  Enter Email: ";
        cin >> e;
        setEmail(e);
    }

    // --- Display ---
    void display() {
        cout << "  | " << left << setw(6) << customerId
             << "| " << setw(20) << name
             << "| " << setw(12) << phone
             << "| " << setw(22) << email << "|" << endl;
    }
};

// ============================================
// SHOW CLASS
// ============================================
class Show {
private:
    int showId;
    string movieName;
    string time;
    int hallNo;
    int availableSeats;

public:
    // Constructor
    Show() : showId(0), movieName(""), time(""), hallNo(0), availableSeats(0) {}

    // --- Getters ---
    int getShowId() { return showId; }
    string getMovieName() { return movieName; }
    string getTime() { return time; }
    int getHallNo() { return hallNo; }
    int getAvailableSeats() { return availableSeats; }

    // --- Setters with Validation ---
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
        if (s >= 0 && s <= 300) availableSeats = s;
        else cout << "  [!] Seats must be 0-300." << endl;
    }

    // --- Book / Cancel Seat ---
    bool bookSeat() {
        if (availableSeats > 0) {
            availableSeats--;
            return true;
        }
        cout << "  [!] No seats available." << endl;
        return false;
    }

    void cancelSeat() {
        if (availableSeats < 300) availableSeats++;
    }

    // --- Input ---
    void input() {
        int id, h, s;
        string m, t;

        cout << "  Enter Show ID: ";
        cin >> id;
        setShowId(id);

        cout << "  Enter Movie Name: ";
        cin.ignore();
        getline(cin, m);
        setMovieName(m);

        cout << "  Enter Show Time (e.g. 6:30PM): ";
        cin >> t;
        setTime(t);

        cout << "  Enter Hall No (1-10): ";
        cin >> h;
        setHallNo(h);

        cout << "  Enter Available Seats (0-300): ";
        cin >> s;
        setAvailableSeats(s);
    }

    // --- Display ---
    void display() {
        cout << "  | " << left << setw(6) << showId
             << "| " << setw(22) << movieName
             << "| " << setw(10) << time
             << "| " << setw(6) << hallNo
             << "| " << setw(6) << availableSeats << "|" << endl;
    }
};

// ============================================
// ROOM CLASS
// ============================================
class Room {
private:
    int roomNo;
    string type;
    float pricePerNight;
    bool isAvailable;

public:
    // Constructor
    Room() : roomNo(0), type(""), pricePerNight(0), isAvailable(true) {}

    // --- Getters ---
    int getRoomNo() { return roomNo; }
    string getType() { return type; }
    float getPricePerNight() { return pricePerNight; }
    bool getIsAvailable() { return isAvailable; }

    // --- Setters with Validation ---
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

    // --- Mark Booked / Available ---
    void markBooked() {
        if (isAvailable) isAvailable = false;
        else cout << "  [!] Room already booked." << endl;
    }

    void markAvailable() { isAvailable = true; }

    // --- Input ---
    void input() {
        int r;
        string t;
        float p;

        cout << "  Enter Room No: ";
        cin >> r;
        setRoomNo(r);

        cout << "  Enter Room Type (Standard/Deluxe/Suite): ";
        cin >> t;
        setType(t);

        cout << "  Enter Price Per Night (Rs.): ";
        cin >> p;
        setPricePerNight(p);

        isAvailable = true;
    }

    // --- Display ---
    void display() {
        cout << "  | " << left << setw(6) << roomNo
             << "| " << setw(10) << type
             << "| Rs." << setw(10) << fixed << setprecision(0) << pricePerNight
             << "| " << setw(12) << (isAvailable ? "Available" : "Booked") << "|" << endl;
    }
};

// ============================================
// GLOBAL ARRAYS & COUNTERS
// ============================================
const int MAX_CUSTOMERS = 50;
const int MAX_SHOWS = 10;
const int MAX_ROOMS = 20;

Customer customers[MAX_CUSTOMERS];
Show shows[MAX_SHOWS];
Room rooms[MAX_ROOMS];

int customerCount = 0;
int showCount = 0;
int roomCount = 0;

// ============================================
// UTILITY FUNCTIONS
// ============================================

void printLine() {
    cout << "  ";
    for (int i = 0; i < 66; i++) cout << "-";
    cout << endl;
}

void printDoubleLine() {
    cout << "  ";
    for (int i = 0; i < 66; i++) cout << "=";
    cout << endl;
}

// ============================================
// CUSTOMER MANAGEMENT FUNCTIONS
// ============================================

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        cout << "  [!] Maximum customers reached (" << MAX_CUSTOMERS << ")." << endl;
        return;
    }

    // Check for duplicate ID
    cout << endl << "  --- Add New Customer ---" << endl;
    customers[customerCount].input();

    // Verify no duplicate ID
    int newId = customers[customerCount].getCustomerId();
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].getCustomerId() == newId) {
            cout << "  [!] Customer ID " << newId << " already exists. Cancelled." << endl;
            return;
        }
    }

    customerCount++;
    cout << "  [+] Customer added successfully! Total: " << customerCount << endl;
}

void viewAllCustomers() {
    if (customerCount == 0) {
        cout << "  [!] No customers registered yet." << endl;
        return;
    }

    cout << endl << "  --- All Customers (" << customerCount << ") ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "ID"
         << "| " << setw(20) << "Name"
         << "| " << setw(12) << "Phone"
         << "| " << setw(22) << "Email" << "|" << endl;
    printLine();

    for (int i = 0; i < customerCount; i++) {
        customers[i].display();
    }
    printLine();
}

void searchCustomer() {
    if (customerCount == 0) {
        cout << "  [!] No customers to search." << endl;
        return;
    }

    int id;
    cout << "  Enter Customer ID to search: ";
    cin >> id;

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].getCustomerId() == id) {
            cout << "  [+] Customer found:" << endl;
            printLine();
            cout << "  | " << left << setw(6) << "ID"
                 << "| " << setw(20) << "Name"
                 << "| " << setw(12) << "Phone"
                 << "| " << setw(22) << "Email" << "|" << endl;
            printLine();
            customers[i].display();
            printLine();
            return;
        }
    }
    cout << "  [!] Customer ID " << id << " not found." << endl;
}

void deleteCustomer() {
    if (customerCount == 0) {
        cout << "  [!] No customers to delete." << endl;
        return;
    }

    int id;
    cout << "  Enter Customer ID to delete: ";
    cin >> id;

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].getCustomerId() == id) {
            cout << "  Deleting: " << customers[i].getName() << " (ID: " << id << ")" << endl;

            // Shift remaining customers left
            for (int j = i; j < customerCount - 1; j++) {
                customers[j] = customers[j + 1];
            }
            customerCount--;
            cout << "  [+] Customer deleted. Remaining: " << customerCount << endl;
            return;
        }
    }
    cout << "  [!] Customer ID " << id << " not found." << endl;
}

// ============================================
// SHOW MANAGEMENT FUNCTIONS
// ============================================

void addShow() {
    if (showCount >= MAX_SHOWS) {
        cout << "  [!] Maximum shows reached (" << MAX_SHOWS << ")." << endl;
        return;
    }

    cout << endl << "  --- Add New Show ---" << endl;
    shows[showCount].input();

    // Check for duplicate ID
    int newId = shows[showCount].getShowId();
    for (int i = 0; i < showCount; i++) {
        if (shows[i].getShowId() == newId) {
            cout << "  [!] Show ID " << newId << " already exists. Cancelled." << endl;
            return;
        }
    }

    showCount++;
    cout << "  [+] Show added successfully! Total: " << showCount << endl;
}

void viewAllShows() {
    if (showCount == 0) {
        cout << "  [!] No shows available yet." << endl;
        return;
    }

    cout << endl << "  --- All Shows (" << showCount << ") ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "ID"
         << "| " << setw(22) << "Movie"
         << "| " << setw(10) << "Time"
         << "| " << setw(6) << "Hall"
         << "| " << setw(6) << "Seats" << "|" << endl;
    printLine();

    for (int i = 0; i < showCount; i++) {
        shows[i].display();
    }
    printLine();
}

// ============================================
// ROOM MANAGEMENT FUNCTIONS
// ============================================

void addRoom() {
    if (roomCount >= MAX_ROOMS) {
        cout << "  [!] Maximum rooms reached (" << MAX_ROOMS << ")." << endl;
        return;
    }

    cout << endl << "  --- Add New Room ---" << endl;
    rooms[roomCount].input();

    // Check for duplicate room number
    int newNo = rooms[roomCount].getRoomNo();
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].getRoomNo() == newNo) {
            cout << "  [!] Room No " << newNo << " already exists. Cancelled." << endl;
            return;
        }
    }

    roomCount++;
    cout << "  [+] Room added successfully! Total: " << roomCount << endl;
}

void viewAllRooms() {
    if (roomCount == 0) {
        cout << "  [!] No rooms available yet." << endl;
        return;
    }

    cout << endl << "  --- All Rooms (" << roomCount << ") ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "Room"
         << "| " << setw(10) << "Type"
         << "| " << setw(14) << "Price/Night"
         << "| " << setw(12) << "Status" << "|" << endl;
    printLine();

    for (int i = 0; i < roomCount; i++) {
        rooms[i].display();
    }
    printLine();
}

void viewAvailableRooms() {
    if (roomCount == 0) {
        cout << "  [!] No rooms registered yet." << endl;
        return;
    }

    cout << endl << "  --- Available Rooms ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "Room"
         << "| " << setw(10) << "Type"
         << "| " << setw(14) << "Price/Night"
         << "| " << setw(12) << "Status" << "|" << endl;
    printLine();

    int found = 0;
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].getIsAvailable()) {
            rooms[i].display();
            found++;
        }
    }

    if (found == 0) {
        cout << "  | No available rooms at the moment.                            |" << endl;
    }
    printLine();
    cout << "  Available: " << found << " / " << roomCount << " rooms" << endl;
}

// ============================================
// MAIN MENU
// ============================================

void displayMenu() {
    cout << endl;
    printDoubleLine();
    cout << "        Cinema & Hotel Booking System" << endl;
    cout << "        Phase 3 - Menu-Driven Interface" << endl;
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
    cout << endl;
    cout << "  HOTEL MANAGEMENT" << endl;
    cout << "    7.  Add Room" << endl;
    cout << "    8.  View All Rooms" << endl;
    cout << "    9.  View Available Rooms" << endl;
    cout << endl;
    cout << "    0.  Exit" << endl;
    printDoubleLine();
    cout << "  Enter your choice: ";
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "  [!] Invalid input. Please enter a number." << endl;
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
            case 7: addRoom(); break;
            case 8: viewAllRooms(); break;
            case 9: viewAvailableRooms(); break;
            case 0:
                cout << "  Thank you for using Cinema & Hotel Booking System!" << endl;
                cout << "  Phase 3 Complete!" << endl;
                printDoubleLine();
                break;
            default:
                cout << "  [!] Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
