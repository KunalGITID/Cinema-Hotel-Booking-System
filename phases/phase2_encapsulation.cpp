// Phase 2: Encapsulation (Private Members, Getters/Setters, Validation)
#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    int id; string name; string phone;
public:
    // Inlined Getters
    int getId() { return id; }
    string getName() { return name; }
    string getPhone() { return phone; }

    // Setters with inline validation
    void setId(int i) { if (i > 0) id = i; else cout << "  [!] Invalid ID.\n"; }
    void setName(string n) { if (!n.empty()) name = n; else cout << "  [!] Name empty.\n"; }
    void setPhone(string p) { if (p.length() == 10) phone = p; else cout << "  [!] Phone must be 10 digits.\n"; }

    void input() {
        int i; string n, p;
        cout << "Enter Customer ID: "; cin >> i; setId(i);
        cout << "Enter Name: "; cin.ignore(); getline(cin, n); setName(n);
        cout << "Enter Phone (10 digits): "; cin >> p; setPhone(p);
    }
    void display() { cout << "Customer: " << name << " [ID: " << id << "] - Ph: " << phone << "\n"; }
};

class Show {
private:
    int id; string movie; int seats;
public:
    // Getters
    int getId() { return id; } string getMovie() { return movie; } int getSeats() { return seats; }
    
    // Setters
    void setId(int i) { if (i > 0) id = i; }
    void setMovie(string m) { if (!m.empty()) movie = m; }
    void setSeats(int s) { if (s >= 0) seats = s; }

    bool bookSeat() { if (seats > 0) { seats--; return true; } return false; }

    void input() {
        int i, s; string m;
        cout << "Enter Show ID: "; cin >> i; setId(i);
        cout << "Enter Movie: "; cin.ignore(); getline(cin, m); setMovie(m);
        cout << "Enter Seats: "; cin >> s; setSeats(s);
    }
    void display() { cout << "Show: " << movie << " [ID: " << id << "] - Seats Left: " << seats << "\n"; }
};

class Room {
private:
    int no; string type; bool available;
public:
    // Getters & Setters
    int getNo() { return no; } string getType() { return type; } bool isAvailable() { return available; }
    void setNo(int n) { if (n > 0) no = n; }
    void setType(string t) { type = t; }
    
    void markBooked() { available = false; }
    void markAvailable() { available = true; }

    void input() {
        int n; string t;
        cout << "Enter Room No, Type (e.g., Deluxe): "; cin >> n >> t;
        setNo(n); setType(t); available = true;
    }
    void display() { cout << "Room: " << no << " [" << type << "] - " << (available ? "Available" : "Booked") << "\n"; }
};

int main() {
    cout << "--- Phase 2: Encapsulation Demo ---\n";
    Customer c;
    cout << "[Testing Validation]\n";
    c.setPhone("123");         // Will fail and print error
    c.setPhone("9876543210");  // Will succeed silently

    cout << "\n[Input Details]\n";
    c.input();
    Show s; s.input();
    Room r; r.input();

    cout << "\n[Testing Booking Logic]\n";
    if(s.bookSeat()) cout << "  -> Successfully booked 1 seat!\n";
    r.markBooked(); cout << "  -> Room marked as booked!\n";

    cout << "\n--- System Summary ---\n";
    c.display(); 
    s.display(); 
    r.display();
    return 0;
}
