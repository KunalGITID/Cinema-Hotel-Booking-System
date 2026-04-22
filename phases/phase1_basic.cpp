// Phase 1: Basic Classes & Objects
#include <iostream>
#include <string>
using namespace std;

class Customer {
public:
    int id; string name, phone;
    
    void input() {
        cout << "Enter Customer ID: "; cin >> id;
        cout << "Enter Name: "; cin.ignore(); getline(cin, name);
        cout << "Enter Phone: "; cin >> phone;
    }
    void display() { 
        cout << "Customer [ID: " << id << ", Name: " << name << ", Phone: " << phone << "]\n"; 
    }
};

class Show {
public:
    int id, seats; string movie, time;
    
    void input() {
        cout << "Enter Show ID: "; cin >> id;
        cout << "Enter Movie: "; cin.ignore(); getline(cin, movie);
        cout << "Enter Time: "; cin >> time;
        cout << "Enter Seats: "; cin >> seats;
    }
    void display() { 
        cout << "Show [ID: " << id << ", Movie: " << movie << ", Time: " << time << ", Seats: " << seats << "]\n"; 
    }
};

class Room {
public:
    int no; string type; float price;
    
    void input() {
        cout << "Enter Room No: "; cin >> no;
        cout << "Enter Type: "; cin >> type;
        cout << "Enter Price: "; cin >> price;
    }
    void display() { 
        cout << "Room [No: " << no << ", Type: " << type << ", Price: Rs." << price << "]\n"; 
    }
};

int main() {
    Customer c; Show s; Room r;
    
    cout << "--- Enter Details ---\n";
    c.input(); cout << "\n";
    s.input(); cout << "\n";
    r.input(); cout << "\n";
    
    cout << "--- System Summary ---\n";
    c.display();
    s.display();
    r.display();
    
    return 0;
}
