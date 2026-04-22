// ================================================================
// Cinema & Hotel Booking System - Final Version
// OOP Concepts: Classes, Encapsulation, Vectors, Inheritance
// Team: Kunal Shukla, Kushagra Jain, Nourice
// ================================================================
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// --- ENCAPSULATED CLASSES ---
class Customer {
    int id; string name;
public:
    int getId() { return id; } string getName() { return name; }
    void input() { cout << "  ID: "; cin >> id; cout << "  Name: "; cin >> ws; getline(cin, name); }
    void display() { cout << "  Customer: " << name << " [ID: " << id << "]\n"; }
};

class Show {
    int id; string movie; int seats; float price;
public:
    int getId() { return id; } string getMovie() { return movie; } float getPrice() { return price; }
    void input() { 
        cout << "  ID, Price, Seats: "; cin >> id >> price >> seats; 
        cout << "  Movie: "; cin >> ws; getline(cin, movie); 
    }
    void display() { cout << "  Show: " << movie << " [ID: " << id << "] Seats: " << seats << " (Rs." << price << ")\n"; }
    bool book(int qty) { if (seats >= qty) { seats -= qty; return true; } return false; }
};

class Room {
    int no; float price; bool avail;
public:
    int getNo() { return no; } float getPrice() { return price; } bool isAvail() { return avail; }
    void input() { cout << "  Room No & Price: "; cin >> no >> price; avail = true; }
    void display() { cout << "  Room: " << no << " (Rs." << price << ") - " << (avail ? "Available" : "Booked") << "\n"; }
    void book() { avail = false; }
};

// --- INHERITANCE HIERARCHY ---
class Booking {
protected:
    int bId; string cName; float amount;
public:
    Booking(int id, string n, float a) : bId(id), cName(n), amount(a) {}
    float getAmount() { return amount; }
    virtual void display() { cout << "  [BkID: " << bId << "] " << cName << " | Total: Rs." << amount; }
};

class MovieBooking : public Booking {
    string movie; int tix;
public:
    MovieBooking(int id, string n, float a, string m, int t) : Booking(id, n, a), movie(m), tix(t) {}
    void display() override { Booking::display(); cout << " | Movie: " << movie << " (" << tix << " tix)\n"; }
};

class HotelBooking : public Booking {
    int roomNo; int nights;
public:
    HotelBooking(int id, string n, float a, int r, int nt) : Booking(id, n, a), roomNo(r), nights(nt) {}
    void display() override { Booking::display(); cout << " | Room: " << roomNo << " (" << nights << " nights)\n"; }
};

// --- GLOBAL VECTORS (Sequence Containers) ---
vector<Customer> customers;
vector<Show> shows;
vector<Room> rooms;
vector<MovieBooking> m_bookings;
vector<HotelBooking> h_bookings;
int nextBkId = 1001;

// --- BOOKING LOGIC ---
void bookMovie() {
    int cId, sId, tix; cout << "  Enter Customer ID, Show ID, Tickets: "; cin >> cId >> sId >> tix;
    string cName = ""; float price = 0; string mName = ""; bool sFound = false;
    
    for(auto& c : customers) if(c.getId() == cId) cName = c.getName();
    if(cName == "") { cout << "  [!] Customer not found.\n"; return; }
    
    for(auto& s : shows) if(s.getId() == sId) {
        if(s.book(tix)) { price = s.getPrice(); mName = s.getMovie(); sFound = true; }
        else { cout << "  [!] Not enough seats.\n"; return; }
    }
    if(!sFound) { cout << "  [!] Show not found.\n"; return; }
    
    m_bookings.push_back(MovieBooking(nextBkId++, cName, price * tix, mName, tix));
    cout << "  [+] Movie Booked! Total: Rs." << price * tix << "\n";
}

void bookHotel() {
    int cId, rNo, nights; cout << "  Enter Customer ID, Room No, Nights: "; cin >> cId >> rNo >> nights;
    string cName = ""; float price = 0; bool rFound = false;
    
    for(auto& c : customers) if(c.getId() == cId) cName = c.getName();
    if(cName == "") { cout << "  [!] Customer not found.\n"; return; }
    
    for(auto& r : rooms) if(r.getNo() == rNo) {
        if(r.isAvail()) { r.book(); price = r.getPrice(); rFound = true; }
        else { cout << "  [!] Room already booked.\n"; return; }
    }
    if(!rFound) { cout << "  [!] Room not found.\n"; return; }
    
    h_bookings.push_back(HotelBooking(nextBkId++, cName, price * nights, rNo, nights));
    cout << "  [+] Hotel Booked! Total: Rs." << price * nights << "\n";
}

void viewAllAndRevenue() {
    cout << "\n--- System Data ---\n";
    for(auto& c : customers) c.display();
    for(auto& s : shows) s.display();
    for(auto& r : rooms) r.display();
    
    cout << "\n--- Bookings & Revenue ---\n";
    float totalRev = 0;
    for(auto& mb : m_bookings) { mb.display(); totalRev += mb.getAmount(); }
    for(auto& hb : h_bookings) { hb.display(); totalRev += hb.getAmount(); }
    cout << "=================================\n";
    cout << "  TOTAL REVENUE: Rs." << totalRev << "\n";
    cout << "=================================\n";
}

// --- MAIN MENU ---
int main() {
    int opt;
    do {
        cout << "\n=== Cinema & Hotel Booking (Team: Kunal, Kushagra, Nourice) ===\n"
             << "1. Add Customer   4. Book Movie Ticket\n"
             << "2. Add Show       5. Book Hotel Room\n"
             << "3. Add Room       6. View All Data & Revenue\n"
             << "0. Exit\nChoice: ";
        cin >> opt;
        if (cin.fail()) { cin.clear(); cin.ignore(10000, '\n'); continue; }

        cout << "\n";
        switch (opt) {
            case 1: { Customer c; c.input(); customers.push_back(c); cout << "  [+] Customer Added.\n"; break; }
            case 2: { Show s; s.input(); shows.push_back(s); cout << "  [+] Show Added.\n"; break; }
            case 3: { Room r; r.input(); rooms.push_back(r); cout << "  [+] Room Added.\n"; break; }
            case 4: bookMovie(); break;
            case 5: bookHotel(); break;
            case 6: viewAllAndRevenue(); break;
            case 0: cout << "  Exiting... Thank you!\n"; break;
            default: cout << "  [!] Invalid choice.\n";
        }
    } while (opt != 0);
    return 0;
}
