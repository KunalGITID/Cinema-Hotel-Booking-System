// Phase 3: Arrays & Object Collections (Using std::vector)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// --- ENCAPSULATED CLASSES ---
class Customer {
private:
    int id; string name; string phone;
public:
    int getId() { return id; }
    void input() {
        cout << "  Enter ID: "; cin >> id;
        cout << "  Enter Name: "; cin.ignore(); getline(cin, name);
        cout << "  Enter Phone: "; cin >> phone;
    }
    void display() { cout << "  -> Customer: " << name << " [ID: " << id << "] Ph: " << phone << "\n"; }
};

class Show {
private:
    int id; string movie; int seats;
public:
    int getId() { return id; }
    void input() {
        cout << "  Enter Show ID, Movie Name, Seats: "; 
        cin >> id; cin.ignore(); getline(cin, movie); cin >> seats;
    }
    void display() { cout << "  -> Show: " << movie << " [ID: " << id << "] Seats Left: " << seats << "\n"; }
};

class Room {
private:
    int no; string type; bool available;
public:
    int getNo() { return no; } bool isAvailable() { return available; }
    void input() {
        cout << "  Enter Room No & Type (e.g., 101 Deluxe): "; cin >> no >> type;
        available = true;
    }
    void display() { cout << "  -> Room: " << no << " [" << type << "] - " << (available ? "Available" : "Booked") << "\n"; }
};

// --- GLOBAL VECTORS (Dynamic Sequence Containers) ---
vector<Customer> customers;
vector<Show> shows;
vector<Room> rooms;

// --- MENU FUNCTIONS ---
void manageCustomers() {
    int choice; cout << "\n1.Add 2.View All 3.Delete\nChoice: "; cin >> choice;
    if (choice == 1) {
        Customer c; c.input(); customers.push_back(c); cout << "  [+] Added!\n";
    } else if (choice == 2) {
        if (customers.empty()) cout << "  [!] No customers.\n";
        for (auto& c : customers) c.display();
    } else if (choice == 3) {
        int id; cout << "  Enter ID to delete: "; cin >> id;
        for (auto it = customers.begin(); it != customers.end(); ++it) {
            if (it->getId() == id) {
                customers.erase(it); cout << "  [-] Deleted!\n"; return;
            }
        }
        cout << "  [!] Not found.\n";
    }
}

void manageShows() {
    int choice; cout << "\n1.Add 2.View All\nChoice: "; cin >> choice;
    if (choice == 1) {
        Show s; s.input(); shows.push_back(s); cout << "  [+] Added!\n";
    } else if (choice == 2) {
        if (shows.empty()) cout << "  [!] No shows.\n";
        for (auto& s : shows) s.display();
    }
}

void manageRooms() {
    int choice; cout << "\n1.Add 2.View All 3.View Available\nChoice: "; cin >> choice;
    if (choice == 1) {
        Room r; r.input(); rooms.push_back(r); cout << "  [+] Added!\n";
    } else if (choice == 2) {
        if (rooms.empty()) cout << "  [!] No rooms.\n";
        for (auto& r : rooms) r.display();
    } else if (choice == 3) {
        for (auto& r : rooms) if (r.isAvailable()) r.display();
    }
}

int main() {
    int opt;
    do {
        cout << "\n=== Cinema & Hotel System ===\n"
             << "1. Manage Customers\n2. Manage Shows\n3. Manage Rooms\n0. Exit\n"
             << "Enter choice: ";
        cin >> opt;

        if (cin.fail()) { cin.clear(); cin.ignore(10000, '\n'); continue; }

        switch (opt) {
            case 1: manageCustomers(); break;
            case 2: manageShows(); break;
            case 3: manageRooms(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (opt != 0);

    return 0;
}
