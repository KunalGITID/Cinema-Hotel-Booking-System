# Cinema & Hotel Booking Management System

**LLT1 — Application Development Using Design Concepts**
**B.Tech CSE (Data Science) — Semester 2**

A progressive C++ OOP project built phase-by-phase, demonstrating object-oriented design concepts through a unified Cinema & Hotel Booking Management System.

---

## Team Members

| Name | Registration Number |
|------|-------------------|
| Kunal Shukla | RA2511056010237 |
| Kushagra Jain | RA2511056010289 |
| Nourice | RA2511056010290 |

---

## About the Project

This system manages both a cinema hall and a hotel under one roof. Customers can book movie tickets, reserve hotel rooms, or do both. The system tracks customers, shows, rooms, and all bookings using proper object-oriented design.

The project was developed progressively across 6 phases — each phase introduces a new OOP concept as taught in class, building on top of the previous version.

---

## Features

- Add, Search, Delete, and View Customers
- Add and View Movie Shows
- Book Movie Tickets with seat tracking
- Add and View Hotel Rooms (Standard / Deluxe / Suite)
- Book Hotel Rooms with check-in/check-out and auto price calculation
- Cancel Movie and Hotel Bookings (seats/rooms auto-freed)
- View All Bookings with Revenue Summary
- Input validation on all fields (phone, email, IDs, room types)
- Menu-driven console interface with formatted tables

---

## OOP Concepts Demonstrated

| Phase | Concept | What Was Done |
|-------|---------|---------------|
| 1 | Classes & Objects (CO1) | Basic Customer, Show, Room classes with input/display |
| 2 | Encapsulation (CO2) | Private members, getters/setters, input validation |
| 3 | Arrays & Collections (CO3) | Arrays of objects, search/delete, menu-driven interface |
| 4 | Inheritance (CO4) | Booking base class, MovieBooking & HotelBooking derived |
| 5 | UML Diagrams (CO5) | Use Case, Class, Sequence, Collaboration diagrams |
| 6 | Final Integration | All concepts combined into a polished system |

---

## Folder Structure

```
Cinema-Hotel-Booking-System/
|
|-- README.md                          <-- You are here
|
|-- phases/                            <-- Code for each development phase
|   |-- phase1_basic.cpp               Phase 1: Basic classes & objects
|   |-- phase2_encapsulation.cpp       Phase 2: Private members, getters/setters
|   |-- phase3_arrays.cpp              Phase 3: Arrays, search, menu system
|   |-- phase4_inheritance.cpp         Phase 4: Booking base + derived classes
|   |-- final_cinema_hotel.cpp         Phase 6: Final polished version
|
|-- uml/                               <-- UML Diagrams (Phase 5)
|   |-- use_case_diagram.png           Actors & system actions
|   |-- class_diagram.png              Classes, attributes, methods, relationships
|   |-- sequence_diagram.png           Message flow for booking a movie ticket
|   |-- collaboration_diagram.png      Object interactions with numbered messages
|   |-- phase5_uml_documentation.md    Explanation of all 4 diagrams
|
|-- docs/                              <-- Project documentation
|   |-- Cinema_Hotel_Project_Blueprint.docx   Full project blueprint & guide
|
|-- .gitignore                         Ignores compiled files & IDE configs
```

---

## Class Structure

```
Customer          (standalone)    — stores customer details
Show              (standalone)    — stores movie show details
Room              (standalone)    — stores hotel room details

Booking           (base class)    — common booking attributes
  |
  |-- MovieBooking  (derived)     — adds movie, seat, hall info
  |-- HotelBooking  (derived)     — adds room, check-in/out, nights
```

**Key Relationships:**
- Customer → Booking (1 to many)
- MovieBooking → Show (uses)
- HotelBooking → Room (uses)
- MovieBooking & HotelBooking inherit from Booking

---

## How to Compile & Run

**Using g++ (Linux / Mac / MinGW on Windows):**
```bash
g++ phases/final_cinema_hotel.cpp -o booking_system -std=c++17
./booking_system
```

**Using an IDE:**
- Open `phases/final_cinema_hotel.cpp` in VS Code / Code::Blocks / Dev-C++
- Build and run

**To run individual phases:**
```bash
g++ phases/phase1_basic.cpp -o phase1 -std=c++17 && ./phase1
g++ phases/phase2_encapsulation.cpp -o phase2 -std=c++17 && ./phase2
g++ phases/phase3_arrays.cpp -o phase3 -std=c++17 && ./phase3
g++ phases/phase4_inheritance.cpp -o phase4 -std=c++17 && ./phase4
```

---

## Menu Options (Final Version)

```
  CUSTOMER MANAGEMENT
    1.  Add Customer
    2.  View All Customers
    3.  Search Customer
    4.  Delete Customer

  CINEMA MANAGEMENT
    5.  Add Show
    6.  View All Shows
    7.  Book Movie Ticket
    8.  Cancel Movie Booking

  HOTEL MANAGEMENT
    9.  Add Room
    10. View All Rooms
    11. View Available Rooms
    12. Book Hotel Room
    13. Cancel Hotel Booking

  REPORTS
    14. View All Bookings (with Revenue)

    0.  Exit
```

---

## UML Diagrams

All diagrams are in the `uml/` folder. See `uml/phase5_uml_documentation.md` for detailed explanations.

| Diagram | File | What It Shows |
|---------|------|---------------|
| Use Case | `use_case_diagram.png` | Customer & Admin actors with 8 system actions |
| Class | `class_diagram.png` | All 6 classes with attributes, methods, inheritance |
| Sequence | `sequence_diagram.png` | Step-by-step message flow for booking a movie ticket |
| Collaboration | `collaboration_diagram.png` | Object links with numbered message sequence |

---

## Progressive Development (Commit History)

Each phase was committed separately to demonstrate continuous improvement:

```
Phase 1: Basic classes - Customer, Show, Room
Phase 2: Encapsulation - private members, getters/setters, validation
Phase 3: Arrays - object collections, menu-driven interface, search/delete
Phase 4: Inheritance - Booking base class, MovieBooking & HotelBooking
Phase 5: UML diagrams - Use Case, Class, Sequence, Collaboration
Phase 6: Final polished version - complete system with all features
```

---

## Tech Stack

- **Language:** C++ (C++17)
- **Compiler:** g++ / any C++17 compatible compiler
- **UML Tools:** SVG (programmatic generation)
- **Version Control:** Git & GitHub
