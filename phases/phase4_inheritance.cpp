// ============================================
// Cinema & Hotel Booking Management System
// Phase 4: Inheritance
// OOP Concepts: Base & Derived Classes,
//               Code Reuse, Method Overriding
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
    Customer() : customerId(0), name(""), phone(""), email("") {}

    // Getters
    int getCustomerId() { return customerId; }
    string getName() { return name; }
    string getPhone() { return phone; }
    string getEmail() { return email; }

    // Setters with Validation
    void setCustomerId(int id) {
        if (id > 0) customerId = id;
        else cout << "  [!] Customer ID must be positive." << endl;
    }

    void setName(string n) {
        if (n.length() > 0) name = n;
        else cout << "  [!] Name cannot be empty." << endl;
    }

    void setPhone(string p) {
        if (p.length() == 10) phone = p;
        else cout << "  [!] Phone must be exactly 10 digits." << endl;
    }

    void setEmail(string e) {
        if (e.find('@') != string::npos && e.find('.') != string::npos) email = e;
        else cout << "  [!] Invalid email format." << endl;
    }

    void input() {
        int id; string n, p, e;
        cout << "  Enter Customer ID: "; cin >> id; setCustomerId(id);
        cout << "  Enter Name: "; cin.ignore(); getline(cin, n); setName(n);
        cout << "  Enter Phone (10 digits): "; cin >> p; setPhone(p);
        cout << "  Enter Email: "; cin >> e; setEmail(e);
    }

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
    Show() : showId(0), movieName(""), time(""), hallNo(0), availableSeats(0) {}

    int getShowId() { return showId; }
    string getMovieName() { return movieName; }
    string getTime() { return time; }
    int getHallNo() { return hallNo; }
    int getAvailableSeats() { return availableSeats; }

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

    bool bookSeat() {
        if (availableSeats > 0) { availableSeats--; return true; }
        cout << "  [!] No seats available." << endl;
        return false;
    }
    void cancelSeat() { if (availableSeats < 300) availableSeats++; }

    void input() {
        int id, h, s; string m, t;
        cout << "  Enter Show ID: "; cin >> id; setShowId(id);
        cout << "  Enter Movie Name: "; cin.ignore(); getline(cin, m); setMovieName(m);
        cout << "  Enter Show Time (e.g. 6:30PM): "; cin >> t; setTime(t);
        cout << "  Enter Hall No (1-10): "; cin >> h; setHallNo(h);
        cout << "  Enter Available Seats (0-300): "; cin >> s; setAvailableSeats(s);
    }

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
        cout << "  Enter Room No: "; cin >> r; setRoomNo(r);
        cout << "  Enter Room Type (Standard/Deluxe/Suite): "; cin >> t; setType(t);
        cout << "  Enter Price Per Night (Rs.): "; cin >> p; setPricePerNight(p);
        isAvailable = true;
    }

    void display() {
        cout << "  | " << left << setw(6) << roomNo
             << "| " << setw(10) << type
             << "| Rs." << setw(10) << fixed << setprecision(0) << pricePerNight
             << "| " << setw(12) << (isAvailable ? "Available" : "Booked") << "|" << endl;
    }
};

// ============================================
// BOOKING BASE CLASS (Phase 4 - NEW)
// ============================================
class Booking {
protected:
    int bookingId;
    int customerId;
    string date;
    float totalAmount;
    string bookingType; // "Movie" or "Hotel"

public:
    Booking() : bookingId(0), customerId(0), date(""), totalAmount(0), bookingType("") {}

    // Getters
    int getBookingId() { return bookingId; }
    int getCustomerId() { return customerId; }
    string getDate() { return date; }
    float getTotalAmount() { return totalAmount; }
    string getBookingType() { return bookingType; }

    // Setters with Validation
    void setBookingId(int id) {
        if (id > 0) bookingId = id;
        else cout << "  [!] Booking ID must be positive." << endl;
    }
    void setCustomerId(int id) {
        if (id > 0) customerId = id;
        else cout << "  [!] Customer ID must be positive." << endl;
    }
    void setDate(string d) {
        if (d.length() > 0) date = d;
        else cout << "  [!] Date cannot be empty." << endl;
    }
    void setTotalAmount(float a) {
        if (a >= 0) totalAmount = a;
        else cout << "  [!] Amount cannot be negative." << endl;
    }

    // Base display - shows common booking info
    void display() {
        cout << "  Booking ID   : " << bookingId << endl;
        cout << "  Customer ID  : " << customerId << endl;
        cout << "  Date         : " << date << endl;
        cout << "  Type         : " << bookingType << endl;
        cout << "  Amount       : Rs." << fixed << setprecision(0) << totalAmount << endl;
    }
};

// ============================================
// MOVIEBOOKING - DERIVED FROM BOOKING (Phase 4)
// Demonstrates: Inheritance, Code Reuse
// ============================================
class MovieBooking : public Booking {
private:
    string movieName;
    string showTime;
    int seatNumber;
    int hallNumber;

public:
    MovieBooking() : movieName(""), showTime(""), seatNumber(0), hallNumber(0) {
        bookingType = "Movie";
    }

    // Getters
    string getMovieName() { return movieName; }
    string getShowTime() { return showTime; }
    int getSeatNumber() { return seatNumber; }
    int getHallNumber() { return hallNumber; }

    // Setters
    void setMovieName(string m) { movieName = m; }
    void setShowTime(string t) { showTime = t; }
    void setSeatNumber(int s) {
        if (s > 0) seatNumber = s;
        else cout << "  [!] Seat number must be positive." << endl;
    }
    void setHallNumber(int h) {
        if (h >= 1 && h <= 10) hallNumber = h;
        else cout << "  [!] Hall number must be 1-10." << endl;
    }

    // Input - takes booking details for a movie
    void input(int bId, int custId) {
        string d, m, t;
        int seat, hall;
        float price;

        setBookingId(bId);
        setCustomerId(custId);

        cout << "  Enter Booking Date (DD/MM/YYYY): "; cin >> d; setDate(d);
        cout << "  Enter Movie Name: "; cin.ignore(); getline(cin, m); setMovieName(m);
        cout << "  Enter Show Time: "; cin >> t; setShowTime(t);
        cout << "  Enter Hall No (1-10): "; cin >> hall; setHallNumber(hall);
        cout << "  Enter Seat Number: "; cin >> seat; setSeatNumber(seat);
        cout << "  Enter Ticket Price (Rs.): "; cin >> price; setTotalAmount(price);
    }

    // Overridden display - shows movie-specific details
    // Demonstrates: Method Overriding
    void display() {
        cout << "  +-----------------------------------------+" << endl;
        cout << "  |        MOVIE TICKET                     |" << endl;
        cout << "  +-----------------------------------------+" << endl;
        cout << "  | Booking ID  : " << left << setw(26) << bookingId << "|" << endl;
        cout << "  | Customer ID : " << left << setw(26) << customerId << "|" << endl;
        cout << "  | Date        : " << left << setw(26) << date << "|" << endl;
        cout << "  | Movie       : " << left << setw(26) << movieName << "|" << endl;
        cout << "  | Show Time   : " << left << setw(26) << showTime << "|" << endl;
        cout << "  | Hall No     : " << left << setw(26) << hallNumber << "|" << endl;
        cout << "  | Seat No     : " << left << setw(26) << seatNumber << "|" << endl;
        cout << "  | Amount      : Rs." << left << setw(22) << fixed << setprecision(0) << totalAmount << "|" << endl;
        cout << "  +-----------------------------------------+" << endl;
    }
};

// ============================================
// HOTELBOOKING - DERIVED FROM BOOKING (Phase 4)
// Demonstrates: Inheritance, Code Reuse
// ============================================
class HotelBooking : public Booking {
private:
    int roomNumber;
    string roomType;
    string checkIn;
    string checkOut;
    int nights;

public:
    HotelBooking() : roomNumber(0), roomType(""), checkIn(""), checkOut(""), nights(0) {
        bookingType = "Hotel";
    }

    // Getters
    int getRoomNumber() { return roomNumber; }
    string getRoomType() { return roomType; }
    string getCheckIn() { return checkIn; }
    string getCheckOut() { return checkOut; }
    int getNights() { return nights; }

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

    // Input - takes booking details for a hotel room
    void input(int bId, int custId) {
        string d, ci, co, rt;
        int room, n;
        float ppn;

        setBookingId(bId);
        setCustomerId(custId);

        cout << "  Enter Booking Date (DD/MM/YYYY): "; cin >> d; setDate(d);
        cout << "  Enter Room Number: "; cin >> room; setRoomNumber(room);
        cout << "  Enter Room Type (Standard/Deluxe/Suite): "; cin >> rt; setRoomType(rt);
        cout << "  Enter Check-In Date (DD/MM/YYYY): "; cin >> ci; setCheckIn(ci);
        cout << "  Enter Check-Out Date (DD/MM/YYYY): "; cin >> co; setCheckOut(co);
        cout << "  Enter Number of Nights: "; cin >> n; setNights(n);
        cout << "  Enter Price Per Night (Rs.): "; cin >> ppn;

        // Auto-calculate total
        setTotalAmount(ppn * n);
        cout << "  Total Amount: Rs." << fixed << setprecision(0) << (ppn * n) << endl;
    }

    // Overridden display - shows hotel-specific details
    // Demonstrates: Method Overriding
    void display() {
        cout << "  +-----------------------------------------+" << endl;
        cout << "  |        HOTEL RECEIPT                    |" << endl;
        cout << "  +-----------------------------------------+" << endl;
        cout << "  | Booking ID  : " << left << setw(26) << bookingId << "|" << endl;
        cout << "  | Customer ID : " << left << setw(26) << customerId << "|" << endl;
        cout << "  | Date        : " << left << setw(26) << date << "|" << endl;
        cout << "  | Room No     : " << left << setw(26) << roomNumber << "|" << endl;
        cout << "  | Room Type   : " << left << setw(26) << roomType << "|" << endl;
        cout << "  | Check-In    : " << left << setw(26) << checkIn << "|" << endl;
        cout << "  | Check-Out   : " << left << setw(26) << checkOut << "|" << endl;
        cout << "  | Nights      : " << left << setw(26) << nights << "|" << endl;
        cout << "  | Total       : Rs." << left << setw(22) << fixed << setprecision(0) << totalAmount << "|" << endl;
        cout << "  +-----------------------------------------+" << endl;
    }
};

// ============================================
// GLOBAL ARRAYS & COUNTERS
// ============================================
const int MAX_CUSTOMERS = 50;
const int MAX_SHOWS = 10;
const int MAX_ROOMS = 20;
const int MAX_MOVIE_BOOKINGS = 100;
const int MAX_HOTEL_BOOKINGS = 100;

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
int nextBookingId = 1001; // Auto-incrementing booking ID

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

// Find customer index by ID, returns -1 if not found
int findCustomer(int id) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].getCustomerId() == id) return i;
    }
    return -1;
}

// Find show index by ID, returns -1 if not found
int findShow(int id) {
    for (int i = 0; i < showCount; i++) {
        if (shows[i].getShowId() == id) return i;
    }
    return -1;
}

// Find room index by number, returns -1 if not found
int findRoom(int no) {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].getRoomNo() == no) return i;
    }
    return -1;
}

// ============================================
// CUSTOMER MANAGEMENT
// ============================================
void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        cout << "  [!] Maximum customers reached." << endl;
        return;
    }
    cout << endl << "  --- Add New Customer ---" << endl;
    customers[customerCount].input();

    int newId = customers[customerCount].getCustomerId();
    if (findCustomer(newId) != -1 && findCustomer(newId) != customerCount) {
        cout << "  [!] Customer ID " << newId << " already exists." << endl;
        return;
    }
    customerCount++;
    cout << "  [+] Customer added! Total: " << customerCount << endl;
}

void viewAllCustomers() {
    if (customerCount == 0) { cout << "  [!] No customers yet." << endl; return; }
    cout << endl << "  --- All Customers (" << customerCount << ") ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "ID" << "| " << setw(20) << "Name"
         << "| " << setw(12) << "Phone" << "| " << setw(22) << "Email" << "|" << endl;
    printLine();
    for (int i = 0; i < customerCount; i++) customers[i].display();
    printLine();
}

void searchCustomer() {
    if (customerCount == 0) { cout << "  [!] No customers to search." << endl; return; }
    int id; cout << "  Enter Customer ID: "; cin >> id;
    int idx = findCustomer(id);
    if (idx != -1) {
        cout << "  [+] Customer found:" << endl;
        printLine();
        cout << "  | " << left << setw(6) << "ID" << "| " << setw(20) << "Name"
             << "| " << setw(12) << "Phone" << "| " << setw(22) << "Email" << "|" << endl;
        printLine();
        customers[idx].display();
        printLine();
    } else {
        cout << "  [!] Customer ID " << id << " not found." << endl;
    }
}

void deleteCustomer() {
    if (customerCount == 0) { cout << "  [!] No customers to delete." << endl; return; }
    int id; cout << "  Enter Customer ID to delete: "; cin >> id;
    int idx = findCustomer(id);
    if (idx != -1) {
        cout << "  Deleting: " << customers[idx].getName() << " (ID: " << id << ")" << endl;
        for (int j = idx; j < customerCount - 1; j++) customers[j] = customers[j + 1];
        customerCount--;
        cout << "  [+] Deleted. Remaining: " << customerCount << endl;
    } else {
        cout << "  [!] Customer ID " << id << " not found." << endl;
    }
}

// ============================================
// SHOW MANAGEMENT
// ============================================
void addShow() {
    if (showCount >= MAX_SHOWS) { cout << "  [!] Maximum shows reached." << endl; return; }
    cout << endl << "  --- Add New Show ---" << endl;
    shows[showCount].input();
    int newId = shows[showCount].getShowId();
    if (findShow(newId) != -1 && findShow(newId) != showCount) {
        cout << "  [!] Show ID " << newId << " already exists." << endl;
        return;
    }
    showCount++;
    cout << "  [+] Show added! Total: " << showCount << endl;
}

void viewAllShows() {
    if (showCount == 0) { cout << "  [!] No shows available." << endl; return; }
    cout << endl << "  --- All Shows (" << showCount << ") ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "ID" << "| " << setw(22) << "Movie"
         << "| " << setw(10) << "Time" << "| " << setw(6) << "Hall"
         << "| " << setw(6) << "Seats" << "|" << endl;
    printLine();
    for (int i = 0; i < showCount; i++) shows[i].display();
    printLine();
}

// ============================================
// ROOM MANAGEMENT
// ============================================
void addRoom() {
    if (roomCount >= MAX_ROOMS) { cout << "  [!] Maximum rooms reached." << endl; return; }
    cout << endl << "  --- Add New Room ---" << endl;
    rooms[roomCount].input();
    int newNo = rooms[roomCount].getRoomNo();
    if (findRoom(newNo) != -1 && findRoom(newNo) != roomCount) {
        cout << "  [!] Room No " << newNo << " already exists." << endl;
        return;
    }
    roomCount++;
    cout << "  [+] Room added! Total: " << roomCount << endl;
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
    if (found == 0) cout << "  | No available rooms at the moment.                            |" << endl;
    printLine();
    cout << "  Available: " << found << " / " << roomCount << endl;
}

// ============================================
// MOVIE BOOKING (Phase 4 - NEW)
// ============================================
void bookMovieTicket() {
    if (movieBookingCount >= MAX_MOVIE_BOOKINGS) {
        cout << "  [!] Maximum movie bookings reached." << endl;
        return;
    }
    if (customerCount == 0) {
        cout << "  [!] No customers registered. Add a customer first." << endl;
        return;
    }
    if (showCount == 0) {
        cout << "  [!] No shows available. Add a show first." << endl;
        return;
    }

    cout << endl << "  --- Book Movie Ticket ---" << endl;

    // Step 1: Verify customer
    int custId;
    cout << "  Enter Customer ID: "; cin >> custId;
    int custIdx = findCustomer(custId);
    if (custIdx == -1) {
        cout << "  [!] Customer not found. Please add customer first." << endl;
        return;
    }
    cout << "  Customer: " << customers[custIdx].getName() << endl;

    // Step 2: Show available shows
    cout << endl << "  Available Shows:" << endl;
    viewAllShows();

    // Step 3: Select show and verify seats
    int showId;
    cout << "  Enter Show ID to book: "; cin >> showId;
    int showIdx = findShow(showId);
    if (showIdx == -1) {
        cout << "  [!] Show not found." << endl;
        return;
    }
    if (shows[showIdx].getAvailableSeats() <= 0) {
        cout << "  [!] No seats available for this show." << endl;
        return;
    }

    // Step 4: Create the MovieBooking (inherits from Booking)
    movieBookings[movieBookingCount].input(nextBookingId, custId);

    // Auto-fill movie details from selected show
    movieBookings[movieBookingCount].setMovieName(shows[showIdx].getMovieName());
    movieBookings[movieBookingCount].setShowTime(shows[showIdx].getTime());
    movieBookings[movieBookingCount].setHallNumber(shows[showIdx].getHallNo());

    // Book the seat in the show
    shows[showIdx].bookSeat();

    cout << endl << "  [+] Movie ticket booked successfully!" << endl;
    cout << endl;
    movieBookings[movieBookingCount].display();

    movieBookingCount++;
    nextBookingId++;
}

void cancelMovieBooking() {
    if (movieBookingCount == 0) {
        cout << "  [!] No movie bookings to cancel." << endl;
        return;
    }

    int bId;
    cout << "  Enter Booking ID to cancel: "; cin >> bId;

    for (int i = 0; i < movieBookingCount; i++) {
        if (movieBookings[i].getBookingId() == bId) {
            cout << "  Cancelling booking:" << endl;
            movieBookings[i].display();

            // Shift remaining bookings
            for (int j = i; j < movieBookingCount - 1; j++) {
                movieBookings[j] = movieBookings[j + 1];
            }
            movieBookingCount--;
            cout << "  [+] Movie booking cancelled." << endl;
            return;
        }
    }
    cout << "  [!] Booking ID " << bId << " not found." << endl;
}

// ============================================
// HOTEL BOOKING (Phase 4 - NEW)
// ============================================
void bookHotelRoom() {
    if (hotelBookingCount >= MAX_HOTEL_BOOKINGS) {
        cout << "  [!] Maximum hotel bookings reached." << endl;
        return;
    }
    if (customerCount == 0) {
        cout << "  [!] No customers registered. Add a customer first." << endl;
        return;
    }
    if (roomCount == 0) {
        cout << "  [!] No rooms available. Add a room first." << endl;
        return;
    }

    cout << endl << "  --- Book Hotel Room ---" << endl;

    // Step 1: Verify customer
    int custId;
    cout << "  Enter Customer ID: "; cin >> custId;
    int custIdx = findCustomer(custId);
    if (custIdx == -1) {
        cout << "  [!] Customer not found. Please add customer first." << endl;
        return;
    }
    cout << "  Customer: " << customers[custIdx].getName() << endl;

    // Step 2: Show available rooms
    cout << endl;
    viewAvailableRooms();

    // Step 3: Select room
    int roomNo;
    cout << "  Enter Room No to book: "; cin >> roomNo;
    int roomIdx = findRoom(roomNo);
    if (roomIdx == -1) {
        cout << "  [!] Room not found." << endl;
        return;
    }
    if (!rooms[roomIdx].getIsAvailable()) {
        cout << "  [!] Room " << roomNo << " is already booked." << endl;
        return;
    }

    // Step 4: Create the HotelBooking (inherits from Booking)
    hotelBookings[hotelBookingCount].input(nextBookingId, custId);

    // Auto-fill room details from selected room
    hotelBookings[hotelBookingCount].setRoomNumber(rooms[roomIdx].getRoomNo());
    hotelBookings[hotelBookingCount].setRoomType(rooms[roomIdx].getType());

    // Mark room as booked
    rooms[roomIdx].markBooked();

    cout << endl << "  [+] Hotel room booked successfully!" << endl;
    cout << endl;
    hotelBookings[hotelBookingCount].display();

    hotelBookingCount++;
    nextBookingId++;
}

void cancelHotelBooking() {
    if (hotelBookingCount == 0) {
        cout << "  [!] No hotel bookings to cancel." << endl;
        return;
    }

    int bId;
    cout << "  Enter Booking ID to cancel: "; cin >> bId;

    for (int i = 0; i < hotelBookingCount; i++) {
        if (hotelBookings[i].getBookingId() == bId) {
            cout << "  Cancelling booking:" << endl;
            hotelBookings[i].display();

            // Free the room
            int roomNo = hotelBookings[i].getRoomNumber();
            int roomIdx = findRoom(roomNo);
            if (roomIdx != -1) rooms[roomIdx].markAvailable();

            // Shift remaining bookings
            for (int j = i; j < hotelBookingCount - 1; j++) {
                hotelBookings[j] = hotelBookings[j + 1];
            }
            hotelBookingCount--;
            cout << "  [+] Hotel booking cancelled. Room freed." << endl;
            return;
        }
    }
    cout << "  [!] Booking ID " << bId << " not found." << endl;
}

// ============================================
// VIEW ALL BOOKINGS (Phase 4 - NEW)
// ============================================
void viewAllBookings() {
    int total = movieBookingCount + hotelBookingCount;
    if (total == 0) {
        cout << "  [!] No bookings yet." << endl;
        return;
    }

    cout << endl;
    printDoubleLine();
    cout << "        All Bookings (" << total << " total)" << endl;
    printDoubleLine();

    if (movieBookingCount > 0) {
        cout << endl << "  MOVIE BOOKINGS (" << movieBookingCount << "):" << endl;
        for (int i = 0; i < movieBookingCount; i++) {
            cout << endl;
            movieBookings[i].display();
        }
    }

    if (hotelBookingCount > 0) {
        cout << endl << "  HOTEL BOOKINGS (" << hotelBookingCount << "):" << endl;
        for (int i = 0; i < hotelBookingCount; i++) {
            cout << endl;
            hotelBookings[i].display();
        }
    }

    cout << endl;
    printDoubleLine();
    cout << "  Summary: " << movieBookingCount << " movie + "
         << hotelBookingCount << " hotel = " << total << " bookings" << endl;
    printDoubleLine();
}

// ============================================
// MAIN MENU
// ============================================
void displayMenu() {
    cout << endl;
    printDoubleLine();
    cout << "        Cinema & Hotel Booking System" << endl;
    cout << "        Phase 4 - Inheritance" << endl;
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
    cout << "  BOOKINGS" << endl;
    cout << "    14. View All Bookings" << endl;
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

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "  [!] Invalid input. Enter a number." << endl;
            continue;
        }

        cout << endl;

        switch (choice) {
            // Customer
            case 1: addCustomer(); break;
            case 2: viewAllCustomers(); break;
            case 3: searchCustomer(); break;
            case 4: deleteCustomer(); break;

            // Cinema
            case 5: addShow(); break;
            case 6: viewAllShows(); break;
            case 7: bookMovieTicket(); break;
            case 8: cancelMovieBooking(); break;

            // Hotel
            case 9: addRoom(); break;
            case 10: viewAllRooms(); break;
            case 11: viewAvailableRooms(); break;
            case 12: bookHotelRoom(); break;
            case 13: cancelHotelBooking(); break;

            // Bookings
            case 14: viewAllBookings(); break;

            case 0:
                cout << endl;
                printDoubleLine();
                cout << "  Thank you for using Cinema & Hotel Booking System!" << endl;
                cout << "  Phase 4 Complete - Inheritance Applied:" << endl;
                cout << "    - Booking (base class)" << endl;
                cout << "    - MovieBooking (derived, inherits Booking)" << endl;
                cout << "    - HotelBooking (derived, inherits Booking)" << endl;
                printDoubleLine();
                break;

            default:
                cout << "  [!] Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
